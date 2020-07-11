#include "header.h"

type_node *type_head, *type_tail;
field_node *field_head, *field_tail;
extern int yylineno;

void type_table_create()
{
    /**
     * create default types
    */
    type_insert("integer", 1, NULL);
    type_insert("string", 1, NULL);
    type_insert("boolean", 0, NULL);
    type_insert("null", 0, NULL);
    type_insert("type", 0, NULL);
}

type_node *type_find(char *type_name)
{
    /**
     * find varible or return type
    */
    assert(type_name != NULL);
    type_node *type_temp = type_head;
    while (type_temp != NULL)
    {
        if (strcmp(type_temp->type_name, type_name) == 0)
            return type_temp;
        type_temp = type_temp->next;
    }
    return NULL;
}

void type_insert(char *type_name, int type_size, field_node *field_list)
{
    /**
     * insert a user defined type
    */
    type_node *type_temp = type_find(type_name);

    if (type_temp != NULL)
    {
        printf("line: %d type: multiple declaration: %s\n", yylineno, type_name);
        exit(EXIT_FAILURE);
    }
    type_node *new_node = (type_node *)malloc(sizeof(type_node));
    new_node->type_name = type_name;
    new_node->size = type_size;
    new_node->field_list = field_list;
    new_node->next = NULL;

    if (type_head == NULL)
    {
        type_head = new_node;
        type_tail = new_node;
    }
    else
    {
        type_tail->next = new_node;
        type_tail = new_node;
    }
}

field_node *field_find(type_node *field_type, char *field_name)
{
    /**
     * find a field in a type
    */
    assert(field_name != NULL);
    if (field_type == NULL)
    {
        printf("line: %d NULL type\n", yylineno);
        return NULL;
    }
    field_node *field_temp = field_type->field_list;

    while (field_temp != NULL)
    {
        if (strcmp(field_temp->field_name, field_name) == 0)
            return field_temp;
        field_temp = field_temp->next;
    }
    return NULL;
}

void field_insert(type_node *field_type, char *field_name)
{

    if (field_type == NULL)
    {
        printf("line: %d NULL type: field: %s\n", yylineno, field_name);
        exit(EXIT_FAILURE);
    }

    field_node *field_temp = field_head;
    while (field_temp != NULL)
    {
        if (strcmp(field_temp->field_name, field_name) == 0)
        {
            printf("line: %d type definition: multiple declaration: %s\n", yylineno, field_name);
            exit(EXIT_FAILURE);
        }
        field_temp = field_temp->next;
    }

    field_node *new_node = (field_node *)malloc(sizeof(field_node));
    new_node->field_name = field_name;
    // this global field index is set to zero in define_type()
    // correct index set for each field
    new_node->field_index = global_field_index++;
    new_node->field_type = field_type;
    new_node->next = NULL;

    if (field_head == NULL)
    {
        field_head = new_node;
        field_tail = new_node;
    }
    else
    {
        field_tail->next = new_node;
        field_tail = new_node;
    }
}
