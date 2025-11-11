/* Cifratura */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* string;

int main(){

    string cfr;
    int n;


    printf("\nInserisci una parola: ");
    fgets(cfr, 30, stdin);

    printf("\nInserisci una cifra: ");
    scanf("%d", &n);

    for(int i=0; i<sizeof(cfr)/sizeof(char); i++){
        cfr[i]+=n;
    }

    printf("\n Ecco la parola cifrata. \n %s", cfr);

    return 0;
}