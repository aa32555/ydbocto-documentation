%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);
%}

%require "3.0"
%debug

%token PLUS
%token MINUS
%token MULT
%token DIV
%token LITERAL


%%

expr
  : term
  ;


term
  : factor
  | term PLUS factor
  | term MINUS factor
  ;

factor
  : LITERAL
  | factor MULT LITERAL
  | factor DIV LITERAL
  ;

%%

int main() {
  yyin = stdin;
  yydebug = 1;

  do {
    yyparse();
  } while(!feof(yyin));
  return 0;
}

void yyerror(const char *s) {
  fprintf(stderr, "error: %s\n", s);
}
