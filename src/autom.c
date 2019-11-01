#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autom.h"
#include "graph.h"
#include "queue.h"


Automate* create_automate(int nb_st, char *alphab, int i_st, int* f_st, int nb_finals)
{
	Automate *autom = malloc(sizeof(Automate));
	autom->grph = create_graph(nb_st);
	autom->alphab = alphab;
	autom->init_st = i_st;
	autom->finals_st = f_st;
	autom->nb_finals = nb_finals;

	return autom;
}


void free_autom(Automate* autom)
{
	free_graph(autom->grph);
	free(autom);
}

int add_transition(Automate* autom, int e1, char ch, int e2)
{
	int ch_notvalid=1, i=0;
	while(autom->alphab[i] != '\0' && ch_notvalid)
	{
		if(autom->alphab[i] == ch)
		{
			ch_notvalid = 0;
		}
		i++;
	}


	if( e1 < autom->grph->nb_head && e2 < autom->grph->nb_head && e1>=0 && e2>=0 && !ch_notvalid)
	{
		if(arc_exist(autom->grph, e1, ch, e2))
		{
			printf("Error this transition already exist\n");
			return -1;
		}
		else{
			add_arc(autom->grph, e1, ch, e2);
			return 1;
		}
	}
	else
	{
		printf("Error in one of the parameter\n");
		return -1;
	}
}

void print_autom(Automate* autom)
{
	int i=0;
	printf("Init state= %d \n", autom->init_st);
	printf("Nb finals states= %d \n", autom->nb_finals);

	printf("{ ");
	for(i=0;i<autom->nb_finals;i++)
	{
		printf("%d ",autom->finals_st[i]);
	}
	printf("}\n");
	
	printf("Alphabet : { %s }\n",autom->alphab);

	print_Graph(autom->grph);

}

int word_in_alphabet(char* word, char* alphab)
{
	int i =0;
	while (word[i]!= '\0')
	{
		if(strchr(alphab,word[i]) == NULL)
		{
			return 0;
		}
		i++;
	}
	return 1;
}


int stateNextChar(Automate* autom, int s1, char e)
{
	return transit(autom->grph, s1, e);
}



int accept(Automate* autom, char* word)
{
	int current_state=autom->init_st, i=0;

	while(word[i] != '\0');
	{
		current_state = transit(autom->grph, current_state, word[i]);
		if(current_state == -1)
		{
			return 0;
		}
		else{
			i++;
		}
	}

	for(i=0;i<autom->nb_finals;i++)
	{
		if(current_state == autom->finals_st[i])
			return 1;
	}

	return 0;
	

}


void langage_croissant(Automate* autom, int profMax)
{
	/*Queue* q=NULL;
	Arc* acx;
	int i=0, bool_final_st=0, current_state = autom->init_st;
	init_queue(&q);

	add_elt(&q, current_state, "");

	while(empty_queue(q) == 0)
	{
		acx = autom->grph->arcs[current_state];
		while(acx != NULL)
		{
			for(i=0;i<autom->nb_finals;i++)
			{
				if(current_state == autom->finals_st[i])
					bool_final_st=1;
			}
			if(bool_final_st)
			{
				
			}
			add_elt(&q, acx->ngbr, acx->ch);
			acx = acx->nxtA;
		}
	}*/
}
