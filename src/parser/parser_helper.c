#include "../util/header.h"

type_node *global_var_type;
type_node *global_func_type;
type_node *global_param_type;
type_node *global_type;
class_node *global_class;

extern int yylineno;

/* ------------------------------- type helper ------------------------------ */

void print_type_table()
{
    /**
     * Prints all the defined types
    */
    printf("\ntype table: \n");
    printf("***********\n\n");

    type_node *type_temp = type_head;
    while (type_temp != NULL)
    {
        printf("type: %s\n", type_temp->type_name);
        printf("    size: %d\n", type_temp->size);
        printf("    fields: \n");
        print_type_fields(type_temp);
        printf("\n");
        type_temp = type_temp->next;
    }
}

void print_type_fields(type_node *defined_type)
{
    /**
     * Prints the fields in a type
    */
    assert(defined_type != NULL);
    field_node *field_temp = defined_type->field_list;

    if (field_temp == NULL)
        printf("        NULL\n");

    while (field_temp != NULL)
    {
        assert(field_temp->field_type != NULL);
        printf("        type: %s, name: %s, index: %d\n",
               field_temp->field_type->type_name, field_temp->field_name, field_temp->field_index);
        field_temp = field_temp->next;
    }
}

type_node *define_type(char *new_type_name)
{
    /**
     * Sets all additional values for a type
     * after a initial empty type is inserted
     * in the type table. To accomodate for
     * types which have itself as a field;
     * type node{
     *      int data;
     *      node next;
     * }
    */
    assert(new_type_name != NULL);
    type_node *type_temp = type_find(new_type_name);
    assert(type_temp != NULL);
    type_temp->field_list = field_head;
    set_type_size(type_temp);

    /**
     * empty field_list
    */
    field_head = NULL;
    field_tail = NULL;
    global_field_index = 0;

    return type_temp;
}

void set_type_size(type_node *var_type)
{
    /**
     * Check and set size of fields for a type
     * size is fixed as buddy allocation
     * is not followed.
    */
    // function has redundancy
    // size = global_field_index + 1
    // or remove size altogether not used in any function
    assert(var_type != NULL);

    field_node *field_temp = var_type->field_list;
    int size = 0;
    while (field_temp != NULL)
    {
        size++;
        field_temp = field_temp->next;
    }
    var_type->size = size;

    if (size > 8)
    {
        printf("line: %d type size exceeds allowed(8): %s\n", yylineno, var_type->type_name);
        exit(EXIT_FAILURE);
    }
}

/* ------------------------------ class helper ------------------------------ */

void create_virtual_function_table()
{
    print_class_table();

    _LABEL_DEC(start);
    _MOV("SP", "4095");

    class_node *class_temp = class_head;
    while (class_temp != NULL)
    {
        class_func_node *class_func_temp = class_temp->class_func_list;
        int func_count = 0;
        while (class_func_temp != NULL)
        {
            /**
             * Special instruction
             * Not in xsm instructions
             * makes tasks easy as F0
             * changes to function address
             * during label translation
            */
            fprintf(target_file, "MOV R0, F%d\n", class_func_temp->func_label);
            _PUSH(0);

            func_count++;
            class_func_temp = class_func_temp->next;
        }

        _MOV_RN(0, -1);
        while (func_count < 8)
        {
            _PUSH(0);
            func_count++;
        }
        current_addr_bind = current_addr_bind + 8;
        class_temp = class_temp->next;
    }
}

void print_class_table()
{
    /**
     * Prints all classes
    */
    printf("\nclass table: \n");
    printf("************\n\n");

    class_node *class_temp = class_head;
    while (class_temp != NULL)
    {
        printf("class: %s\n", class_temp->class_name);
        printf("parent: %s\n",
               class_temp->parent_class == NULL ? "NULL" : class_temp->parent_class->class_name);
        printf("index: %d\n", class_temp->class_index);
        printf("field_count: %d\n", class_temp->class_field_count);
        print_class_fields(class_temp);

        printf("function_count: %d\n", class_temp->class_func_count);
        print_class_functions(class_temp);
        printf("\n");
        class_temp = class_temp->next;
    }
}

void print_class_fields(class_node *class)
{
    /**
     * Print all fields in a class
    */
    assert(class != NULL);
    field_node *field_temp = class->class_field_list;

    while (field_temp != NULL)
    {
        assert(field_temp->field_type != NULL || field_temp->field_class_type != NULL);
        if (field_temp->field_type != NULL)
            printf("    type: %s, ", field_temp->field_type->type_name);
        else
            printf("    type: %s, ", field_temp->field_class_type->class_name);

        printf("name: %s, ", field_temp->field_name);
        printf("index: %d\n", field_temp->field_index);
        field_temp = field_temp->next;
    }
}

