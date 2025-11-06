/* Scrivere un programma in linguaggio C che calcoli e visualizzi il codice fiscale */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
typedef enum {true, false} bool;

int cnt;
string infoname(string name){

    string nnn;
    name=(string)malloc((20+1)*sizeof(char));
    printf("Inserisci il suo nome: ");
    fgets(name,20,stdin);
    name=(string)realloc(name, (strlen(name)+1)*sizeof(char));

    for(int i=0; i<strlen(name); i++){
        if(name[i]!='a'&&name[i]!='e'&&name[i]!='i'&&name[i]!='o'&&name[i]!='u'){
            cnt++;
        }
    }
    if(cnt>=4){
        nnn[0]=name[0];
        nnn[1]=name[1];
        nnn[2]=name[2];
    }

    return nnn;
}

string infosurname(string surname){


    surname=(string)malloc((20+1)*sizeof(char));
    printf("Inserisci il suo cognome: ");
    fgets(surname,20,stdin);
    surname=(string)realloc(surname, (strlen(surname)+1)*sizeof(char));

    for(int i=0; i<strlen(surname); i++){
        if(surname[i]!='a'&&surname[i]!='e'&&surname[i]!='i'&&surname[i]!='o'&&surname[i]!='u'){
            cnt++;
        }
    }
    if(cnt>=4){
        ccc[0]=surname[0];
        ccc[1]=surname[1];
        cc[2]=surname[2];
    }

    return ccc;
}

bool infosex(bool sex){

    string sSex=(string)malloc((20+1)*sizeof(char));
    printf("Inserisci il suo sesso: ");
    fgets(sSex,20,stdin);
    sSex=(string)realloc(sSex, (strlen(sSex)+1)*sizeof(char));

    if(sSex[1]=('F')){
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
        printf("\nMese: ");
        scanf("%d", &mm);
        if(mm>12 || mm<1){
            printf("\nERRORE. ");
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
        printf("\nGiorno: ");
        scanf("%d", &dd);
        if(dd>30 && mm!=1 && mm!=3 && mm!=5 && mm!=7 && mm!=8 && mm!=10 && mm!=12){
            printf("\nERRORE. ");
            flag=1;
        }
        if(dd>31 && mm==1 && mm==3 && mm==5 && mm==7 && mm==8 && mm==10 && mm==12){
            printf("\nERRORE. ");
            flag=1;
        }
        if(dd>29 && mm==2){
            printf("\nERRORE. ");
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
    printf("\nAnno: ");
    scanf("%d", &yy);

    return yy;    
}

 
int main(){

    string name;
    string surname;
    bool sex;
    int dd,mm,yy;
    char COM={'G186'};
    string fcode;

    name=fcodename=infoname(name);
    surname=infosurname(surname);
    mm=infomm(mm);
    dd=infodd(dd,fcodemm);
    yy=infoyy(yy);

    if(sex=false){
        dd+=40;
    }

    // CCC NNN YYMDD LLLL 

    printf("%s",fcode);

}