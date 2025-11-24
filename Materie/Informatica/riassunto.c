#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  riassunto.c - documento didattico
  Spiegazioni e esempi (commentati) su:
   - stringhe statiche
   - allocazione dinamica (malloc, realloc, free)
   - input sicuro (scanf width, fgets) e pulizia del buffer
   - uso di realloc in blocchi
   - typedef per stringhe
   - errori comuni
   - funzioni principali di <string.h> con esempi
  Nota: le funzioni qui sono usate come contenitori di spiegazioni; gli snippet
  all'interno sono esempi commentati, non richiedono che il file sia eseguibile.
*/

    //Stringhe statiche
    - Una stringa in C è un array di char terminato dal byte '\0'.
    - Esempi:
     char s1[20] = "ciao";    // buffer fisso, può contenere fino a 19 caratteri + '\0'
     char s2[] = "hello";     // dimensione calcolata automaticamente (6)
     char s3[5] = {'c','i','a','o','\0'}; // inizializzazione esplicita
   // Limite: la dimensione è fissata al momento della dichiarazione.


    //Allocazione dinamica
    //Usare malloc per creare stringhe la cui dimensione è decisa a runtime.
    - Regole:
     * Sempre allocare spazio per il terminatore '\0' (strlen + 1).
     * Controllare il valore di ritorno di malloc/realloc.
     * Liberare la memoria con free quando non serve più.
    //Esempio:
    len = 20;
    char *s = malloc((len + 1)*sizeof(char)); // +1 per '\0'
    char *s = realloc(s, (len + 10)*sizeof(char));
    
    if(s == NULL){
        //errore
    }

    strncpy(s, "test", len);
    s[len] = '\0'; // sicurezza
    free(s);

    //Evitare buffer overflow: scanf width e fgets
   - scanf con specifica di larghezza: scanf("%19s", buf) per buf[20]
   - fgets legge fino a n-1 caratteri e conserva gli spazi; rimuove '\n' se necessario.

    //Typedef per stringhe
    - typedef char* String; // migliora la leggibilità didattica

    //Errori comuni con stringhe dinamiche (elenco e rimedi)
    - Dimenticare spazio per '\0' -> usare strlen+1
    - Non controllare malloc/realloc -> controllare sempre i ritorni
    - Usare scanf("%s") senza limite -> usare width o fgets
    - Dimenticare free -> memory leak
    - Usare la memoria dopo free -> comportamento indefinito



    //Funzioni principali di <string.h> con esempi e note
    - strlen(const char *s): //restituisce numero di byte prima di '\0'
        L = strlen("ciao"); // 4
    - strcpy(dest, src): //copia tutta la stringa (assicurarsi che dest sia abbastanza grande)
    - strncpy(dest, src, n): //copia al massimo n caratteri; non garantisce terminazione se src >= n
        // quindi fare dest[n-1] = '\0' quando serve
    - strcat(dest, src): //concatena src in fondo a dest/
    - strncat(dest, src, n): //concatena al massimo n caratteri da src
    - strcmp(s1, s2): //confronto lessicografico (0 se uguali, <0, >0)
    - strncmp(s1, s2, n): //confronto sui primi n caratteri
    - strchr(s, c): //trova primo occorrenza di c -> restituisce puntatore o NULL
    - strrchr(s, c): //trova ultima occorrenza di c
    - strstr(haystack, needle): //trova sottostringa needle in haystack
    - strtok(s, delim): //tokenizza