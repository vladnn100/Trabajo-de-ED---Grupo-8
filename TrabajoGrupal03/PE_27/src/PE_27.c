/*
 ============================================================================
 Name        : PE_27.c
 Grupo 		 : 8
 Description : 27. Write a program to count the number of non-zero
values in a circular linked list.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int dato;
	struct node *next;
};



struct node *iniNod=NULL;
struct node *endNod=NULL;


void addNod(int data);
void showLs();
int countNoZero();


int main() {
	int val;
	printf("\nInsertar valores al nodo\n");
	printf("(-1)Salir\n");
	do{
		fflush(stdout);
		scanf("%d",&val);
		if(val==-1){
			break;
		}else{
			addNod(val);

		}

	}while(val!=-1);
	showLs();
	printf("\n Cantidad de valores no ceros : %d\n",countNoZero());

	return 0;
}


void addNod(int data){
	struct node *newNod=(struct node*)malloc(sizeof(struct node));
	newNod->dato=data;
	if(iniNod==NULL){
		iniNod=newNod;
		endNod=newNod;
		newNod->next=iniNod;
	}else{
		endNod->next=newNod;
		endNod=newNod;
		endNod->next=iniNod;
	}

}



void showLs(){
	struct node *actual=(struct node*)malloc(sizeof(struct node));
	actual = iniNod;
	if(iniNod==NULL){
		printf("\nLista vacia\n");
	}else{
		printf("\nList : \n");
		do{
			printf("%d ",actual->dato);
			actual=actual->next;
		}while(actual!=iniNod);
	}
}


int countNoZero(){
	int cont=0;
	struct node *actual=(struct node*)malloc(sizeof(struct node));
	actual = iniNod;
	if(iniNod==NULL){
		printf("\nLista vacia\n");
		return 0;
	}else{
		do{
			if(actual->dato!=0){
				cont++;
			}
			actual=actual->next;
		}while(actual!=iniNod);
		return cont;
	}

}
