%{
    /* Required for <=bison-3.5
    #include "bison-bug/parser.y.h"
    #include <stdio.h>
    
    void yyerror(const char* msg);
%}

%define api.pure full
%define api.push-pull push
%define parse.error verbose
%define api.header.include {"bison-bug/parser.y.h"}

%union {
    char* string;
}

%destructor { free($$); } <string>

%token<string> STRING
%token ','

%%
root:
    STRING ',' STRING { str_free($1); str_free($3); }
  ;
%%

void yyerror(const char* msg)
{
}
