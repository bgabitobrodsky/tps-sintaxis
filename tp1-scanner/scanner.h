#ifndef SCANNER_HEADER
#define SCANNER_HEADER

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum{IDENTIFICADOR, CONSTANTE_ENTERA, NUMERAL, ERROR, FDT} TOKEN; 

TOKEN aceptarToken(int e);
int proximoEstado();
TOKEN scanner();
bool deboParar(int estado);

#include "scanner.c"

#endif
