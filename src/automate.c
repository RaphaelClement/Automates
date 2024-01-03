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
