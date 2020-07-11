#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include "header.h"

typedef struct gst_node
{
    char *sym_name;
    struct type_node *sym_type;
    struct class_node *sym_class_type;
    int row_size, col_size;
    int address_bind;
    _node_type node_type;
    struct param_node *sym_param_list;
    int sym_func_label;
    struct gst_node *next;
} gst_node;

typedef struct param_node
{
    char *param_name;
    struct type_node *param_type;
    int address_bind;
    _node_type node_type;
    struct param_node *next;
} param_node;

typedef struct lst_node
{
    char *var_name;
    struct type_node *var_type;
    int address_bind;
    _node_type node_type;
    struct lst_node *next;
} lst_node;

extern gst_node *gst_head, *gst_tail;
extern lst_node *lst_head, *lst_tail;
extern param_node *param_head, *param_tail;

gst_node *gst_find(char *sym_name);
void gst_insert(char *sym_name, struct type_node *sym_type, struct class_node *sym_class_type,
                int row_size, int col_size, _node_type node_type, struct param_node *param_list);
lst_node* lst_find(char *var_name);
void lst_insert(char *var_name, type_node *var_type, _node_type node_type);
param_node *param_find(char *param_name);
void param_insert(char *param_name, type_node *param_type, _node_type node_type);

// parser_helper.c functions
void global_decl_helper();
void print_global_decl();
void set_var_type(char *var_type);
void set_function_type(char *func_type);
void define_function(struct ast_node *func, struct ast_node *body);
void define_main_function(struct ast_node *body);

void create_function_param(char *param_name);
void set_param_type(char *param_type);

#endif