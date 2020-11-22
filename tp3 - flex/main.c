/*
	TP 3 - Scanner con la herramienta Flex
	
	Curso K2004
	
	Grupo: 12
	
	Alumnos:
		- Bernardo Gabito Brodsky
			Legajo: 171653-0
		- Julia Martí
			Legajo: 171834-4
		- Nicolas Lofuto
			Legajo: 172840-4

*/

#include "scanner.h"

TOKEN t;
char *tokens[] = {"Fin de Archivo", "Asignación", "Programa", "Fin-Prog", "Declarar", "Leer", "Escribir", "Identificador", "Constante"};

int main(){
	
	do{
		t = yylex();
		if(t <= ESCRIBIR){
	       printf("Token: %s \n",tokens[t]);
	    }else if(t==IDENTIFICADOR || t == CONSTANTE){
	       printf("Token: %s\t lexema: %s\n",tokens[t], yytext);
	    }else{
        	printf("Token: \'%c\'\n",t);
      	}
	}while(t!=FDT);
	
	return 0;
}
