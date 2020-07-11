#include "header.h"

int global_register;
int label;
int flabel;
int current_addr_bind;
int local_addr_bind;
int param_addr_bind;
int global_field_index;
int global_class_index;
int start;

FILE *target_file;

extern int yylineno;

int identifier_code_gen(ast_node *tnode)
{
	assert(tnode != NULL);

	lst_node *lst_temp = lst_find(tnode->var_name);
	param_node *param_temp = param_find(tnode->var_name);
	gst_node *gst_temp = gst_find(tnode->var_name);

	if (lst_temp != NULL && param_temp != NULL)
	{
		// when local variable and function arguments are the same
		printf("line: %d multiple declarations: local var and function param: %s\n", yylineno, tnode->var_name);
		exit(EXIT_FAILURE);
	}

	int r1 = get_reg();
	if (lst_temp != NULL)
	{
		// fetch the last stackpointer
		_MOV_RBP(r1);
		// add the address offset
		_ADD_N(r1, lst_temp->address_bind);
		// fetch the variable
		_MOVA_RA(r1, r1);
	}
	else if (param_temp != NULL)
	{
		// fetch the last stack pointer
		_MOV_RBP(r1);
		// subtract the offset + 2 IP and return value
		_SUB_N(r1, param_temp->address_bind + 2);
		// fetch the variable
		_MOVA_RA(r1, r1);
	}
	else if (gst_temp != NULL)
	{
		// fetch address directly
		_MOV_RA(r1, gst_temp->address_bind);
	}
	else
	{
		printf("line: %d unknown identifier: %s\n", yylineno, tnode->var_name);
		exit(EXIT_FAILURE);
	}
	return r1;
}

int field_code_gen(ast_node *tnode)
{
	int r1 = get_reg();
	if (tnode->var_name != NULL)
	{
		// for self.id objects
		// fields inside a class
		int offset = 3;
		param_node *param_temp = param_head;
		while (param_temp != NULL)
		{
			offset++;
			param_temp = param_temp->next;
		}
		_MOV_RBP(r1);
		_SUB_N(r1, offset + 1);
		_MOVA_RA(r1, r1);
		// now r1 has the heap address

		class_node *class_temp = class_find(tnode->var_name);
		assert(class_temp != NULL);
		field_node *field_temp = class_temp->class_field_list;

		offset = 0;
		assert(tnode->p1 != NULL);
		while (strcmp(field_temp->field_name, tnode->p1->var_name))
		{
			offset++;
			if (field_temp->field_type == NULL)
				offset++;
			field_temp = field_temp->next;
		}

		// find the field index
		_ADD_N(r1, offset);
		// move it to the register
		_MOVA_RA(r1, r1);

		assert(field_temp != NULL);
		type_node *type_temp = field_temp->field_type;

		ast_node *tree_temp = tnode->p3;
		while (tree_temp != NULL)
		{
			assert(tree_temp->p1 != NULL);
			field_temp = field_find(type_temp, tree_temp->p1->var_name);
			if (field_temp == NULL)
			{
				printf("line: %d unknown variable in field: %s\n", yylineno, tree_temp->p1->var_name);
				exit(EXIT_FAILURE);
			}
			_ADD_N(r1, field_temp->field_index);
			_MOVA_RA(r1, r1);
			type_temp = field_temp->field_type;
			tree_temp = tree_temp->p3;
		}
	}
	else
	{
		assert(tnode->p1 != NULL);
		lst_node *lst_temp = lst_find(tnode->p1->var_name);
		param_node *param_temp = param_find(tnode->p1->var_name);
		gst_node *gst_temp = gst_find(tnode->p1->var_name);
		type_node *type_temp = NULL;

		if (lst_temp != NULL && param_temp != NULL)
		{
			printf("line: %d multiple declaration: %s\n", yylineno, tnode->p1->var_name);
			exit(EXIT_FAILURE);
		}

		if (lst_temp != NULL)
		{
			type_temp = lst_temp->var_type;
			_MOV_RBP(r1);
			_ADD_N(r1, lst_temp->address_bind);
			_MOVA_RA(r1, r1);
		}
		else if (param_temp != NULL)
		{
			type_temp = param_temp->param_type;
			_MOV_RBP(r1);
			_SUB_N(r1, param_temp->address_bind + 2);
			_MOVA_RA(r1, r1);
		}
		else if (gst_temp != NULL)
		{
			type_temp = gst_temp->sym_type;
			_MOV_RA(r1, gst_temp->address_bind);
		}
		else
		{
			printf("line: %d unknown variable: %s\n", yylineno, tnode->p1->var_name);
			exit(EXIT_FAILURE);
		}

		ast_node *tree_temp = tnode;
		while (tree_temp->p3 != NULL)
		{
			assert(tree_temp->p3->p1 != NULL);
			field_node *field_temp = field_find(type_temp, tree_temp->p3->p1->var_name);
			if (field_temp == NULL)
			{
				printf("line: %d unknown variable in field: %s\n", yylineno, tree_temp->p3->p1->var_name);
				exit(EXIT_FAILURE);
			}
			_ADD_N(r1, field_temp->field_index);
			_MOVA_RA(r1, r1);
			type_temp = field_temp->field_type;
			tree_temp = tree_temp->p3;
		}
	}
	return r1;
}

int operation_util(char *operation, ast_node *tnode)
{
	assert(tnode != NULL);
	int r1 = code_gen(tnode->p1);
	int r2 = code_gen(tnode->p3);
	fprintf(target_file, "%s R%d, R%d\n", operation, r1, r2);
	free_reg();
	return r1;
}

int compare_params(param_node *param_temp, ast_node *tree_temp, char *func_name)
{
	int decl_params = 0;
	while (param_temp != NULL)
	{
		decl_params++;
		param_temp = param_temp->next;
	}

	int actual_params = 0;
	while (tree_temp != NULL)
	{
		actual_params++;
		tree_temp = tree_temp->p1;
	}
	if (decl_params != actual_params)
	{
		printf("line: %d incorrect arguments: %s()\n", yylineno, func_name);
		exit(EXIT_FAILURE);
	}

	return actual_params;
}

