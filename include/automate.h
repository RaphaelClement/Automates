// automate.h

#include <stdbool.h>
#ifndef AUTOMATE_H
#define AUTOMATE_H


struct Etat {
  int id;
  bool final;
};

struct Transition {
  struct Etat *from;
  struct Etat *to;
  char carac;
};

struct Automate {
  int etat_nb;
  struct Etat **etats;
  int transition_nb;
  struct Transition **transitions;
};


struct Automate *creer_automate();
void ajoute_etat(struct Automate *automate, int id);
void ajoute_transition(struct Automate *automate, int from, int to, char carac);
void determine_langue(struct Automate *automate);
void free_automate(struct Automate *automate);
int etat_final_du_mot(struct Automate *automate, const char *mot);

#endif /* AUTOMATE_H */
