#include "header.h"

gst_node *gst_head, *gst_tail;
lst_node *lst_head, *lst_tail;
param_node *param_head, *param_tail;

extern int yylineno;

gst_node *gst_find(char *sym_name)
{
    /**
     * find entries in global symbol table
    */
    assert(sym_name != NULL);
    gst_node *gst_temp = gst_head;
    while (gst_temp != NULL)
    {
        if (strcmp(gst_temp->sym_name, sym_name) == 0)
            return gst_temp;
        gst_temp = gst_temp->next;
    }
    return NULL;
}

void gst_insert(char *sym_name, type_node *sym_type, class_node *sym_class_type,
                int row_size, int col_size, _node_type node_type, param_node *param_list)
{
    /**
     * insert into global symbol table
    */
    gst_node *gst_temp = gst_find(sym_name);
    if (gst_temp != NULL)
    {
        printf("line: %d global symbol: multiple declarations: %s\n", yylineno, sym_name);
        exit(EXIT_FAILURE);
    }

    gst_node *new_node = (gst_node *)malloc(sizeof(gst_node));

    new_node->sym_name = sym_name;
    new_node->sym_type = sym_type;
    new_node->sym_class_type = sym_class_type;
    new_node->row_size = row_size;

    // class objects two spaces required
    // one class address other virtual function table
    if (sym_class_type != NULL)
        new_node->row_size = 2;

    new_node->col_size = col_size;
    new_node->node_type = node_type;
    new_node->sym_param_list = param_list;

    new_node->next = NULL;

    if (current_addr_bind + row_size * col_size > 5120)
    {
        printf("line: %d insufficient memory: stack overflow\n", yylineno);
        exit(EXIT_FAILURE);
    }

    if (new_node->node_type == FUNC_NODE)
    {
        // set function label
        // set function not defined
        new_node->sym_func_label = get_func_label();
        new_node->address_bind = -1;
    }
    else
    {
        // set symbol not a function
        new_node->sym_func_label = -1;
        // set address bind
        new_node->address_bind = current_addr_bind;
    }

    current_addr_bind += new_node->row_size * new_node->col_size;

    if (gst_head == NULL)
    {
        gst_head = new_node;
        gst_tail = new_node;
    }
    else
    {
        gst_tail->next = new_node;
        gst_tail = new_node;
    }
}

lst_node *lst_find(char *var_name)
{
    /**
     * find in local symbol table
    */
    assert(var_name != NULL);
    lst_node *lst_temp = lst_head;
    while (lst_temp != NULL)
    {
        if (strcmp(lst_temp->var_name, var_name) == 0)
            return lst_temp;
        lst_temp = lst_temp->next;
    }
    return NULL;
}

void lst_insert(char *var_name, type_node *var_type, _node_type node_type)
{
    lst_node *lst_temp = lst_find(var_name);
    if (lst_temp != NULL)
    {
        printf("line: %d local symbol: multiple declarations: %s\n", yylineno, var_name);
        exit(EXIT_FAILURE);
    }
    if (var_type == NULL)
    {
        printf("line: %d class variable not allowed: %s\n", yylineno, var_name);
        exit(EXIT_FAILURE);
    }

    lst_node *new_node = (lst_node *)malloc(sizeof(lst_node));

    new_node->var_name = var_name;
    new_node->var_type = var_type;
    new_node->node_type = node_type;
    new_node->address_bind = local_addr_bind++;

    new_node->next = NULL;

    // insert at end
    if (lst_head == NULL)
    {
        lst_head = new_node;
        lst_tail = new_node;
    }
    else
    {
        lst_tail->next = new_node;
        lst_tail = new_node;
    }
}

param_node *param_find(char *param_name)
{
    /**
     * find parameter in a function
    */
    assert(param_name != NULL);
    param_node *param_temp = param_head;
    while (param_temp != NULL)
    {
        if (strcmp(param_temp->param_name, param_name) == 0)
            return param_temp;
        param_temp = param_temp->next;
    }
    return NULL;
}

void param_insert(char *param_name, type_node *param_type, _node_type node_type)
{
    /**
     * insert a parameter for a function
    */
    param_node *param_temp = param_find(param_name);

    if (param_temp != NULL)
    {
        printf("line: %d param symbol: multiple declaration: %s\n", yylineno, param_name);
        exit(EXIT_FAILURE);
    }
    if (param_type == NULL)
    {
        printf("line: %d class variable not allowed: %s\n", yylineno, param_name);
        exit(EXIT_FAILURE);
    }

    param_node *new_node = (param_node *)malloc(sizeof(param_node));

    new_node->param_name = param_name;
    new_node->param_type = param_type;
    new_node->node_type = node_type;
    new_node->address_bind = param_addr_bind++;
    new_node->next = NULL;

    if (param_head == NULL)
    {
        param_head = new_node;
        param_tail = new_node;
    }
    else
    {
        param_tail->next = new_node;
        param_tail = new_node;
    }
}