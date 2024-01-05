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
