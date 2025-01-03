%{
#include "parser.tab.h"
#include <stdlib.h>
extern int syntax_error;
%}

%option noyywrap
%%

"&&"         { return AND; }          // AND Operator 
"||"         { return OR; }           // OR Operator
"!"          { return NOT; }          // NOT Operator

"<="         { return LE; }           // Less equal
">="         { return GE; }           // Greater equal
"=="         { return EQ; }           // Equal
"!="         { return NE; }           // Not Equal
"<"          { return LT; }           // Less Than
">"          { return GT; }           // More than

[0-9]+       { yylval.value = atoi(yytext); return NUM; } 

"("          { return OPAR; }         
")"          { return CPAR; }      

[ \t\n]+
.            {
    syntax_error = 1; 
    perror("Invalid syntax");
    return -1;
}

%%

