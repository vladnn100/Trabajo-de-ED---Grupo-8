
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct nodo{
int dato;
struct nodo*siguiente;

}nodo;
nodo* primero=NULL;
nodo* ultimo=NULL;
void insertarvalores();
void mostrarvalores();
void sumarvalores();


int main()
{
 int n;
printf("cuantos elementos va a tener la lista:\n");
scanf("%d",&n);
for(int i=1;i<=n;i++){
   insertarvalores();
}
mostrarvalores();
sumarvalores();


   system("pause");
   return(0);
}
void insertarvalores(){
nodo* nuevo=(nodo*) malloc(sizeof(nodo));
printf("ingrese dato :");
scanf("%d",&nuevo->dato);
if(primero==NULL){
  primero=nuevo;
  primero->siguiente=NULL;
  ultimo=nuevo;
}else{
  ultimo->siguiente=nuevo;
  nuevo->siguiente=NULL;
  ultimo=nuevo;

}
}
void mostrarvalores(){
nodo* actual=(nodo*) malloc(sizeof(nodo));
printf("\n---------------los valores de la lista son:---------------------\n");
actual=primero;
if(primero!=NULL){
while(actual!=NULL){
printf("%d\n",actual->dato);
actual=actual->siguiente;
}
}else {
printf("lista vacia >:v");
}

}
void sumarvalores(){
printf("\n---------------Media de los valores de la lista ---------------------\n");
nodo* actual=(nodo*) malloc(sizeof(nodo));
actual=primero;
float suma=0,media,contador=0;
if(primero!=NULL){
while(actual!=NULL){
   suma=suma+actual->dato;
   actual=actual->siguiente;
   contador=contador+1;
}
media=suma/contador;
printf("\nLa media es: %f\n",media);
}else{
printf("\nlista vacia >:v\n");
printf("\n La media: NULL\n");
}



}
