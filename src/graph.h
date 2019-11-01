#ifndef GRAPHE_H
#define GRAPHE_H

typedef struct Arc
{
	int ngbr; //Index of the state whichs is links by the state of this state
	char ch; // Character representing this arc
	struct Arc* nxtA;
}Arc;

typedef struct Graph
{
	int nb_head;
	Arc** arcs;
}Graph;

Graph* create_graph(int nb_head);

void add_arc(Graph* g, int s1, char e, int s2);

//Return 0 if the arc does not exist and 1 otherwise
int arc_exist(Graph* g, int s1, char e, int s2);

void print_Arc(int s1, Arc* a);

void print_Graph(Graph* g);

void rmv_arc(Graph* g, int s1, char e, int s2);

//Return n (int), corresponding to the state reached from <s1> after having read <e> and -1 if none transition exist
int transit(Graph* g, int s1, char e);

void free_graph(Graph* g);

#endif
