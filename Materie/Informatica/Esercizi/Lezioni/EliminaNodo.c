//CREAZIONE DI UNA LISTA IN TESTA E CANCELLAZIONE DI UN ELEMENTO DALLA LISTA	
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
void eliminaTesta(pN lista){
	pN pUltimo, pPultimo;
	int i=1;
	pUltimo=NULL;
	pPultimo=NULL;
	printf("\nSono in elimina testa");
	if(lista==NULL){
		free(lista);
		printf("\nLista inesistente ");
	}
	else {
		//supponiamo di voler eliminare il terzo elemento
		pUltimo=lista;
		pPultimo=lista;
		pUltimo=pUltimo->next;
		i++;
		while(pUltimo!=NULL && i!=3){
			i++;
			pUltimo=pUltimo->next;
			pPultimo=pPultimo->next;
		}
		pPultimo->next=pUltimo->next;
		free(pUltimo);			
	}
}
main(){
	pN pTesta;	//puntatore alla testa della lista
	pN pNodo; 	//puntatore al generico nodo
	//così per l'inserimento anche per la cancellazione di un nodo dalla lista 
	//abbiamo bisogno di un puntatore temporaneo pTemp 
	//PRIMA ABBIAMO LA CREAZIONE DELLA LISTA DALLA TESTA
	pTesta=NULL;
	pNodo=NULL;
	int i, n=0;
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
	//PASSIAMO ADESSO ALL'ELIMINAZIONE DI UN NODO DALLA TESTA
	eliminaTesta(pTesta);
	stampaLista(pTesta);
}
