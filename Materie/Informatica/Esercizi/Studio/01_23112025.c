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

    int cnt=0;
    int len=(strlen(s1)+strlen(s2));
    string s3=malloc((len+1)*sizeof(char));

    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            
        }
    }
    return s3;
}

int main(){

    string s1=malloc(50*sizeof(char));
    string s2=malloc(50*sizeof(char));
    string s3;

    printf("\nInserisci una stringa: ");
    fgets(s1, 50, stdin);
    
    printf("\nInserisci una stringa: ");
    fgets(s2, 50, stdin);

    s3=alterna(s1,s2);

    printf("La stringa alternata è: \n%s", s3);
}