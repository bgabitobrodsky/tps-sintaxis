#include "scanner.h"

int main(int argc, char *argv[]) {
	TOKEN t;
	int identificadores = 0, constantes_enteras = 0, numerales = 0, errores = 0;
	do{
		t = scanner();
		if(t == IDENTIFICADOR){
			identificadores++;
			printf("Identificador \n");
		}else if(t == CONSTANTE_ENTERA){
			constantes_enteras++;
			printf("Constante entera \n");
		}else if(t == NUMERAL){
			numerales++;
			printf("Numeral \n");
		}else if(t == ERROR){
			errores++;
			printf("Error \n");
		}
	}while(t != FDT);
	
	printf("----\n");
	printf("Totales:\n");
	printf("Identificadores %d\n",identificadores);
	printf("Constantes enteras %d\n",constantes_enteras);
	printf("Numerales %d\n",numerales);
	printf("Errores %d\n",errores);
	
	return 0;
}
