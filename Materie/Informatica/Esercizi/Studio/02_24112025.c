/* Eliminare gli spazi da una stringa */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* string;

int inseriscilen(int l){

    printf("\nInserisci la lunghezza della stringa");
    scanf("%d", l);

    return l;
}

string inseriscistringa(string s, int l){

    printf("\nInserisci la stringa: ");
    scanf("%d", l);

}
string eliminaspazi(string s,int len){

    int cnt=0;
    char tmp;

    for(int i=0; i<len; i++){
        if(s[i]==' '){
            cnt++;
            tmp=s[i];
            s[i]=s[i+1];
        }
    }
}
int main(){

    string s;
    int len;

    len=inseriscilen(len);
    s=inseriscistringa(s, len);

    s=eliminaspazi(s, len);

    printf("\nLa stringa senza spazi è: \n%s.", s);
    free(s);

    return 0;
}