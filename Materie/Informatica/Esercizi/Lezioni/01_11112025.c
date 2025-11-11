/* Data una stringa iniziale e il fattore di
    cifratura creare la stringa cifrata */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//typedef char* string;

int main(){

    char cfr[50];
    int n;


    printf("\nInserisci una parola: ");
    fgets(cfr, 20, stdin);

    printf("\nInserisci una cifra: ");
    scanf(" %d", &n);

    for(int i=0; i<strlen(cfr); i++){
        cfr[i]=cfr[i]+n;
    }

    printf("\n Ecco la parola cifrata. \n %s \n", cfr);

    for(int i=0; i<strlen(cfr); i++){
        cfr[i]=cfr[i]-n;
    }

    printf("\n Ecco la parola decifrata. \n %s \n", cfr);
    
    return 0;
}