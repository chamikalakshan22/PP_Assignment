/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FORM = 258,
     META = 259,
     SECTION = 260,
     FIELD = 261,
     VALIDATE = 262,
     IF = 263,
     ERROR = 264,
     TEXT = 265,
     TEXTAREA = 266,
     NUMBER_TYPE = 267,
     EMAIL = 268,
     DATE = 269,
     CHECKBOX = 270,
     DROPDOWN = 271,
     RADIO = 272,
     PASSWORD = 273,
     FILE_FIELD = 274,
     REQUIRED = 275,
     PATTERN = 276,
     DEFAULT = 277,
     MIN = 278,
     MAX = 279,
     ROWS = 280,
     COLS = 281,
     OPTIONS = 282,
     ACCEPT = 283,
     LBRACE = 284,
     RBRACE = 285,
     LBRACKET = 286,
     RBRACKET = 287,
     LPAREN = 288,
     RPAREN = 289,
     SEMICOLON = 290,
     COMMA = 291,
     COLON = 292,
     EQUALS = 293,
     LT = 294,
     GT = 295,
     LE = 296,
     GE = 297,
     EQ = 298,
     NE = 299,
     IDENTIFIER = 300,
     STRING = 301,
     NUMBER = 302,
     BOOLEAN = 303
   };
#endif
/* Tokens.  */
#define FORM 258
#define META 259
#define SECTION 260
#define FIELD 261
#define VALIDATE 262
#define IF 263
#define ERROR 264
#define TEXT 265
#define TEXTAREA 266
#define NUMBER_TYPE 267
#define EMAIL 268
#define DATE 269
#define CHECKBOX 270
#define DROPDOWN 271
#define RADIO 272
#define PASSWORD 273
#define FILE_FIELD 274
#define REQUIRED 275
#define PATTERN 276
#define DEFAULT 277
#define MIN 278
#define MAX 279
#define ROWS 280
#define COLS 281
#define OPTIONS 282
#define ACCEPT 283
#define LBRACE 284
#define RBRACE 285
#define LBRACKET 286
#define RBRACKET 287
#define LPAREN 288
#define RPAREN 289
#define SEMICOLON 290
#define COMMA 291
#define COLON 292
#define EQUALS 293
#define LT 294
#define GT 295
#define LE 296
#define GE 297
#define EQ 298
#define NE 299
#define IDENTIFIER 300
#define STRING 301
#define NUMBER 302
#define BOOLEAN 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 68 "parser.y"
{
    char *str;
    double num;
    int boolean;
}
/* Line 1529 of yacc.c.  */
#line 151 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

