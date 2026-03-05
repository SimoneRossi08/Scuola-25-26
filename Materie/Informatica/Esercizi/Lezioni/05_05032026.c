#include <stdio.h>
#include <stdlib.h>

typedef struct Persona{
    char nome[20];
    char cognome[20];
    int età;
}Persona;

int main(){

    int n;
    printf("Quante persone si vuole inserire?");
    scanf("%d", &n);
    Persona *p=(Persona)malloc(n*sizeof(Persona));
    FILE *file=fopen("05_05032026.txt", "w");
    if(file==NULL){
        printf("Errore apertura file. \n");
        return 1;
    }

    for(int i=0; i<n; i++){
        fprintf(file, "%s %s %d", p.nome, p.cognome, p.età);
    }

    fclose(file);
    return 0;
}