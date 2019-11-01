#ifndef GRAPHE_H
#define GRAPHE_H

typedef struct Arc
{
	int ngb;
	char ch;
	struct Arc* nxtA;
}Arc;

typedef struct Graph
{
	int nb_head;
	Arc* arcs;
}Graph;

Graph* create_graph(int nb_head);

void add_arc(Graph* g, int s1, char e, int s2);

int arc_exist(Graph* g, int s1, char e, int s2);

#endif
