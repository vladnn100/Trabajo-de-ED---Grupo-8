/*
 ============================================================================
 Name        : Cola_1.c
 Author      : grupo 8
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 ============================================================================
 Name        : PilasEjemplo.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXFILA 20

typedef char arr[40];

typedef struct Cola
{
	char arr[40];
	int p,q;
} Cola;

Cola variableglobal;

Cola colaCreate(){
	Cola cola;
	cola.p=-1;
	cola.q=-1;
	return cola;
};

void colaEncolar( char c){
	variableglobal.q=(variableglobal.q+1)%MAXFILA;
	variableglobal.arr[variableglobal.q]=c;
	if (variableglobal.p < 0){
		variableglobal.p = variableglobal.q;
	}
}

char colaDesencolar(){
	char aux = variableglobal.arr[variableglobal.p+1];
	if(variableglobal.p==variableglobal.q){
		variableglobal.p = -1;
	}
	else {
	variableglobal.p=(variableglobal.p+2)%MAXFILA;
	}
	return aux;
}

void mostrarCola(){
	int valor=variableglobal.p;
	if(variableglobal.p==-1){
		printf("Lista vacia");
	}
	while(variableglobal.q!=valor-1){
		printf("%c ",variableglobal.arr[valor]);
		valor++;
	}
}

bool colaEsvacia(Cola cola){
	if(variableglobal.p<0)return true;
	else return false;
}



int main() {

	variableglobal = colaCreate();
	int opc;
	char val;
	int salir=0;

	while(salir==0){
		printf("\nInserte la operacion :\n");
		printf("\(0)Salir   (1)Colar   (2)Desencolar   (3)Mostrar   (4)Limpiar\n");
		fflush(stdout);
		scanf("%d",&opc);
		switch(opc){
		case 0:
			salir=1;
			break;
		case 1:
			printf("\nInsertar valores en la Cola: \n");
			printf("(s)Salir\n");
			do{
				fflush(stdout);
				scanf("%c",&val);
				if(val=='s'){
					break;
				}else{
					colaEncolar(val);
				}
			}while(val!='s');
			printf("\nSe agregaron los valores satisfactoriamente");

			break;
		case 2:

			printf("\nDesencolado correctamente : ");
			printf("%c",colaDesencolar());

			break;
		case 3:

			mostrarCola();

			break;
		case 4:
			variableglobal = colaCreate();

			printf("\n Se limpio correctamente\n");
			break;


		}

	}












	return 0;
 }
