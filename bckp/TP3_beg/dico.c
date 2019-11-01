#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Cellule{
	char* mot;
	struct Cellule *nxt;
} Cellule;

void insert (Cellule **c, char *mot)
{
	int s = strlen(mot);
	
	if(*c == NULL)
	{
		*c = malloc(sizeof(Cellule));
		(*c)->mot = malloc(sizeof(mot)+1);
		strcpy((*c)->mot, mot);
		(*c)->nxt = NULL;
	}
	else
	{
		int i=0;
		Cellule *cx;

		while((*c)->mot[i] == mot[i] && i < s)
		{
			i++;
		}


		if(i == s)
		{
			cx = *c;
			*c = malloc(sizeof(Cellule));
			(*c)->mot = malloc(sizeof(mot)+1);
			strcpy((*c)->mot, mot);
			(*c)->nxt = cx;
		}
		else
		{
			
			if((*c)->mot[i] > mot[i])
			{
				cx = *c;
				*c = malloc(sizeof(Cellule));
				(*c)->mot = malloc(sizeof(mot)+1);
				strcpy((*c)->mot, mot);
				(*c)->nxt = cx;
			}
			else if((*c)->nxt == NULL)
			{
				
				(*c)->nxt = malloc(sizeof(Cellule));
				(*c)->nxt->mot = malloc(sizeof(mot)+1);
				strcpy((*c)->nxt->mot, mot);
				(*c)->nxt->nxt = NULL;
			}
			else
			{
				int insert_ok = 0;
				Cellule *cx0;
				
				cx = *c;
				while(!insert_ok)
				{
					i = 0;
					while(cx->nxt->mot[i] == mot[i] && i < s)
					{
						i++;
					}

					if( i == s)
					{
						cx0 = cx->nxt;
						cx->nxt = malloc(sizeof(Cellule));
						cx->nxt->mot = malloc(sizeof(mot)+1);
						strcpy(cx->nxt->mot, mot);
						cx->nxt->nxt = cx0;
						insert_ok = 1;
					}
					else
					{
						if(cx->nxt->mot[i] > mot[i])
						{
							cx0 = cx->nxt;
							cx->nxt = malloc(sizeof(Cellule));
							cx->nxt->mot = malloc(sizeof(mot)+1);
							strcpy(cx->nxt->mot, mot);
							cx->nxt->nxt = cx0;
							insert_ok = 1;
						}
						else if(cx->nxt->nxt != NULL) //Attention à l'ordre des conditions
						{
							cx = cx->nxt;
						}
						else
						{
							cx = cx->nxt;
							cx->nxt = malloc(sizeof(Cellule));
							cx->nxt->mot = malloc(sizeof(mot)+1);
							strcpy(cx->nxt->mot, mot);
							cx->nxt->nxt = NULL;
							insert_ok = 1;
						}
						
					}
					
				}
				
			}
				
		}
	}
	
	
}

void printd(Cellule *c)
{
	while(c != NULL)
	{
		printf("%s  ", c->mot);
		c = c->nxt;
	}
	printf("[-\n");
}


int main()
{
	Cellule *c = NULL;

	insert(&c, "ada");
	printd(c);
	insert(&c, "ajar");
	printd(c);
	insert(&c, "awi");
	printd(c);
	insert(&c, "azi");
	printd(c);
	insert(&c, "amie");
	printd(c);
	insert(&c, "bami");
	printd(c);
	insert(&c, "zami");
	printd(c);
	insert(&c, "aami");
	printd(c);
	insert(&c, "ami");
	printd(c);
	insert(&c, "amis");
	printd(c);
	insert(&c, "ajjar");
	printd(c);
	insert(&c, "hajar");
	printd(c);
	insert(&c, "heddoun");
	printd(c);

	
	return 0;
}
