/* creare una struct Squadra contenente le seguenti 
informazioni: nome, colore, punteggio e le informazioni del proprio  
alenatore(nome, cognome, titoli)
caricato un massimo di 10 squadre stampare quelle 
con punteggio superiore a 100 e numero di titoli per allenatore superiore a 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct squadra{

	char nome[20];
	char colore[20];
	int punteggio;

	struct allenatore{
		char nome[20];
		char cognome[20];
		int titoli;
	};
};

typedef struct squadra squadre;

void caricaSquadre(squadra squadre, int n)
{
    for (int i = 0; i < n; i++) {
        printf("Nome squadra: ");
        scanf("%s", v[i].nome);
        printf("Colore squadra: ");
        scanf("%s", v[i].colore);
        printf("Punteggio: ");
        scanf("%d", &v[i].punteggio);
        printf("Nome allenatore: ");

        scanf("%s", v[i].allenatore.nome);
        printf("Cognome allenatore: ");
        scanf("%s", v[i].allenatore.cognome);
        printf("Titoli allenatore: ");
        scanf("%d", &v[i].allenatore.titoli);
    }
}

void stampaSelezionate(squadra squadre, int n){

    for (int i = 0; i < n; i++) {
        if (v[i].punteggio > 100 && v[i].allenatore.titoli > 10){

            printf("Squadra: %s\n", v[i].nome);
            printf("Colore: %s\n", v[i].colore);
            printf("Punteggio: %d\n", v[i].punteggio);

            printf("Allenatore: %s %s\n", v[i].allenatore.nome, v[i].allenatore.cognome);
            printf("Titoli: %d\n", v[i].allenatore.titoli);
        }
    }
}
int main(){

    int n;
    squadra squadre[10];

    printf("Inserire la quantità di squadre: ");
    scanf("%d", &n);

    caricaSquadre(squadre, n);

    stampaSelezionate(squadre, n);

    return 0;
}