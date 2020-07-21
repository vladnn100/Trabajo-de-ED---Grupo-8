/*
 ============================================================================
 Name        : T3_PE_12.c
 Author      : grupo 8
 Description : :Write a program to input two queue and compare their contents
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node *next;
};



struct cola{
	struct node *front;
	struct node *rear;
};

struct cola *cola1;
struct cola *cola2;


struct cola *encolar(struct cola *,int val);
struct cola *crear(struct cola *aux);
struct cola *desencolar(struct cola *);
void displayCola(struct cola *);
void comparacionNum(struct cola *,struct cola *);


int main() {
	int gameOver=0;
	int opc=-1;
	int val=-1;
	cola1=crear(cola1);
	cola2=crear(cola2);
	do{
		printf("\nSelecione la cola\n");
		printf("(0)Salir  (1)Cola 1  (2)Cola 2\n");
		fflush(stdout);
		scanf("%d",&opc);
		switch(opc){
			case 0:
				gameOver=1;
				break;
			case 1:
				printf("\nSelecione la operacion para la cola\n");
				printf("(1)Colar  (2)Desencolar  (3)Mostrar   (4)Comparar con la cola 2\n");
				fflush(stdout);
				scanf("%d",&opc);

				switch(opc){
					case 1:

						printf("\nInsetar los valores a colar\n");
						printf("(-1)Salir\n");
						do{
							fflush(stdout);
							scanf("%d",&val);
							if(val==-1){
								break;
							}else{
								cola1=encolar(cola1,val);

							}
						}while(val!=-1);

						break;
					case 2:
						cola1=desencolar(cola1);
						break;
					case 3:
						displayCola(cola1);
						break;
					case 4:
						comparacionNum(cola1,cola2);
				}
				break;
				//Cola 2
			case 2:
				printf("\nSelecione la operacion para la cola\n");
				printf("(1)Colar  (2)Desencolar  (3)Mostrar   (4)Comparar con la cola 1\n");
				fflush(stdout);
				scanf("%d",&opc);

				switch(opc){
					case 1:

						printf("\nInsetar los valores a colar\n");
						printf("(-1)Salir\n");
						do{
							fflush(stdout);
							scanf("%d",&val);
							if(val==-1){
								break;
							}else{
								cola2=encolar(cola2,val);

							}
						}while(val!=-1);

						break;
					case 2:
						cola2=desencolar(cola2);
						break;
					case 3:
						displayCola(cola2);
						break;
					case 4:
						comparacionNum(cola1,cola2);
				}
				break;

				break;
		}

	}while(gameOver==0);

	return 0;
}

struct cola *crear(struct cola *aux){
	aux=(struct cola *)malloc(sizeof(struct cola));
	aux->front=NULL;
	aux->rear=NULL;
	return aux;
}

struct cola *encolar(struct cola *aux,int val){
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	if(aux->front==NULL){
		aux->rear=ptr;
		aux->front=ptr;
		aux->front->next=NULL;
		aux->rear->next=NULL;

	}else{

		aux->rear->next=ptr;
		aux->rear=ptr;
		aux->rear->next=NULL;
	}

	return aux;
}


struct cola *desencolar(struct cola *aux){
	struct node *ptr;
	ptr=aux->front;
	if(aux->front==NULL){
		printf("\nCola vacia\n");
	}else{
		aux->front=aux->front->next;
		printf("\nValor desencolado : %d\n",ptr->data);
		free(ptr);
	}
	return aux;
}

void displayCola(struct cola *aux){
	struct node *ptr;
	ptr=aux->front;
	if(ptr==NULL){
		printf("\nNada para mostrar\n");
	}else{
		printf("\n");
		printf("Valores de la cola :\n");
		while(ptr!=aux->rear){
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		printf("%d ",ptr->data);

	}
}

void comparacionNum(struct cola *aux1,struct cola *aux2){

	int cant;
	int cant1=0;
	int cant2=0;
	struct node *ptr1;
	struct node *ptr2;
	ptr1=aux1->front;
	ptr2=aux2->front;
	if(aux1->front!=NULL){
		while(ptr1!=aux1->rear){
			ptr1=ptr1->next;
			cant1++;
		}
		cant1++;
	}else{
		cant1=0;
	}
	if(aux2->front!=NULL){
		while(ptr2!=aux2->rear){
			ptr2=ptr2->next;
			cant2++;
		}
		cant2++;
	}else{
		cant2=0;
	}



	printf("\nSize cola 1 = % d     Size cola 2 = %d",cant1,cant2);
	if(cant2>cant1){
		printf("\nLa cola 2 es mayor que la cola 1\n");

		cant=cant2-cant1;
	}else if(cant1>cant2){
		printf("\nLa cola 1 es mayor que la cola 2\n");

		cant=cant1-cant2;
	}else{
		printf("\nLas colas tiene igual size\n");
		cant=0;
	}

	printf("La diferencia es = %d\n",cant);
}
