//CREAZIONE DI UNA LISTA IN TESTA	
#include <stdio.h>
#include <stdlib.h>
struct s_nodo{
	int info;
	struct s_nodo *next;
};
typedef struct s_nodo nodo;		//nodo della lista
typedef nodo *pN;				//puntatore al nodo

void stampaLista(pN lista){
	while(lista!=NULL){
		printf("\n%d", lista->info);
		lista=lista->next;
	}
}

void ordina(pN *pointer)
{
int k;
pN *punt=pointer,*punt1=pointer,*store;

if ((*pointer==NULL)||( *(pointer->next)==NULL))
else{
do
{
k=0;
while(punt!=NULL)
      {

       punt1=punt;
       punt=punt->next;
       if ((punt1->elem)>=(punt->elem))
       {
          store=punt1;
          punt1=punt;
          punt=store;
          k=1;
       }
       }
}while (k!=0);
//return pointer; 
}
}
main(){
	pN pTesta;	//puntatore alla testa della lista
	pN pNodo; 	//puntatore al generico nodo
	pTesta=NULL;
	pNodo=NULL;
	int i, n=0;
	do{
		printf("Quanti elementi vuoi inserire?");
		scanf("%d",&n);
	}while(n<=0);
	for(i=0; i<n; i++){
		pNodo=malloc(sizeof(nodo));
		pNodo->info=i+1;
		pNodo->next=pTesta;
		pTesta=pNodo;
	}
	printf("\nStampiamo la lista: ");
	stampaLista(pTesta);
	ordina(pTesta);
	stampaLista(pTesta);
}
