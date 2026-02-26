/*
DATA LA STRUCT PRODOTTO:
    - NOME
    - CODICE (int)
    - PREZZO
ESEGUIRE: 
    1. INSERIRE PRODOTTO
    2. STAMPARE ELENCO PRODOTTI
    3. CERCARE UN PRODTTO PER CODICE
    4. CALCOLARE IL VALORE TOTALE DEL MAGAZZINO
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prodotto{
    char nome[20];
    int codice;
    float prezzo;
}prodotto;

prodotto inserireProdotto(prodotto* p, int* n){

    p=(prodotto*)realloc(p, ((*n)+1)*sizeof(prodotto));
	if(l==NULL){
		printf("Errore di allocazione!");
		exit(p);
	}

    printf("\nInserisci il nome del prodotto:");
    fgets(p[*n].nome,100,stdin);
	p[*n].nome[strcspn(p[*n].nome,"\n")]='\0';

    printf("Inserisci il codice del prodotto:");
    scanf("%d", p[*n].codice);

    printf("Inserisci il prezzo del prodotto:");
    scanf("%f", p[*n].prezzo);

    return p;
}

void stampaElenco(prodotto* p, int* n){

    printf("\n---ELENCO PRODOTTI---\n\n");
    for(int i=0; i<n; i++){
        printf("\nNome del prodotto: %c", p[*n].nome);
        printf("\Codice del prodotto: %d", p[*n].codice);
        printf("\nNome del prodotto: %.2f", p[*n].prezzo);
    }
}

void ricercaProdotto(prodotti, &n){

    int codice;
    printf("\nInserisci il codice del prodotto che stai cercando: ");
	scanf("%d", &codice);

	for(int i=0; i<n; i++){
		if(codice==p[*n].codice){
			trovato=1;
            printf("\nNome del prodotto: %c", p[*n].nome);
            printf("\Codice del prodotto: %d", p[*n].codice);
            printf("\nNome del prodotto: %.2f", p[*n].prezzo);
		}else{
			printf("Prodotto non disponibile.");
		}
	}
	if(!trovato)
		printf("\nProdotto non trovato");
	return;
}
void valoreTotale(prodotto* p, int* n){

    float prezzoTotale=0;

    for(int i=0; i<n; i++){
        prezzoTotale+=p[*n].prezzo;
    }

    printf("\nVALORE TOTALE MAGAZZINO:\n%.2f", prezzoTotale);
}

int main(){

    prodotto* prodotti=NULL;
    int opt, n=0;
    char c;

    do{
		printf("\n\n---MENU---");
		printf("\n1) Inserire prodotto.");
		printf("\n2) Elenco prodotti.");
		printf("\n3) Cercare prodotto tramite codice.");
		printf("\n4) Valore totale del magazzino.");
		printf("\n5) Uscire.\n\n");
        scanf("%d", &opt)
		while((c=getchar())!='\n'){}
		
		switch(scelta){
			case 1:
                inserireProdotto(prodotti, &n);
				break;
			case 2:
                stampaElenco(prodotti, &n);
				break;
			case 3:
                ricercaProdotto(prodotti, &n)
				break;
			case 4:
                valoreTotale(prodotti, &n);
				break;
			case 5:
				printf("Chiusura del programma.\n");
				break;
		}
	}while(scelta!=7);
}