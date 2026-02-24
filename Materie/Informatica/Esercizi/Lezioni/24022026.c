/*    Dichiarare un array di libri di dimensione massima N
    Consentire l'inserimento dei dati di un libro.
    Aggiornare correttamente il numero di copie disponibili.
    Registare il prestito di un libro:
        -inserendo la data di un prestito e la data di restituzione
        -decrementando il numero di copie disponibili
        -impedendo il prestito se non ci sono copie disponibili
    Visualizzare l'elenco completo dei libri con tutte le informazioni
    Visualizzare solo i libri attualmente in prestito(copie disponibili<copie totali)
    Cercare un libro tramite ISBN
    Stampare solo i libri con prestito scaduto
    Vincoli: accedere ai campi delle date tramite struct annidata
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int giorno;
    int mese;
    int anno;
}data;

typedef struct libro{
    char titolo[20];
    char autore[20];
    int isbn;
    int copietot;
    int copiedisp;
    data prestito;
    data restituzione;
}libro;

libro* InserisciLibro(libro* l, int* n){
	l=(libro*)realloc(l, ((*n)+1)*sizeof(libro));
	if(l==NULL){
		printf("Errore di allocazione!");
		exit(l);
	}

	printf("Inserisci titolo:");
	fgets(l[*n].titolo,100,stdin);
	l[*n].titolo[strcspn(l[*n].titolo,"\n")]='\0';

	printf("Inserisci autore:");
	fgets(l[*n].autore,100,stdin);
	l[*n].titolo[strcspn(l[*n].autore,"\n")]='\0';

	printf("Inserisci isbn:");
	scanf("%d",&l[*n].isbn);

	printf("Inserisci le copie totali: ");
	scanf("%d",&l[*n].copietot);
	l[*n].prestito.giorno=0;
	l[*n].restituzione.giorno=0;
}

void stampa(libro *l, int n){

	for(int i=0; i<n; i++){
		printf("\nTitolo: %s",l[*n].titolo);
		printf("\nAutore: %s",l[*n].autore);
		printf("\nISBN: %d",l[*n].isbn);
		printf("\nISBN: %d",l[*n].isbn);
		printf("\nCopie totali: %d", l[*n].copietot);
		printf("\nCopie disponibili: %d", l[*n].copiedisp);
		printf("\nData prestito: %d", l[*n].prestito.giorno,l[*n].prestito.mese,l[*n].prestito.anno);
		printf("\nData restituzione: %d", l[*n].restituzione.giorno,l[*n].restituzione.mese,l[*n].restituzione.anno);
	}
}

void registraLibro(libro *l,int n){
	int isbn, trovato=0;

	printf("\nInserisci l'ISBN del libro che stai cercando: ");
	scanf("%d", &isbn);
	for(int i=0; i<n; i++){
		if(isbn==l[*n].isbn){
			trovato=1;
			l[*n].copiedisp-=1;
			printf("\nInserisci il giorno del prestito: ");
			scanf("%d",l[*n].prestito.giorno);
			printf("Inserisci il mese del prestito: ");
			scanf("%d",l[*n].prestito.mese);
			printf("Inserisci il anno del prestito: ");
			scanf("%d",l[*n].prestito.anno);

			printf("\nInserisci il giorno della restituzione: ");
			scanf("%d",l[*n].restituzione.giorno);
			printf("\nInserisci il mese della restituzione: ");
			scanf("%d",l[*n].restituzione.mese);
			printf("\nInserisci il anno della restituzione: ");
			scanf("%d",l[*n].restituzione.anno);
		}else{
			printf("Libro non disponibile.");
		}
	}
}

void visualizzaLibriPrestito(libro* l, int n){

	for(int i=0; i<n; i++){
		if(l[i].copiedisp<l[i].copietot){
			printf("Il libro in prestito è: %s.", l[i].titolo);
		}
	}
}

void visualizzaPrestitoScaduto(libro* l,int n){
	int ggTras;
	for(int i=0; i<n; i++){
		ggTras=30*(l[i].restituzione.mese-l[i].prestito.mese)*l[i].restituzione.giorno+(30-l[i].prestito.giorno);
		if(ggTras>40){
			pritnf("Titolo: %s",l[*n].titolo);
			pritnf("Autore: %s",l[*n].autpore);
		}
	}
}
int main(){

    libro* biblioteca=NULL;
	int n=0, scelta;
	char c;

    do{
		printf("\n\n---MENU---");
		printf("\n1) Inserire dati dei libri.");
		printf("\n2) Registrare un prestito di un libro.");
		printf("\n3) Visualizzare l'elenco di libri.");
		printf("\n4) Visualizzare l'elenco di libri in prestito.");
		printf("\n5) Cercare un libro tramite ISBN.");
		printf("\n6) Visualizzare l'elenco di libri con prestito scaduto.");
		printf("\n7) Uscire.\n\n");
        scanf("%d", &scelta)
		while((c=getchar())!='\n'){}
		
		switch(scelta){
			case 1:
				biblioteca=InserisciLibro(biblioteca,&n);
				break;
			case 2:
				stampa(biblioteca,&n);
				break;
			case 3:
				registraLibro(biblioteca,*n);
				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:
				printf("Esci dal programma.\n");
				break;
		}
	}while(scelta!=7);
}