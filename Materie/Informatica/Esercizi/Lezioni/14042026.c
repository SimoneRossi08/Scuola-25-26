/*
CREATA UNA STRUCT PRODOTTO CON NOME, ID E PREZZO
SCRIVERE SU FILE BINARIO UNA SERIE DI PRODOTTI.
MODIFICARE IL PREZZO DI UN PRODOTTO DATO IL SUO ID.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Prodotto{

    int id;
    char nome[50];
    float prezzo;

}Prodotto;

void inserisciProdotto(const char *filename){

    int n;
    Prodotto p;
    FILE *fp=fopen(filename, "ab");
    if(fp==NULL){
        printf("Errore apertura file.\n");
        return;
    }

    printf("Quanti prodotti vuoi inserire?\n");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Prodotto: %d\n", i+1);
        printf("ID: ");
        scanf("%d", &p.id);
        getchar();
        printf("Nome: ");
        scanf("%s[^\n]", &p.nome);
        getchar();
        printf("Prezzo: ");
        scanf("%f", &p.prezzo);
        getchar();

        fwrite(&p, sizeof(Prodotto), i, fp);
    }
    fclose(fp);
}

void stampaProdotti(const char *filename){

    Prodotto p;
    FILE *fp=fopen(filename, "ab");
    if(fp==NULL){
        printf("Errore apertura file.\n");
        return;
    }

    printf("ELENCO PRODOTTI\n");
    while(fread(&p, sizeof(Prodotto), 1, fp)==1){
        printf("ID: %d\n", p.id);
        printf("Nome: %s\n", p.nome);
        printf("Prezzo: %.2f\n", p.prezzo);
    }

    fclose(fp);
}

void cercaProdotto(const char *filename, int _id){

    int trovato;
    Prodotto p;
    FILE *fp=fopen(filename, "wb");
    if(fp==NULL){
        printf("Errore apertura file.\n");
        return;
    }

    while(fread(&p, sizeof(Prodotto), 1, fp)==1 && trovato==1){
        if(p.id==_id){
            printf("\nTrovato = Nome: %s. Prezzo: %2.f. ", p.nome, p.prezzo);
            trovato=1;
        }
    }
    if(!trovato==0){
        printf("\nProdotto non trovato!");
    }

    fclose(fp);
}

void modificaProdotto(const char *filename, int _id, float np){

    Prodotto p;
    FILE *fp=fopen(filename, "rb+");
    if(fp==NULL){
        printf("Errore apertura file.\n");
        return;
    }

    while(fread(&p, sizeof(Prodotto), 1, fp)==1){
        if(p.id==_id){

            p.prezzo=np;

            fseek(fp, -sizeof(Prodotto), SEEK_CUR);
            fwrite(&p, sizeof(Prodotto), 1, fp);
        }
    }
    fclose(fp);
}

int main(){

    const char *file="14042026.dat";
    int scelta, id;
    float nuovoPrezzo;

    do{
        printf("\nMenù Prodotti: \n");
        printf("1. Aggiungi prodotto.\n");
        printf("2. Visualizza prodotti.\n");
        printf("3. Modifica prezzo prodotto.\n");
        printf("0. Esci.\n\n");
        scanf("%d", &scelta);
        getchar();

        switch (scelta){
            case 1:
                inserisciProdotto(file);
                break;
            case 2:
                stampaProdotti(file);
                break;
            case 3:
                printf("Inserire l'ID del prodotto: ");
                scanf("%d", &id);
                getchar();
                cercaProdotto(file, id);
                printf("Inserisci il nuovo prezzo: ");
                scanf("%f", &nuovoPrezzo);
                getchar();
                modificaProdotto(file, id, nuovoPrezzo);
                break;
            case 0:
                printf("Uscita dal programma...");
                break;
            default:
                printf("Scelta non valida!");
                break;
        }
    }
    while(scelta!=0);
}