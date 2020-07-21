/*
 ============================================================================
 Name        : Pilas.c
 Autores     : Grupo 8
 Description : Modelagem da Pilha com Vetor - Trabalho 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXPILA 30
const int ERRORPILALLENA=-1;
const int ERRORPILAVACIA=-2;

typedef struct pila{
	int data[MAXPILA];
	int head;

}pila;


pila aPila;

void iniPila();
int addPila(int dato);

int main() {
	int opc;
	int val;
	int salir=0;

	while(salir==0){
		printf("\nInserte la operacion :\n");
		printf("\(0)Salir   (1)Apilar   (2)Desapilar   (3)Limpiar   (4)Mostrar\n");
		fflush(stdout);
		scanf("%d",&opc);
		switch(opc){
		case 0:
			salir=1;
			break;
		case 1:
			printf("\nInsertar valores en la pila: \n");
			printf("(-1)Salir\n");
			do{
				fflush(stdout);
				scanf("%d",&val);

				if(addPila(val)==ERRORPILALLENA){
					break;
				}else{
					continue;
				}
			}while(val!=-1);
			printf("\nSe agregaron los valores satisfactoriamente");

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;


		}

	}




	return 0;
}


void iniPila(){
	aPila.head=-1;
}

int addPila(int dato){
	return -2;
}
