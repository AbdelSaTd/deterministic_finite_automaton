#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "queue.h"

void init_queue(Queue** ptr2_q)
{
    *ptr2_q = malloc(sizeof(Queue));
    (*ptr2_q)->head = NULL;
    (*ptr2_q)->bottom = NULL;
    (*ptr2_q)->nbElts = 0;
}


void add_elt(Queue** p2_q, int state, char* word)
{
    Cell *cx;
    if( (*p2_q)->head == NULL)
    {
        (*p2_q)->head = malloc(sizeof(Cell));
        (*p2_q)->bottom = (*p2_q)->head;

        cx = (*p2_q)->head;
        cx->state = state;
        cx->word = malloc((strlen(word)+1)*sizeof(char));
        strcpy(cx->word, word);

        cx->nxt = NULL;
        (*p2_q)->nbElts++;
    }
    else
    {
        ((*p2_q)->bottom)->nxt = malloc(sizeof(Cell));
        cx = ((*p2_q)->bottom)->nxt;
        
		cx->state = state;
        cx->word = malloc((strlen(word)+1)*sizeof(char));
        strcpy(cx->word, word);
        
		cx->nxt = NULL;
        (*p2_q)->bottom = cx;
        (*p2_q)->nbElts++;
    }
}

Cell* del_elt(Queue** p2_q)
{
    Cell* c = (*p2_q)->head;
    if( c != NULL )
    {
        if(c->nxt == NULL)
        {
            (*p2_q)->head = NULL;
            (*p2_q)->bottom = NULL;
            (*p2_q)->nbElts--;
        }
        else
        {
            (*p2_q)->head = c->nxt; 
            (*p2_q)->nbElts--;          
        }
		return c;
    }
    else
    {
        printf("NULLL\n");
		return NULL;
    }
}

void disp_q(Queue* p_q)
{
    if(p_q != NULL)
    {
        Cell* cx = p_q->head;
        printf("Queue(%d) => { ", p_q->nbElts);
        while(cx != NULL)
        {
            printf("(st:%d, word:%s) ", cx->state, cx->word);
            cx = cx->nxt;
        }
        printf("}\n");
    }else{
        printf("NULL\n");
    }
}

int empty_queue(Queue* p_q)
{
	return (p_q->nbElts == 0);
}