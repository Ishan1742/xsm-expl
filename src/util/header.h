#ifndef _HEADER_H_
#define _HEADER_H_

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "syntax_tree.h"
#include "type_table.h"
#include "symbol_table.h"
#include "class_table.h"
#include "loop_stack.h"
#include "xsm_instr.h"

extern int global_register;
extern int label;
extern int flabel;
extern int current_addr_bind;
extern int local_addr_bind;
extern int param_addr_bind;
extern int global_field_index;
extern int global_class_index;
extern int start;

extern FILE *target_file;

int code_gen(ast_node *tnode);
int identifier_code_gen(ast_node *tnode);
int field_code_gen(ast_node *tnode);
int compare_params(param_node *param_temp, ast_node *tree_temp, char *func_name);
int class_func_one_code_gen(ast_node *tnode);
int class_func_two_code_gen(ast_node *tnode);
int class_func_three_code_gen(ast_node *tnode);
int operation_util(char *operation, ast_node *tnode);
int assign_code_gen(_node_type node_type, ast_node *tnode);
int read_code_gen(_node_type node_type, ast_node *tnode);
void read_library_call(int r1, int r2);
int write_library_call(ast_node *tnode);

void output_initial_code();
int get_reg();
void free_reg();
int get_label();
int get_func_label();
int yyerror(char const *s);

#endif