int function_code_gen(ast_node *tnode)
{
	assert(tnode != NULL);
	gst_node *gst_temp = gst_find(tnode->var_name);
	if (gst_temp == NULL)
	{
		printf("line: %d function undeclared: %s\n", tnode->var_name);
		exit(EXIT_FAILURE);
	}

	param_node *param_temp = gst_temp->sym_param_list;
	ast_node *tree_temp = tnode->p3;

	int params = compare_params(param_temp, tree_temp, tnode->var_name);
	// one extra
	params--;
	param_temp = gst_temp->sym_param_list;
	// check all param types
	while (param_temp != NULL)
	{
		int offset = 0;
		tree_temp = tnode->p3;
		while (offset < params)
		{
			offset++;
			tree_temp = tree_temp->p1;
		}
		assert(tree_temp->p3 != NULL);
		if (param_temp->param_type != tree_temp->p3->var_type)
		{
			printf("line: %d incorrect parameter: %s function: %s()\n", yylineno, param_temp->param_name, tnode->var_name);
			exit(EXIT_FAILURE);
		}
		params--;
		param_temp = param_temp->next;
	}

	// push registers
	int reg_store = -1;
	for (reg_store = -1; reg_store < global_register; reg_store++)
		_PUSH(reg_store + 1);

	global_register = -1;

	// push arguments
	int r1 = code_gen(tnode->p3);
	r1 = get_reg();
	_PUSH(r1);
	_FUNC_LABEL_CALL(gst_temp->sym_func_label);
	_POP(r1);
	free_reg();

	int offset = 0;
	param_temp = gst_temp->sym_param_list;
	r1 = get_reg();
	while (param_temp != NULL)
	{
		_POP(r1);
		param_temp = param_temp->next;
		offset++;
	}
	free_reg();

	global_register = reg_store;
	for (; reg_store >= 0; reg_store--)
	{
		fprintf(target_file, "POP R%d\n", reg_store);
		offset++;
	}

	r1 = get_reg();
	// this is just to fetch the return value into register
	fprintf(target_file, "MOV R%d, SP\n", r1);
	_ADD_N(r1, offset + 1);
	_MOVA_RA(r1, r1);
	return r1;
}

int class_func_one_code_gen(ast_node *tnode)
{
	assert(tnode->p1 != NULL);
	gst_node *gst_temp = gst_find(tnode->p1->var_name);
	if (gst_temp == NULL)
	{
		printf("line: %d object undeclared: %s\n", yylineno, tnode->p1->var_name);
		exit(EXIT_FAILURE);
	}
	class_node *class_temp = gst_temp->sym_class_type;
	class_func_node *class_func_temp = class_temp->class_func_list;
	while (class_func_temp != NULL)
	{
		assert(tnode->p2 != NULL);
		if (strcmp(class_func_temp->class_func_name, tnode->p2->var_name) == 0)
			break;
		class_func_temp = class_func_temp->next;
	}

	param_node *param_temp = class_func_temp->func_param_list;
	ast_node *tree_temp = tnode->p3;

	int params = compare_params(param_temp, tree_temp, tnode->var_name);
	params--;

	param_temp = class_func_temp->func_param_list;;
	while (param_temp != NULL)
	{
		int offset = 0;
		tree_temp = tnode->p3;
		while (offset < params)
		{
			offset++;
			tree_temp = tree_temp->p1;
		}
		assert(tree_temp->p3 != NULL);
		if (param_temp->param_type != tree_temp->p3->var_type)
		{
			printf("line: %d incorrect parameter: %s function: %s()\n", yylineno, param_temp->param_name, tnode->p2->var_name);
			exit(EXIT_FAILURE);
		}
		params--;
		param_temp = param_temp->next;
	}

	int reg_store = -1;
	for (reg_store = -1; reg_store < global_register; reg_store++)
		_PUSH(reg_store + 1);
	global_register = -1;

	int r1 = get_reg();
	// push both the parts of a class object
	_MOV_RA(r1, gst_temp->address_bind);
	_PUSH(r1);
	_MOV_RA(r1, gst_temp->address_bind + 1);
	_PUSH(r1);
	free_reg();

	// push arguments
	r1 = code_gen(tnode->p3);
	r1 = get_reg();

	// push return value
	_PUSH(r1);
	// virtual function table
	_MOV_RA(r1, gst_temp->address_bind + 1);
	_ADD_N(r1, class_func_temp->func_position);
	_MOVA_RA(r1, r1);
	// call the address directly
	// no labels
	fprintf(target_file, "CALL R%d\n", r1);

	// pop the return value
	_POP(r1);
	free_reg();

	int offset = 0;
	param_temp = class_func_temp->func_param_list;
	r1 = get_reg();
	while (param_temp != NULL)
	{
		// pop arguments
		_POP(r1);
		param_temp = param_temp->next;
		offset++;
	}
	free_reg();
	// pop self address
	fprintf(target_file, "SUB SP, 2\n");
	offset += 2;

	global_register = reg_store;
	for (; reg_store >= 0; reg_store--)
	{
		// pop registers
		_POP(reg_store);
		offset++;
	}

	r1 = get_reg();
	fprintf(target_file, "MOV R%d, SP\n", r1);
	_ADD_N(r1, offset + 1);
	_MOVA_RA(r1, r1);
	return r1;
}

