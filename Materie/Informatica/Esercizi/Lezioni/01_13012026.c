/*
    Registrare le informazioni di alcuni libri
    con titolo, autore, anno e prezzo.
    Determinare il libro più costoso e il più vecchio.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct libro{
    char titolo[40];
    char autore[20];
    int anno;
    float prezzo;
}libro;
typedef char* string;

void compatta(string buffer, int lun){
    if(lun>0 && buffer[lun-1]=='\n'){
        buffer[lun-1]='\0';
        lun--;
    }
}
int main(){

    libro *libri=(libro*)malloc(n*sizeof(libro));
    if(libri==NULL){
        printf("Errore di allocazione");
        return 1;
    }
    int n=3,datato,idatato,icosto,lunghezza;
    float costo;
    char Libro[40];

    strcpy(libri[0].titolo, "L'amore mio non muore");
    strcpy(libri[0].autore, "Roberto Saviano");
    libri[0].anno=2025;
    libri[0].prezzo=19.50;

    strcpy(libri[1].titolo, "Maledetti di Dio");
    strcpy(libri[1].autore, "Sven Hassel");
    libri[1].anno=1953;
    libri[1].prezzo=13;

    strcpy(libri[2].titolo, "Il diritto di contare");
    strcpy(libri[2].autore, "Margot Lee Shetterly");
    libri[2].anno=2017;
    libri[2].prezzo=18.50;

    n+=1;
    libri=(libro*)realloc(libri,n*sizeof(libro));
    if(libri==NULL){
        printf("Errore di allocazione");
        return 1;
    }

    strcpy(libri[3].titolo, "Orgoglio e pregiudizio");
    strcpy(libri[3].autore, "Jane Austen");
    libri[3].anno=1813;
    libri[3].prezzo=9;

    for(int i=0; i<n; i++){
        printf("Libro: %d\n", i+1);
        printf("Titolo: %s\n", libri[i].titolo);
        printf("Autore: %s\n", libri[i].autore);
        printf("Anno: %d\n", libri[i].anno);
        printf("Prezzo: %.2f\n\n", libri[i].prezzo);
    }

    datato=libri[0].anno;
    for(int i=datato; i<n; i++){
        if(libri[i].anno<datato){
            datato=libri[i].anno;
            idatato=i;
        }
    }

    printf("\nIl libro più datato è: %s", libri[idatato].titolo);

    costo=libri[0].prezzo;
    for(int i=1; i<n; i++){
        if(libri[i].prezzo>costo){
            costo=libri[i].prezzo;
            icosto=i;
        }
    }

    printf("\nIl libro più costoso è:%s", libri[icosto].titolo);

    printf("\nInserisci un libro da eliminare:");
    fgets(Libro,50,stdin);
    lunghezza=strlen(Libro);
    compatta(Libro,lunghezza);

    for(int i=0; i<n; i++){
        if(!(strcmp(libri[i].titolo,Libro))){
            for(int j=i; j<(n-1); j++){
                strcpy(libri[j].titolo,libri[j+1].titolo);
                strcpy(libri[j].autore,libri[j+1].autore);
                libri[j].anno=libri[j+1].anno;
                libri[j].prezzo=libri[j+1].prezzo;
            }
            n-=1;
        }
    }

    libri=(libro*)realloc(libri,n*sizeof(libro));
    if(libri==NULL){
        printf("Errore di allocazione");
        return 1;
    }

    for(int i=0; i<n; i++){
        printf("Libro: %d\n", i+1);
        printf("Titolo: %s\n", libri[i].titolo);
        printf("Autore: %s\n", libri[i].autore);
        printf("Anno: %d\n", libri[i].anno);
        printf("Prezzo: %.2f\n\n", libri[i].prezzo);
    }
    
    free(libri);

    return 0;
}