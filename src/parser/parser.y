%{
	#include "parser_helper.c"

	extern int yylex(void);
	extern FILE *yyin;
	extern int yylineno;
%}

%define parse.error verbose

%union
{
	struct ast_node *tree_node;
}

%type <tree_node> NUM ID STRING expr END program stmtlist body arglist field fieldfunction
%type <tree_node> stmt inputstmt outputstmt assignstmt ifstmt whilestmt breakstmt continuestmt debugstmt returnstmt

%token NUM PLUS MINUS MUL DIV MOD LT GT LE GE EQ NE OR AND NOT ID ASSIGN _BEGIN END DECL ENDDECL BRKP
%token READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE REPEAT UNTIL RETURN MAIN
%token TYPE ENDTYPE INITIALIZE ALLOC FREE _NULL
%token CLASS ENDCLASS EXTENDS NEW DELETE SELF
%token INT STR STRING

%nonassoc LT GT LE GE NE EQ
%left OR
%left AND
%left PLUS MINUS
%left MUL DIV MOD
%right NOT

%%

program
	: 	typedefblock classdefblock gdeclblock fdefblock mainblock
			{ return 1; }
	|	typedefblock classdefblock gdeclblock mainblock
			{ return 1; }
	|	typedefblock classdefblock mainblock
			{ return 1; }
	|	typedefblock classdefblock
			{ return 1; }
	;

typedefblock
	: 	TYPE typedeflist ENDTYPE
			{ print_type_table(); }
	|
			{ print_type_table(); /*Default types exist*/ }
	;

typedeflist
	: 	typedeflist typedef
	| 	typedef
	;

typedef
	: 	ID
			{ type_insert($1->var_name,0,NULL); }
		'{'
			fielddecllist
		'}'
			{ global_type = define_type($1->var_name); }
	;

fielddecllist
	: 	fielddecllist fielddecl
    | 	fielddecl
	;

fielddecl
	: 	typename ID ';'
			{ field_insert(global_type,$2->var_name); }
	;


typename
	: 	INT
			{ global_type = type_find("integer"); }
    | 	STR
			{ global_type = type_find("string"); }
    | 	ID
			{ global_type = type_find($1->var_name);}
	;

classdefblock
	: 	CLASS classdeflist ENDCLASS
			{ create_virtual_function_table(); }
	|
			{ _LABEL_DEC(start); }
	;

classdeflist
	: 	classdeflist classdef
	| 	classdef
	;

classdef
	: 	classname
		'{'
			DECL
				classfieldlist
				classfuncdecllist
			ENDDECL
			classfuncdefs
		'}'
			{ check_class_constraints(); }
	;

classname
	:  	ID
			{ current_class = create_class($1, NULL); }
    | 	ID EXTENDS ID
			{ current_class = create_class($1, $3); }
	;

classfieldlist
	:  	classfieldlist classfield
	|
	;

classfield
	: 	type ID ';'
			{ class_field_helper($2, global_var_type, global_class); }
	;

classfuncdecllist
	: 	classfuncdecllist classfuncdecl
	| 	classfuncdecl
	;

classfuncdecl
	: 	type ID '(' paramlist ')' ';'
			{ class_func_helper($2, global_var_type, global_class); }
	;

classfuncdefs
	: 	classfuncdefs fdef
    | 	fdef
	;

gdeclblock
	: 	DECL gdecllist ENDDECL
			{ global_decl_helper(); }
	| 	DECL ENDDECL
			{ global_decl_helper(); }
	;

gdecllist
	: 	gdecllist gdecl
	| 	gdecl
	;

gdecl
	: 	type gidlist ';'
	;

type
	: 	INT
			{ set_variable_type("integer"); }
	| 	STR
			{ set_variable_type("string"); }
	| 	ID
			{ set_variable_type($1->var_name); }
	;

gidlist
	: 	gidlist ',' gid
	| 	gid
	;

gid
	:  	ID
			{ gst_insert($1->var_name,global_var_type,global_class,1,1,ID_NODE,NULL); }
	| 	ID '[' NUM ']'
			{ gst_insert($1->var_name,global_var_type,NULL,$3->constant.int_val,1,ARRAY_NODE,NULL); }
	| 	ID '[' NUM ']' '[' NUM ']'
			{ gst_insert($1->var_name,global_var_type,NULL,$3->constant.int_val,$6->constant.int_val,MATRIX_NODE,NULL); }
	| 	MUL ID
			{ gst_insert($2->var_name,global_var_type,NULL,1,1,PTR_NODE,NULL); }
	| 	ID '(' paramlist ')'
			{ gst_insert($1->var_name,global_var_type,NULL,0,0,FUNC_NODE,param_head); param_head=param_tail=NULL; }
	;

