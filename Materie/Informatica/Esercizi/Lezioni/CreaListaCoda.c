//CREAZIONE DI UNA LISTA IN CODA	
#include <stdio.h>
#include <stdlib.h>
struct s_nodo{
	int info;
	struct s_nodo *next;
};
typedef struct s_nodo nodo;		//nodo della lista
typedef nodo *pN;				//puntatore al nodo
//FARE PRIMA IL MAIN			
//funzione inserisciCodaLista
void inserisciCodaLista(pN *lista,int dato){
	pN ultimo; 	//puntatore genenrico alla lista che la scorre
	pN pNodo;
	//creazione del nuovo record/nodo
	pNodo = malloc(sizeof(nodo));
	pNodo->info = dato;
	pNodo->next = NULL;
	//troviamo l'ultimo elemento
	if (*lista == NULL)	//caso in cui ancora nessun record sia stato creato
		*lista = pNodo;
	else{
		ultimo = *lista;
		while(ultimo->next != NULL)
			ultimo = ultimo->next;
		ultimo->next = pNodo;	//concateniamo il nuovo nodo alla coda della lista
	}
}
void stampaLista(pN lista){
	while(lista != NULL){
		printf("\n%d", lista->info);
		lista=lista->next;
	}
}
main(){
	pN pTesta;	//puntatore alla testa della lista
	pTesta=NULL;
	//creiamo con una funzione di creazione di lista in coda
	inserisciCodaLista(&pTesta,1);
	inserisciCodaLista(&pTesta,2);
	inserisciCodaLista(&pTesta,3);
	inserisciCodaLista(&pTesta,4);
	printf("\nStampiamo la lista: ");
	stampaLista(pTesta);
}
