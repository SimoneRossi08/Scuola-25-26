//lettura di dati formattati
#include <stdio.h>

int main(){

    char nome[100];
    int età;
    float media;

    FILE *file=fopen("dati.txt", "r");
    if(file==NULL){
        printf("Errore apertura file. \n");
        return 1;
    }
    fscanf(file, "%s %d %f", nome, &età, &media);
    printf("Nome: %s; Età: %d; Media: %.2f.", nome,età,media);

    fclose(file);
    return 0;
}