fdefblock
	: 	fdefblock fdef
	| 	fdef
	;

functype
	: 	INT
			{ set_function_type("integer"); }
	|	STR
			{ set_function_type("string"); }
	| 	ID
			{ set_function_type($1->var_name); }
	;

fdef
	: 	functype ID '(' paramlist ')'
		'{'
			ldeclblock
			body
		'}'
			{ define_function($2,$8); }
	;

mainblock
	: 	INT MAIN '(' ')'
		'{'
			ldeclblock
			body
		'}'
			{ define_main_function($7); }
	;

paramlist
	: 	paramlist ',' param
	| 	param
	|
	;

param
	: 	paramtype ID
			{ create_function_param($2->var_name); }
 	|	paramtype MUL ID
	 		{ create_function_param($3->var_name); }
	;

paramtype
	: 	INT
			{ set_param_type("integer"); }
	| 	STR
			{ set_param_type("string"); }
	| 	ID
			{ set_param_type($1->var_name); }
	;

ldeclblock
	: 	DECL ldecllist ENDDECL
	| 	DECL ENDDECL
	;

ldecllist
	: 	ldecllist ldecl
	| 	ldecl
	;

ldecl
	: 	type idlist ';' // do not use 'type' here. class variables are not allowed in local table.
	;

idlist
	: 	idlist ',' ID
			{lst_insert($3->var_name,global_var_type,ID_NODE);}
	| 	idlist ',' MUL ID
			{lst_insert($4->var_name,global_var_type,PTR_NODE);}
	| 	ID
			{lst_insert($1->var_name,global_var_type,ID_NODE);}
	| 	MUL ID
			{lst_insert($2->var_name,global_var_type,PTR_NODE);}
	;

body
	: 	_BEGIN stmtlist returnstmt END
			{$$ = create_ast_node(type_find("void"),NULL,BODY_NODE,$2,NULL,$3);}
	| 	_BEGIN returnstmt END
			{$$ = create_ast_node(type_find("void"),NULL,BODY_NODE,NULL,NULL,$2);}
	;

stmtlist
	: 	stmtlist stmt
			{ $$ = create_ast_node(type_find("void"),NULL,BODY_NODE,$1,NULL,$2); }
	| 	stmt
			{ $$=$1; }
	;

stmt
	: 	inputstmt ';'
			{ $$=$1; }
	| 	outputstmt ';'
			{ $$=$1; }
	| 	assignstmt ';'
			{ $$=$1; }
	| 	ifstmt ';'
			{ $$=$1; }
	| 	whilestmt ';'
			{ $$=$1; }
	| 	breakstmt ';'
			{ $$=$1; }
	| 	continuestmt ';'
			{ $$=$1; }
	| 	debugstmt ';'
			{ $$=$1; }
	;

inputstmt
	: 	READ '(' ID ')'
			{ $$ = create_ast_node(type_find("void"),NULL,READ_NODE,$3,NULL,NULL); }
	|	READ '(' ID '[' expr ']' ')'
			{ $$ = create_ast_node(type_find("void"),NULL,READ_ARRAY_NODE,$3,$5,NULL); }
	|	READ '(' ID '[' expr ']' '[' expr ']' ')'
			{ $$ = create_ast_node(type_find("void"),NULL,READ_MATRIX_NODE,$3,$5,$8); }
	| 	READ '(' MUL ID ')'
			{ $$ = create_ast_node(type_find("void"),NULL,READ_PTR_NODE,$4,NULL,NULL); }
	| 	READ '(' field ')'
			{ $$ = create_ast_node(type_find("void"),NULL,READ_FIELD_NODE,$3,NULL,NULL); }
	;

outputstmt
	:	WRITE '(' expr ')'
			{$$ = create_ast_node(type_find("void"),NULL,WRITE_NODE,$3,NULL,NULL);}
	;

