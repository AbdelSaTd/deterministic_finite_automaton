#include <stdio.h>
#include <stdlib.h>
#include "../src/autom.h"
#include "../src/graph.h"


#define NB_FINALS_STATES 2
#define CARD_ALPHB 5 

int main()
{
    int nb_states = 5;
    int finals_st[NB_FINALS_STATES] = {2,  4};
    int nb_finals = NB_FINALS_STATES;
    char alphabet[CARD_ALPHB] = "abcd";
    int initial = 0;

    Automate *autom = create_automate(nb_states, alphabet, initial, finals_st, nb_finals);


    add_transition(autom,0,'a',1);
    add_transition(autom,1,'b',4);
    add_transition(autom,0,'c',3);
    add_transition(autom,3,'b',1);
    add_transition(autom,1,'d',1);

    print_autom(autom);
    
    if(accept(autom, "ab"))
    {
        printf("Trv \n");
    }
    else
    {
        printf("Pas trv \n");
    }

    if(accept(autom, "cb"))
    {
        printf("Trv \n");
    }
    else
    {
        printf("Pas trv \n");
    }

    
    if(accept(autom, "cc"))
    {
        printf("Trv \n");
    }
    else
    {
        printf("Pas trv \n");
    }

    if(accept(autom, "adddb"))
    {
        printf("Trv \n");
    }
    else
    {
        printf("Pas trv \n");
    }





    
    return 0;
}
