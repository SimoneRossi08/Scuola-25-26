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
#include <string.h>

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
    scanf(" %[^\n]", lib.autore);
    printf("\nInserisci titolo:");
    scanf(" %[^\n]", lib.titolo);
    printf("\nInserisci ISBN:");
    scanf(" %[^\n]", lib.ISBN);
    printf("\nInserisci anno:");
    scanf("%d", &lib.anno);

    fwrite(&lib, sizeof(Libro), 1, f);
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

void separaLibri(){
    
    Libro lib;
    FILE *f=fopen("28042026.bin", "rb");
    if(f==NULL){
        printf("\nERRORE...");
    }
    FILE *f1=fopen("28042026l1.bin", "ab");
    if(f1==NULL){
        printf("\nERRORE...");
    }
    FILE *f2=fopen("28042026l2.bin", "ab");
    if(f2==NULL){
        printf("\nERRORE...");
    }

    if(lib.anno>=2000){
        fwrite(&lib, sizeof(Libro), 1, f1);
    }
    else{
        fwrite(&lib, sizeof(Libro), 1, f2);
    }
}

void rimuoviLibro(){

    Libro lib;
    char libro[30];

    FILE *f=fopen("28042026.bin", "rb");
    if(f==NULL){
        printf("\nERRORE...");
    }
    FILE *t=fopen("28042026t.dat", "wb");
    if(t==NULL){
        printf("\nERRORE...");
    }

    printf("\nInserisci il titolo del libro da rimuovere:");
    scanf("%[^\n]", libro);

    while(fread(&lib, sizeof(Libro), 1, f)){
        if(strcmp(lib.titolo, libro)==0){
            printf("\nLibro rimosso...");
        }
        else{
            fwrite(&lib, sizeof(Libro), 1, t);
        }
    }

    fclose(f);
    fclose(t);

    f=fopen("28042026.bin", "wb");
    if(f==NULL){
        printf("\nERRORE...");
    }
    t=fopen("28042026t.dat", "rb");
    if(t==NULL){
        printf("\nERRORE...");
    }

    while(fread(&lib, sizeof(Libro), 1, t)){
        fwrite(&lib, sizeof(Libro), 1, f);
    }

    fclose(f);
    fclose(t);
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
        if(strcmp(l.ISBN, isbn)==0){
            strcpy(l.ISBN, Nisbn);
            fseek(f, sizeof(Libro), SEEK_CUR);
            fwrite(&l, sizeof(int), 1, f);
        }
    }
    fclose(f);
}

void stampaLibri(){

    Libro l;
    int opt;

    printf("\nQuale lista di libri da stampare?");
    printf("\n1. Lista completa");
    printf("\n2. Lista pre-2000");
    printf("\n3. Lista post-2000\n");
    scanf("%d", &opt);
    getchar();

    switch(opt){
        case 1:
            FILE *f=fopen("28042026.bin", "rb");
            if(f==NULL){
                printf("\nERRORE...");
            }
            while(fread(&l, sizeof(Libro), 1, f)==1){
                printf("\n\nTitolo: %s \nAutore: %s \nAnno: %d", l.titolo, l.autore, l.anno);
            }
            break;
        case 2:
            FILE *f1=fopen("28042026l1.bin", "rb");
            if(f==NULL){
                printf("\nERRORE...");
            }
            while(fread(&l, sizeof(Libro), 1, f1)==1){
                printf("\n\nTitolo: %s \nAutore: %s \nAnno: %d", l.titolo, l.autore, l.anno);
            }
            break;
        case 3:
            FILE *f2=fopen("28042026l2.bin", "rb");
            if(f==NULL){
                printf("\nERRORE...");
            }
            while(fread(&l, sizeof(Libro), 1, f2)==1){
                printf("\n\nTitolo: %s \nAutore: %s \nAnno: %d\n", l.titolo, l.autore, l.anno);
            }
            break;
        default:
            printf("\nERRORE...");
            break;
    }
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
        printf("\n6. Visualizza libri.");
        printf("\n0. Esci...\n");
        scanf("%d", &opt);
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
                modificaISBN();
                break;
            case 5:
                separaLibri();
                break;
            case 6:
                stampaLibri();
                break;
            case 0:
                printf("\nChiusura del programma...");
                break;
            default:
                printf("\nERRORE...");
                break;
        }
    }while(opt!=0);

    return 0;
}