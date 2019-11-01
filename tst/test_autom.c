#include <stdio.h>
#include <stdlib.h>
#include "../src/autom.h"
#include "../src/graph.h"
#include <string.h>


#define NB_FINALS_STATES 2
#define CARD_ALPHB 5 

int main()
{
    int nb_states = 5;
    int finals_st[NB_FINALS_STATES] = {2,  4};
    int nb_finals = NB_FINALS_STATES;
    char alphabet[CARD_ALPHB] = "abcd", word[20];
    int initial = 0;


    Automate *autom = create_automate(nb_states, alphabet, initial, finals_st, nb_finals);


    add_transition(autom,0,'a',1);
    add_transition(autom,1,'b',4);
    add_transition(autom,0,'c',3);
    add_transition(autom,3,'b',1);
    add_transition(autom,3,'a',4);
    add_transition(autom,1,'d',1);
    add_transition(autom,1,'b',2);
    add_transition(autom,2,'c',3);



    print_autom(autom);
    
    strcpy(word, "ab\0");
    printf("%s find in automate ? %d \n", word, accept(autom, word));
   
    strcpy(word, "cb");
    printf("%s find in automate ? %d \n", word, accept(autom, word));
   
    strcpy(word, "cc");
    printf("%s find in automate ? %d \n", word, accept(autom, word));   
    

    strcpy(word, "abcbddb");
    printf("%s find in automate ? %d \n", word, accept(autom, word));

    strcpy(word, "abcbdd");
    printf("%s find in automate ? %d \n", word, accept(autom, word));

    
    return 0;
}
