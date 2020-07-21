/*
 ============================================================================
 Grupo 		 : 8
 Name        : PE_37.c
 Description : 37. Write a program to create a header linked list.
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node* next;
};

struct node *iniNod=NULL;

void addNod(int data);
void showNod();

int main(){

	int val;
	printf("\nInsertar valores a la header linked list : \n");
	printf("(-1)Salir\n");
	do{
		fflush(stdout);
		scanf("%d",&val);
		addNod(val);
	}while(val!=-1);
	printf("\nSe creo satisfactoriamente la lista");
	printf("\nToda la lista : ");
	showNod();

	return 0;
}


void addNod(int data){
	struct node *newNod, *aux;
	newNod=(struct node*)malloc(sizeof(struct node));
	newNod->data=data;
	newNod->next=NULL;

	if(iniNod==NULL){
		iniNod=newNod;
	}else{
		aux=iniNod;
		while(aux->next!=NULL){

			aux=aux->next;
		}
		aux->next=newNod;
	}
}


void showNod(){
	struct node *aux;
	aux=(struct node*)malloc(sizeof(struct node));
	aux=iniNod;
	if(iniNod==NULL){
		printf("\nLista vacia, nada para mostrar\n");
	}else{
		while(aux->next!=NULL){
			printf("%d ",aux->data);
			aux=aux->next;
		}
	}

}
