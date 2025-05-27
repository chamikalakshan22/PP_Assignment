%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

int line_num = 1;
%}

%option yylineno
%option noyywrap

%%

form                { return FORM; }
meta                { return META; }
section             { return SECTION; }
field               { return FIELD; }
validate            { return VALIDATE; }
if                  { return IF; }
error               { return ERROR; }
true                { yylval.boolean = 1; return BOOLEAN; }
false               { yylval.boolean = 0; return BOOLEAN; }

text                { return TEXT; }
textarea            { return TEXTAREA; }
number              { return NUMBER_TYPE; }
email               { return EMAIL; }
date                { return DATE; }
checkbox            { return CHECKBOX; }
dropdown            { return DROPDOWN; }
radio               { return RADIO; }
password            { return PASSWORD; }
file                { return FILE_FIELD; }

required            { return REQUIRED; }
pattern             { return PATTERN; }
default             { return DEFAULT; }
min                 { return MIN; }
max                 { return MAX; }
rows                { return ROWS; }
cols                { return COLS; }
options             { return OPTIONS; }
accept              { return ACCEPT; }

"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
";"                 { return SEMICOLON; }
","                 { return COMMA; }
":"                 { return COLON; }
"="                 { return EQUALS; }
"<="                { return LE; }
">="                { return GE; }
"=="                { return EQ; }
"!="                { return NE; }
"<"                 { return LT; }
">"                 { return GT; }

[a-zA-Z_][a-zA-Z0-9_]*   { yylval.str = strdup(yytext); return IDENTIFIER; }

\"([^\"\\]|\\.)*\"       { yylval.str = strdup(yytext); return STRING; }

[0-9]+(\.[0-9]+)?        { yylval.num = atof(yytext); return NUMBER; }

[ \t]+                   { /* ignore whitespace */ }
\n                       { line_num++; }
\r\n                     { line_num++; }

.                        { 
    fprintf(stderr, "Lexical error: unexpected character '%c' at line %d\n", yytext[0], line_num); 
    return yytext[0];
}

%%