#ifndef _LOOP_STACK_H_
#define _LOOP_STACK_H_

typedef struct loop_node
{
	int _break;
	int _continue;
	struct loop_node *next;
} loop_node;

extern loop_node *loop_head;

void loop_push(int _continue, int _break);
void loop_pop();

#endif