void print_class_functions(class_node *class)
{
    /**
     * Prints all functions in a class
    */
    assert(class != NULL);
    class_func_node *class_func_temp = class->class_func_list;

    while (class_func_temp != NULL)
    {
        printf("    func: %s\n", class_func_temp->class_func_name);
        assert(class_func_temp->func_return_type != NULL);
        printf("        func_type: %s, ", class_func_temp->func_return_type->type_name);
        printf("func_label : F%d, ", class_func_temp->func_label);
        printf("func_pos: %d\n", class_func_temp->func_position);
        printf("        params: \n");

        param_node *param_temp = class_func_temp->func_param_list;
        if (param_temp == NULL)
            printf("            NULL\n");

        while (param_temp != NULL)
        {
            assert(param_temp->param_type != NULL);
            printf("            type: %s, ", param_temp->param_type->type_name);
            printf("name: %s\n", param_temp->param_name);
            param_temp = param_temp->next;
        }
        class_func_temp = class_func_temp->next;
    }
}

void check_class_constraints()
{
    /**
     * Checks and sets fields and function count
     * in a class which cannot be greater than 8.
    */
    /**
     * current_class is the class being parsed
    */
    assert(current_class != NULL);

    int field_count = 0;
    field_node *field_temp = current_class->class_field_list;
    while (field_temp != NULL)
    {
        field_temp->field_index = field_count++;
        /**
         * field_type is not set for class objects
         * field_class_type is set for such objects
         * need two spaces one for class location
         * other for class virtual function table
         * .declare a class object and can call the
         * functions in the class object.
        */
        if (field_temp->field_type == NULL)
        {
            field_count++;
        }
        field_temp = field_temp->next;
    }
    if (field_count > 8)
    {
        printf("line: %d class field count exceeds allowed(8): %s\n", yylineno, current_class->class_name);
        exit(EXIT_FAILURE);
    }
    current_class->class_field_count = field_count;

    int func_count = 0;
    class_func_node *class_func_temp = current_class->class_func_list;
    while (class_func_temp != NULL)
    {
        if (class_func_temp->func_position == -1)
        {
            printf("line: %d class function not defined: %s.%s\n", yylineno, current_class->class_name, class_func_temp->class_func_name);
            exit(EXIT_FAILURE);
        }
        class_func_temp->func_position = func_count++;
        class_func_temp = class_func_temp->next;
    }
    if (func_count > 8)
    {
        printf("line: %d class function count exceeds allowed(8): %s\n", yylineno, current_class->class_name);
        exit(EXIT_FAILURE);
    }
    current_class->class_func_count = func_count;

    current_class = NULL;
}

class_node *create_class(ast_node *class_tnode, ast_node *parent_class_tnode)
{
    /**
     * Create class entry in class table
     * if parent_class_tnode exists fetch all
     * of their functions to defined class
    */
    assert(class_tnode != NULL);
    if (parent_class_tnode == NULL)
    {
        class_insert(class_tnode->var_name, NULL);
        return class_find(class_tnode->var_name);
    }
    else
    {
        class_insert(class_tnode->var_name, parent_class_tnode->var_name);
        class_node *class_temp = class_find(parent_class_tnode->var_name);

        assert(class_temp != NULL);
        field_node *field_temp = class_temp->class_field_list;
        while (field_temp != NULL)
        {
            assert(field_temp->field_type != NULL || field_temp->field_class_type != NULL);
            class_temp = class_find(class_tnode->var_name);
            if (field_temp->field_type != NULL)
                class_field_insert(class_temp, field_temp->field_type->type_name, field_temp->field_name);
            else
                class_field_insert(class_temp, field_temp->field_class_type->class_name, field_temp->field_name);
            field_temp = field_temp->next;
        }

        class_temp = class_find(parent_class_tnode->var_name);
        class_func_node *parent_class_func_temp = class_temp->class_func_list;
        while (parent_class_func_temp != NULL)
        {
            class_temp = class_find(class_tnode->var_name);
            assert(class_temp != NULL);

            class_func_insert(class_temp, parent_class_func_temp->class_func_name,
                              parent_class_func_temp->func_return_type, parent_class_func_temp->func_param_list);
            /**
             * when a function is defined in it's parent class
             * no need to use up the extra label
             * see class_func_insert
             * so delete that label
             * should work without flabel-- also
            */
            flabel--;
            class_func_node *class_func_temp = class_func_find(class_temp,
                                                               parent_class_func_temp->class_func_name);

            // fucntion position updated in check_class_constraints
            // after all the classes are declared.
            class_func_temp->func_position = 0;
            class_func_temp->func_label = parent_class_func_temp->func_label;
            parent_class_func_temp = parent_class_func_temp->next;
        }
        return class_find(class_tnode->var_name);
    }
}

