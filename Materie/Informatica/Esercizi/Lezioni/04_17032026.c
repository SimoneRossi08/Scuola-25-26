//scrittura di dati formattati
#include <stdio.h>

int main(){
	FILE *file = fopen("dati.txt", "w");
	
	if (file==NULL){
		printf("errore apertura file\n");
		return 1;
	}
	fprintf(file, "%s %d %.2f", "Luca", 12, 6.5);
	fclose(file);
	return 0;
}