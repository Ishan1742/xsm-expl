#ifndef _CLASS_TABLE_H_
#define _CLASS_TABLE_H_

typedef struct class_node
{
	char *class_name;
	struct field_node *class_field_list;
	struct class_func_node *class_func_list;
	struct class_node *parent_class;
	int class_index;
	int class_field_count;
	int class_func_count;
	struct class_node *next;
} class_node;

typedef struct class_func_node
{
	char *class_func_name;
	struct type_node *func_return_type;
	struct param_node *func_param_list;
	int func_position;
	int func_label;
	struct class_func_node *next;
} class_func_node;

extern class_node *class_head, *class_tail;
extern class_node *current_class;

void class_insert(char *class_name, char *parent_class_name);
class_node *class_find(char *class_name);
void class_field_insert(class_node *class, char *field_type_name, char *field_name);
field_node *class_field_find(class_node *class, char *field_name);
void class_func_insert(class_node *class, char *func_name, type_node *func_return_type, param_node *param_list);
class_func_node *class_func_find(class_node *class, char *func_name);

// parser_helper functions
void create_virtual_function_table();
void print_class_table();
void print_class_fields(class_node *class);
void print_class_functions(class_node *class);
void check_class_constraints();
class_node *create_class(ast_node *class, ast_node *parent_class);
void class_field_helper(ast_node *class_field, type_node *field_type, class_node *field_class_type);
void class_func_helper(ast_node *class_func, type_node *var_type, class_node *class_type);

#endif