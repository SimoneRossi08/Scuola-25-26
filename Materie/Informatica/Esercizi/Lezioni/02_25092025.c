/* Scrivere un programma in linguaggio C che:
    1. Allochi dinamicamente un array iniziale di N numeri
    2. Inserimento dei valori
    3. Stampa array
    4. Calcoli la somma degli elementi multipli di 3
    5. Creiamo un nuovo array contenente solo valori dispari
*/

#include <stdio.h>
#include <stdlib.h>

int* creaarray(int _n){

    int *_array=(int*)malloc(_n *sizeof(int));

    if(_array==NULL){
        printf("Errore di allocazione!\n");
        return NULL;
    }

    return _array;
}

int* insarray(int *_array, int _n){

    for(int i=0; i<_n; i++){
        printf("Inserisci un elemento:");
        scanf("%d", &_array[i]);
    }
    
    return _array;
}

void stampaarray(int *_array, int _n){

    for(int i=0; i<_n; i++){
        printf("%d ", _array[i]);
    }
    printf("\n");
}

int* sommultipli(int *_array, int _n, int _s){

    for(int i=0; i<_n; i++){
        if(array[i]%3==0){
            _s+=_array[i];
        }
    }
    
    return _s;
}

int* disparray(int *_array, int _n, int *_dim){

    int *_d=NULL;
    *_dim=0;

    for(int=0; i<_n; i++){
        if(_array[i]%2!=0){
            (*_dim)++;
            int *tmp=realloc(_d, (*_dim)*sizeof(int));
            if()
        }
    }

}

int main(){
    
    int n,s,*d,dim,*array=NULL;

    do{
        printf("Inserisci la quantità di elementi: ");
        scanf("%d", &n);
    }
    while(n<0);

    array=creaarray(n);
    array=insarray(array,n);
    stampaarray(array,n);
    s=sommultipli(array,n,s);
    printf("\nLa somma dei multipili di 3 vale %d.", s);
    //creiamo l'array contenente i valori dispari tramite realloc
    d=disparray(array,n,&dim);
    free(array);

    return 0;
}