/*data una stringa contare il numero delle vocali */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char* stringa;

void compatta(stringa buffer, int len);
int conteggio(stringa frase);
int main() {  
    char buffer[200];
    stringa frase=NULL;
    int len;
    int cnt=0;
    printf("inserisci una stringa: ");
    fgets(buffer, sizeof(buffer), stdin);
    len = strlen(buffer);
    compatta(buffer, len);
    frase=(stringa)malloc((len+1)*sizeof(char));
    if (frase==NULL){
        printf("Errore di allocazione memoria\n");
        return 1;
    }
    strcpy(frase, buffer);
    printf("il numero delle vocali e': %d\n", conteggio(frase));
    free(frase);
    return 0;
}
void compatta(stringa buffer, int len){
    if(len>0 && buffer[len-1]=='\n'){
        buffer[len-1]='\0';
        len--;
    }
}
int conteggio(stringa frase){
    int cnt=0;
    char c;
    for(int i=0; frase[i]!='\0'; i++){
        c=tolower(frase[i]);
         if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'|| c=='A'){
            cnt++;
             
         }  
        }
        return cnt;
    }
