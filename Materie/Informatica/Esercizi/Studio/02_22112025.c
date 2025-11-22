/* Data una stringa scriverla al contrario */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char* string;

string inverti(string s){

    for(int i=0; i<strlen(s); i++){
        s[i]=s[strlen(s)-i-1];
    }

    return s;
}

int main(){

    string stringa;

    printf("\nInserisci una stringa: ");
    scanf("%s",&stringa);

    stringa=inverti(stringa);

    printf("La stringa al contrario è: %s", stringa);
}