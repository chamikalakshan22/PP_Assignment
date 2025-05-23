%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare yylex to avoid implicit function declaration
extern int yylex(void);

// Global form and field structures
typedef struct {
    char *name;
    char *meta[50];
    int meta_count;
    int section_count;
} Form;

typedef struct {
    char *name;
    char *type;
    char *attributes[50];
    int attr_count;
} Field;

Form current_form;
Field current_field;

void add_attribute(const char *attr) {
    if (current_field.attr_count < 50) {
        current_field.attributes[current_field.attr_count++] = strdup(attr);
    }
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

%}

%union {
    char *str;
    double num;
}

// Token Declarations
%token FORM META SECTION FIELD VALIDATE IF ERROR TRUE FALSE
%token TEXT TEXTAREA NUMBER EMAIL DATE CHECKBOX DROPDOWN RADIO PASSWORD FILE_INPUT
%token REQUIRED PATTERN DEFAULT MIN MAX ROWS COLS OPTIONS
%token LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA COLON EQUALS
%token LT GT EQ NE LE GE
%token <str> IDENTIFIER STRING
%token <num> NUMBER

// Non-terminal Type Declarations
%type <str> field_type string_list form
%type <num> expression

%%

program:
    form { /* Program complete */ }
;

form:
    FORM IDENTIFIER LBRACE meta_list section_list validate_block RBRACE
    {
        current_form.name = strdup($2);
        current_form.section_count = 0;
        current_form.meta_count = 0;
        $$ = $2;
    }
;

meta_list:
    /* empty */
    | meta_list meta_stmt
;

meta_stmt:
    META IDENTIFIER EQUALS STRING SEMICOLON
    {
        if (current_form.meta_count < 50) {
            current_form.meta[current_form.meta_count++] = strdup($4);
        }
    }
;

section_list:
    /* empty */
    | section_list section_stmt
;

section_stmt:
    SECTION IDENTIFIER LBRACE field_list RBRACE
;

field_list:
    /* empty */
    | field_list field_stmt
;

field_stmt:
    FIELD IDENTIFIER COLON field_type attributes SEMICOLON
    {
        current_field.name = strdup($2);
        current_field.type = strdup($4);
        current_field.attr_count = 0;
    }
;

field_type:
    TEXT { $$ = strdup("text"); }
    | TEXTAREA { $$ = strdup("textarea"); }
    | NUMBER { $$ = strdup("number"); }
    | EMAIL { $$ = strdup("email"); }
    | DATE { $$ = strdup("date"); }
    | CHECKBOX { $$ = strdup("checkbox"); }
    | DROPDOWN { $$ = strdup("dropdown"); }
    | RADIO { $$ = strdup("radio"); }
    | PASSWORD { $$ = strdup("password"); }
    | FILE_INPUT { $$ = strdup("file"); }
;

attributes:
    /* empty */
    | attributes attribute
;

attribute:
    PATTERN EQUALS STRING
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "pattern=%s", $3);
        add_attribute(buf);
        free($3);
    }
    | DEFAULT EQUALS STRING
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "value=%s", $3);
        add_attribute(buf);
        free($3);
    }
    | REQUIRED
    {
        add_attribute("required");
    }
    | MIN EQUALS NUMBER
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "min=%f", $3);
        add_attribute(buf);
    }
    | MAX EQUALS NUMBER
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "max=%f", $3);
        add_attribute(buf);
    }
;

string_list:
    STRING { $$ = strdup($1); free($1); }
    | string_list COMMA STRING
    {
        char *temp = malloc(strlen($1) + strlen($3) + 2);
        sprintf(temp, "%s,%s", $1, $3);
        free($1);
        free($3);
        $$ = temp;
    }
;

validate_block:
    /* empty */
    | VALIDATE LBRACE validation_rules RBRACE
;

validation_rules:
    /* empty */
    | validation_rules validation_rule
;

validation_rule:
    IF expression ERROR STRING SEMICOLON
;

expression:
    TRUE { $$ = 1; }
    | FALSE { $$ = 0; }
    | NUMBER { $$ = $1; }
;

%%

int main() {
    yyparse();
    return 0;
}