int class_func_two_code_gen(ast_node *tnode)
{
	assert(tnode != NULL);
	class_node *class_temp = class_find(tnode->var_name);
	class_func_node *class_func_temp = class_temp->class_func_list;

	int func_offset = 0;
	// find the function
	while (class_func_temp != NULL)
	{
		assert(tnode->p1 != NULL);
		if (strcmp(class_func_temp->class_func_name, tnode->p1->var_name) == 0)
			break;
		class_func_temp = class_func_temp->next;
		func_offset++;
	}

	param_node *param_temp = class_func_temp->func_param_list;
	ast_node *tree_temp = tnode->p3;

	int params = compare_params(param_temp, tree_temp, tnode->var_name);

	// this is the paramlist of the caller function
	/*This is really important*/
	// param_head points to the caller function
	// load the bp and then easily access the self variables
	param_temp = param_head;
	int param_count = 0;
	while (param_temp != NULL)
	{
		param_count++;
		param_temp = param_temp->next;
	}

	params--;
	param_temp = class_func_temp->func_param_list;
	while (param_temp != NULL)
	{
		int offset = 0;
		tree_temp = tnode->p3;
		while (offset < params)
		{
			offset++;
			tree_temp = tree_temp->p1;
		}
		assert(tree_temp->p3 != NULL);
		if (param_temp->param_type != tree_temp->p3->var_type)
		{
			printf("line: %d incorrect parameter: %s function: %s()\n", yylineno, param_temp->param_name, tnode->p2->var_name);
			exit(EXIT_FAILURE);
		}
		params--;
		param_temp = param_temp->next;
	}

	int reg_store = -1;
	// push existing registers
	for (reg_store = -1; reg_store < global_register; reg_store++)
		_PUSH(reg_store + 1);
	global_register = -1;

	int r1 = get_reg();
	int r2 = get_reg();
	_MOV_RBP(r1);
	_SUB_N(r1, param_count + 4);
	_MOVA_RA(r2, r1);
	_PUSH(r2);
	_ADD_N(r1, 1);
	_MOVA_RA(r2, r1);
	_PUSH(r2);
	free_reg();
	free_reg();

	// push arguments
	r1 = code_gen(tnode->p3);
	r1 = get_reg();

	// push return value
	_PUSH(r1);
	// find label from virtual function pointer
	_MOV_RBP(r1);
	_SUB_N(r1, param_count + 3);
	_MOVA_RA(r1, r1);
	_ADD_N(r1, func_offset);
	_MOVA_RA(r1, r1);
	fprintf(target_file, "CALL R%d\n", r1);

	// pop return value
	fprintf(target_file, "POP R%d\n", r1);
	free_reg();

	int offset = 0;
	param_temp = class_func_temp->func_param_list;
	r1 = get_reg();
	while (param_temp != NULL)
	{
		// pop arguments
		_POP(r1);
		param_temp = param_temp->next;
		offset++;
	}
	free_reg();
	// pop self address
	fprintf(target_file, "SUB SP, 2\n");
	offset += 2;

	global_register = reg_store;
	for (; reg_store >= 0; reg_store--)
	{
		// pop registers
		_POP(reg_store);
		offset++;
	}
	r1 = get_reg();
	fprintf(target_file, "MOV R%d, SP\n", r1);
	_ADD_N(r1, offset + 1);
	_MOVA_RA(r1, r1);
	return r1;
}

int class_func_three_code_gen(ast_node *tnode)
{
	assert(tnode != NULL);
	assert(current_class != NULL);
	class_node *class_temp = current_class;
	field_node *field_temp = class_temp->class_field_list;

	int field_pos = 0;
	assert(tnode->p1 != NULL);
	assert(tnode->p1->p1 != NULL);
	while (strcmp(field_temp->field_name, tnode->p1->p1->var_name))
	{
		field_temp = field_temp->next;
		field_pos++;
	}

	class_temp = field_temp->field_class_type;
	class_func_node *class_func_temp = class_temp->class_func_list;

	int func_pos = 0;
	while (class_func_temp != NULL)
	{
		assert(tnode->p2 != NULL);
		if (strcmp(class_func_temp->class_func_name, tnode->p2->var_name) == 0)
			break;
		class_func_temp = class_func_temp->next;
		func_pos++;
	}

	param_node *param_temp = class_func_temp->func_param_list;
	ast_node *tree_temp = tnode->p3;

	int params = compare_params(param_temp, tree_temp, tnode->var_name);

	param_temp = param_head;
	int param_count = 0;
	while (param_temp != NULL)
	{
		param_count++;
		param_temp = param_temp->next;
	}

	params--;
	param_temp = class_func_temp->func_param_list;
	while (param_temp != NULL)
	{
		int offset = 0;
		tree_temp = tnode->p3;
		while (offset < params)
		{
			offset++;
			tree_temp = tree_temp->p1;
		}
		if (param_temp->param_type != tree_temp->p3->var_type)
		{
			printf("line: %d incorrect parameter: %s function: %s()\n", yylineno, param_temp->param_name, tnode->p2->var_name);
			exit(EXIT_FAILURE);
		}
		params--;
		param_temp = param_temp->next;
	}

	int reg_store = -1;
	for (reg_store = -1; reg_store < global_register; reg_store++)
	{
		_PUSH(reg_store + 1);
	}

	global_register = -1;

	int r1 = get_reg();
	int r2 = get_reg();
	_MOV_RBP(r1);
	_SUB_N(r1, param_count + 4);
	_MOVA_RA(r1, r1);
	_ADD_N(r1, field_pos);
	_MOVA_RA(r2, r1);
	_PUSH(r2);
	_ADD_N(r1, 1);
	_MOVA_RA(r2, r1);
	_PUSH(r2);
	free_reg();
	free_reg();

	// push arguments
	r1 = code_gen(tnode->p3);
	r1 = get_reg();

	// push return value
	_PUSH(r1);
	// function table pointer
	_MOV_RBP(r1);
	_SUB_N(r1, param_count + 4);
	_MOVA_RA(r1, r1);
	_ADD_N(r1, field_pos + 1);
	_MOVA_RA(r1, r1);
	_ADD_N(r1, func_pos);
	_MOVA_RA(r1, r1);
	fprintf(target_file, "CALL R%d\n", r1);

	// pop return value
	_POP(r1);
	free_reg();

	int offset = 0;
	param_temp = class_func_temp->func_param_list;
	r1 = get_reg();
	while (param_temp != NULL)
	{
		// pop argumetns
		_POP(r1);
		param_temp = param_temp->next;
		offset++;
	}
	// pop self address
	fprintf(target_file, "SUB SP, 2\n");
	offset += 2;

	free_reg();
	global_register = reg_store;
	for (; reg_store >= 0; reg_store--)
	{
		// pop registers
		_POP(reg_store);
		offset++;
	}

	r1 = get_reg();
	fprintf(target_file, "MOV R%d, SP\n", r1);
	fprintf(target_file, "ADD R%d, %d\n", r1, offset + 1);
	fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);

	return r1;
}

