%{
#include <stdio.h>
#include <stdlib.h>
#include "exp.h"

/* External declarations */
void yyerror(const char* s);
extern int yylex(void);
extern FILE* yyin;

/* Error flag */
int syntax_error = 0;
%}

%union {
    int value;
    struct node* n;
}

%token <value> NUM
%token AND OR NOT
%token LE GE EQ NE LT GT
%token OPAR CPAR

%left OR
%left AND
%right NOT
%left LT LE GT GE EQ NE

%type <n> program expr

%start program

%%
program:
    expr YYEOF { 
        if (!syntax_error) {
            printf("Valid syntax\n");
            printf("AST:\n");
            print_tree($1, 4);  // Print the AST starting from the root node ($1)
            
            // Print the result of evaluating the AST
            if (evaluate_tree($1)) {
                printf("Result: true\n");
            } else {
                printf("Result: false\n");
            }
        }
    }
;

expr:
      NUM                              { $$ = create_num_node($1); }
    | expr AND expr                    { $$ = create_binary_node('A', $1, $3); }  // 'A' for AND
    | expr OR expr                     { $$ = create_binary_node('O', $1, $3); }  // 'O' for OR
    | NOT expr                         { $$ = create_binary_node('X', $2, NULL); } // 'X' for NOT
    | expr LT expr                     { $$ = create_binary_node('L', $1, $3); }  // 'L' for LT
    | expr LE expr                     { $$ = create_binary_node('l', $1, $3); }  // 'l' for LE
    | expr GT expr                     { $$ = create_binary_node('G', $1, $3); }  // 'G' for GT
    | expr GE expr                     { $$ = create_binary_node('g', $1, $3); }  // 'g' for GE
    | expr EQ expr                     { $$ = create_binary_node('E', $1, $3); }  // 'E' for EQ
    | expr NE expr                     { $$ = create_binary_node('e', $1, $3); }  // 'e' for NE
    ;

%%
void yyerror(const char* s) {
    fprintf(stderr, "Invalid syntax\n");
    syntax_error = 1;
}

int main(void) {
    yyin = fopen("testing.txt", "r"); 
    int result = yyparse();
    fclose(yyin);

    if (syntax_error || result != 0) {
        return 1;
    }
    return 0;
}