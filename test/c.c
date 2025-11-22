/* Data una stringa trovare una sottostringa */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 20
typedef char* string;

int main(){

    string frase;
    string sottofrase;
    int cnt=0,flag;

    printf("\nInserisci una frase: ");
    fgets(frase, DIM+1, stdin);
    frase=(string)malloc(frase, (DIM+1)*sizeof(char));

    printf("\nInserisci una sottofrase: ");
    fgets(sottofrase, DIM+1, stdin);
    sottofrase=(string)malloc(sottofrase, (DIM+1)*sizeof(char));

    for(int i=0; i<strlen(frase); i++){
        for(int j=0; j<strlen(frase); j++){
            if(frase[i]==sottofrase[j]){
                flag=1;
                cnt++;
            }
            else{
                flag=0;
            }
        }
    }
    if(flag==1 && strlen(sottofrase)==cnt){
    printf("\nLa frase contiene la sottofrase.");
    }
    else{
    printf("\nLa frase non contiene la sottofrase.");
    }
}