int code_gen(ast_node *tnode)
{
	if (tnode == NULL)
	{
		return -2;
	}

	switch (tnode->node_type)
	{
	case NUM_NODE:
	{
		// integer constants
		assert(tnode != NULL);
		int r1 = get_reg();
		_MOV_RN(r1, tnode->constant.int_val);
		return r1;
	}

	case STR_NODE:
	{
		// string contstants
		assert(tnode != NULL);
		int r1 = get_reg();
		_MOV_RS(r1, tnode->constant.str_val);
		return r1;
	}

	case ID_NODE:
	{
		return identifier_code_gen(tnode);
	}

	case FIELD_NODE:
	{
		return field_code_gen(tnode);
	}

	case FUNC_NODE:
	{
		return function_code_gen(tnode);
	}

	case ARG_NODE:
	{
		// pushing arguments in reverse order
		if (tnode != NULL)
		{
			int r1 = code_gen(tnode->p3);
			free_reg();
			_PUSH(r1);
			r1 = code_gen(tnode->p1);
			free_reg();
		}
		return -1;
	}

	case RET_NODE:
	{
		// this is also done in function call
		int lst_count = 0;
		lst_node *lst_temp = lst_head;
		while (lst_temp != NULL)
		{
			lst_count++;
			lst_temp = lst_temp->next;
		}

		int r1 = code_gen(tnode->p1);
		int r2 = get_reg();
		_MOV_RBP(r2);
		_SUB_N(r2, 2);
		// put return value in return space
		_MOVA_AR(r2, r1);
		free_reg();
		free_reg();
		// pop local variables
		fprintf(target_file, "SUB SP, %d\n", lst_count);
		fprintf(target_file, "MOV BP,[SP]\n");
		// remove the old bp
		_POP(0);
		_RET;
		break;
	}

	case CLASS_FUNC1_NODE:
	{
		return class_func_one_code_gen(tnode);
	}

	case CLASS_FUNC2_NODE:
	{
		return class_func_two_code_gen(tnode);
	}

	case CLASS_FUNC3_NODE:
	{
		return class_func_three_code_gen(tnode);
	}

	case ARRAY_NODE:
	{
		gst_node *gst_temp = gst_find(tnode->var_name);
		if (gst_temp == NULL)
		{
			printf("line: %d unknown variable; %s\n", yylineno, tnode->var_name);
			exit(EXIT_FAILURE);
		}
		int r1 = code_gen(tnode->p2);
		_ADD_N(r1, gst_temp->address_bind);
		_MOVA_RA(r1, r1);
		return r1;
	}

	case MATRIX_NODE:
	{
		gst_node *gst_temp = gst_find(tnode->var_name);
		if (gst_temp == NULL)
		{
			printf("line: %d unknown variable: %s\n", tnode->var_name);
			exit(EXIT_FAILURE);
		}
		int r1 = code_gen(tnode->p2);
		int r2 = code_gen(tnode->p3);
		_MUL_N(r1, gst_temp->col_size);
		_ADD_N(r2, gst_temp->address_bind);
		_ADD(r1, r2);
		_MOVA_RA(r1, r1);
		free_reg();
		return r1;
	}

	case PTR_NODE:
	{
		int r1 = get_reg();
		lst_node *lst_temp = lst_find(tnode->var_name);
		param_node *param_temp = param_find(tnode->var_name);
		gst_node *gst_temp = gst_find(tnode->var_name);

		if (lst_temp != NULL && param_temp != NULL)
		{
			printf("line: %d multiple declarations: %s\n", yylineno, tnode->var_name);
			exit(EXIT_FAILURE);
		}

		if (lst_temp != NULL)
		{
			_MOV_RBP(r1);
			_MOV_RN(r1, lst_temp->address_bind);
			_MOVA_RA(r1, r1);
			_MOVA_RA(r1, r1);
		}
		else if (param_temp != NULL)
		{
			_MOV_RBP(r1);
			_SUB_N(r1, param_temp->address_bind + 2);
			_MOVA_RA(r1, r1);
			_MOVA_RA(r1, r1);
		}
		else if (gst_temp != NULL)
		{
			_MOV_RA(r1, gst_temp->address_bind);
			_MOVA_RA(r1, r1);
		}
		else
		{
			printf("line: %d unknown variable: %s\n", yylineno, tnode->var_name);
			exit(EXIT_FAILURE);
		}
		return r1;
	}

	case ADDR_NODE:
	{
		assert(tnode != NULL);
		lst_node *lst_temp = lst_find(tnode->var_name);
		param_node *param_temp = param_find(tnode->var_name);
		gst_node *gst_temp = gst_find(tnode->var_name);
		if (lst_temp == NULL && param_temp == NULL && gst_temp == NULL)
		{
			printf("line: %d unknown variable: %s\n", yylineno, tnode->var_name);
			exit(EXIT_FAILURE);
		}

		int r1 = code_gen(tnode->p1);
		return r1;
	}

	case INIT_NODE:
	{
		int r1 = get_reg();
		_MOV_RS(r1, "Heapset");
		_PUSH(r1);
		_PUSH(r1);
		_PUSH(r1);
		_PUSH(r1);
		_PUSH(r1);
		_CALL("0");
		_POP(r1);
		_POP(r1);
		_POP(r1);
		_POP(r1);
		_POP(r1);
		_MOV_RN(r1, 0);
		return r1;
		break;
	}

	case ALLOC_NODE:
	{
		int r1 = get_reg();
		int r2 = get_reg();
		_MOV_RS(r2, "Alloc");
		_PUSH(r2);
		_PUSH(r2);
		_PUSH(r2);
		_PUSH(r2);
		_PUSH(r2);
		_CALL("0");
		_POP(r1);
		_POP(r2);
		_POP(r2);
		_POP(r2);
		_POP(r2);
		free_reg();
		return r1;
		break;
	}

	case FREE_NODE:
	{
		int r1 = code_gen(tnode->p1);
		int r2 = get_reg();
		_MOV_RS(r2, "Free");
		_PUSH(r2);
		_PUSH(r1);
		_PUSH(r2);
		_PUSH(r2);
		_PUSH(r2);
		_CALL("0");
		_POP(r2);
		_POP(r2);
		_POP(r2);
		_POP(r2);
		_POP(r2);
		free_reg();
		free_reg();
		return -1;
		break;
	}

	case NULL_NODE:
	{
		int r1 = get_reg();
		_MOV_RN(r1, -1);
		return r1;
	}

	case BRKP_NODE:
	{
		_BRKP;
		return -1;
	}

	case ASSIGN_NODE:
	{
		return assign_code_gen(ASSIGN_NODE, tnode);
	}

	case ASSIGN_FIELD_NODE:
	{
		return assign_code_gen(ASSIGN_FIELD_NODE, tnode);
	}

	case ASSIGN_ARRAY_NODE:
	{
		return assign_code_gen(ASSIGN_ARRAY_NODE, tnode);
	}

	case ASSIGN_MATRIX_NODE:
	{
		return assign_code_gen(ASSIGN_MATRIX_NODE, tnode);
	}

	case ASSIGN_PTR_NODE:
	{
		return assign_code_gen(ASSIGN_PTR_NODE, tnode);
	}

	case PLUS_NODE:
	{
		return operation_util("ADD", tnode);
	}

	case MINUS_NODE:
	{
		return operation_util("SUB", tnode);
	}

	case MUL_NODE:
	{
		return operation_util("MUL", tnode);
	}

	case DIV_NODE:
	{
		return operation_util("DIV", tnode);
	}

	case MOD_NODE:
	{
		return operation_util("MOD", tnode);
	}

	case LT_NODE:
	{
		return operation_util("LT", tnode);
	}

	case GT_NODE:
	{
		return operation_util("GT", tnode);
	}

	case LE_NODE:
	{
		return operation_util("LE", tnode);
	}

	case GE_NODE:
	{
		return operation_util("GE", tnode);
	}

	case EQ_NODE:
	{
		return operation_util("EQ", tnode);
	}

	case NE_NODE:
	{
		return operation_util("NE", tnode);
	}

	case AND_NODE:
	{
		// hack xsm has true set to 1 and false 0
		return operation_util("MUL", tnode);
	}

	case OR_NODE:
	{
		int r1 = code_gen(tnode->p1);
		int r2 = code_gen(tnode->p3);
		// add both ot them
		_ADD(r1, r2);
		// compare with one
		_MOV_RN(r2, 1);
		_GE(r1, r2);
		free_reg();
		return r1;
	}

	case BODY_NODE:
	{
		assert(tnode != NULL);
		int r1 = code_gen(tnode->p1);
		int r2 = code_gen(tnode->p3);
		return -1;
	}

	case BREAK_NODE:
	{
		if (loop_head != NULL)
			_LABEL_JMP(loop_head->_break);
		return -1;
	}

	case CONTINUE_NODE:
	{
		if (loop_head != NULL)
			_LABEL_JMP(loop_head->_continue);
		return -1;
	}

	case READ_NODE:
	{
		return read_code_gen(READ_NODE, tnode);
	}

	case READ_ARRAY_NODE:
	{
		return read_code_gen(READ_ARRAY_NODE, tnode);
	}

	case READ_FIELD_NODE:
	{
		return read_code_gen(READ_FIELD_NODE, tnode);
	}

	case READ_MATRIX_NODE:
	{
		return read_code_gen(READ_MATRIX_NODE, tnode);
	}

	case READ_PTR_NODE:
	{
		return read_code_gen(READ_PTR_NODE, tnode);
	}

	case WRITE_NODE:
	{
		return write_library_call(tnode);
	}

	case IF_NODE:
	{
		int l1 = get_label();
		int r1 = code_gen(tnode->p1);
		// check confition end
		_LABEL_JZ(r1, l1);
		free_reg();
		int r2 = code_gen(tnode->p2);
		// end
		_LABEL_DEC(l1);
		return -1;
	}

	case ELIF_NODE:
	{
		int l1 = get_label();
		int l2 = get_label();
		int r1 = code_gen(tnode->p1);
		// check condition go else
		_LABEL_JZ(r1, l1);
		free_reg();
		int r2 = code_gen(tnode->p2);
		// go end after complete
		_LABEL_JMP(l2);
		// else
		_LABEL_DEC(l1);
		int r3 = code_gen(tnode->p3);
		// end
		_LABEL_DEC(l2);
		return -1;
	}

	case WHILE_NODE:
	{
		int l1 = get_label();
		int l2 = get_label();
		loop_push(l1, l2);
		// start
		_LABEL_DEC(l1);
		int r1 = code_gen(tnode->p1);
		// go end
		_LABEL_JZ(r1, l2);
		free_reg();
		int r2 = code_gen(tnode->p3);
		// go start
		_LABEL_JMP(l1);
		// end
		_LABEL_DEC(l2);
		loop_pop();
		return -1;
	}

	case DOWHILE_NODE:
	{
		int l1 = get_label();
		int l2 = get_label();
		int l3 = get_label();
		loop_push(l3, l2);
		// label start
		_LABEL_DEC(l1);
		int r1 = code_gen(tnode->p3);
		// continue if there is a continue
		// in the loop then make sure the
		// condition is checked before jumping
		_LABEL_DEC(l3);
		int r2 = code_gen(tnode->p1);
		// jump to start if not zero
		_LABEL_JNZ(r2, l1);
		free_reg();
		// label end
		_LABEL_DEC(l2);
		loop_pop();
		return -1;
	}

	case REPEAT_NODE:
	{
		int l1 = get_label();
		int l2 = get_label();
		loop_push(l1, l2);
		// label start
		_LABEL_DEC(l1);
		int r1 = code_gen(tnode->p3);
		int r2 = code_gen(tnode->p1);
		// jump back to start if equality
		_LABEL_JZ(r2, l1);
		free_reg();
		// label end
		_LABEL_DEC(l2);
		loop_pop();
		return -1;
	}
	}
}

