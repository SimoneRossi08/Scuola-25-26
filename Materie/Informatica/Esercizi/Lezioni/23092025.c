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

int main(){

    int *array=NULL; //array dinamico
    int opt,n,t,dim=0,flag=0;

    do{
        printf("\nMenu:\n");
        printf("1. Aggiungi un numero.\n");
        printf("2. Visualizza tutti i numeri.\n");
        printf("3. Cercare un numero specifico.\n");
        printf("4. Ordina i numeri in ordine crescente.\n");
        printf("5. Elimina un numero.\n");
        printf("6. Esci.\n");
        printf("Scelta: ");
        scanf("%d", &opt);

        switch(opt){
            case 1:
                printf("Inserisci il numero da aggiungere: ");
                scanf("%d", &n);
                array=(int*)realloc(array, (dim+1)*sizeof(int));
                if(array==NULL){
                    printf("Errore! Allocazione fallita.\n");
                    break;
                }
                array[dim]=n;
                dim+1;
                printf("Numero aggiunto con successo.\n");
                break;
            case 2:
                if(dim==0){
                    printf("Errore! Array vuoto.\n");
                }
                else{
                    for(int i=0; i<dim; i++){
                        printf("%d ", array[i]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                printf("Inserisci il numero da cercare: ");
                scanf("%d", &n);

                for(int i=0; i<dim; i++){
                    if(array[i]==n){
                        flag=1;
                        printf("Numero %d trovato nella posizione %d.\n", n, i);
                        break;
                    }
                    else{
                    flag=0;
                    }
                }
                if(flag==0){
                    printf("Errore! Numero %d non trovato.\n", n);
                }
                break;
            case 4:
                for(int i=0; i<dim-1; i++){
                    for(int j=i+1; j<dim; j++){
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
                for(int i=0;i<dim; i++) {
                    if(array[i]==n){
                        for(int j=i; j<dim-1; j++){
                            array[j]=array[j+1];
                            dim-1;
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