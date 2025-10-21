/* Data una stringa contare il numero delle vocali */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char* string;

void compact(string buffer, int len){
    
    if(len>0 && buffer[len-1]=='\n'){
        buffer[len-1]='\0';
        len--;
    }
}

int cnt(string text){

    int cnt=0;

    for(int i=0; text[i]!='\0'; i++){
        char c=tolower(text[i]);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            cnt++;
        }
    }
    return cnt;
}

int main(){

    char buffer[200];
    string text;

    printf("Inserisci una stringa: \n");
    fgets(buffer, sizeof(buffer), stdin);

    int len=strlen(buffer);
    compact(buffer,len);
    text=(string)malloc((len+1)*sizeof(char));

    if(text==NULL){
        printf("C'è un errore!\n");
        return 1;
    }

    strcpy(text,buffer);

    printf("Il numero delle vocali è %d", cnt(text));
    free(text);
    return 0;
}