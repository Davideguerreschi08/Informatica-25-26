#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char s1[]="come";
    char s2[]="va";
    char s[] = "programmazione in C";
    char delim[]="_";
    char sub[]="zio";
    //lunghezza delle stringhe
    printf("la prima strimga ha lunghezza di %zu caratteri\n,", strlen(s1));
    printf("la seconda strimga ha lunghezza di %zu caratteri\n,", strlen(s2));
    //copia stringa
    if(strcpy(s1,s2)==0){
                printf("la prima stringa è uguale alla seconda\n");

    } else {
         printf("la prima stringa non è uguale alla seconda\n");
    }
    //concatenazione
    strcat(s1,s2);
    printf("la concatenazione delle due stringhe è: %s\n",s1);
    //confronto
    if(strcmp(s1,s2)==0){
        printf("le due stringhe sono uguali\n");
    } else {
        printf("le due stringhe sono diverse\n");
    }

    strchr(s1,'c');
    printf("la prima occorrenza del carattere 'c' nella prima stringa è: %s\n",strchr(s1,'c'));
    strrchr(s1,'c');
    printf("l'ultima occorrenza del carattere 'c' nella prima stringa è: %s\n",strrchr(s1,'c'));

    strstr(s,"zio");
    printf("la sottostringa 'sub' nella stringa principale è: %s\n",strstr(s,"zio"));
    printf("la prima token della stringa principale è: %s\n",strtok(s,delim));
}
