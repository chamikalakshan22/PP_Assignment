%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
%}

%%

"form"      { return FORM; }
"meta"      { return META; }
"section"   { return SECTION; }
"field"     { return FIELD; }
"validate"  { return VALIDATE; }
"if"        { return IF; }
"error"     { return ERROR; }
"true"      { return TRUE; }
"false"     { return FALSE; }
"text"      { return TEXT; }
"textarea"  { return TEXTAREA; }
"number"    { return NUMBER; }
"email"     { return EMAIL; }
"date"      { return DATE; }
"checkbox"  { return CHECKBOX; }
"dropdown"  { return DROPDOWN; }
"radio"     { return RADIO; }
"password"  { return PASSWORD; }
"file"      { return FILE_INPUT; }
"required"  { return REQUIRED; }
"pattern"   { return PATTERN; }
"default"   { return DEFAULT; }
"min"       { return MIN; }
"max"       { return MAX; }
"rows"      { return ROWS; }
"cols"      { return COLS; }
"options"   { return OPTIONS; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"["         { return LBRACKET; }
"]"         { return RBRACKET; }
";"         { return SEMICOLON; }
","         { return COMMA; }
":"         { return COLON; }
"="         { return EQUALS; }
"<"         { return LT; }
">"         { return GT; }
"=="        { return EQ; }
"!="        { return NE; }
"<="        { return LE; }
">="        { return GE; }

[a-zA-Z][a-zA-Z0-9_]*   { yylval.str = strdup(yytext); return IDENTIFIER; }
\"[^\"]*\"               { yylval.str = strdup(yytext); return STRING; }
[0-9]+(\.[0-9]+)?       { yylval.num = atof(yytext); return NUMBER; }

[ \t\n]+                { /* Ignore whitespace */ }
.                       { fprintf(stderr, "Invalid character: %s\n", yytext); }

%%

int yywrap() { return 1; }
