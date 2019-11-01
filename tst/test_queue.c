#include <stdio.h>
#include <stdlib.h>
#include "../src/queue.h"

int main()
{
    Queue* q=NULL;
    init_queue(&q);

    add_elt(&q, 10, "Hello\0");
    disp_q(q);
    del_elt(&q);
    disp_q(q);

    add_elt(&q, 9, "ello");
    add_elt(&q, 8, "llo");
    add_elt(&q, 7, "lo");
    add_elt(&q, 6, "o");
    add_elt(&q, 5, "");
    disp_q(q);
    del_elt(&q);

    disp_q(q);

}
