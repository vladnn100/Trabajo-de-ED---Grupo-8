#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct nodo{
int dato;
struct nodo*siguiente;

}nodo;
nodo* primero=NULL;
nodo* ultimo=NULL;

void mostrar();
void insertarnodo();
void eliminar();
int main(void) {
	for(int i=1;i<=10;i++){
		insertarnodo();
	}


	int opc;

		do {
			printf("\n\n MENU ");
			printf("\n 1.insertar un elemento");
			printf("\n 2. mostrar la cola");
			printf("\n 3.eliminar un elemento");
			printf("\n 4.salir");
			printf("\n escoja una opcion ");
			fflush(stdout);
			scanf("%d",&opc);
			switch(opc){
			case 1:

				insertarnodo();
				break;

			case 2:
				mostrar();
				break;
            case 3:
				eliminar();
				break;


			}
		}while(opc!=4);

		getch();
		return 0;


	return 0;
}
void insertarnodo(){
nodo* nuevo=(nodo*) malloc(sizeof(nodo));
printf("\n elemento: ");
fflush(stdout);
scanf("%d",&nuevo->dato);
if(primero==NULL){
   primero=nuevo;
   primero->siguiente =NULL;
   ultimo=nuevo;
}else{
   ultimo->siguiente=nuevo;
   nuevo->siguiente=NULL;
   ultimo=nuevo;
}
}
void mostrar(){
	nodo* actual=(nodo*) malloc(sizeof(nodo));
	actual=primero;
	if(actual!=NULL){
		while(actual!=NULL){
			printf("%d \n",actual->dato);
			actual=actual->siguiente;
		}

	}else{
		printf("la cola no existe\n");
	}
}
void eliminar(){
	    nodo* actual=(nodo*) malloc(sizeof(nodo));
		nodo*temp;
		actual=primero;
if(actual== NULL)
printf("\n esta vacio");
else
{
temp=actual;
primero=primero->siguiente ;
actual=actual->siguiente;
printf("\n el valor eliminado : %d", temp->dato);
temp=NULL;
}

}
