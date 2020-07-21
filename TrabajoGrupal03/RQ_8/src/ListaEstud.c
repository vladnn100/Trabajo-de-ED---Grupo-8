/*
 ============================================================================
 Name        : ListaEstud.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	char *nombre;
	struct nodo *sig;
} Estudiante;

Estudiante *listaEstudiante(Estudiante *Lista){
	Lista = NULL;
	return Lista;
}

Estudiante *agregarEstudiante(Estudiante *Lista, char *nombre){
	Estudiante *nuevoEstudiante, *aux;
	nuevoEstudiante= (Estudiante*)malloc(sizeof(Estudiante));
	nuevoEstudiante->nombre = nombre;
	nuevoEstudiante->sig = NULL;
	if(Lista == NULL){
		Lista = nuevoEstudiante;
	} else{
		aux = Lista;
		while(aux->sig !=NULL){
			aux = aux->sig;
		}
		aux->sig = nuevoEstudiante;
	}
	return Lista;
}

int main(void) {
	Estudiante *Lista = listaEstudiante(Lista);
	Lista = agregarEstudiante(Lista,"Frank");
	Lista = agregarEstudiante(Lista,"Vladimir");
	while(Lista != NULL){
		printf("%s\n",Lista->nombre);
		Lista = Lista->sig;
	}
	return 0;
}
