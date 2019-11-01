#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

Graph* create_graph(int nb_head)
{
	Arc* arcs =(Arc*) malloc(nb_head*sizeof(Arc));
	Graph* g = malloc(sizeof(Graph));
	g->arcs = arcs;
	return g;
}


void create_arc(Graph* g, int s1, char e, int s2)
{
    exit(0);
}

int arc_exist(Graph* g, int s1, char e, int s2)
{
    exit(0);
}
