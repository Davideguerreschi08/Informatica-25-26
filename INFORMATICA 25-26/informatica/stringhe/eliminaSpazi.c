/*Elimina gli spazi da una stringa*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char* stringa;

void compattaSpazi(stringa buffer, int len);

int main() {  
    char buffer[200];
    stringa frase=NULL;
    int len;
    int cnt=0;
    printf("inserisci una stringa: ");
    fgets(buffer, sizeof(buffer), stdin);
    len = strlen(buffer);
    frase=(stringa)malloc((len+1)*sizeof(char));
    if (frase==NULL){
        printf("Errore di allocazione memoria\n");
        return 1;
    }
    strcpy(frase, buffer);
    compattaSpazi(buffer, len);
    printf("la stringa senza spazi e': %s\n", frase);
    free(frase);
}
void compattaSpazi(stringa buffer, int len){
        for(int i=0; i<len; i++){
            if(buffer[i]==' '){
                for(int j=i; j<len; j++){
                    buffer[j]=buffer[j+1];
                    len--;
                }
                buffer=(stringa)realloc(buffer, len+1*sizeof(char));
                    if(buffer==NULL){
                        printf("Errore di riallocazione memoria\n");
                        exit(1);
                    }
            }
        }
        
    }
