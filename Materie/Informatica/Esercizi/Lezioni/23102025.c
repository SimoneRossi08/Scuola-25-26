/* Verificare se una stringa è palindroma. 
    Esempio: otto è palindroma
            ciao non è palindroma        */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char* string;

int leng(string s){

    int i=0;

    while(s[i]!='\0'){
        i++;
    }

    return i-1;
}

int plndrma(string s,int dim){

    int flag=0;

    for(int i=0, int j=dim-1; i<dim/2; i++, j--){
        if(s[i]!=s[j]){
            flag=1;
        }
        return flag;
    }
}

int main(){

    int dim=0,plndrm=0;
    string s=(string)malloc(sizeof(s)*sizeof(char));
    if(s==NULL){
        return 1;
    }

    printf("Inserisci una stringa: ");
    fgets(s, 50, stdin);
    printf("\n%s", s);

    dim=leng(s);
    printf("\n%d", dim);

    plndrm=plndrma(s,dim);

    if(plndrm=1){
        printf("\nLa stringa non è palindroma");
    }
    else{
        printf("\nLa stringa è palindroma");
    }

    return 0;
}