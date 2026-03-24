/*file con numeri a caso:
-ordinare i numeri mettendoli al contrario 
-scrivere i numeri in ordine sul file 
-scrivere una funzione che preso in ingresso il nome del file contenente interi, lo modifichi
in modo tale da contenere gli stessi numeri ma ordinati in senso decrescente
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSortChar(char nomeFile[] ){
    FILE *filep=fopen(nomeFile, "r");
    int v[100];
    int i, n;

    if(filep==NULL){
        printf("\nerrore apertura file");
        return;
    }

    while(fscanf(filep, "%d", v[i])==1){//==1 è un flag e riporta 1 se trova qualcosa
        printf("elemento %d: %d", i+1, v[i]);
        i++;
    }
    fclose(filep);
    n=i+1;//rappresenta la dimensione dell'array
    for(i=0; i<n; i++){

    }
}

int main(){
    char nome[20];
    printf("inserire il nome del file: ");
    scanf("%s", nome);

    bubbleSortChar(nome);
}