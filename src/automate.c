// automate.c

#include "../include/automate.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct Automate *creer_automate() {
  printf("\nCréation de l'automate :\n");
  struct Automate *automate = (struct Automate *)malloc(sizeof(struct Automate));
  if (automate != NULL) {
    automate->etat_nb = 0;
    automate->etats = NULL;
    automate->transition_nb = 0;
    automate->transitions = NULL;
  }
  return automate;
}

void ajoute_etat(struct Automate *automate, int id) {
  printf("\tAjout d’un état %d\n", id);

  if (automate != NULL) {
    // Augmenter la taille du tableau des états
    automate->etats = realloc(automate->etats, (automate->etat_nb + 1) * sizeof(struct Etat *));

    // Allouer de la mémoire pour le nouvel état
    automate->etats[automate->etat_nb] = malloc(sizeof(struct Etat));
   	 
    if (automate->etats[automate->etat_nb] != NULL) {
      automate->etats[automate->etat_nb]->id = id;
      automate->etat_nb++;
    } else {
      fprintf(stderr, "Erreur : Impossible d'allouer de la mémoire pour l'état %d\n", id);
    }
  } else {
    fprintf(stderr, "Erreur : L'automate est NULL\n");
  }
}


void ajoute_transition(struct Automate *automate, int from, int to, char carac) {
  printf("\tAjout d’un transition de %d à %d avec le caractère %c\n", from, to, carac);

  if (automate != NULL) {
    // Augmenter la taille du tableau des transitions
    automate->transitions = realloc(automate->transitions, (automate->transition_nb + 1) * sizeof(struct Transition *));

    // Allouer de la mémoire pour la nouvelle transition
    automate->transitions[automate->transition_nb] = malloc(sizeof(struct Transition));

    if (automate->transitions[automate->transition_nb] != NULL) {
      automate->transitions[automate->transition_nb]->from = automate->etats[from];
