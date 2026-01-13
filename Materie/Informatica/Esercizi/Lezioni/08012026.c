/*  Classe di studenti:
    Cognome, Nome, classe, matricola
    Per ogni studente dotato di matricola abbiamo le
    informazioni riguardante gli esami e il livello raggiunto.
    1) Ricercare lo studente con più certificazioni.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char cognome[20];
    char nome[20];
    char classe[3];
    int matricola; //1000 - 9999
}studente;

typedef struct{
    int matricola;
    struct{
        char corso[20];
        int livello; //(1-3)
    }esame;
}certificazioni;

studente inserimentoDatiStudente(int n,studente* studenti){

    for(int i=0; i<n; i++){
        printf("Inserisci il cognome dello studente: ");
        scanf("%s", studenti->cognome);
        getchar();
        printf("\nInserisci il nome dello studente: ");
        scanf("%s", studenti->nome);
        getchar();
        printf("Inserisci la classe dello studente: ");
        scanf("%s", studenti->classe);
        getchar();

        do{
            printf("Inserisci la classe dello studente: ");
            scanf("%d", studenti->matricola);
            getchar();
        }
        while(studenti->matricola>=1000 && studenti->matricola<=9999);
    }

    return studenti;
}

certificazioni inserimentoDatiCertificazioni(int n,certificazioni* certificazioni){

    for(int i=0; i<n; i++){
        do{
            printf("Inserisci la classe dello studente: ");
            scanf("%d", certificazioni->matricola);
            getchar();
        }
        while(certificazioni->matricola>=1000 && certificazioni->matricola<=9999);

        printf("\nInserisci il nome dello studente: ");
        scanf("%s", certificazioni.esame->corso);
        getchar();
        do{
            printf("Inserisci il cognome dello studente: ");
            scanf("%d", certificazioni.esame->livello);
        }
        while(certificazioni.esame->livello>=1 && certificazioni.esame->livello<=3);
    }

    return certificazioni;
}

void ricercaStudente(int n,studente* studenti,certificazioni* certificazioni){

    for(int i=0; i<n, i++){
        
    }
}

int main(){

    int n=0;
    printf("\nInserisci il numero di studenti: ");
    scanf("%d", &n);

    studente* studenti=(studente)malloc(sizeof*(studente));
    certificazioni* certificazioni=(certificazioni)malloc(sizeof*(certificazioni));

    inserimentoDatiCertificazioni(n,certificazioni* certificazioni)
    return 0;
}