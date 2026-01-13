/*  Classe di studenti:
    Cognome, Nome, classe, matricola
    Per ogni studente dotato di matricola abbiamo le
    informazioni riguardante gli esami e il livello raggiunto.
    1) Ricercare lo studente con più certificazione.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char cognome[20];
    char nome[20];
    char classe[3];
    int matricola; //1000 - 9999
    int certificazioni;
}studente;

typedef struct{
    int matricola;
    struct{
        char corso[20];
        int livello; //(1-3)
    }esame;
}certificazione;

int main(){

    int n=3,num,cmax,cmin,imax;
    studente *studenti=(studente)malloc(n*(sizeof*(studente)));
    if(studenti==NULL){
        printf("Errore di allocazione");
        return 1;
    }
    certificazione *certificazioni=(certificazione)malloc(n*(sizeof*(certificazione)));
    if(certificazioni==NULL){
        printf("Errore di allocazione");
        return 1;
    }

    strcpy(studenti[0].cognome, "Rossi");
    strcpy(studenti[0].nome, "Roberto");
    strcpy(studenti[0].classe, "4I");
    studenti[0].matricola=123;
    studenti[0].certificazioni=0;

    strcpy(studenti[2].cognome, "Verdi");
    strcpy(studenti[2].nome, "Carlo");
    strcpy(studenti[2].classe, "3IA");
    studenti[2].matricola=456;
    studenti[2].certificazioni=0;

    strcpy(studenti[3].cognome, "Gialli");
    strcpy(studenti[3].nome, "Sofia");
    strcpy(studenti[3].classe, "3I");
    studenti[3].matricola=789;
    studenti[3].certificazioni=0;

    certificazioni[0].matricola=123;
    strcpy(certificazioni[0].esame.corso, "Inglese");
    certificazioni[0].esame.livello=2;

    certificazioni[1].matricola=123;
    strcpy(certificazioni[1].esame.corso, "Tedesco");
    certificazioni[1].esame.livello=3;

    certificazioni[2].matricola=789;
    strcpy(certificazioni[2].esame.corso, "Inglese");
    certificazioni[2].esame.livello=1;

    for(int i=0; i<n; i++){
        printf("Studente: %d\n", i+1);
        printf("Cognome: %s\n", studenti[i].cognome);
        printf("Nome: %s\n", studenti[i].nome);
        printf("Classe: %s\n", studenti[i].classe);
        printf("Matricola: %d\n", studenti[i].matricola);
        printf("Numero Certificazioni: %d\n\n", studenti[i].certificazioni);
    }

    for(int i=0; i<n; i++){
        printf("Studente: %d\n", i+1);
        printf("Matricola: %d\n", certificazioni[i].matricola);
        printf("Corso: %s\n", certificazioni[i].esame.corso);
        printf("Livello Certificazione: %d\n\n", certificazioni[i].esame.livello);
    }

    for(int i=0; i<n; i++){
        num=studenti[i].matricola;
        for(int j=0; j<n; j++){
            if(certificazioni[j].matricola==num){
                studenti[i].matricola+=1;
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("Studente: %d\n", i+1);
        printf("Cognome: %s\n", studenti[i].cognome);
        printf("Nome: %s\n", studenti[i].nome);
        printf("Classe: %s\n", studenti[i].classe);
        printf("Matricola: %d\n", studenti[i].matricola);
        printf("Numero Certificazioni: %d\n\n", studenti[i].certificazioni);
    }

    cmax=studenti[0].certificazioni;
    imax=0;
    for(int i=0; i<n; i++){

        if(studenti[0].certificazioni>cmax){
            cmax=studenti[0].certificazioni
            imax=i;
        }
    }

    prinf("\nLo studente con il maggior numero di certificazioni è %s %s.", studenti[i].cognome,studenti[i].nome);
    
    free(studenti);
    free(certificazioni);
    
    return 0;
}