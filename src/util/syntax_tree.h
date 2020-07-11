#ifndef _SYNTAX_TREE_H_
#define _SYNTAX_TREE_H_

typedef enum _node_type
{
    ID_NODE,
    NUM_NODE,
    ASSIGN_NODE,

    PLUS_NODE,
    MINUS_NODE,
    MUL_NODE,
    DIV_NODE,
    MOD_NODE,

    EQ_NODE,
    NE_NODE,
    LT_NODE,
    GT_NODE,
    LE_NODE,
    GE_NODE,

    AND_NODE,
    OR_NODE,
    NOT_NODE,

    BODY_NODE,
    WRITE_NODE,
    READ_NODE,

    ELIF_NODE,
    IF_NODE,

    WHILE_NODE,
    BREAK_NODE,
    CONTINUE_NODE,
    REPEAT_NODE,
    DOWHILE_NODE,

    STR_NODE,

    ARRAY_NODE,
    ASSIGN_ARRAY_NODE,
    READ_ARRAY_NODE,

    MATRIX_NODE,
    ASSIGN_MATRIX_NODE,
    READ_MATRIX_NODE,

    PTR_NODE,
    ASSIGN_PTR_NODE,
    READ_PTR_NODE,
    ADDR_NODE,

    FUNC_NODE,
    RET_NODE,
    ARG_NODE,

    INIT_NODE,
    ALLOC_NODE,
    FREE_NODE,

    FIELD_NODE,
    ASSIGN_FIELD_NODE,
    READ_FIELD_NODE,

    NULL_NODE,
    NEW_NODE,
    DELETE_NODE,

    CLASS_FUNC1_NODE,
    CLASS_FUNC2_NODE,
    CLASS_FUNC3_NODE,

    BRKP_NODE
} _node_type;

typedef union _constant
{
    int int_val;
    char *str_val;
} _constant;

typedef struct ast_node
{
    struct type_node *var_type;
    _constant constant;
    char *var_name;
    _node_type node_type;
    struct gst_node *gst_entry;
    struct lst_node *lst_entry;
    struct ast_node *p1, *p2, *p3;
} ast_node;

ast_node *create_ast_node(struct type_node *type, char *var_name, _node_type node_type, ast_node *l, ast_node *m, ast_node *r);
void ast_type_checker(ast_node *tnode);
void var_type_checker(ast_node *tnode);

#endif