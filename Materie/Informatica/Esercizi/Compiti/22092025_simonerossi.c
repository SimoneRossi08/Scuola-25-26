/* Scrivere un programma in C che gestisca un insieme di numeri interi usando un array dinamico.
Il programma deve permettere, tramite menù:
    1. Aggiungere un numero (espandendo l’array con realloc)
    2. Visualizzare tutti i numeri
    3. Cercare un numero specifico
    4. Ordinare i numeri in ordine crescente
    5. Eliminare un numero scelto
    6. Uscire                       */

#include <stdio.h>
#include <stdlib.h>
#define DIM 5

int main(){

    int array[DIM]={1,2,3,4,5},opt,n,t;

    do{
        printf("\nMenu:\n");
        printf("1. Aggiungi un numero\n");
        printf("2. Visualizza tutti i numeri\n");
        printf("3. Cercare un numero specifico\n");
        printf("4. Ordina i numeri in ordine crescente\n");
        printf("5. Elimina un numero scelto\n");
        printf("6. Esci\n");
        printf("Scelta: ");
        scanf("%d", &opt);

        switch(opt){
            case 1:
                printf("Inserisci il numero da aggiungere: ");
                scanf("%d", &n);
                DIM+1;
                array[DIM]=n;
                break;
            case 2:
                for(int i=0; i<DIM; i++){
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            case 3:
                printf("Inserisci il numero da cercare: ");
                scanf("%d", &n);

                for(int i=0; i<DIM; i++){
                    if(array[i]==n){
                        printf("Numero %d trovato nella posizione %d.\n", n, i);
                        break;
                    }
                    else{
                    printf("Numero %d non trovato.\n", n);
                    }
                }
                break;
            case 4:
                for(int i=0; i<DIM-1; i++){
                    for(int j=i+1; j<DIM; j++){
                        if(array[i]>array[j]){
                            t=array[i];
                            array[i]=array[j];
                            array[j]=t;
                        }
                    }
                }
                break;
            case 5:
                printf("Inserisci il numero da eliminare: ");
                scanf("%d", &n);
                for(int i=0;i<DIM; i++) {
                    if(array[i]==n){
                        for(int j=i; j<DIM-1; j++){
                            array[j]=array[j+1];
                            DIM-1;
                        }
                    }
                }
                break;
            default:
                printf("Scelta non valida. Riprova.\n");   
                break;
        }
    }
    while(opt!=6);
    printf("Uscita dal programma.\n");

    return 0;
}       
