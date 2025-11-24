/*
    Scrivi un programma in C che chieda nome e cognome all'utente. 
    Se il cognome dell'utente è "Miotto" allora si assegna allo studente
    una nota che dice che lo studente parla troppo.
    Se il nome dello studente inizia con "Prais" allora si assegna
    una nota che dice che lo studente è troppo bello.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* string;

string inseriscistringa(string s){

    s=(string)malloc(20*sizeof(char));
    if(s==NULL){
        printf("ERRORE!");
        exit(1);
    }
    printf("Inserisci una stringa: ");
    fgets(s, 20, stdin);

    return s;
}

int main(){

    string nome,cognome;

    nome=inseriscistringa(nome);
    cognome=inseriscistringa(cognome);

    //char mp="Miotto";
    if(cognome==strstr(cognome,"Miotto")){
        printf("L'alunno parla troppo.");
    }
    else if(strstr(nome,"Prais")!=NULL){
        printf("L'alunno è troppo bello.");
    }
}