/* --------------------------- class field helper --------------------------- */

void class_field_helper(ast_node *class_field_tnode, type_node *field_type, class_node *field_class_type)
{
    /**
     * field_type and field_class_type are global
     * should work without them too
     * insert a field in a class
    */
    if (field_type != NULL)
    {
        class_field_insert(current_class, field_type->type_name, class_field_tnode->var_name);
    }
    else if (field_class_type != NULL)
    {
        class_field_insert(current_class, field_class_type->class_name, class_field_tnode->var_name);
    }
    else
    {
        printf("line: %d class field null. exception: %s\n", yylineno, class_field_tnode->var_name);
    }
}

/* -------------------------- class function helper ------------------------- */

void class_func_helper(ast_node *class_func_tnode, type_node *func_return_type, class_node *func_class_return_type)
{
    /**
     * insert a function in a class
    */
    if (func_class_return_type != NULL)
    {
        printf("line: %d class return type not supported, function: %s\n", yylineno, class_func_tnode->var_name);
        exit(EXIT_FAILURE);
    }
    class_func_insert(current_class, class_func_tnode->var_name, func_return_type, param_head);

    param_head = NULL;
    param_tail = NULL;
    lst_head = NULL;
    lst_tail = NULL;
    local_addr_bind = 1;
    param_addr_bind = 1;
}

/* --------------------------- symbol table helper -------------------------- */

void global_decl_helper()
{
    /**
     * Updates initial code in file
     * need to do it here after all
     * global variables are declared
    */
    print_global_decl();

    output_initial_code();

    // set initial values
    local_addr_bind = 1;
    param_addr_bind = 1;
}

void print_global_decl()
{
    /**
     * Print all global symbols
    */
    printf("global symbol table:\n");
    printf("********************\n\n");
    gst_node *gst_temp = gst_head;
    while (gst_temp != NULL)
    {
        printf("name: %s\n", gst_temp->sym_name);
        assert(gst_temp->sym_type != NULL || gst_temp->sym_class_type != NULL);
        // would be a return type for a function
        if (gst_temp->sym_type != NULL)
            printf("    type: %s\n", gst_temp->sym_type->type_name);
        else
            printf("    type(class): %s\n", gst_temp->sym_class_type->class_name);

        printf("    row size: %d\n", gst_temp->row_size);
        printf("    col size: %d\n", gst_temp->col_size);
        printf("    address: %d\n", gst_temp->address_bind);

        // it is a function
        if (gst_temp->sym_func_label != -1)
        {
            printf("    func label: %d\n", gst_temp->sym_func_label);
            printf("    params: \n");
            param_node *param_temp = gst_temp->sym_param_list;
            while (param_temp != NULL)
            {
                assert(param_temp->param_type != NULL);
                printf("        type: %s, ", param_temp->param_type->type_name);
                printf("name: %s\n", param_temp->param_name);
                param_temp = param_temp->next;
            }
        }
        gst_temp = gst_temp->next;
    }
    printf("\n");
}

void output_initial_code()
{
    /**
     * Output to file starting instruction
     * for the xsm program
    */
    fprintf(target_file, "MOV SP, %d\n", current_addr_bind - 1);
    fprintf(target_file, "MOV BP, %d\n", current_addr_bind);
    _PUSH(0);
    _CALL("MAIN");
    fprintf(target_file, "INT 10\n");
}

void set_variable_type(char *var_type_name)
{
    /**
     * set variable type for declared objects
    */
    assert(var_type_name != NULL);
    global_var_type = type_find(var_type_name);
    global_class = class_find(var_type_name);

    if (global_var_type == NULL && global_class == NULL)
    {
        printf("line: %d unknown type: %s \n", yylineno, var_type_name);
        exit(EXIT_FAILURE);
    }
}

/* ----------------------------- function helper ---------------------------- */

