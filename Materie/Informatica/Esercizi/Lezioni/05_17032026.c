/*file con numeri a caso:
-ordinare i numeri mettendoli al contrario 
-scrivere i numeri in ordine sul file 
-scrivere una funzione che preso in ingresso il nome del file contenente interi, lo modifichi
in modo tale da contenere gli stessi numeri ma ordinati in senso decrescente
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSortChar(char nomeFile[]){

    FILE *filep=fopen(nomeFile, "r");
    int v[100];
    int i,n=0,tmp;

    if(filep==NULL){
        printf("\nErrore apertura file");
        return;
    }

    while(fscanf(filep, "%d", &v[n])==1){//==1 è un flag e riporta 1 se trova qualcosa
        printf("elemento %d: %d", n+1, v[n]);
        n++;
    }
    fclose(filep);
    n=n+1;//rappresenta la dimensione dell'array
    for(i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[i]<v[j]){
                tmp=v[i];
                v[i]=v[j];
                v[j]=tmp;
            }
        }
    }
    filep=fopen(nomeFile, "w");
    if(filep==NULL){
        printf("\nErrore apertura file");
        return;
    }

    for(int i=0; i<n; i++){
        fprintf(filep, "%d",v[i]);
    }
    fclose(filep);
}

int main(){

    char nome[20];
    printf("inserire il nome del file: ");
    scanf("%s", nome);
    bubbleSortChar(nome);
}