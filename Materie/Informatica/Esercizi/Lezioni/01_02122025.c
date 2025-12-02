/* esempio di utilizzo una di una struttura complessa
    facendo accesso ai campi in modalità variabile
        e in modalità puntatore alla struttura
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona{
    char nome[20];
    char cognome[20];
    int età;
}persona;

void clear(){
    int c;
    while ((c = getchar()) != '\n'){}
}

int main(){

    persona p1;
    persona p2;

    //inseriamo le informazioni in p1
    printf("\nInserisci il nome della persona: ");
    scanf("%s", p1.nome);
    clear();
    printf("Inserisci il cognome della persona: ");
    scanf("%s", p1.cognome);
    clear();
    printf("Inserisci l'età della persona: ");
    scanf("%d", &(p1.età));
    clear();

    printf("Dati della persona: %s %s, %d", p1.nome, p1.cognome, p1.età);

    //inseriamo le informazioni in p2
    printf("\nInserisci il nome della persona: ");
    scanf("%s", p2.nome);
    clear();
    printf("Inserisci il cognome della persona: ");
    scanf("%s", p2.cognome);
    clear();
    printf("Inserisci l'età della persona: ");
    scanf("%d", &(p2.età));
    clear();

    printf("Dati della persona: %s %s, %d", p2.nome, p2.cognome, p2.età);
}