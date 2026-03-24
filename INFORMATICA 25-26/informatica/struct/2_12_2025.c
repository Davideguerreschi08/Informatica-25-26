/* esempio di utilizzo di una struttura complessa 
   facendo accesso ai campi in modalità variabile 
   e in modalità puntatore alla struttura
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[20];
	char cognome[20];
	int eta;
}Persona;

int main(){
	Persona p1;
	Persona *p2;
	
	//inseriamo le informazioni in p1
	printf("Inserisci il nome della persona: ");
	scanf("%s", p1.nome);
	fflush(stdin);
	printf("Inserisci il cognome della persona: ");
	scanf("%s", p1.cognome);
	fflush(stdin);
	printf("Inserisci l'età' della persona: ");
	scanf("%d", &(p1.eta));
	fflush(stdin);
	
	printf("Dati della persona: %s, %s, %d", p1.nome, p1.cognome, p1.eta);
	
	//inseriamo le informazioni in p2
	p2=malloc(sizeof(Persona));
	printf("Inserisci il nome della persona: ");
	scanf("%s", p2->nome);
	fflush(stdin);
	printf("Inserisci il cognome della persona: ");
	scanf("%s", p2->cognome);
	fflush(stdin);
	printf("Inserisci l'età' della persona: ");
	scanf("%d", &(p2->eta));
	fflush(stdin);
	
	printf("Dati della persona: %s, %s, %d", p2->nome, p2->cognome, p2->eta);
}