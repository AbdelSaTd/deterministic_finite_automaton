#ifndef AUTO_H
#define AUTO_H

#include "graph.h"

typedef struct Automate
{ 
	int init_st;
	int nb_finals;//Final state number
	int *finals_st;
	char *alphab;
	Graph *grph;
}Automate;

Automate* create_automate(int nb_st, char *alphab, int i_st, int* f_st, int nb_finals);

void free_autom(Automate* autom);
//Return -1 if the transition already exist or 0 if <ch> does not belong to the alphabet or <s1>, <s2> to the states
int add_transition(Automate* autom, int e1, char ch, int e2);
void print_autom(Automate* autom);

/*
* Return 1 if word is recognized by autom, 0 else
*/
int accept(Automate* autom, char* word);


int stateNextChar(Automate* autom, int s1, char e);
void langage_croissant(Automate* autom, int);


#endif
