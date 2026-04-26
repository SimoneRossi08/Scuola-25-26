#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
typedef struct{
    void (*exe)(char[]);
}script;

string salvanome(){
    char nome[30];
    printf("come ti chiami?");
    scanf("%c", nome);
    return nome;
}

int main(){
    script salvanome;
    char name[30]=salvanome;
    printf("%c", name);
    return 0;
}