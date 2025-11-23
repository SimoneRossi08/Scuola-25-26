/* Data una stringa scriverla al contrario */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char* string;

string inverti(string s1){

    string s2;
    for(int i=0; s1[i]!='\0'; i++){
        s2[i]=s1[strlen(s1)-i-1];
    }

    return s2;
}

int main(){

    string stringa;

    printf("\nInserisci una stringa: ");
    scanf("%s", stringa);

    stringa=inverti(stringa);

    printf("La stringa al contrario è: %s", stringa);
}