/*creare una rubrica che gestisca la memorizzazione dei contatti e ne visualizzi l'elenco*/
#include <stdio.h>
#include <stdlib.h>

typedef struct contatto{
    char telefono[30];
    char nome[30];
}contatto;

void aggiungoContatto(){
    FILE *fp=fopen("rubrica.bin", "ab");

    if(fp==NULL){
        printf("Errore apertura file\n");
        exit;
    }
    contatto cont;
    printf("\ninserisci il nome del contatto: ");
    scanf("%s[^\n]", cont.nome);
    printf("\ninserisci il numero di telefono: ");
    scanf("%s[^\n]", cont.telefono);
    fwrite(&cont, sizeof(contatto), 1, fp);
    fclose(fp);

}
 void stampaContatti(){
    FILE *fp=fopen("rubrica.bin", "rb");

    if(fp==NULL){
        printf("Errore apertura file\n");
        exit;
    }
    
    contatto c;
    printf("\n-----RUBRICA-----");

   while (fread(&c, sizeof(contatto), 1, fp)==1){
        printf("Nome: %s, Telefono: %s\n", c.nome, c.telefono);
   }
   fclose(fp);
 }

int main(){
    
    int scelta;

    do{
        printf("\nMenu rubrica:\n");
        printf("1. aggiungi contatto\n");
        printf("2. visualizza contatto\n");
        printf("0. esci\n");
        printf("scelta: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                aggiungoContatto();
                break;
            case 2:
                stampaContatti();
                break;
            case 0:
                    printf("esci dal programma");
                break;

            default:
            printf("ERRORE SCELTA NON VALIDA....");
        }
    }while(scelta!=0);

}
