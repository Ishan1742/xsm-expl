#include "header.h"

extern int yylineno;

ast_node *create_ast_node(type_node *var_type, char *var_name, _node_type node_type, ast_node *p1, ast_node *p2, ast_node *p3)
{
	/**
	 * create the abstract syntax tree node
	*/
	ast_node *new_node = (ast_node *)malloc(sizeof(ast_node));

	new_node->var_name = var_name;
	new_node->var_type = var_type;
	new_node->node_type = node_type;

	if (node_type == ID_NODE)
	{
		lst_node *lst_temp = lst_find(new_node->var_name);
		param_node *param_temp = param_find(new_node->var_name);
		gst_node *gst_temp = gst_find(new_node->var_name);

		if (lst_temp != NULL)
			new_node->var_type = lst_temp->var_type;
		else if (param_temp != NULL)
			new_node->var_type = param_temp->param_type;
		else if (gst_temp != NULL)
			new_node->var_type = gst_temp->sym_type;

		// TODO remove these
		new_node->lst_entry = lst_temp;
		new_node->gst_entry = gst_temp;
	}

	new_node->p1 = p1;
	new_node->p2 = p2;
	new_node->p3 = p3;

	ast_type_checker(new_node);
	var_type_checker(new_node);

	return new_node;
}

void ast_type_checker(ast_node *tnode)
{
	/**
	 * tree node type checker
	*/
	assert(tnode != NULL);
	switch (tnode->node_type)
	{

	case PLUS_NODE:
	case MINUS_NODE:
	case MUL_NODE:
	case DIV_NODE:
	case MOD_NODE:
	{
		assert(tnode->p1 != NULL);
		assert(tnode->p3 != NULL);
		type_node *int_type = type_find("integer");
		if (tnode->p1->var_type != int_type || tnode->p3->var_type != int_type)
		{
			if (tnode->p1->var_type == NULL || tnode->p3->var_type == NULL)
			{
				printf("line: %d type mismatch: operands should be integers\n", yylineno);
				exit(EXIT_FAILURE);
			}
			printf("line: %d type mismatch: operands should be integers found: %s and %s\n",
				   yylineno, tnode->p1->var_type->type_name, tnode->p3->var_type->type_name);
			exit(EXIT_FAILURE);
		}
		break;
	}
	case EQ_NODE:
	case NE_NODE:
	case LT_NODE:
	case GT_NODE:
	case LE_NODE:
	case GE_NODE:
	{
		assert(tnode->p3 != NULL);
		assert(tnode->p1 != NULL);
		type_node *int_type = type_find("integer");
		type_node *type_type = type_find("type");
		type_node *str_type = type_find("string");
		if ((tnode->p3->var_type == type_type) && (tnode->p1->var_type == int_type || tnode->p1->var_type == str_type))
		{
			printf("line: %d type mismatch: relational operator\n", yylineno);
			exit(EXIT_FAILURE);
		}
		if ((tnode->p3->var_type != type_type) && (tnode->p1->var_type != int_type || tnode->p3->var_type != int_type))
		{
			yyerror("yylineno %d type mismatch: relational operator integers expected\n");
			exit(EXIT_FAILURE);
		}
		break;
	}

	case AND_NODE:
	case OR_NODE:
	case NOT_NODE:
	{
		assert(tnode->p3 != NULL);
		assert(tnode->p1 != NULL);
		type_node *bool_type = type_find("boolean");
		if (tnode->p1->var_type != bool_type || tnode->p3->var_type != bool_type)
		{
			printf("line: %d type mismatch: logical operator expected boolean\n", yylineno);
			exit(EXIT_FAILURE);
		}
		break;
	}

	case ARRAY_NODE:
	{
		assert(tnode->p2 != NULL);
		type_node *int_type = type_find("integer");
		if (tnode->p2->var_type != int_type)
		{
			printf("line: %d type mismatch: array index expected integer\n", yylineno);
			exit(EXIT_FAILURE);
		}
		break;
	}

	case MATRIX_NODE:
	{
		assert(tnode->p2 != NULL);
		assert(tnode->p3 != NULL);
		type_node *int_type = type_find("integer");
		if (tnode->p2->var_type != int_type || tnode->p3->var_type != int_type)
		{
			printf("line: %d type mismatch: matrix index expected integer\n");
			exit(EXIT_FAILURE);
		}
		break;
	}

	case ELIF_NODE:
	case IF_NODE:
	case WHILE_NODE:
	case DOWHILE_NODE:
	case REPEAT_NODE:
	{
		assert(tnode->p1 != NULL);
		type_node *bool_type = type_find("boolean");
		if (tnode->p1->var_type != bool_type)
		{
			printf("line: %d type mismatch: conditional expected boolean\n");
			exit(EXIT_FAILURE);
		}
		break;
	}

	case ASSIGN_NODE:
	{
		assert(tnode->p3 != NULL);
		assert(tnode->p1 != NULL);
		type_node *int_type = type_find("integer");
		// "type" is for NULL and alloc() delete() function calls
		type_node *type_type = type_find("type");
		type_node *str_type = type_find("string");
		if ((tnode->p3->var_type == type_type) && ((tnode->p1->var_type == int_type) || (tnode->p1->var_type == str_type)))
		{
			printf("line: %d type mismatch: assignment user defined type\n", yylineno);
			exit(EXIT_FAILURE);
		}
		else if (tnode->p3->var_type != type_type && tnode->p1->var_type != tnode->p3->var_type)
		{
			printf("line: %d type mismatch: assignement incorrect types\n", yylineno);
			exit(EXIT_FAILURE);
		}
		break;
	}

	case ASSIGN_ARRAY_NODE:
	{
		assert(tnode->p1 != NULL);
		assert(tnode->p2 != NULL);
		assert(tnode->p3 != NULL);
		type_node *int_type = type_find("integer");
		if (tnode->p1->var_type != tnode->p3->var_type)
		{
			printf("line: %d type mismatch: array assignment integers expected\n", yylineno);
			exit(EXIT_FAILURE);
		}
		if (tnode->p2->var_type != int_type)
		{
			printf("line: %d type mismatch: array index integer expected\n", yylineno);
			exit(EXIT_FAILURE);
		}
		break;
	}

	case ASSIGN_MATRIX_NODE:
	{
		assert(tnode->p1 != NULL);
		assert(tnode->p3 != NULL);
		assert(tnode->p2->p1 != NULL);
		assert(tnode->p2->p2 != NULL);
		type_node *int_type = type_find("integer");
		if (tnode->p1->var_type != tnode->p3->var_type)
		{
			printf("line: %d type mismatch: matrix assignment operands: integer expected\n", yylineno);
			exit(EXIT_FAILURE);
		}
		if (tnode->p2->p1->var_type != int_type || tnode->p2->p2->var_type != int_type)
		{
			printf("line: %d type mismatch: matrix index integer expected\n", yylineno);
			exit(EXIT_FAILURE);
		}
		break;
	}

	case ASSIGN_PTR_NODE:
	{
		assert(tnode->p1 != NULL);
		assert(tnode->p3 != NULL);
		if (tnode->p1->var_type != tnode->p3->var_type)
		{
			printf("line %d type mismatch: pointer assignment integers expected\n", yylineno);
			exit(EXIT_FAILURE);
		}
		break;
	}

	case READ_ARRAY_NODE:
	{
		assert(tnode->p2 != NULL);
		type_node *int_type = type_find("integer");
		if (tnode->p2->var_type != int_type)
		{
			printf("line: %d type mismatch: array index integer expected\n", yylineno);
			exit(EXIT_FAILURE);
		}
		break;
	}

	case READ_MATRIX_NODE:
	{
		assert(tnode->p2 != NULL);
		assert(tnode->p3 != NULL);
		type_node *int_type = type_find("integer");
		if (tnode->p2->var_type != int_type || tnode->p3->var_type != int_type)
		{
			printf("line; %d type mismatch: matrix index integer expected\n", yylineno);
			exit(EXIT_FAILURE);
		}
		break;
	}
	}
}