int assign_code_gen(_node_type node_type, ast_node *tnode)
{
	assert(tnode != NULL);
	if (node_type == ASSIGN_NODE)
	{

		assert(tnode->p1 != NULL);
		int r1 = code_gen(tnode->p3);
		int r2 = get_reg();

		lst_node *lst_temp = lst_find(tnode->p1->var_name);
		param_node *param_temp = param_find(tnode->p1->var_name);
		gst_node *gst_temp = gst_find(tnode->p1->var_name);

		if (lst_temp == NULL && param_temp == NULL && gst_temp == NULL)
		{
			printf("line: %d unknown variable: %s\n", yylineno, tnode->p1->var_name);
			exit(EXIT_FAILURE);
		}

		if (lst_temp != NULL)
		{
			// fetch the address
			_MOV_RBP(r2);
			// add the offset
			_ADD_N(r2, lst_temp->address_bind);
			// move the variable data to address
			_MOVA_AR(r2, r1);
		}
		else if (param_temp != NULL)
		{
			_MOV_RBP(r2);
			_SUB_N(r2, param_temp->address_bind + 2);
			_MOVA_AR(r2, r1);
		}
		else if (gst_temp != NULL)
		{
			_MOV_AR(gst_temp->address_bind, r1);
		}

		if (tnode->p2 == NULL)
			assert(tnode->p3 != NULL);

		if (tnode->p2 != NULL)
		{
			// id = new(class);
			class_node *class_temp = class_find(tnode->p2->var_name);
			if (class_temp == NULL)
			{
				printf("line: %d unknown class: %s\n", yylineno, tnode->p2->var_name);
				exit(EXIT_FAILURE);
			}
			class_node *parent_temp = class_temp;
			assert(gst_temp != NULL);
			assert(gst_temp->sym_class_type != NULL);
			while (parent_temp != NULL)
			{
				if (strcmp(gst_temp->sym_class_type->class_name, parent_temp->class_name) == 0)
					break;
				parent_temp = parent_temp->parent_class;
			}
			if (parent_temp == NULL)
			{
				printf("line: %d class not in it's descendents: %s\n", yylineno, tnode->p2->var_name);
				exit(EXIT_FAILURE);
			}
			fprintf(target_file, "MOV [%d], %d\n", gst_temp->address_bind + 1, 4096 + 8 * class_temp->class_index);
		}
		else if (tnode->p3->var_type == NULL)
		{
			// object of a class
			gst_temp = gst_find(tnode->p3->var_name);
			// class object has two spaces
			_MOV_RA(r1, gst_temp->address_bind + 1);
			gst_temp = gst_find(tnode->p1->var_name);
			_MOV_AR(gst_temp->address_bind + 1, r1);
		}

		free_reg();
		free_reg();
		return -1;
	}
	else if (node_type == ASSIGN_PTR_NODE)
	{
		assert(tnode->p1 != NULL);
		int r1 = code_gen(tnode->p1);
		int r2 = code_gen(tnode->p3);

		lst_node *lst_temp = lst_find(tnode->p1->var_name);
		param_node *param_temp = param_find(tnode->p1->var_name);
		gst_node *gst_temp = gst_find(tnode->p1->var_name);

		if (lst_temp == NULL && param_temp == NULL && gst_temp == NULL)
		{
			printf("line: %d unknown variable; %s\n", tnode->p1->var_name);
			exit(EXIT_FAILURE);
		}

		// get the address
		_MOVA_RA(r1, r1);
		// move the data
		_MOVA_AR(r1, r2);

		free_reg();
		free_reg();
		return -1;
	}
	else if (node_type == ASSIGN_FIELD_NODE)
	{
		assert(tnode->p1 != NULL);
		int r1 = code_gen(tnode->p3);
		int r2 = get_reg();

		if (tnode->p1->var_name != NULL)
		{
			int offset = 3;
			param_node *param_temp = param_head;
			while (param_temp != NULL)
			{
				offset++;
				param_temp = param_temp->next;
			}
			_MOV_RBP(r2);
			_SUB_N(r2, offset + 1);
			_MOVA_RA(r2, r2);

			class_node *class_temp = class_find(tnode->p1->var_name);
			assert(class_temp != NULL);
			field_node *field_temp = class_temp->class_field_list;
			offset = 0;
			assert(tnode->p1->p1 != NULL);
			while (strcmp(field_temp->field_name, tnode->p1->p1->var_name))
			{
				offset++;
				if (field_temp->field_type == NULL)
					offset++;
				field_temp = field_temp->next;
			}
			_ADD_N(r2, offset);
			assert(field_temp != NULL);
			type_node *type_temp = field_temp->field_type;
			if (tnode->p1->p3 != NULL)
			{
				_MOVA_RA(r2, r2);
				ast_node *tree_temp = tnode->p1->p3;
				while (tree_temp->p3 != NULL)
				{
					field_temp = field_find(type_temp, tree_temp->p1->var_name);
					if (field_temp == NULL)
					{
						printf("line: %d unknown variable in field: %s\n", yylineno, tree_temp->p1->var_name);
						exit(EXIT_FAILURE);
					}
					_ADD_N(r2, field_temp->field_index);
					_MOVA_RA(r2, r2);
					type_temp = field_temp->field_type;
					tree_temp = tree_temp->p3;
				}

				assert(tree_temp->p1 != NULL);
				field_temp = field_find(type_temp, tree_temp->p1->var_name);
				if (field_temp == NULL)
				{
					printf("line: %d unknown variable in field: %s\n", yylineno, tree_temp->p1->var_name);
					exit(EXIT_FAILURE);
				}
				_ADD_N(r2, field_temp->field_index);
			}

			_MOVA_AR(r2, r1);
			if (tnode->p2 != NULL)
			{
				class_temp = class_find(tnode->p2->var_name);
				if (class_temp == NULL)
				{
					printf("line: %d unknown class: %s\n", yylineno, tnode->p2->var_name);
					exit(EXIT_FAILURE);
				}
				class_node *parent_temp = class_temp;
				while (parent_temp != NULL)
				{
					if (strcmp(field_temp->field_class_type->class_name, parent_temp->class_name) == 0)
						break;
					parent_temp = parent_temp->parent_class;
				}
				if (parent_temp == NULL)
				{
					printf("line: %d class not in it's descendents: %s\n", yylineno, tnode->p2->var_name);
					exit(EXIT_FAILURE);
				}
				_INR_R(r2);
				fprintf(target_file, "MOV [R%d], %d\n", r2, 4096 + 8 * class_temp->class_index);
			}
		}
		else
		{
			lst_node *lst_temp = lst_find(tnode->p1->p1->var_name);
			param_node *param_temp = param_find(tnode->p1->p1->var_name);
			gst_node *gst_temp = gst_find(tnode->p1->p1->var_name);
			type_node *type_temp = NULL;

			if (lst_temp == NULL && param_temp == NULL && gst_temp == NULL)
			{
				printf("line: %d unknown variable: %s\n", yylineno, tnode->p1->p1->var_name);
				exit(EXIT_FAILURE);
			}

			if (lst_temp != NULL)
			{
				type_temp = lst_temp->var_type;
				_MOV_RBP(r2);
				_ADD_N(r2, lst_temp->address_bind);
				_MOVA_RA(r2, r2);
			}
			else if (param_temp != NULL)
			{
				type_temp = param_temp->param_type;
				_MOV_RBP(r2);
				_SUB_N(r2, param_temp->address_bind + 2);
				_MOVA_RA(r2, r2);
			}
			else if (gst_temp != NULL)
			{
				type_temp = gst_temp->sym_type;
				_MOV_RA(r2, gst_temp->address_bind);
			}

			ast_node *tree_temp = tnode->p1;
			assert(tree_temp->p3 != NULL);
			while (tree_temp->p3->p3 != NULL)
			{
				assert(tree_temp->p3->p1 != NULL);
				field_node *field_temp = field_find(type_temp, tree_temp->p3->p1->var_name);
				if (field_temp == NULL)
				{
					printf("line: %d unknown variable in field: %s\n", yylineno, tree_temp->p3->p1->var_name);
					exit(EXIT_FAILURE);
				}
				_ADD_N(r2, field_temp->field_index);
				_MOVA_RA(r2, r2);

				type_temp = field_temp->field_type;
				tree_temp = tree_temp->p3;
				assert(tree_temp->p3 != NULL);
			}

			assert(tree_temp->p3 != NULL);
			assert(tree_temp->p3->p1 != NULL);
			field_node *field_temp = field_find(type_temp, tree_temp->p3->p1->var_name);
			if (field_temp == NULL)
			{
				printf("line: %d unknown variable in field: %s\n", yylineno, tree_temp->p3->p1->var_name);
				exit(EXIT_FAILURE);
			}
			_ADD_N(r2, field_temp->field_index);
			_MOVA_AR(r2, r1);
		}
		free_reg();
		free_reg();
		return -1;
	}
	else if (node_type == ASSIGN_ARRAY_NODE)
	{
		assert(tnode->p1 != NULL);
		int r1 = code_gen(tnode->p2);
		int r2 = code_gen(tnode->p3);
		gst_node *gst_temp = gst_find(tnode->p1->var_name);
		if (gst_temp == NULL)
		{
			printf("line: %d unknown variable: %s\n", yylineno, tnode->p1->var_name);
			exit(EXIT_FAILURE);
		}
		int r3 = gst_temp->address_bind;
		_ADD_N(r1, r3);
		_MOVA_AR(r1, r2);
		free_reg();
		free_reg();
		return -1;
	}
	else if (node_type == ASSIGN_MATRIX_NODE)
	{
		assert(tnode->p1 != NULL);
		assert(tnode->p2 != NULL);
		int r1 = code_gen(tnode->p2->p1);
		int r2 = code_gen(tnode->p2->p2);
		int r3 = code_gen(tnode->p3);

		gst_node *gst_temp = gst_find(tnode->p1->var_name);
		if (gst_temp == NULL)
		{
			printf("line: %d unknown variable: %s\n", yylineno, tnode->p1->var_name);
			exit(EXIT_FAILURE);
		}

		_MUL_N(r1, gst_temp->col_size);
		_ADD_N(r2, gst_temp->address_bind);
		_ADD(r1, r2);
		_MOVA_AR(r1, r3);
		free_reg();
		free_reg();
		free_reg();
		return -1;
	}
}

