/*Classe di studenti: Cognome, nome, calsse, matricola
Per ogni studente dotato di matricola abbiamo 
le informazione riguardante gli esami e il livello raggiunto
1) ricercare lo studente con più certificazioni*/
#include <stdio.h>
#include <stdlib.h>

typedef struct studente{
    char Cognome[20];
    char Nome[20];
    char classe[5];
    int matricola;//1000-9999
};

typedef struct{
    int matricola;
    struct esame{
        char corso[20];
        int livello;
    };
}certificazioni;

void menu(){
    printf("inserire le informazioni dello studente da registrare\n");
    printf("\nRicerca dello studente con più certificazioni");
    printf("\n");
    
}
int main(){
    menu();
}