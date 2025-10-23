/* Completare la seguente funzione iniziata in classe: void maiuscole_minuscole(Stringa s1, Bool maiusc_to_minusc) */

#include <stdio.h>
#include <stdlib.h>

typedef char* string; 
typedef enum {true, false} Bool;

void maiuscole_minuscole(string s1, Bool maiusc_to_minusc){
    int i=0,j=0;

    while(s1[i]!='\0'){
        if(s1[i]>=65 && s1[i]<=90){
            maiusc_to_minusc=true;
        }
        if(s1[i]>=97 && s1[i]<=122){
            maiusc_to_minusc=false;
        }
        if(maiusc_to_minusc==true){
            s1[i]+=32;
        }
        else{
            s1[i]-=32;
        }
        i++;
    }
    printf("%s ", s1);
}

string crea_stringa_dimensionata(int n){
    string c = (string) malloc(n * sizeof(char));
    if(c == NULL){
        printf("Errore di allocazione!\n");
        exit(1);
    }
    fgets(c, n, stdin); //n=5 "ciao oggi è proprio divertente"
    return c;
}

int main(){

    int n=10;
    string s=crea_stringa_dimensionata(n);
    Bool mami;
    
    printf("%s", s);
    maiuscole_minuscole(s, mami);
    
}
