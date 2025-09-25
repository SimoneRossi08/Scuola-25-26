/* Creare un array dinamico chiedendo all'utente la sua dimensione. 
    Il programma deve prevedere le seguenti funzioni: 
    1. Crea array
    2. Inserire elementi
    3. Stampa dei valori
    4. Esci
*/

#include <stdio.h>
#include <stdlib.h>

int* creaVett(int _n){

    int *_vett=(int*)malloc(_n *sizeof(int));

    if(_vett==NULL){
        printf("Errore di allocazione!\n");
        return 1;
    }

    return _vett;
}

int* insVett(int *_vett, int _n){

    for(int i=0; i<_n; i++){
        printf("Inserisci un elemento:");
        scanf("%d", &_vett[i]);
    }
    
    return _vett;
}

void stampaVett(int *_vett, int _n){

    for(int i=0; i<dim; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    
}

int main(){

    int n,*vett=NULL; //puntatore al vettore

    do{
        printf("Inserisci la quantità di elementi: ");
        scanf("%d", &n);
    }
    while(n<0);

    vett=creaVett(n);
    vett=insVett(vett,n);
    stampaVett(vett,n);

    free(vett);

}