/*dato una stringa trovare una sottostringa*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char* string;

int main(){
    string s1;
    string s2;
    
    printf("scrivi una frase: ");
    fgets(s1, 50, stdin);
    printf("scrivi una sottofrase da cercare: ");
    fgets(s2, 20, stdin);

    for(int i=0; s1[i]!='\0'; i++){
        for(int j=0;s2[i]!='\0'; j++){
            if(s1[i+j]==s2[j]){
                if(s2[j+1]=='\0'){
                    printf("sottostringa trovata");
                }   
                printf("sottostringa non trovata");
            }
        }
    }
    printf("la sottostringa è %s", s2);
}