int read_code_gen(_node_type node_type, ast_node *tnode)
{
	assert(tnode != NULL);
	if (node_type == READ_NODE)
	{
		assert(tnode->p1 != NULL);
		lst_node *lst_temp = lst_find(tnode->p1->var_name);
		param_node *param_temp = param_find(tnode->p1->var_name);
		gst_node *gst_temp = gst_find(tnode->p1->var_name);

		if (lst_temp == NULL && param_temp == NULL && gst_temp == NULL)
		{
			printf("line: %d unknown variable: %s\n", yylineno, tnode->p1->var_name);
			exit(EXIT_FAILURE);
		}

		int r1 = get_reg();
		if (lst_temp != NULL)
		{
			// fetch previous stack pointer
			_MOV_RBP(r1);
			// get address
			_ADD_N(r1, lst_temp->address_bind);
		}
		else if (param_temp != NULL)
		{
			_MOV_RBP(r1);
			_SUB_N(r1, param_temp->address_bind + 2);
		}
		else if (gst_temp != NULL)
		{
			_MOV_RN(r1, gst_temp->address_bind);
		}

		int r2 = get_reg();
		read_library_call(r2, r1);
		free_reg();
		free_reg();
		return -1;
	}
	else if (node_type == READ_FIELD_NODE)
	{
		assert(tnode->p1 != NULL);
		int r1 = get_reg();
		if (tnode->p1->var_name != NULL)
		{
			int offset = 3;
			param_node *param_temp = param_head;
			while (param_temp != NULL)
			{
				offset++;
				param_temp = param_temp->next;
			}
			_MOV_RBP(r1);
			// class variable need two spaces
			_SUB_N(r1, offset + 1);
			_MOVA_RA(r1, r1);

			class_node *class_temp = class_find(tnode->p1->var_name);
			assert(class_temp != NULL);
			field_node *field_temp = class_temp->class_field_list;

			offset = 0;
			assert(tnode->p1->p1 != NULL);
			while (strcmp(field_temp->field_name, tnode->p1->p1->var_name))
			{
				offset++;
				// class object take 2 spaces
				if (field_temp->field_type == NULL)
					offset++;
				field_temp = field_temp->next;
			}

			_ADD_N(r1, offset);

			assert(field_temp != NULL);
			type_node *type_temp = field_temp->field_type;
			if (tnode->p1->p3 != NULL)
			{
				_MOVA_RA(r1, r1);
				ast_node *tree_temp = tnode->p1->p3;
				while (tree_temp->p3 != NULL)
				{
					field_temp = field_find(type_temp, tree_temp->p1->var_name);
					if (field_temp == NULL)
					{
						printf("line: %d unknown variable in field: %s\n", yylineno, tree_temp->p1->var_name);
						exit(EXIT_FAILURE);
					}
					// get the field index
					_ADD_N(r1, field_temp->field_index);
					// move the variable
					_MOVA_RA(r1, r1);
					type_temp = field_temp->field_type;
					tree_temp = tree_temp->p3;
				}

				field_temp = field_find(type_temp, tree_temp->p1->var_name);
				if (field_temp == NULL)
				{
					printf("line: %d unknown variable in field: %s\n", yylineno, tree_temp->p1->var_name);
					exit(EXIT_FAILURE);
				}
				_ADD_N(r1, field_temp->field_index);
			}
		}
		else
		{
			assert(tnode->p1->p1 != NULL);
			lst_node *lst_temp = lst_find(tnode->p1->p1->var_name);
			param_node *param_temp = param_find(tnode->p1->p1->var_name);
			gst_node *gst_temp = gst_find(tnode->p1->p1->var_name);
			type_node *type_temp = NULL;

			if (lst_temp == NULL && param_temp == NULL && gst_temp == NULL)
			{
				printf("line: %d unknown variable: %s\n", tnode->p1->p1->var_name);
				exit(EXIT_FAILURE);
			}

			if (lst_temp != NULL)
			{
				type_temp = lst_temp->var_type;
				// same as field type
				_MOV_RBP(r1);
				_ADD_N(r1, lst_temp->address_bind);
				_MOVA_RA(r1, r1);
			}
			else if (param_temp != NULL)
			{
				type_temp = param_temp->param_type;
				_MOV_RBP(r1);
				_SUB_N(r1, param_temp->address_bind + 2);
				_MOVA_RA(r1, r1);
			}
			else if (gst_temp != NULL)
			{
				type_temp = gst_temp->sym_type;
				_MOV_RA(r1, gst_temp->address_bind);
			}

			// got till the end of the field object
			ast_node *tree_temp = tnode->p1;
			assert(tree_temp->p3 != NULL);
			while (tree_temp->p3->p3 != NULL)
			{
				assert(type_temp != NULL);
				assert(tree_temp->p3->p1 != NULL);
				field_node *field_temp = field_find(type_temp, tree_temp->p3->p1->var_name);
				if (field_temp == NULL)
				{
					printf("line: %d unknown variable in field: %s\n", yylineno, tree_temp->p3->p1->var_name);
					exit(EXIT_FAILURE);
				}
				// get the index and get the variable
				_ADD_N(r1, field_temp->field_index);
				_MOVA_RA(r1, r1);

				// go to the next field
				type_temp = field_temp->field_type;
				tree_temp = tree_temp->p3;
				assert(tree_temp->p3 != NULL);
			}

			assert(tree_temp->p3 != NULL);
			assert(tree_temp->p3->p1 != NULL);
			field_node *field_temp = field_find(type_temp, tree_temp->p3->p1->var_name);

			if (field_temp == NULL)
			{
				printf("line: %d unknown variable in field: %s\n", yylineno, tree_temp->p3->p1->var_name);
				exit(EXIT_FAILURE);
			}
			_ADD_N(r1, field_temp->field_index);
		}

		int r2 = get_reg();
		read_library_call(r2, r1);
		free_reg();
		free_reg();
		return -1;
	}
	else if (node_type == READ_ARRAY_NODE)
	{
		assert(tnode->p1 != NULL);
		gst_node *gst_temp = gst_find(tnode->p1->var_name);
		if (gst_temp == NULL)
		{
			printf("line: %d unknown variable: %s\n", yylineno, tnode->p1->var_name);
			exit(EXIT_FAILURE);
		}
		int r1 = get_reg();
		int r2 = code_gen(tnode->p2);
		// add offset from address
		_ADD_N(r2, gst_temp->address_bind);
		read_library_call(r1, r2);
		free_reg();
		free_reg();
		return -1;
	}
	else if (node_type == READ_MATRIX_NODE)
	{
		assert(tnode->p1 != NULL);
		gst_node *gst_temp = gst_find(tnode->p1->var_name);
		if (gst_temp == NULL)
		{
			printf("line: %d unknwon varaible: %s\n", yylineno, tnode->p1->var_name);
			exit(EXIT_FAILURE);
		}
		int r1 = get_reg();
		// row
		int r2 = code_gen(tnode->p2);
		// column
		int r3 = code_gen(tnode->p3);

		// fetch the offset
		_MUL_N(r2, gst_temp->col_size);
		// calculate the relative index
		_ADD(r2, r3);
		// from start add the index
		_ADD_N(r2, gst_temp->address_bind);
		read_library_call(r1, r2);
		free_reg();
		free_reg();
		free_reg();
		return -1;
	}
	else if (node_type == READ_PTR_NODE)
	{
		assert(tnode->p1 != NULL);
		lst_node *lst_temp = lst_find(tnode->p1->var_name);
		param_node *param_temp = param_find(tnode->p1->var_name);
		gst_node *gst_temp = gst_find(tnode->p1->var_name);

		if (lst_temp == NULL && param_temp == NULL && gst_temp == NULL)
		{
			printf("line: %d unknwon varaible: %s\n", yylineno, tnode->p1->var_name);
			exit(EXIT_FAILURE);
		}

		// fetch the pointer in the read function
		int r1 = code_gen(tnode->p1);
		_MOV_RA(r1, r1);
		int r2 = get_reg();
		read_library_call(r2, r1);
		free_reg();
		free_reg();
		return -1;
	}
}