assignstmt
	: 	ID ASSIGN expr
			{ $$ = create_ast_node(type_find("void"),NULL,ASSIGN_NODE,$1,NULL,$3); }
	| 	ID '[' expr ']' ASSIGN expr
			{ $$ = create_ast_node(type_find("void"),NULL,ASSIGN_ARRAY_NODE,$1,$3,$6); }
	| 	ID '[' expr ']' '[' expr ']' ASSIGN expr
			{ $$ = create_ast_node(type_find("void"),NULL,ASSIGN_MATRIX_NODE,$1,create_ast_node(type_find("void"),NULL,BODY_NODE,$3,$6,NULL),$9); }
	| 	MUL ID ASSIGN expr
			{ $$ = create_ast_node(type_find("void"),NULL,ASSIGN_PTR_NODE,$2,NULL,$4); }
	| 	ID ASSIGN INITIALIZE '(' ')'
			{ $$ = create_ast_node(type_find("void"),NULL,ASSIGN_NODE,$1,NULL,create_ast_node(type_find("integer"),NULL,INIT_NODE,NULL,NULL,NULL)); }
	| 	ID ASSIGN ALLOC '(' ')'
			{ $$ = create_ast_node(type_find("void"),NULL,ASSIGN_NODE,$1,NULL,create_ast_node(type_find("type"),NULL,ALLOC_NODE,NULL,NULL,NULL)); }
	| 	field ASSIGN expr
			{ $$ = create_ast_node(type_find("void"),NULL,ASSIGN_FIELD_NODE,$1,NULL,$3); }
	| 	field ASSIGN ALLOC '(' ')'
			{ $$ = create_ast_node(type_find("void"),NULL,ASSIGN_FIELD_NODE,$1,NULL,create_ast_node(type_find("type"),NULL,ALLOC_NODE,NULL,NULL,NULL)); }
	|	FREE '(' ID ')'
			{ $$ = create_ast_node(type_find("void"),NULL,FREE_NODE,$3,NULL,NULL); }
	|	FREE '(' field ')'
			{ $$ = create_ast_node(type_find("void"),NULL,FREE_NODE,$3,NULL,NULL); }
	| 	ID ASSIGN NEW '(' ID ')'
			{ $$ = create_ast_node(type_find("void"),NULL,ASSIGN_NODE,$1,$5,create_ast_node(type_find("type"),NULL,ALLOC_NODE,NULL,NULL,NULL)); }
	| 	field ASSIGN NEW '(' ID ')'
			{ $$ = create_ast_node(type_find("void"),NULL,ASSIGN_FIELD_NODE,$1,$5,create_ast_node(type_find("type"),NULL,ALLOC_NODE,NULL,NULL,NULL)); }
	| 	DELETE '(' field ')'
			{ $$ = create_ast_node(type_find("void"),NULL,FREE_NODE,$3,NULL,NULL); }
	;

ifstmt
	: 	IF '(' expr ')' THEN stmtlist ELSE stmtlist ENDIF
			{ $$=create_ast_node(type_find("void"),NULL,ELIF_NODE,$3,$6,$8); }
	| 	IF '(' expr ')' THEN stmtlist ENDIF
			{ $$=create_ast_node(type_find("void"),NULL,IF_NODE,$3,$6,NULL); }
	;

whilestmt
	: 	WHILE '(' expr ')' DO stmtlist ENDWHILE
			{ $$ = create_ast_node(type_find("void"),NULL,WHILE_NODE,$3,NULL,$6); }
 	| 	REPEAT stmtlist UNTIL '(' expr ')'
	 		{ $$ = create_ast_node(type_find("void"),NULL,REPEAT_NODE,$5,NULL,$2); }
	| 	DO stmtlist WHILE '(' expr ')'
			{ $$ = create_ast_node(type_find("void"),NULL,DOWHILE_NODE,$5,NULL,$2); }
	;

breakstmt
	: 	BREAK
			{ $$ = create_ast_node(type_find("void"),NULL,BREAK_NODE,NULL,NULL,NULL); }
	;

continuestmt
	: 	CONTINUE
			{ $$ = create_ast_node(type_find("void"),NULL,CONTINUE_NODE,NULL,NULL,NULL); }
	;

debugstmt
	: 	BRKP
			{ $$ = create_ast_node(type_find("void"),NULL,BRKP_NODE,NULL,NULL,NULL); }
	;

returnstmt
	: 	RETURN expr ';'
			{ $$ = create_ast_node(type_find("void"),NULL,RET_NODE,$2,NULL,NULL); }
	;

arglist
	: 	arglist ',' expr
			{ $$ = create_ast_node(type_find("void"),NULL,ARG_NODE,$1,NULL,$3); }
	| 	expr
			{ $$ = create_ast_node(type_find("void"),NULL,ARG_NODE,NULL,NULL,$1); }
	|
			{ $$ = NULL; }
	;

field
	: 	ID '.' ID
			{ $$ = field_type1($1, $3); }
    | 	field '.' ID
			{ $$ = field_type2($1, $3); $$->var_type = $3->var_type; }
	| 	SELF '.' ID
			{ $$ = field_type3($3); }
	;

