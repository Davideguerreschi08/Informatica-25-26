#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona{
    char nome [50];
    char cognome [50];
    int eta;
}persona;

int main(){
    FILE *file=fopen("persona.txt", "w");
    persona *p;
    int n;
    printf("quante persone devi registrare?");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("nome: ");
        scanf("%s",  p[i].nome);
        printf("cognome: ");
        scanf("%s", p[i].cognome);
        printf("età: "); 
        scanf("%d",  p[i].eta);

    }
    for(int i=0; i<n; i++){
        printf("nome: %s",p[i].nome);
        printf("cognome: %s", p[i].cognome);
        printf("eta: %d", p[i].eta);
   }
}