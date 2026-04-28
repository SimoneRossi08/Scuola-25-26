/*
CREARE UN PROGRAMMA CHE GESTISCA UNA LIBRERIA DOTATA DI DIVERSI LIBRI TALE DA POTER ESEGUIRE LE SEGUENTI OPERAZONI:
- AGGIUNTA/CREAZIONE DELLA LISTA DI LIBRI;
- RICERCA DI UN LIBRO;
- CANCELLAZIONE DI UN LIBRO;
- MODIFICA DELL'ISBN;
- SEPARARE LA LISTA DEI LIBRI IN DUE LISTE CONTENENTI RISPETTIVAMENTE I LIBRI CREATI PRIMA DEL 2000 E QUELLI DOPO;
TUTTO VIENE GESTITO DA FILE BINARI
typedef struct{
      char autore[30];
      char titolo[30];
      char ISBN[20];
      int anno;
}Libro;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
      char autore[30];
      char titolo[30];
      char ISBN[20];
      int anno;
}Libro;

void aggiungiLibro(){

    Libro lib;

    FILE *f=fopen("28042026.bin", "wb");
    if(f==NULL){
        printf("\nERRORE...");
    }

    printf("\nInserisci autore:");
    scanf("%[^\n]", lib.autore);
    printf("\nInserisci titolo:");
    scanf("%[^\n]", lib.titolo);
    printf("\nInserisci ISBN:");
    scanf("%[^\n]", lib.ISBN);
    printf("\nInserisci anno:");
    scanf("%d", lib.anno);

    fwrite(&lib, sizeof(Libro), f);
    fclose(f);
}

void ricercaLibro(){

    Libro l;
    char isbn[20];
    FILE *f=fopen("28042026.bin", "rb");
    if(f==NULL){
        printf("\nERRORE...");
    }

    printf("\nInserisci l'ISBN del libro da cercare:");
    scanf("%[^\n]", isbn);
    getchar();
    
    while(fread(&l, sizeof(Libro), 1, f)==1){
        if(isbn==l.ISBN){
            printf("\nTitolo: %s \nAutore: %s \nAnno: %d", l.titolo, l.autore, l.anno);
        }
    }

    fclose(f);
}

void rimuoviLibro(){

}

void modificaISBN(){

    Libro l;
    char isbn[20], Nisbn[20];
    FILE *f=fopen("28042026.bin", "rb+");
    if(f==NULL){
        printf("\nERRORE...");
    }

    printf("\nInserisci l'ISBN del libro da modificare:");
    scanf("%[^\n]", isbn);
    getchar();

    printf("\nInserisci il nuovo ISBN:");
    scanf("%[^\n]", Nisbn);
    getchar();

    while(fread(&l, sizeof(Libro), 1, f)==1){
        if(l.ISBN==isbn){
            l.ISBN=Nisbn;
            fseek(f, sizeof(Libro), SEEK_CUR);
            fwrite(&Nl, sizeof(int), 1, f);
        }
    }
    fclose(f);
}

int main(){

    int opt;
    do{
        printf("\n--MENU--");
        printf("\n1. Aggiungi libro.");
        printf("\n2. Rimuovi libro.");
        printf("\n3. Cerca libro.");
        printf("\n4. Modifica ISBN.");

        printf("\n5. Separa libri del 2000.");
        printf("\n0. Esci...");
        scanf("%d", opt);
        getchar();

        switch(opt){
            case 1:
                aggiungiLibro();
                break;
            case 2:
                rimuoviLibro();
                break;
            case 3:
                ricercaLibro();
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                printf("\nChiusura del programma...");
                break;
            default:
                printf("\nERRORE...");
                break;
        }
    }
}