/* FUNZIONE FGETS */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char buffer;

    printf("Inserisci una stringa: ");
    if(fgets(buffer, 20, stdin)!=NULL){
        printf("Hai inserito: %s", buffer);
        
    }
}