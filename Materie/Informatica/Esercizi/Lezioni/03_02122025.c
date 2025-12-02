/* creare una struct per contenere i dati di una squadra e
        stamparne solo quelle che superano 100 punti
                    (massimo 10 squadre)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct squad{

    char nome[20];
    char color[10];
    int points;

}squad;

void clear(){
    int c;
    while ((c=getchar())!='\n'){}
}

int main(){

    srand(time(0));
    squad *teams;
    int n;
    do{
        printf("Inserisci il numero delle squadre (max 10): ");
        scanf("%d", &n);
    }while(n<0||n>10);

    teams=(squad*)malloc(sizeof(squad));
    if(teams==NULL){
        printf("\nErrore durante l'allocazione");
        return 1;
    }

    for(int i=0; i<n; i++){

        printf("\nInserisci il nome della squadra: ");
        scanf("%s", teams[i].nome);
        clear();
        printf("\nInserisci il colore della squadra: ");
        scanf("%s", teams[i].color);
        clear();
        teams[i].points=rand()%201;

    }

    for(int i=0; i<n; i++){
        if(teams[i].points>=100){
        printf("\nDati della squadra: %s, %s, %d", teams[i].nome, teams[i].color, teams[i].points);
        }
    }
}