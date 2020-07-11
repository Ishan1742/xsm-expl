#ifndef _TYPE_TABLE_H_
#define _TYPE_TABLE_H_

typedef struct type_node
{
    char *type_name;
    int size;
    struct field_node *field_list;
    struct type_node *next;
} type_node;

extern type_node *type_head, *type_tail;

typedef struct field_node
{
    char *field_name;
    int field_index;
    struct type_node *field_type;
    struct class_node *field_class_type;
    struct field_node *next;
} field_node;

extern field_node *field_head, *field_tail;

void type_insert(char *type_name, int size, field_node *field_list);
type_node *type_find(char *type_name);
void type_table_create();
field_node *field_find(type_node *field_type, char *field_name);
void field_insert(type_node *field_type, char *field_name);

// parser_helper functions
void print_type_table();
void print_type_fields(type_node *defined_type);
type_node *define_type(char *new_type_name);
void set_type_size(type_node *type);

#endif