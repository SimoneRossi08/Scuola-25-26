#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    char cognome[20];
    int titoli;
}Allenatore;

typedef struct {
    char nome[20];
    char colore[20];
    int punteggio;
    Allenatore allenatore;
}Squadra;

void caricaSquadre(Squadra v[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("Nome squadra ");
        scanf("%s", v[i].nome);
        printf("Colore squadra ");
        scanf("%s", v[i].colore);
        printf("Punteggio ");
        scanf("%d", &v[i].punteggio);
        printf("Nome allenatore ");
        scanf("%s", v[i].allenatore.nome);
        printf("Cognome allenatore ");
        scanf("%s", v[i].allenatore.cognome);
        printf("Titoli allenatore ");
        scanf("%d", &v[i].allenatore.titoli);
        printf("\n");
    }
}

void stampaSelezionate(Squadra v[], int n){

    for (int i = 0; i < n; i++) {
        if (v[i].punteggio > 100 && v[i].allenatore.titoli > 10) {
            printf("Squadra: %s\n", v[i].nome);
            printf("Colore: %s\n", v[i].colore);
            printf("Punteggio: %d\n", v[i].punteggio);
            printf("Allenatore: %s %s\n", v[i].allenatore.nome, v[i].allenatore.cognome);
            printf("Titoli: %d\n\n", v[i].allenatore.titoli);
        }
    }
}
int main()
{
    int n;
    printf("Quante squadre ");
    scanf("%d", &n);
    Squadra squadre[10];
    caricaSquadre(squadre, n);
    stampaSelezionate(squadre, n);
    return 0;

}