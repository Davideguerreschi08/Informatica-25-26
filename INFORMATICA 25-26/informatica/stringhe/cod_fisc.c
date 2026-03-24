/*codice che calcola il codice fiscale*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

    char nome[20], cognome[20], data[11], sesso, comune[20];
    char codice_fiscale[17]; 
    int giorno, mese, anno;
    int i, j, consonanti, vocali;
    const char *mesi[] = {"A", "B", "C", "D", "E", "H", "L", "M", "P", "R", "S", "T"};
    const char *comuni[] = {"Ostiglia"};

    printf("Inserisci il nome: ");
    scanf("%s", nome);
    printf("Inserisci il cognome: ");
    scanf("%s", cognome);
    printf("Inserisci la data di nascita (aaaa/mm/gg): ");
    scanf("%s", data);
    printf("Inserisci il sesso (M/F): ");
    scanf(" %c", &sesso);
    printf("Inserisci il comune di nascita: ");
    scanf("%s", comune);        
    
    consonanti = 0;
    vocali = 0;
    j = 0;
    for(i = 0; i < strlen(cognome); i++){
        if(strchr("BCDFGHJKLMNPQRSTVWXYZ", toupper(cognome[i]))){
            codice_fiscale[j++] = toupper(cognome[i]);
            consonanti++;
        }
        

    }
    for(i = 0; i < strlen(cognome) && consonanti < 3; i++){
        if(strchr("AEIOU", toupper(cognome[i]))){
            codice_fiscale[j++] = toupper(cognome[i]);
            vocali++;
        }
    }
    while(consonanti + vocali < 3){
        codice_fiscale[j++] = 'X';
        vocali++;      
    } 
    
    consonanti = 0;
    vocali = 0;         
    for(i = 0; i < strlen(nome); i++){
        if(strchr("BCDFGHJKLMNPQRSTVWXYZ", toupper(nome[i]))){
            consonanti++;
        }
    }
    if(consonanti >= 4){
        consonanti = 0;
        for(i = 0; i < strlen(nome); i++){
            if(strchr("BCDFGHJKLMNPQRSTVWXYZ", toupper(nome[i]))
            ){
                if(consonanti != 1){
                    codice_fiscale[j++] = toupper(nome[i]);
                }
                consonanti++;
            }
        }

    }
    else{
        for(i = 0; i < strlen(nome); i++){
            if(strchr("BCDFGHJKLMNPQRSTVWXYZ", toupper(nome[i]))){
                codice_fiscale[j++] = toupper(nome[i]);
                consonanti++;
            }
        }
        for(i = 0; i < strlen(nome) && consonanti < 3; i++){
            if(strchr("AEIOU", toupper(nome[i]))){
                codice_fiscale[j++] = toupper(nome[i]);
                vocali++;
            }
        }
        while(consonanti + vocali < 3){
            codice_fiscale[j++] = 'X';
            vocali++;      
        } 
    }
    if(fgets(anno,20,stdin)!=NULL);
    printf("%s", anno);
    if(fgets(mese,20,stdin)!=NULL);
    printf("%s", mese);
    if(fgets(giorno,20,stdin)!=NULL);
    printf("%s", giorno);
    codice_fiscale[j++]=(anno/10%10)+'0';
    codice_fiscale[j++]=(anno % 10)+'0';  
    codice_fiscale[j++]=*mesi[mese-1];

    if(sesso == 'M' || sesso == 'm'){
        codice_fiscale[j++]=(giorno/10)+'0';
        codice_fiscale[j++]=(giorno % 10)+'0';
    }
    else if(sesso == 'F' || sesso == 'f'){
        giorno += 40;
        codice_fiscale[j++]=(giorno/10)+'0';
        codice_fiscale[j++]=(giorno % 10)+'0';
    }
    if(strcmp(comune, "Ostiglia") == 0){
        codice_fiscale[j++]='O';
        codice_fiscale[j++]='F';
        codice_fiscale[j++]='I';    
    }

    codice_fiscale[j]='\0';
    printf("Il codice fiscale e': %s\n", codice_fiscale);
    return 0;

}