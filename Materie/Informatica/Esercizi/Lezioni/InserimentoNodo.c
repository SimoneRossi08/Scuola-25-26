//CREAZIONE DI UNA LISTA IN TESTA CON RANDOM
//inseriamo un elemento in mezzo alla lista	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
main(){
	pN pTesta;	//puntatore alla testa della lista
	pN pNodo; 	//puntatore al generico nodo
	pN pTemp; 	//puntatore temporaneo
	pTesta=NULL;
	pNodo=NULL;
	pTemp=NULL;
	int i, n=0, inserito=0;
	srand(time(NULL));
	do{
		printf("Quanti elementi vuoi inserire?");
		scanf("%d",&n);
	}while(n<=0);
	for(i=0; i<n; i++){
		pNodo=malloc(sizeof(nodo));
		pNodo->info=rand()%100;
		pNodo->next=pTesta;
		pTesta=pNodo;
	}
	printf("\nStampiamo la lista: ");
	stampaLista(pTesta);
	//creiamo il nuovo nodo da inserire nella lista
	pNodo=NULL;
	pNodo=malloc(sizeof(nodo));
	pNodo->info=rand()%100;
	printf("\nIl nuovo nodo creato vale: %d", pNodo->info);
	//scorriamo la lista e cerchiamo l'elemento dove inserire il nodo
	pTemp=pTesta;
	while(pTemp!= NULL && !inserito){
		if	(pTemp->info > pNodo->info){
			pNodo->next=pTemp->next;
			pTemp->next=pNodo;
			inserito=1;
		}
		else
			pTemp=pTemp->next;		
	}
	//stampiamo adesso la nuova lista con il nodo aggiunto
	printf("\nLa lista aggiornata con il nuovo elemento e\': ");
	stampaLista(pTesta);   
}
