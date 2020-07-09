/*
 ============================================================================
 Name        : PE_7.c
 Author      : Nick
 Description : 7. Write a program to merge two linked lists.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct nodo {
   int data;
   struct nodo *sig;
};

struct nodo *primero = NULL;
struct nodo *segundo = NULL;
struct node *lista = NULL;


void insert(int data) {
   struct nodo *link = (struct nodo*) malloc(sizeof(struct nodo));
   struct nodo *current;

   link->data = data;
   link->sig = NULL;

   if(data%2 == 0) {
      if(primero == NULL) {
         primero = link;
         return;
      } else {
         current = primero;

         while(current->sig != NULL)
         current = current->sig;

         current->sig = link;
      }

   } else {
      if(segundo == NULL) {
         segundo = link;
         return;
      } else {
         current = segundo;

         while(current->sig!=NULL)
            current = current->sig;

         	current->sig = link;
      }
   }
}

void display(struct nodo *head) {
   struct nodo *ptr = head;

   while(ptr != NULL) {
      printf(" %d",ptr->data);
      ptr = ptr->sig;
   }

   printf("\n");
}

void combinar() {
   struct nodo *link;

   lista = primero;
   link = lista;

   while(link->sig!= NULL) {
      link = link->sig;
   }

   link->sig = segundo;
}

int main() {
   int val=-2;
   printf("\nInserte valores, seran ubicados de la siguiente manera : \n");
   printf("Lista 1 : Los pares\n");
   printf("Lista 2 : Los impares\n");
   printf("(-1) Salir\n");
   while(val!=-1){
	   fflush(stdout);

	   scanf("%d",&val);
	   if(val!=-1){
		   insert(val);
	   }
   }

   printf("Lista 1 : ");
   display(primero);

   printf("Lista 2  : ");
   display(segundo);

   combinar();

   printf("Listas combinadas :");
   display(lista);
   return 0;
}

