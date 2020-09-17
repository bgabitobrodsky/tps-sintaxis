#include "scanner.h"

int estado;         //L   D   #  FDT ESP OTRO
int estados[9][6]={ { 1,  2,  4,  7,  0,  3}, //estado inicial
					{ 1,  1,  5,  5,  5,  5}, //reconociendo identificador
					{ 6,  2,  6,  6,  6,  6}, //reconociendo constantes enteras
					{ 8,  8,  8,  8,  8,  3}, //reconociendo error lexico
					{99, 99, 99, 99, 99, 99}, //reconociendo numeral
					{99, 99, 99, 99, 99, 99}, //identificador reconocido
					{99, 99, 99, 99, 99, 99}, //constante entera reconocida
					{99, 99, 99, 99, 99, 99}, //fdt reconocido
					{99, 99, 99, 99, 99, 99}  //error lexico reconocido
};
char c;

int proximoEstado(){
	if(isalpha(c))
    	return estados[estado][0];
  	else if(isdigit(c))
    	return estados[estado][1];
    else if(c == '#')
    	return estados[estado][2];
  	else if (c == EOF )
    	return estados[estado][3];
  	else if(isspace(c))
    	return estados[estado][4];
    	
    return estados[estado][5];
}

TOKEN aceptarToken(int e){
	switch(e){
		case 4:
			return NUMERAL;
		case 5:
			ungetc(c,stdin);
			return IDENTIFICADOR;
		case 6:
			ungetc(c,stdin);
			return CONSTANTE_ENTERA;
		case 7: 
			return FDT;
		case 8:
			ungetc(c,stdin);
			return ERROR;
	}
	return ERROR;
}

TOKEN scanner(){
	estado = 0;
	do{
		c = getchar();
		estado = proximoEstado(c);
	}while(!deboParar(estado));
	
	return aceptarToken(estado);
}

bool deboParar(int e){
	return e > 3;
}
