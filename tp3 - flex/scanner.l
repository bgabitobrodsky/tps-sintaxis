%top{
	#include "tokens.h"
}

%option header-file="scanner.h"
%option outfile="scanner.c"
%option noinput
%option nounput

LETRA			[[:alpha:]]
DIGITO			[[:digit:]]
LETRAoDIGITO		[[:alnum:]]
ASIGNACION		<-
ESPACIO  		[[:space:]]
COMENTARIO		"##".*
OTRO  			[[:punct:]]{-}[(),+\-*/;]

%%

programa		return INICIO;
fin-prog		return FIN;
declarar		return DECLARAR;
leer			return LEER;
escribir 		return ESCRIBIR;
{LETRA}{LETRAoDIGITO}*	return IDENTIFICADOR;
{DIGITO}+		return CONSTANTE;
"("|")"|","|"+"|"-"|"*"|"/"|";"	return *yytext;
{ASIGNACION}		return ASIGNACION;
{OTRO}+		printf("Error Léxico: cadena desconocida: %s\n", yytext);
{LETRA}{LETRAoDIGITO}*{OTRO}+({LETRAoDIGITO}|{OTRO})*	printf("Error Léxico: identificador inválido: %s\n",yytext);
{DIGITO}+{LETRA}+{LETRAoDIGITO}*				printf("Error Léxico: constante inválida: %s\n",yytext);
{ESPACIO}+		|
{COMENTARIO}		|
.
