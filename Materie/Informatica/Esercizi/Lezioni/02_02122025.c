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
    while ((c = getchar()) != '\n'){}
}

int main(){

    squad sq1;
    squad sq2;
    squad sq3;
    squad sq4;
    squad sq5;

    srand(time(0));

    sq1.points=rand()%201;
    sq2.points=rand()%201;
    sq3.points=rand()%201;
    sq4.points=rand()%201;
    sq5.points=rand()%201;

    printf("\nInserisci il nome della squadra: ");
    scanf("%s", sq1.nome);
    clear();
    printf("\nInserisci il colore della squadra: ");
    scanf("%s", sq1.color);
    clear();

    printf("\nInserisci il nome della squadra: ");
    scanf("%s", sq2.nome);
    clear();
    printf("\nInserisci il colore della squadra: ");
    scanf("%s", sq2.color);
    clear();

    printf("\nInserisci il nome della squadra: ");
    scanf("%s", sq3.nome);
    clear();
    printf("\nInserisci il colore della squadra: ");
    scanf("%s", sq3.color);
    clear();

    printf("\nInserisci il nome della squadra: ");
    scanf("%s", sq4.nome);
    clear();
    printf("\nInserisci il colore della squadra: ");
    scanf("%s", sq4.color);
    clear();
    
    printf("\nInserisci il nome della squadra: ");
    scanf("%s", sq5.nome);
    clear();
    printf("\nInserisci il colore della squadra: ");
    scanf("%s", sq5.color);
    clear();

    if(sq1.points>=100){
        printf("\nDati della squadra: %s %s, %d", sq1.nome, sq1.color, sq1.points);
    }
    if(sq2.points>=100){
        printf("\nDati della squadra: %s %s, %d", sq2.nome, sq2.color, sq2.points);
    }
    if(sq3.points>=100){
        printf("\nDati della squadra: %s %s, %d", sq3.nome, sq3.color, sq3.points);
    }
    if(sq4.points>=100){
        printf("\nDati della squadra: %s %s, %d", sq4.nome, sq4.color, sq4.points);
    }
    if(sq5.points>=100){
        printf("\nDati della squadra: %s %s, %d", sq5.nome, sq5.color, sq5.points);
    }
}