/*DATA UNA LISTA DI NUMERI ORDINATI Es: 4->6->8->11
COMPLETARE LA LISTA CON I NUMERI MANCANTI 
Es: 4->5->6->7->8->9->10->11   */
#include <stdio.h>
#include <stdlib.h>
struct s_nodo{
	int info;
	struct s_nodo *next;
};
typedef struct s_nodo nodo;		
typedef nodo *pN;//definizione del tipo puntatore al nodo				
			
pN creaNodo(int val){	//funzione di tipo pN che restituisce l'indirizzo del nodo creato
	pN p;
	p=malloc(sizeof(nodo));
	p->info=val;
	p->next=NULL;
	return (p);
}

void creaListaCoda(pN *lista){
	pN ultimo, pNodo=NULL; 	
	int i,n, val;
	
	do{
		printf("Quanti elementi vuoi inserire? ");
		scanf("%d",&n);
	}while(n<=0);
	printf("Inserisci %d elementi in ordine crescente: \n", n);
	for(i=0; i<n; i++){
		scanf("%d", &val);
		pNodo=creaNodo(val);//chiamata alla funzione che crea il nuovo nodo
		//troviamo l'ultimo elemento
		if (*lista == NULL)	//caso in cui ancora nessun nodo sia stato creato
			*lista = pNodo;
		else{
			ultimo = *lista;
			while(ultimo->next != NULL)
				ultimo = ultimo->next;
			ultimo->next = pNodo;	//concateniamo il nuovo nodo alla coda della lista
		}
	}
}

void completaLista(pN testa){
	pN lista, p;
	
	lista=testa;
	while(lista->next != NULL){
		while(lista->info < lista->next->info - 1 ){
			p = creaNodo(lista->info + 1);
			p->next=lista->next;
			lista->next = p;
		}
		lista=lista->next;
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
	
	creaListaCoda(&pTesta);
	printf("\nStampiamo la lista: ");
	stampaLista(pTesta);
	completaLista(pTesta);
	printf("\nStampiamo la lista completa: ");
	stampaLista(pTesta);
}
