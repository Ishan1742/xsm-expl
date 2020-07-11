#include "header.h"

class_node *class_head, *class_tail;
class_node *current_class;

extern int yylineno;

void class_insert(char *class_name, char *parent_class_name)
{
    /**
     * create a new entry in the class table
    */
    type_node *type_temp = type_find(class_name);
    if (type_temp != NULL)
    {
        printf("line: %d user type: multiple declaration: %s\n", yylineno, class_name);
        exit(EXIT_FAILURE);
    }

    class_node *class_temp = class_find(class_name);

    if (class_temp != NULL)
    {
        printf("line: %d class: multiple declaration: %s\n", yylineno, class_name);
        exit(EXIT_FAILURE);
    }

    class_node *new_node = (class_node *)malloc(sizeof(class_node));
    new_node->class_name = class_name;
    new_node->class_field_list = NULL;
    new_node->class_func_list = NULL;
    new_node->parent_class = NULL;
    new_node->class_index = global_class_index++;
    new_node->class_field_count = 0;
    new_node->class_func_count = 0;
    new_node->next = NULL;

    if (parent_class_name != NULL)
    {
        class_temp = class_find(parent_class_name);
        if (class_temp == NULL)
        {
            printf("line: %d class: parent class not found: %s\n", yylineno, parent_class_name);
            exit(EXIT_FAILURE);
        }
        new_node->parent_class = class_temp;
    }

    if (class_head == NULL)
    {
        class_head = new_node;
        class_tail = new_node;
    }
    else
    {
        class_tail->next = new_node;
        class_tail = new_node;
    }
}

class_node *class_find(char *class_name)
{
    /**
     * find the class
    */
    assert(class_name != NULL);
    class_node *class_temp = class_head;
    while (class_temp != NULL)
    {
        if (strcmp(class_temp->class_name, class_name) == 0)
            return class_temp;
        class_temp = class_temp->next;
    }
    return NULL;
}

void class_field_insert(class_node *class, char *field_type_name, char *field_name)
{
    /**
     * insert a field in a class
    */
    assert(class != NULL);
    type_node *type_temp = type_find(field_type_name);
    class_node *class_temp = class_find(field_type_name);

    if (type_temp == NULL && class_temp == NULL)
    {
        printf("line: %d unknown type: field: %s\n", yylineno, field_name);
        exit(EXIT_FAILURE);
    }

    field_node *field_temp = class->class_field_list;
    field_node *last = NULL;
    while (field_temp != NULL)
    {
        if (strcmp(field_temp->field_name, field_name) == 0)
        {
            printf("line: %d class fields: multiple declaration: %s\n", yylineno, field_name);
            exit(EXIT_FAILURE);
        }
        last = field_temp;
        field_temp = field_temp->next;
    }

    field_node *new_node = (field_node *)malloc(sizeof(field_node));
    new_node->field_name = field_name;
    // this field index set is useless
    // and it sets incorrect fields as global_field_index
    // is never set back to zero unlike for type_insert
    // correct field_index set in check_class_constraints()
    new_node->field_index = global_field_index++;
    new_node->field_type = type_temp;
    new_node->field_class_type = class_temp;
    new_node->next = NULL;

    if (class->class_field_list == NULL)
        class->class_field_list = new_node;
    else
        last->next = new_node;
}

void class_func_insert(class_node *class, char *func_name, type_node *func_return_type, param_node *param_list)
{
    assert(class != NULL);
    class_func_node *func_temp = class->class_func_list;
    class_func_node *last = NULL;
    while (func_temp != NULL)
    {
        if (strcmp(func_temp->class_func_name, func_name) == 0)
        {
            param_node *decl_param = func_temp->func_param_list;
            param_node *formal_param = param_list;
            while (decl_param != NULL && formal_param != NULL)
            {
                if (decl_param->param_type == formal_param->param_type &&
                    strcmp(decl_param->param_name, formal_param->param_name) == 0)
                {
                    decl_param = decl_param->next;
                    formal_param = formal_param->next;
                }
                else
                {
                    break;
                }
            }
            if (decl_param != NULL || formal_param != NULL)
            {
                printf("line: %d function overloading not allowed: multiple declarations: %s\n", yylineno, func_name);
                exit(EXIT_FAILURE);
            }
            else
            {
                if(func_temp->func_position == -1)
                {
                    // this is for multiple functions with the same parameters.
                    // function redeclaration within class with the same parameters
                    printf("line: %d function multiple declarations: %s()\n", yylineno, func_name);
                    exit(EXIT_FAILURE);
                }
                // these are for functions that are inherited
                func_temp->func_position = -1;
                func_temp->func_label = get_func_label();
                return;
            }
        }
        last = func_temp;
        func_temp = func_temp->next;
    }

    class_func_node *new_node = (class_func_node *)malloc(sizeof(class_func_node));
    new_node->class_func_name = func_name;
    new_node->func_return_type = func_return_type;
    new_node->func_param_list = param_list;
    new_node->func_position = -1;
    new_node->func_label = get_func_label();
    new_node->next = NULL;

    if (class->class_func_list == NULL)
        class->class_func_list = new_node;
    else
        last->next = new_node;
}

class_func_node *class_func_find(class_node *class, char *func_name)
{
    /**
     * find the function in a class
    */
    assert(class != NULL);
    assert(func_name != NULL);
    class_func_node *func_temp = class->class_func_list;

    while (func_temp != NULL)
    {
        if (strcmp(func_temp->class_func_name, func_name) == 0)
            return func_temp;
        func_temp = func_temp->next;
    }
    return NULL;
}

field_node *class_field_find(class_node *class, char *field_name)
{
    /**
     * find the field in a class
    */
    assert(class != NULL);
    assert(field_name != NULL);
    field_node *field_temp = class->class_field_list;
    while (field_temp != NULL)
    {
        if (strcmp(field_temp->field_name, field_name) == 0)
            return field_temp;
        field_temp = field_temp->next;
    }
    return NULL;
}