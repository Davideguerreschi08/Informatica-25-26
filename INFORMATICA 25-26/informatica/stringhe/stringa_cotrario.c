/*data una stringa scriverla al contrario*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* stringa;

void invertiStringa(stringa s, stringa str2);

int main(){
    stringa s1;
    stringa s2;
    invertiStringa(s1, s2);
    
}
void invertiStringa(stringa s, stringa str2){
    int len;
    printf("scrivi una frase da invertire:");
    fgets(s, 50, stdin);
    len = strlen(s);
    for(int i=0;i<len;i++){
        str2[i]=s[len-i-1];
    }
    str2[len]='\0';
    printf("la frase invertita e': %s", str2);
}