void set_function_type(char *func_type_name)
{
    /**
     * set function return type
    */
    assert(func_type_name != NULL);
    global_func_type = type_find(func_type_name);
    if (global_func_type == NULL)
    {
        printf("line: %d unknown function type: %s\n", yylineno, func_type_name);
        exit(EXIT_FAILURE);
    }
}

void define_function(ast_node *function_id_tnode, ast_node *body_tnode)
{
    /**
     * define a function
    */
    assert(function_id_tnode != NULL);
    assert(body_tnode != NULL);
    assert(body_tnode->p3 != NULL);
    assert(body_tnode->p3->p1 != NULL);
    assert(body_tnode->p3->p1->var_type != NULL);
    assert(global_func_type != NULL);
    if (body_tnode->p3->p1->var_type != global_func_type)
    {
        printf("line: %d return type incorrect. %s(): expected: %s found: %s\n",
               yylineno, function_id_tnode->var_name, body_tnode->p3->p1->var_type->type_name, global_func_type->type_name);
        exit(EXIT_FAILURE);
    }

    if (current_class == NULL)
    {
        gst_node *gst_temp = gst_find(function_id_tnode->var_name);
        if (gst_temp == NULL || gst_temp->node_type != FUNC_NODE)
        {
            printf("line: %d function undeclared: %s\n", function_id_tnode->var_name);
            exit(EXIT_FAILURE);
        }
        if (gst_temp->sym_type != global_func_type)
        {
            assert(gst_temp->sym_type != NULL);
            assert(global_func_type != NULL);
            printf("line: %d return type incorrect. %s(): declared: %s defined: %s\n", yylineno, function_id_tnode->var_name, gst_temp->sym_type->type_name, global_func_type->type_name);
            exit(EXIT_FAILURE);
        }

        param_node *decl_params = gst_temp->sym_param_list;
        param_node *formal_params = param_head;

        while (decl_params != NULL && formal_params != NULL)
        {
            if (decl_params->param_type == formal_params->param_type &&
                strcmp(decl_params->param_name, formal_params->param_name) == 0)
            {
                decl_params = decl_params->next;
                formal_params = formal_params->next;
            }
            else
            {
                break;
            }
        }

        if (formal_params != NULL || decl_params != NULL)
        {
            printf("line: %d declaration params and definition params different. function: %s()\n",
                   yylineno, function_id_tnode->var_name);
            exit(EXIT_FAILURE);
        }
        else if (gst_temp->address_bind == -2)
        {
            printf("line: %d function redefined: %s()\n",
                   yylineno, function_id_tnode->var_name);
            exit(EXIT_FAILURE);
        }
        // this is a hack to prevent function redefinition
        // function address_bind is set to -1 initially
        // see gst_insert()
        gst_temp->address_bind = -2;

        // Start of the function definition in xsm
        _FUNC_LABEL_DEC(gst_temp->sym_func_label);
        _PUSH_S("BP");
        _MOV("BP", "SP");

        int local_var_count = 0;
        lst_node *lst_temp = lst_head;
        while (lst_temp != NULL)
        {
            local_var_count++;
            lst_temp = lst_temp->next;
        }
        // push local variables
        _ADD_S("SP", local_var_count);
        // generate code for function
        code_gen(body_tnode);
    }
    else
    {
        class_func_node *class_func_temp = current_class->class_func_list;
        while (class_func_temp != NULL)
        {

            if (strcmp(function_id_tnode->var_name, class_func_temp->class_func_name) == 0)
            {
                param_node *formal_params = param_head;
                param_node *decl_params = class_func_temp->func_param_list;
                while (decl_params != NULL && formal_params != NULL)
                {
                    if (decl_params->param_type == formal_params->param_type &&
                        strcmp(decl_params->param_name, formal_params->param_name) == 0)
                    {
                        decl_params = decl_params->next;
                        formal_params = formal_params->next;
                    }
                    else
                    {
                        break;
                    }
                }

                if (formal_params != NULL || decl_params != NULL)
                {
                    printf("line: %d declaration params and definition params different. function: %s()\n",
                           yylineno, function_id_tnode->var_name);
                    exit(EXIT_FAILURE);
                }
                else
                {
                    break;
                }
            }
            class_func_temp = class_func_temp->next;
        }

        if (class_func_temp == NULL)
        {
            printf("line: %d class function undeclared: %s()\n", yylineno, function_id_tnode->var_name);
            exit(EXIT_FAILURE);
        }
        else if (class_func_temp->func_position == 0)
        {
            printf("line: %d class function redefined: %s()\n", yylineno, function_id_tnode->var_name);
            exit(EXIT_FAILURE);
        }

        // this is just to check if function is defined or not
        // a better name such as func_defn would be alright
        class_func_temp->func_position = 0;
        _FUNC_LABEL_DEC(class_func_temp->func_label);
        _PUSH_S("BP");
        _MOV("BP", "SP");

        int local_var_count = 0;
        lst_node *lst_temp = lst_head;
        while (lst_temp != NULL)
        {
            local_var_count++;
            lst_temp = lst_temp->next;
        }

        _ADD_S("SP", local_var_count);

        code_gen(body_tnode);
    }

    // set everything to NULL
    param_head = NULL;
    param_tail = NULL;
    lst_head = NULL;
    lst_tail = NULL;
    local_addr_bind = 1;
    param_addr_bind = 1;
}

