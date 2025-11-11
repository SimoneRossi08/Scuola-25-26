/* Cifratura */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* string;

int main(){

    string cfr;
    int n,len;//,dim=20;

    //cfr=(string)malloc((dim+1)*sizeof(char));

    printf("\nInserisci una parola: ");
    fgets(cfr, sizeof(cfr), stdin);

    len=strlen(cfr);
    //cfr=(string)realloc(dim,(len+1)*sizeof(char));

    printf("\nInserisci una cifra: ");
    scanf("%d", &n);

    for(int i=0; i<len; i++){
        cfr[i]+=n;
    }

    printf("\n Ecco la parola cifrata. \n %s", cfr);

    return 0;
}