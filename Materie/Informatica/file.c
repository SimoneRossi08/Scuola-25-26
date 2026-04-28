
FILE *f = fopen("dati.txt", "r");
ftell(f);
rewind(f);
fwrite(&n, sizeof(int), 1, f);
fread(&n, sizeof(int), 1, f);
fseek(f, offset, SEEK_SET);
fgetc(FILE *f);
fputc(int c, FILE *f);
fprintf(f, "%d\n", n);
fscanf(f, "%d", &n);
scanf(" %[^\n]", c.nome);