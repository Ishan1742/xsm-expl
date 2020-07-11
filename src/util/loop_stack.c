#include "header.h"

loop_node *loop_head;

extern int yylineno;

void loop_push(int _continue, int _break)
{
    loop_node *new_node = (loop_node *)malloc(sizeof(loop_node));
    new_node->_break = _break;
    new_node->_continue = _continue;

    // insert at beginning
    new_node->next = loop_head;
    loop_head = new_node;
}

void loop_pop()
{
    if (loop_head == NULL)
    {
        printf("line: %d empty loop pop\n", yylineno);
        return;
    }
    loop_node *loop_temp = loop_head;
    loop_head = loop_head->next;
    free(loop_temp);
}