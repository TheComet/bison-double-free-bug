%{
    /* Required for <=bison-3.5 */
    #include "bison-bug/parser.y.h"
    #include <stdio.h>
    
    void yyerror(const char* msg);
%}

%define api.pure full
%define api.push-pull push
%define parse.error verbose
%define api.token.prefix {TOK_}
%define api.header.include {"bison-bug/parser.y.h"}

%union {
    char* string;
}

%destructor { printf("destructor: %s\n", $$); free($$); } <string>

%token<string> STRING
%token ';'

%%
root:
    STRING ';' { free($1); }
  ;
%%

void yyerror(const char* msg)
{
}
