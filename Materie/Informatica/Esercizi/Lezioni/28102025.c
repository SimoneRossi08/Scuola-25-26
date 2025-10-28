/*  PROVARE LA LIBRERIA string.h 
    PER LE SEGUENTI OPERAZIONI
    1. CALCOLO LUNGHEZZA STRINGA
    2. CONTROLLO STRINGHE UGUALI
    3. COPIARE UNA STRINGA
    4. CERCARE UN CARATTERE E COMUNICARE LA FREQUENZA
    5. CONCATENARE DUE STRINGHE
    6. RICERCA DI UNA STRINGA DELL'ALTRA
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* string;

int main(){

    string s1="habibi";
    string s2="yallah";
    string s3;
    string s4;
    string s5;
    char c;

    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("\n");

    // calcolo lunghezza
    int len1=strlen(s1);
    int len2=strlen(s2);

    // copia di stringhe
    s3=strncpy(s3, s1, len1);
    s4=strncpy(s4, s2, len2);
    printf("%s\n", s2);
    printf("%s\n", s3);
    printf("\n");

    // confronto tra stringhe
    printf("%d\n", strcmp(s1,s2));
    printf("\n");

    // concatena stringhe
    s5=strcat(s1,s2);
    printf("%s\n", s5);
    printf("\n");

    // cerca carattere
    /*printf("Inserisci un carattere: \n",);
    scanf("%c ", &c);
    printf("%d\n", );
    printf("\n");*/

    // cerca stringa
    printf("%s\n", strstr(s5,s1));

    return 0;
}