fieldfunction
	: 	ID '.' ID '(' arglist ')'
			{ $$ = field_function_type1($1, $3, $5); }
	|	SELF '.' ID '(' arglist ')'
			{ $$ = field_function_type2($3, $5); }
	| 	field '.' ID '(' arglist ')'
			{ $$ = field_function_type3($1, $3, $5); }
	;

expr
	:	expr PLUS expr
			{ $$ = create_ast_node( type_find("integer"), NULL,PLUS_NODE,$1,NULL,$3); }
	| 	expr MINUS expr
			{ $$ = create_ast_node( type_find("integer"), NULL,MINUS_NODE,$1,NULL,$3); }
	| 	expr MUL expr
			{ $$ = create_ast_node( type_find("integer"), NULL,MUL_NODE,$1,NULL,$3); }
	| 	expr DIV expr
			{ $$ = create_ast_node( type_find("integer"), NULL,DIV_NODE,$1,NULL,$3); }
	| 	expr MOD expr
			{ $$ = create_ast_node( type_find("integer"), NULL,MOD_NODE,$1,NULL,$3); }
	| 	'(' expr ')'
			{ $$ = $2; }
	| 	expr EQ expr
			{ $$ = create_ast_node( type_find("boolean"), NULL,EQ_NODE,$1,NULL,$3); }
	| 	expr NE expr
			{ $$ = create_ast_node( type_find("boolean"), NULL,NE_NODE,$1,NULL,$3); }
	| 	expr LE expr
			{ $$ = create_ast_node( type_find("boolean"), NULL,LE_NODE,$1,NULL,$3); }
	| 	expr GE expr
			{ $$ = create_ast_node( type_find("boolean"), NULL,GE_NODE,$1,NULL,$3); }
	|  	expr LT expr
			{ $$ = create_ast_node( type_find("boolean"), NULL,LT_NODE,$1,NULL,$3); }
	| 	expr GT expr
			{ $$ = create_ast_node( type_find("boolean"), NULL,GT_NODE,$1,NULL,$3); }
	| 	expr AND expr
			{ $$ = create_ast_node( type_find("boolean"), NULL,AND_NODE,$1,NULL,$3); }
	| 	expr OR expr
			{ $$ = create_ast_node( type_find("boolean"), NULL,OR_NODE,$1,NULL,$3); }
	| 	expr NOT expr
			{ $$ = create_ast_node( type_find("boolean"), NULL,NOT_NODE,$1,NULL,$3); }
	| 	NUM
			{ $$ = $1; }
	| 	STRING
			{ $$ = $1; }
	| 	_NULL
			{ $$ = create_ast_node(type_find("type"), NULL, NULL_NODE, NULL, NULL, NULL); }
	| 	field
			{ $$ = $1; }
	| 	fieldfunction
			{ $$ = $1; }
	| 	ID
			{ $$ = $1; }
	| 	ID '[' expr ']'
			{ $$ = create_ast_node($1->var_type,$1->var_name,ARRAY_NODE,$1,$3,NULL); }
	| 	ID '[' expr ']' '[' expr ']'
			{ $$ = create_ast_node($1->var_type,$1->var_name,MATRIX_NODE,$1,$3,$6); }
	| 	MUL ID
			{ $$ = create_ast_node($2->var_type,$2->var_name,PTR_NODE,$2,NULL,NULL); }
	| 	'&' ID
			{ $$ = create_ast_node($2->var_type,$2->var_name,ADDR_NODE,$2,NULL,NULL); }
	| 	ID '(' arglist ')'
			{ $$ = create_ast_node($1->var_type,$1->var_name,FUNC_NODE,$1,NULL,$3); }
	| 	MINUS NUM
			{ $2->constant.int_val = - ($2->constant.int_val); $$ = $2; }
	;

%%

int yyerror(char const *s)
{
	printf("line: %d error: %s\n",yylineno, s);
	exit(EXIT_FAILURE);
}


int main(int argc, char *argv[])
{
	// initialise global varibales
	global_register=-1;
	label=0;
	flabel=0;
	current_addr_bind=4096;
	local_addr_bind=1;
	param_addr_bind=1;
	global_field_index=0;
	global_class_index=0;
	start=0;

	FILE *fp = fopen(argv[1],"r");
	if(fp)
	{
			yyin=fp;
	}
	else
	{
		printf("file not found\n");
		exit(EXIT_FAILURE);
	}
	target_file=fopen("test.xsm","w");
	start=get_label();
	fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
	fprintf(target_file, "JMP L%d\n", start);
	type_table_create();
	yyparse();
	return 0;
}