void var_type_checker(ast_node *tnode)
{
	/**
	 * variable type checker
	*/
	assert(tnode != NULL);
	switch (tnode->node_type)
	{
	case ASSIGN_NODE:
	case READ_NODE:
	{
		assert(tnode->p1 != NULL);
		lst_node *lst_entry = lst_find(tnode->p1->var_name);
		gst_node *gst_entry = gst_find(tnode->p1->var_name);

		if (lst_entry != NULL)
		{
			if (lst_entry->node_type != ID_NODE && lst_entry->node_type != PTR_NODE)
			{
				printf("line: %d incorrect var type: variable or pointer expected\n", yylineno);
				exit(EXIT_FAILURE);
			}
		}
		else if (gst_entry != NULL)
		{
			if (gst_entry->node_type != ID_NODE && gst_entry->node_type != PTR_NODE)
			{
				printf("line: %d incorrect var type: variable or pointer expected\n", yylineno);
				exit(EXIT_FAILURE);
			}
		}
		break;
	}
	case ASSIGN_ARRAY_NODE:
	case READ_ARRAY_NODE:
	{
		assert(tnode->p1 != NULL);
		gst_node *gst_entry = gst_find(tnode->p1->var_name);
		if (gst_entry->node_type != ARRAY_NODE)
		{
			printf("line: %d incorrect var type: array expected\n", yylineno);
			exit(EXIT_FAILURE);
		}
		break;
	}
	case ASSIGN_MATRIX_NODE:
	case READ_MATRIX_NODE:
	{
		assert(tnode->p1 != NULL);
		gst_node *gst_entry = gst_find(tnode->p1->var_name);
		if (gst_entry->node_type != MATRIX_NODE)
		{
			printf("line: %d incorrect var type: matrix expected\n", yylineno);
			exit(EXIT_FAILURE);
		}
		break;
	}
	case ASSIGN_PTR_NODE:
	case READ_PTR_NODE:
	{
		assert(tnode->p1 != NULL);
		lst_node *lst_entry = lst_find(tnode->p1->var_name);
		gst_node *gst_entry = gst_find(tnode->p1->var_name);

		if (lst_entry != NULL)
		{
			if (lst_entry->node_type != PTR_NODE)
			{
				printf("line: %d incorrect var type: pointer expected\n", yylineno);
				exit(EXIT_FAILURE);
			}
		}
		else if (gst_entry != NULL)
		{
			if (gst_entry->node_type != PTR_NODE)
			{
				printf("line: %d incorrect var type: pointer excpected\n", yylineno);
				exit(EXIT_FAILURE);
			}
		}

		break;
	}
	}
}