void define_main_function(ast_node *body_tnode)
{
    /**
     * function definition of the main function
    */

    assert(body_tnode != NULL);
    assert(body_tnode->p3 != NULL);
    assert(body_tnode->p3->p1 != NULL);
    assert(body_tnode->p3->p1->var_type != NULL);
    if (body_tnode->p3->p1->var_type != type_find("integer"))
    {
        printf("line: %d return type of main(). expected: integer found: %s\n",
               yylineno, body_tnode->p3->p1->var_type->type_name);
        exit(EXIT_FAILURE);
    }

    fprintf(target_file, "MAIN:\n");
    _PUSH_S("BP");
    _MOV("BP", "SP");

    int local_var_count = 0;
    lst_node *lst_temp = lst_head;
    while (lst_temp != NULL)
    {
        local_var_count++;
        lst_temp = lst_temp->next;
    }

    // adding local variables
    _ADD_S("SP", local_var_count);

    code_gen(body_tnode);

    lst_head = NULL;
    lst_tail = NULL;
    param_head = NULL;
    param_tail = NULL;
    local_addr_bind = 1;
    param_addr_bind = 1;
}

/* ------------------------------ param helper ------------------------------ */

void create_function_param(char *param_name)
{
    /**
     * Create a parameter for a function
    */
    param_node *param_temp = param_find(param_name);
    assert(param_name != NULL);
    if (param_temp != NULL)
    {
        printf("line: %d multiple param declarations: %s\n", param_name);
        exit(EXIT_FAILURE);
    }
    // insert the parameter in the current param_list
    assert(global_param_type != NULL);
    param_insert(param_name, global_param_type, ID_NODE);
}

void set_param_type(char *param_type_name)
{
    /**
     * Set parameter type for a parameter
    */
    // value set globally
    // if you want to experiment
    // see https://www.geeksforgeeks.org/differences-between-synthesized-and-inherited-attributes/
    global_param_type = type_find(param_type_name);
    if (global_param_type == NULL)
    {
        printf("line: %d unknown type: %s\n", yylineno, param_type_name);
        exit(EXIT_FAILURE);
    }
}

/* ------------------------------ field helper ------------------------------ */

ast_node *field_type1(ast_node *field_id1, ast_node *field_id2)
{
    /**
     * field type ID.ID
    */
    assert(field_id1 != NULL);
    field_node *field_temp = field_find(field_id1->var_type, field_id2->var_name);
    if (field_temp == NULL)
    {
        printf("line: %d undeclared field: %s in field: %s\n", yylineno, field_id2->var_name, field_id1->var_name);
        exit(EXIT_FAILURE);
    }
    return create_ast_node(field_temp->field_type, NULL, FIELD_NODE, field_id1, NULL,
                           create_ast_node(type_find("void"), NULL, FIELD_NODE, field_id2, NULL, NULL));
}

ast_node *field_type2(ast_node *field_tnode, ast_node *id_tnode)
{
    /**
     * field type field.ID
    */
    assert(field_tnode != NULL);
    assert(id_tnode != NULL);
    if (field_tnode->var_name != NULL && field_tnode->var_type == NULL)
    {
        printf("line: %d access of private members not allowed: %s\n", yylineno, id_tnode->var_name);
        exit(EXIT_FAILURE);
    }

    /**
     * Right ordering
     * field -> (id, NULL, id)
     * field -> (id, NULL, id -> (id, NULL, NULL))
     * field -> (id, NULL, id -> (field -> (id, NULL, NULL)))
    */

    ast_node *last_field_tnode = field_tnode;
    while (last_field_tnode->p3 != NULL)
        last_field_tnode = last_field_tnode->p3;

    field_node *field_temp = field_find(field_tnode->var_type, id_tnode->var_name);
    if (field_temp == NULL)
    {
        printf("line: unknown field: %s in field: %s\n", yylineno, id_tnode->var_name, last_field_tnode->p1->var_name);
        exit(EXIT_FAILURE);
    }

    ast_node *new_field_tnode = create_ast_node(type_find("void"), NULL, FIELD_NODE, id_tnode, NULL, NULL);
    last_field_tnode->p3 = new_field_tnode;
    return field_tnode;
}

