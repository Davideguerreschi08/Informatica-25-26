/*dato una stringa trovare una sotto stringa*/
#include <stdio.h>

typedef char* stringa;

int main(){
    stringa s1;
    stringa s2;
    
    printf("scrivi una frase: ");
    fgets(s1, 50, stdin);
    printf("scrivi una sotto frase da cercare: ");
    fgets(s2, 20, stdin);

    for(int i=0; s1[i]!='\0'; i++){
        for(int j=0;s2[i]!='\0'; j++){
            if(s1[i+j]==s2[j]){
                if(s2[j+1]=='\0'){
                    printf("sotto stringa trovata");
                }   
                printf("sotto stringa non trovata");
            }
        }
    }
    printf("la sotto stringa è %s", s2);
}