/* Elimare gli spazi da una stringa */

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

int spaceremove(string text, int len){

    for(int i=0; text[i]!='\0'; i++){
        if(text[i]==' '){
            for(int j=i; text[j]!='\0';j++){
                text[j]=text[i+1];
            }
            len=strlen(text);
        }
    }
    return len;
}

int main(){

    char buffer[200];
    string text;

    printf("Inserisci una stringa: \n");
    fgets(buffer, sizeof(buffer), stdin);
    int len=strlen(buffer);

    text=(string)malloc((len+1)*sizeof(char));
    if(text==NULL){
        printf("C'è un errore!\n");
        return 1;
    }

    compact(buffer,len);
    strcpy(text,buffer);

    spaceremove(text,len);
    
    free(text);
    return 0;
}