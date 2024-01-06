// test_automate.c

#include "../include/automate.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


bool mot_dans_auto(struct Automate *automate, const char *mot) {
  int etat_actuel = 0;
  for (size_t i = 0; i < strlen(mot); ++i) {
    char carac_actuel = mot[i];
    bool transition_trouve = false;

    for (int j = 0; j < automate->transition_nb; ++j) {
      if (automate->transitions[j]->from->id == etat_actuel && automate->transitions[j]->carac == carac_actuel) {
	etat_actuel = automate->transitions[j]->to->id;
	transition_trouve = true;
	break;
      }
    }
    if (!transition_trouve) {
      return false;
    }
  }

  for (int i = 0; i < automate->etat_nb; ++i) {
    if (automate->etats[i]->id == etat_actuel) {
      return true;
    }
  }
  return false;
}


int main() {

  char reponse;
  printf("Voulez-vous utiliser l'aphabet et les transitions de base ? (o/n) :");
  scanf(" %c", &reponse);

  if (reponse == 'o') {
  
    struct Automate *automate = creer_automate();

    // Ajout des états et transitions
    ajoute_etat(automate, 0);
    ajoute_etat(automate, 1);
    ajoute_etat(automate, 2);
    ajoute_transition(automate, 0, 1, 'a');
    ajoute_transition(automate, 0, 2, 'b');
    ajoute_transition(automate, 1, 0, 'a');
    ajoute_transition(automate, 1, 2, 'b');
    ajoute_transition(automate, 2, 0, 'a');
    ajoute_transition(automate, 2, 1, 'b');

    // Affichage du langage reconnu par l'automate
    determine_langue(automate);

    // Test si le mot appartient à l'automate
    char mot[100];
    printf("\nEntrez un mot composé de 'a' et 'b') : ");
    scanf("%s", mot);

    if (mot_dans_auto(automate, mot)) {
      printf("\nLe mot \"%s\" appartient à l'automate.\n", mot);
    } else {
      printf("\nLe mot \"%s\" n'appartient pas à l'automate.\n", mot);
    }

    int etat_final = etat_final_du_mot(automate, mot);
    if (etat_final != -1) {
      printf("\nL'automate termine dans l'état : %d\n", etat_final);
    } else {
      printf("\nL'automate n'a pas atteint d'état final pour le mot \"%s\"\n", mot);
    }

    free_automate(automate);

  } else {

    int nb_etat_user;
    printf("Entrez le nombre d'états : ");
    scanf("%d", &nb_etat_user);

    struct Automate *user_automate = creer_automate();
    for (int i = 0; i < nb_etat_user; ++i) {
      ajoute_etat(user_automate, i);
    }
    printf("Entrez le nombre de transitions : ");
    int nb_tran_user;
    scanf("%d", &nb_tran_user);

    for (int i = 0; i < nb_tran_user; ++i) {
      int from, to;
      char carac;
      printf("Transition %d - De l'état : ", i+1);
      scanf("%d", &from);
      printf("Transition %d - À l'état : ", i+1);
      scanf("%d", &to);
      printf("Transition %d - Avec le caractère : ", i+1);
      scanf(" %c", &carac);
      ajoute_transition(user_automate, from, to, carac);
    }

    // Test si le mot appartient à l'automate
    char mot[100];
    printf("\nEntrez un mot composé de l'aphabet que vous avez donné : ");
    scanf("%s", mot);

    if (mot_dans_auto(user_automate, mot)) {
      printf("Le mot \"%s\" appartient à l'automate.\n", mot);
    } else {
      printf("Le mot \"%s\" n'appartient pas à l'automate.\n", mot);
    }

    int etat_final = etat_final_du_mot(user_automate, mot);
    if (etat_final != -1) {
      printf("\nL'automate termine dans l'état : %d\n", etat_final);
    } else {
      printf("\nL'automate n'a pas atteint d'état final pour le mot \"%s\"\n", mot);
    }

    free_automate(user_automate);
  }

      
  return 0;
}