ast_node *field_type3(ast_node *id_tnode)
{
    /**
     * field type SELF.ID
    */
    if (current_class == NULL)
    {
        printf("line: %d self reserved for fields inside class: %s\n", yylineno, id_tnode->var_name);
        exit(EXIT_FAILURE);
    }

    field_node *field_temp = class_field_find(current_class, id_tnode->var_name);

    if (field_temp == NULL)
    {
        printf("line: %d undeclared field: %s in class: %s\n", yylineno, id_tnode->var_name, current_class->class_name);
        exit(EXIT_FAILURE);
    }

    return create_ast_node(field_temp->field_type, current_class->class_name, FIELD_NODE, id_tnode, NULL, NULL);
}

/* -------------------------- field function helper ------------------------- */

ast_node *field_function_type1(ast_node *field_tnode, ast_node *field_function_tnode, ast_node *func_arglist_tnode)
{
    /**
     * field function of type ID.ID()
    */
    assert(field_tnode != NULL);
    gst_node *gst_temp = gst_find(field_tnode->var_name);

    // when identifier not present in gst
    if (gst_temp == NULL)
    {
        printf("line: %d unknown identifier: %s\n", yylineno, field_tnode->var_name);
        exit(EXIT_FAILURE);
    }

    // this should never be the case because
    // class always defined before gst
    if (current_class != NULL)
    {
        printf("line: %d self to be used in class function: %s\n", yylineno, current_class->class_name);
        exit(EXIT_FAILURE);
    }

    // int test in gst
    // func in any class
    // test.func();
    if (gst_temp->sym_class_type == NULL)
    {
        printf("line: %d function: %s() can only be called by a class object.\n", yylineno, field_function_tnode->var_name);
        exit(EXIT_FAILURE);
    }

    class_func_node *class_func_temp = class_func_find(gst_temp->sym_class_type, field_function_tnode->var_name);
    if (class_func_temp == NULL)
    {
        printf("line: %d unknown class function: %s() class object: %s\n", yylineno, field_function_tnode->var_name, field_tnode->var_name);
        exit(EXIT_FAILURE);
    }

    return create_ast_node(class_func_temp->func_return_type, NULL, CLASS_FUNC1_NODE, field_tnode, field_function_tnode, func_arglist_tnode);
}

ast_node *field_function_type2(ast_node *field_func_tnode, ast_node *func_arglist_tnode)
{
    /**
     * field function of type SELF.ID()
    */
    if (current_class == NULL)
    {
        printf("line: %d self allowed inside class.\n");
        exit(EXIT_FAILURE);
    }
    assert(field_func_tnode != NULL);
    class_func_node *class_func_temp = class_func_find(current_class, field_func_tnode->var_name);

    if (class_func_temp == NULL)
    {
        printf("line: %d class function: %s() undeclared in class: %s\n", yylineno, field_func_tnode->var_name, current_class->class_name);
        exit(EXIT_FAILURE);
    }

    return create_ast_node(class_func_temp->func_return_type, current_class->class_name, CLASS_FUNC2_NODE, field_func_tnode, NULL, func_arglist_tnode);
}

ast_node *field_function_type3(ast_node *field_tnode, ast_node *field_func_tnode, ast_node *func_arglist_tnode)
{
    /**
     * field function of type field.ID()
    */
    assert(field_tnode != NULL);
    assert(field_tnode->p1 != NULL);
    assert(current_class != NULL);
    field_node *field_temp = class_field_find(current_class, field_tnode->p1->var_name);
    assert(field_temp != NULL);
    assert(field_func_tnode != NULL);
    class_func_node *class_func_temp = class_func_find(field_temp->field_class_type, field_func_tnode->var_name);
    if (class_func_temp == NULL)
    {
        printf("line: %d class function: %s() undeclared in class: %s\n", yylineno, field_func_tnode->var_name, field_tnode->var_name);
        exit(EXIT_FAILURE);
    }
    return create_ast_node(class_func_temp->func_return_type, NULL, CLASS_FUNC3_NODE, field_tnode, field_func_tnode, func_arglist_tnode);
}