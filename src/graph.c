#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

Graph* create_graph(int nb_head)
{
	int i;
	Arc** arcs =(Arc**) malloc(nb_head*sizeof(Arc*));
	Graph* g = malloc(sizeof(Graph));
	g->arcs = arcs;
	g->nb_head = nb_head;

	for(i=0; i<nb_head; i++)
	{
		g->arcs[i] = NULL;
	}
	return g;
}


/*void add_arc(Graph* g, int s1, char e, int s2)
{
	Arc* ax; 
	if(s1 >= 0 && s1 <g->nb_head)
	{
		if(g->arcs[s1] == NULL)
		{	g->arcs[s1] = malloc(sizeof(Arc));
			((g->arcs)[s1])->ngbr = s2;
			((g->arcs)[s1])->ch = e; 
		}
		else
		{
			ax = g->arcs[s1];
			while(ax->nxtA != NULL)
			{
				ax = ax->nxtA;
			}
			ax->nxtA = malloc(sizeof(Arc));
			ax = ax->nxtA;
			ax->ngbr = s2;
			ax->ch = e;

		}
	}

}*/

void add_arc(Graph* g, int s1, char e, int s2)
{
	Arc* ax; 
	if(s1 >= 0 && s1 < g->nb_head && s2 >= 0 && g->nb_head)
	{
		if(g->arcs[s1] == NULL)
		{	g->arcs[s1] = malloc(sizeof(Arc));
			((g->arcs)[s1])->ngbr = s2;
			g->arcs[s1]->ch = e; 
		}
		else
		{
			ax = g->arcs[s1];
			g->arcs[s1] = malloc(sizeof(Arc));
			g->arcs[s1]->nxtA = ax;
	
			g->arcs[s1]->ngbr = s2;
			g->arcs[s1]->ch = e;

		}
	}
	else{
		printf("Bad state passed !\n");
	}

}

int arc_exist(Graph* g, int s1, char e, int s2)
{
    Arc* ax = g->arcs[s1];
	int cnt = 1;
	int r=0;
	while(ax != NULL && cnt)
	{
		if(ax->ngbr == s2 && ax->ch == e)
		{
			r = 1;
			cnt = 0;
		}
		ax = ax->nxtA;
	}

	return r;

}


void print_Arc(int s1, Arc* a)
{
	printf("[%d %c %d] ", s1, a->ch, a->ngbr);
}

void print_Graph(Graph* g)
{
	int i;
	Arc* ax;
	for(i=0; i<g->nb_head; i++)
	{
		printf("Head %d => ", i);
		ax = g->arcs[i];
		while(ax != NULL)
		{
			print_Arc(i, ax);
			ax = ax->nxtA;
		}
		printf("\n");
	}
	printf("\n");
}


void rmv_arc(Graph* g, int s1, char e, int s2)
{
	Arc *ax = g->arcs[s1], *arv;
	if(ax == NULL)
	{
		printf("Graph empty ! \n");
		exit(1);
	}
	else{
		if(s1 >= 0 && s1 < g->nb_head && s2 >= 0 && g->nb_head)
		{
			if(ax->ngbr == s2 && ax->ch == e)
			{	
				arv = ax;
				g->arcs[s1] = ax->nxtA;;
				free(arv);
				arv = NULL;
			}
			else
			{
				arv = ax->nxtA;
				while(arv != NULL)
				{
					if(arv->ngbr == s2 && arv->ch == e)
					{	
						ax->nxtA = ax->nxtA->nxtA;
						free(arv);
						arv = NULL;
					}
					else
					{
						ax = ax->nxtA;
						arv = arv->nxtA;
					}
				}
			}
		}
		else{
			printf("Bad state passed !\n");
		}
	}

}

int transit(Graph* g, int s1, char e)
{
	Arc* ax = g->arcs[s1];
	int cnt = 1;
	int r=-1;
	while(ax != NULL && cnt)
	{
		if(ax->ch == e)
		{
			r = ax->ngbr;
			cnt = 0;
		}
		ax = ax->nxtA;
	}

	return r;
}


void free_graph(Graph* g)
{
	Arc* ax, *arv;

	if(g != NULL)
	{
		for(int i=0; i<g->nb_head; i++)
		{
			arv = g->arcs[i];
			if(arv != NULL)
			{
				ax = arv->nxtA;
			}

			while(ax != NULL)
			{
				free(arv);
				arv = ax;
				ax = ax->nxtA;
			}
			g->arcs[i] = NULL;
		}
	}
	
}

