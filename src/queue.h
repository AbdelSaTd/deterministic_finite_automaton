#ifndef FILE_H
#define FILE_H

typedef struct Cell{
    //int profond;
	char* word;
	int state;
    struct Cell *nxt;
} Cell;

typedef struct{
    Cell* head;
    Cell* bottom;
    int nbElts;
} Queue;


void init_queue(Queue**);

void add_elt(Queue**, int, char*);

Cell* del_elt(Queue**);


void disp_q(Queue*);

int empty_queue(Queue*);

#endif