void read_library_call(int r1, int r2)
{
	_MOV_RS(r1, "Read");
	_PUSH(r1);
	_MOV_RN(r1, -1);
	_PUSH(r1);
	_MOV_RR(r1, r2);
	_PUSH(r1);
	_PUSH(r1);
	_PUSH(r1);
	_CALL("0");
	_POP(r1);
	_POP(r1);
	_POP(r1);
	_POP(r1);
	_POP(r1);
}

int write_library_call(ast_node *tnode)
{
	assert(tnode != NULL);
	int r1 = code_gen(tnode->p1);
	int r2 = get_reg();
	_MOV_RS(r2, "Write");
	_PUSH(r2);
	_MOV_RN(r2, -2);
	_PUSH(r2);
	_PUSH(r1);
	_PUSH(r2);
	_PUSH(r2);
	_CALL("0");
	_POP(r2);
	_POP(r2);
	_POP(r2);
	_POP(r2);
	_POP(r2);
	free_reg();
	free_reg();
	return -1;
}

int get_reg()
{
	if (global_register >= 20)
	{
		printf("Out of registers\n");
		exit(1);
	}
	return ++global_register;
}

void free_reg()
{
	if (global_register >= 0)
		global_register--;
}

int get_label()
{
	return label++;
}

int get_func_label()
{
	return flabel++;
}