/* Scrivere un programma in linguaggio C che calcoli e visualizzi il codice fiscale */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
typedef enum {true, false} bool;

string infoname(string name, string surname){

    name=malloc(name, 20*sizeof(char));
    printf("Inserisci il suo nome: ");
    fgets(name,stdin);
    name=reallo(rname, (strlen(name))*sizeof(char));

    surname=malloc(surname, 20*sizeof(char));
    printf("Inserisci il suo cognome: ");
    fgets(surname,stdin);
    surname=reallo(surname, (strlen(surname))*sizeof(char));

}

bool infosex(bool sex){

    string sex=malloc(sex, 20*sizeof(char));
    printf("Inserisci il suo sesso: ");
    fgets(sex,stdin);
    sex=reallo(sex, (strlen(sex))*sizeof(char));

    if(sex[1]=('F')){
        return false;
    }
    else{
        return true;
    }

}
void fcode(string name, string surname, bool sex, int dd, int mm, int yy){


}

int main(){

    string name;
    string surname;
    bool sex;
    int dd,mm,yy;



}