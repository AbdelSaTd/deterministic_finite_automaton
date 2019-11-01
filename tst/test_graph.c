#include <stdio.h>
#include <stdlib.h>
#include "../src/graph.h"

int main()
{
    Graph* g = create_graph(3);
    add_arc(g, 0, 'a', 0);
    add_arc(g, 0, 'b', 1);
    add_arc(g, 0, 'c', 2);
    add_arc(g, 0, 'd', 3);

    add_arc(g, 1, 'c', 2);
    print_Graph(g);
    printf("Value %d; Waiting 1\n", arc_exist(g, 0, 'a', 1));
    printf("Value %d; Waiting 0\n", arc_exist(g, 0, 'b', 1));
    printf("Value %d; Waiting 0\n", arc_exist(g, 1, 'a', 1));
    printf("Value %d; Waiting 1\n", arc_exist(g, 1, 'c', 2));
    
    printf("Revomve *** \n\n");
    rmv_arc(g, 0, 'd', 3);
    print_Graph(g);
    
    printf("Revomve *** \n\n");
    rmv_arc(g, 0, 'b', 1);
    print_Graph(g);
    
    printf("Revomve *** \n\n");
    rmv_arc(g, 0, 'a', 0);
    print_Graph(g);

    printf("Value %d; Waiting 2\n", transit(g, 0, 'c'));
    printf("Value %d; Waiting 2\n", transit(g, 1, 'c'));
    free_graph(g);
}
