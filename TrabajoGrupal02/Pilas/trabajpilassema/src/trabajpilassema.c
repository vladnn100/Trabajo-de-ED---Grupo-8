#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define max_array 5
typedef struct{
	short int tope;
	short int vector[max_array];
}stack;
void crearpila(stack *pila){
	pila->tope=-1;

}
int vacia(stack *pila){
	if(pila->tope==-1){
		return true;
	}else{
		return false;
	}

}
int llena(stack *pila){
	if(pila->tope==max_array -1){
		return true;
	}else{
		return false;
	}

}
void agregar(stack *pila,int n){
	if (!llena(pila)){
		pila->tope++;
		pila->vector [pila->tope]=n;
		printf("se ha metido el elemento:%i",pila->vector[pila->tope]);
	}else{
		printf("la lista esta llena");
	}
}
void borrar(stack *pila){
	if(!vacia(pila)){
		int tmp=pila->tope;
		pila->tope--;
		printf("se extrae el ultimo elemento %i\n",pila->vector[tmp]);
	}else{
		printf("la lista esta vacia");
	}
}
int ultimo(stack *pila){
	return pila->vector[pila->tope];
}
void mostrar(stack *pila){
	if(!vacia(pila)){
			while(!vacia(pila)){
				printf("%d\n",pila->vector[pila->tope]);
				pila->tope=pila->tope+1;
			}

	}else{
		printf("lista vacia");
	}

}
int main() {
	 stack pila;
	 crearpila(&pila);
	 int n;
	 int opc;
	 int salir=0;

	 while(salir==0){
		 printf("\nInserte la operacion :\n");
		 printf("\(1)Salir  (2)ingresar elemento a la pila (3)eliminar valor   (4)muestra el ultimo elemento \n");

		 fflush(stdout);
		scanf("%d",&opc);
		switch(opc){
		case 1:
					salir=1;
					break;

		case 2:
			printf("elemento a agregar:");
						fflush(stdout);
						scanf("%d",&n);
						 agregar(&pila,n);

			 break;
		case 3:
			borrar(&pila);
			printf("el ultimo valor es:%d\n",ultimo(&pila));

			break;
		case 4:

			printf("el ultimo valor es: %d\n",ultimo(&pila));
			break;

	 }
	 }

	return 0;
}
