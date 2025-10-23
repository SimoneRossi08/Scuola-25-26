#include "stdstr.h"
#include <stdio.h>
#include <stdlib.h>

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n'){}
}

string crstringdim(int n){
    string c = (string) malloc(n * sizeof(char));
    if(c == NULL){
        printf("Errore di allocazione!\n");
        exit(1);
    }
    fgets(c, n, stdin); //n=5 "ciao oggi è proprio divertente"
    clear_buffer();
    return c;
}

string crea_string_dinamica(char terminator){
    string str = NULL;
    int size = 0;       // lunghezza corrente della string
    int capacity = 0;   // spazio totale allocato
    char c;

    printf("Inserisci una string (termina con %c):\n", terminator);

    while ((c = getchar()) != terminator && c != EOF) {  // finchè l'utente non inserisce il carattere terminatore o non si raggiunge la fine di un file
        if (size + 1 >= capacity) {
            capacity += 10; // rialloco a blocchi di 10
            str = (string) realloc(str, capacity * sizeof(char));
            if (str == NULL) {
                printf("Errore di allocazione\n");
                exit(1);
            }
        }
        str[size++] = c;
    }
    str[size] = '\0'; // aggiungo terminatore della string

    return str;
}

int clclenstring(string s){
    int dim=0;
    while(s[dim]!='\0') dim++;
    
    return dim;
}

string concatena_stringhe(string s1, string s2, char separatore){
    int dim1 = clclenstring(s1);
    int dim2 = clclenstring(s2);
    int dim3 = dim1 + dim2 + 2;
    string s3 = (string)malloc(dim3 * sizeof(char));
    if(s3 == NULL) {
        printf("Errore di allocazione \n");
        exit(1);
    }
    int i = 0;
    for(i = 0; i < dim1; i++){
      s3[i] = s1[i];  
    }
    s3[i] = separatore;

    for(int j = 0; j < dim2; j++){
        i++;
        s3[i] = s2[j];
        
    }
    s3[++i] = '\0';
    return s3;
}
int conta_occorrenze(string s1, char carattere){
    int dim = 0;
    int cnt_carattere = 0;
    while(s1[dim] != '\0'){
        if(s1[dim] == carattere)
            cnt_carattere++;
        dim++;
    }
    return cnt_carattere;

}
int string_in(string s1, string s2){
    int dim1 = clclenstring(s1);
    int dim2 = clclenstring(s2);
    int flag = 0;
    int cnt = 0;

    for(int i = 0; i <= dim1-dim2+1; i++){
        if(s1[i] == s2[0]){
            flag = 1;
            for(int j = 1; j < dim2; j++){
                if(s1[i+j] != s2[j]){
                flag = 0;
                break;
                }
            }
            cnt += flag;
        }
    }
    return cnt;
}

char** dividi_string(string s1, char separatore){
    char** risultato = NULL;
    int lunghezza_totale = clclenstring(s1);
    int lunghezza1 = 0, lunghezza2 = 0;
    int i = 0;
    risultato = (char**) malloc(2 * sizeof(string));
    //s1 "ciao,belli"\0
    while(s1[i]!=separatore){
        i++;
    }
    lunghezza1 = i+1; //5
    lunghezza2 = lunghezza_totale - lunghezza1;
    risultato[0] = (string) malloc(lunghezza1 * sizeof(char));
    risultato[1] = (string) malloc(lunghezza2 * sizeof(char));

    for(int j = 0; j < lunghezza1-1; j++){
        risultato[0][j] = s1[j];
    }
    risultato[0][lunghezza1] = '\0';
    int cnt = 0;
    for(int j=lunghezza1; j<lunghezza_totale; j++){
        risultato[1][cnt] = s1[j];
        cnt++;
    }
    risultato[1][lunghezza2] = '\0';

    return risultato;
}
string crea_copia(string s1){
    string s2;
    int lung=clclenstring(s1)+1;
    s2=(string)malloc(lung *sizeof(char));
    for(int i=0; i<lung; i++){
        s2[i]=s1[i];
    }
    return s2;
}
Bool equivalenti(string s1, string s2){
    int lung1=clclenstring(s1)+1;
    int lung2=clclenstring(s2)+1;
    if(lung1==lung2){
        for(int i=0; i<lung1; i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }return true;
    }else return false;
}

void maiuscole_minuscole(string s1, Bool maiusc_to_minusc){
    int i=0;
    if(maiusc_to_minusc){
        while(s1[i] != '\0'){
            if(s1[i]>=65 && s1[i] <= 90){
                s1[i]+=32;
            }
            i++;
        }
    }else {
        while(s1[i] != '\0'){
            if(s1[i]>=97 && s1[i] <= 122){
                s1[i]-=32;
            }
        }
        i++;
    }

}