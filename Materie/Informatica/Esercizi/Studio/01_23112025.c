/* DATE DUE STRINGHE SCRIVERE LA STRINGA IN ALTERNATA
CIAO
CASA
CCIAASOA  */
/* Date due stringhe riportarle in una stringa a caratteri alternati */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* string;

string alterna(string s1, string s2){

    int i=0;
    int len=(strlen(s1)+strlen(s2));
    //printf("\n%d", len);
    string s3=malloc((len)*sizeof(char));

    for(int cnt=0; cnt<len; cnt+=2){
        s3[cnt]=s1[i];
        s3[cnt+1]=s2[i];
        //printf("\n%c", s3[cnt]);
        i++;
        //printf("\n%d", cnt);
    }

    return s3;
}

int main(){

    string s1=malloc(50*sizeof(char));
    string s2=malloc(50*sizeof(char));
    string s3;

    printf("\nInserisci una stringa: ");
    fgets(s1, 50, stdin);
    
    printf("Inserisci una stringa: ");
    fgets(s2, 50, stdin);

    s3=alterna(s1,s2);

    printf("\nLa stringa alternata è: \n%s", s3);
}