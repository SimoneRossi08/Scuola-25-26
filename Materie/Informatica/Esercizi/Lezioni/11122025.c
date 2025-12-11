/*
    REGISTRARE LE INFORMAZIONI DI ALCUNI LIBRI: TITOLO, AUTORE, ANNO.
        ARRAY DI LIBRI
            CARICARE L'ARRAY
            PUBBLICARE
            RIMUOVERE UN LIBRO
            CERCARE UN LIBRO IN BASE AL TITOLO
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct libro{
    
    char titolo[20];
    char autore[20];
    int anno;
}libro;

void caricaLibri(libro v, int n){
    for (int i=0; i<n; i++){

        printf("\n\nLibro %d: ", i);

        printf("\nTitolo: ");
        scanf("%s", v[i].titolo);
        printf("Autore: ");
        scanf("%s", v[i].autore);
        printf("Anno di pubblicazione: ");
        scanf("%d", &v[i].anno);
    }
}

void cercaLibro(libro v, int n){

    char titolo[20];

    printf("\nInserire il titolo da cercare: ");
    scanf("%c", &titolo);

    for(int i=0; i<n; i++){
        if(v[i].titolo==titolo){
            printf("\nTitolo: %s", v[i].titolo);
            printf("A\nutore: %s", v[i].autore);
            printf("\nAnno di pubblicazione: %d", v[i].anno);
        }
    }
}

void stampa(libro v, int n){

    for(int i=0; i<n; i++){
        printf("Squadra: %s\n", v[i].titolo);
        printf("Colore: %s\n", v[i].autore);
        printf("Punteggio: %d\n", v[i].anno);
    }
}

void rimuoviLibro(libro v; int n){

    char titolo[20];

    printf("\nInserire il titolo da rimuovere: ");
    scanf("%s", &titolo);

    for(int i=0; i<n; i++){
        if(v[i].titolo==titolo){
            v[i-1]=v[i];
        }
    }
}
int main(){

    libro libreria[10];
    int nlib,opt;

    do{
        printf("\nQuale operazione si vuole eseguire? ");
        printf("\n1. Caricare l'array.");
        printf("\n2. Pubblicare.");
        printf("\n3. Rimuovere un titolo.");
        printf("\n4. Cercare un titolo.");
        printf("\n5. Uscire.");
        scanf("%d", &opt);

        switch(expression)
        {
        case 1:
            printf("\nInserire la quantità di libri: ");
            scanf("%d", &nlib);
            caricaLibri(libreria, nlib);
            break;
        case 2:
            stampa(libreria, nlib);
            break;
        case 3:
            rimuoviLibro(libreria, nlib);
            break;
        case 4:
            cercaLibro(libreria, nlib);
            break;
        default:
            printf("\nERRORE: Operazione inesistente!");
            break;
        }
    }while(opt!=5);

    return 0;
}