/* Scrivere un programma in linguaggio C che calcoli e visualizzi il codice fiscale */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
typedef enum {true, false} bool;

string infoname(string name){

    name=malloc(name, 20*sizeof(char));
    printf("Inserisci il suo nome: ");
    fgets(name,stdin);
    name=reallo(rname, (strlen(name))*sizeof(char));

    return name;
}

string infosurname(string surname){

    surname=malloc(surname, 20*sizeof(char));
    printf("Inserisci il suo cognome: ");
    fgets(surname,stdin);
    surname=reallo(surname, (strlen(surname))*sizeof(char));

    return surname;
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

int infomm(int mm){

    int flag;
    printf("Inserisci la sua data di nascita: ");

    //mese
    do{
        printf("\nMese:");
        scanf("%d", &mm);
        if(mm>12 || mm<1){
            printf("\nERRORE.");
            flag=1;
        }
        else{
            flag=0;
        }
    }while(flag!=0);
    
    return mm;
}

int infodd(int dd, int mm){

    int flag;

    //giorno
    do{
        printf("\nGiorno:");
        scanf("%d", &dd);
        if(dd>30 && mm!=1 && mm!=3 && mm!=5 && mm!=7 && mm!=8 && mm!=10 && mm!=12){
            printf("\nERRORE.");
            flag=1;
        }
        if(dd>31 && mm==1 && mm==3 && mm==5 && mm==7 && mm==8 && mm==10 && mm==12){
            printf("\nERRORE.");
            flag=1;
        }
        if(dd>29 && mm==2){
            printf("\nERRORE.");
            flag=1;
        }
        else{
            flag=0;
        }
    }while(flag!=0);

    return dd;
}

int infoyy(int yy){

    //anno
    printf("\nAnno:");
    scanf("%d", &yy);

    return yy;    
}

int main(){

    string name;
    string surname;
    bool sex;
    int dd,mm,yy;

    string fcode;
    string fcodename=infoname(name);
    string fcodesurname=infosurname(surname);
    string fcodemm=infomm(mm);
    string fcodedd=infodd(dd,fcodemm);
    string fcodeyy=infoyy(yy);
    char fcodeCOM={'G186'};

    // CCC NNN YYMDD LLLL 

    fcode=strcat(fcodesurname,fcodename);
    fcode=strcat(fcode,fcodeyy);
    fcode=strcat(fcode,fcodemm);
    fcode=strcat(fcode,fcodedd);
    fcode=strcat(fcode,fcodeCOM);

    printf("%s",fcode);

}