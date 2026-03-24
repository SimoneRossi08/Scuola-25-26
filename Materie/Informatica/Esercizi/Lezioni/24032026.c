/*
INSERIRE LE INFORMAZIONI DI STUDENTI:
    NOME - ETÀ - MEDIA VOTI
DETERMINARE LO STUDENTE CON LA
    MEDIA SCOLASTICA PIÙ ALTA 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studente{
    char nome[20];
    int età;
    float media;
}studente;

void scriviStudenti(char *nome_file, int n_studenti){

    FILE *f=fopen(nome_file, "wb");
    if(f==NULL){
        printf("\nErrore apertura file...");
        return;
    }

    for(int i=0; i<n_studenti; i++){
        studente s;
        printf("Inserisci nome studente %d: ", i+1);
        scanf("%49s", s.nome);
        printf("Inserisci età studente %d: ", i+1);
        scanf("%d", &s.età);
        printf("Inserisci media studente %d: ", i+1);
        scanf("%f", &s.media);
        getchar();
        fwrite(%s, sizeof(studente),1,f);
    }
    fclose(f);
    if(error(f)){
        printf("Errore chiusura file...");
    }
}
studente leggiStudenti(char *nome_file, studente *array){

    FILE *f=fopen(nome_file, "rb");
    if(f==NULL){
        printf("\nErrore apertura file...");
        return array;
    }

    int i=0;
    array=(studente*)realloc(array,sizeof(studente));
    while(fread(&array[i], sizeof(studente),1,f)!=0){
        i++;
        array=(studente*)realloc(array,sizeof(studente));
        if(array==NULL){
        printf("\nErrore di allocazione...");
        return array;
        }
    }
    array=(studente*)realloc(array,sizeof(studente));
    if(array==NULL){
        printf("\nErrore di allocazione...");
        return array;
    }
    fclose(f);
    if(error(f)){
        printf("Errore chiusura file...");
    }
    return array;
}

studente trova_migliore(studente *array){

    int dim=sizeof(array)/sizeof(studente);
    studente best={"",0,0};

    for(inti=0, i<dim; i++){
        if(array[i].media > best.media){
            best.media= array[i].media;
            best.eta array[i].eta;
            strcpy(best.nome, array[i].nome);
        }
    }
    return best;
}