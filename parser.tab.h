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
     TRUE = 265,
     FALSE = 266,
     TEXT = 267,
     TEXTAREA = 268,
     NUMBER = 269,
     EMAIL = 270,
     DATE = 271,
     CHECKBOX = 272,
     DROPDOWN = 273,
     RADIO = 274,
     PASSWORD = 275,
     FILE_INPUT = 276,
     REQUIRED = 277,
     PATTERN = 278,
     DEFAULT = 279,
     MIN = 280,
     MAX = 281,
     ROWS = 282,
     COLS = 283,
     OPTIONS = 284,
     LBRACE = 285,
     RBRACE = 286,
     LBRACKET = 287,
     RBRACKET = 288,
     SEMICOLON = 289,
     COMMA = 290,
     COLON = 291,
     EQUALS = 292,
     LT = 293,
     GT = 294,
     EQ = 295,
     NE = 296,
     LE = 297,
     GE = 298,
     IDENTIFIER = 299,
     STRING = 300
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
#define TRUE 265
#define FALSE 266
#define TEXT 267
#define TEXTAREA 268
#define NUMBER 269
#define EMAIL 270
#define DATE 271
#define CHECKBOX 272
#define DROPDOWN 273
#define RADIO 274
#define PASSWORD 275
#define FILE_INPUT 276
#define REQUIRED 277
#define PATTERN 278
#define DEFAULT 279
#define MIN 280
#define MAX 281
#define ROWS 282
#define COLS 283
#define OPTIONS 284
#define LBRACE 285
#define RBRACE 286
#define LBRACKET 287
#define RBRACKET 288
#define SEMICOLON 289
#define COMMA 290
#define COLON 291
#define EQUALS 292
#define LT 293
#define GT 294
#define EQ 295
#define NE 296
#define LE 297
#define GE 298
#define IDENTIFIER 299
#define STRING 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 40 "parser.y"
{
    char *str;
    double num;
}
/* Line 1529 of yacc.c.  */
#line 144 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

