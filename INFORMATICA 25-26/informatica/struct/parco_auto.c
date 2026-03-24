#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char targa[8];
    char marca[20];
    char modello[20];
    float prezzo;
} Auto;

void assegna_auto(Auto* parco, int *n);
void stampaAuto(Auto* parco, int *n);
int main(){
    Auto* parco=NULL;
    int n=0;
    int scelta;
    do{
        printf("1- Assegna auto\n");
        printf("2- Stampa auto\n");
        printf("0- Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        switch(scelta){
        case 1:
            assegna_auto(parco, &n);
            break;
        case 2:
            stampaAuto(parco, &n);
            break;
        case 0:
            printf("Uscita dal programma\n");
            break;
        default:
            printf("Scelta non valida\n");
    }
}while(scelta!=0);
    
    free(parco);
    return 0;
}
void assegna_auto(Auto** parco, int *n){
printf("----Parco Auto----\n");

printf("assegna la targa: ");
fgets(*parco[*n].targa, 8, stdin);
printf("assegna la marca: ");
fgets(*parco[*n].marca, 8, stdin);
printf("assegna il modello: ");
fgets(*parco[*n].modello, 8, stdin); 
printf("assegna il prezzo: ");
scanf("%f", &(*parco)[*n].prezzo);
while(getchar()!='\n'); 
parco=(Auto*)realloc(parco, sizeof(Auto)*(*n+1));
if(parco==NULL){
    printf("Errore di allocazione memoria\n");
    exit(1);
}
(*n)++;

}
void stampaAuto(Auto* parco, int *n){
    
for(int i=0; i<n; i++){
    printf("la targa dell' auto %d è %s\n", i+1, parco[i].targa);
    printf("la marca dell' auto %d è %s\n", i+1, parco[i].marca);
    printf("il modello dell' auto %d è %s  \n", i+1, parco[i].modello);
    printf("il prezzo dell' auto %d è %.2f\n", i+1, parco[i].prezzo);
}
