/* Data una stringa iniziale e il fattore di
    cifratura creare la stringa cifrata */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* string;

cfrtr(string cfr, int n){
    int len=strlen(cfr);
    int i=0, cntr;

    string tmp=malloc(len*sizeof(char));

    if(tmp==NULL){
        printf("Errore!");
        exit(1);
    }
    while(cfr[i]!='\0'){
        cntr=0;
        if(cfr[i]+n){
            
        }
    }

    return tmp;
}

int main(){

    string cfr=(string)malloc(200*sizeof(char));
    int n;

    printf("\nInserisci una stringa: ");
    fgets(cfr, 200, stdin);

    //cfr=(string)realloc(dim,(len+1)*sizeof(char));

    printf("\nInserisci una cifra: ");
    scanf("%d", &n);

    cfr=cfrtr(cfr,n);


    printf("\n Ecco la parola cifrata. \n %s", cfr);

    return 0;
}