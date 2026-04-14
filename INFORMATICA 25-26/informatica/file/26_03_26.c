/*esempio di apertura file in append*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp;
    char frase[200];
    char scelta;
    fp = fopen("righe.txt", "a");
    if (fp == NULL) {
        printf("Errore nell'aprire il file.\n");
       exit;
 
    }
    do {
        printf("inserisci una frase: ");
        fgets(frase, sizeof(frase), stdin);
        //scriviamo la frase nel file
       fputs(frase,fp);
        printf("Vuoi inserire un altra frase? (s/n): ");
        scanf("%c", &scelta);
        getchar();
    }while(scelta == 's' || scelta == 'S');
    fclose(fp);
    printf("le frasi sono state aggiunte al file righe.txt");
    return 0;
}
