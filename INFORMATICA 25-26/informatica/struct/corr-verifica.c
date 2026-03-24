#include <stdio.h>
#include <stdlib.h>


typedef struct data{//dichiarazione della struct Data
		int giorno;// capo giorno
		int mese;//campo mese
		int anno;//campoanno
}data;

typedef struct libro{////dichiarazione della struct libro
	char titolo[30];//capo (stringa) titolo
	char autore[30];//capo (stringa) autore
	int isbn;       //campo isbn (codice identificativo del libro)
	int copie_totali;// campo copie totali
	int copie_disp;//campo copie disponibili 
	data pres;//campo di tipo data annidato alla struct data 
	data res;//campo di tipo data annidato alla struct data 
	
}libro;


void presLibro(libro v[], int n){
	int t_isbn;
	int i;
	printf("Inserisci il codice iSBN del libro da cercare: ");
	scanf("%d", &t_isbn);
	
	for(i=0; i<n; i++){
		if(v[i].isbn==t_isbn){
			printf("il libro č presente!\n");
			if(v[i].copie_disp==0){
				printf("questo libro non ha pių copie disponibili");
				return;
			}
			printf("\ngiorno prestito: ");
			scanf("%d", &v[i].pres.giorno);
        	scanf("%d", &v[i].pres.mese);
        	scanf("%d", &v[i].pres.anno);
        	
        	v[i].res.giorno=+1;
        	v[i].res.mese=v[i];
        
        	printf("\ngiorno di restituzione: ");
        	scanf("%d", &v[i].res.giorno);
        	scanf("%d", &v[i].res.mese);
        	scanf("%d", &v[i].res.anno);
        	
        	v[i].copie_disp=-1;
		}
	}
}
 
void caricaLibri(libro libri, int n){
	int i;
    for (i=0; i<n; i++) {
        printf("titolo: ");
        scanf("%s", v[i].titolo);
        printf("autore: ");
        scanf("%s", v[i].autore);
        printf("ISBN: ");
        scanf("%d", &v[i].isbn);
        printf("numero copie: ");
		scanf("%d", v[i].copie_totali);
        printf("Copie disponibili: ");
        scanf("%s", v[i].copie_disp);
    }
}
void stampaLibri(libro v[], int n){
	int i;
	for (i=0; i<n; i++){
		printf("\ntitolo: ");
		scanf("%s", v[i].titolo);
		printf("\nautore: ");
		scanf("%s", v[i].autore);
		printf("\ncodice ISBN: ");
		scanf("%d", v[i].isbn);
		printf("\ncopie totali: ");
		scanf("%d", v[i].copie_totali);
		printf("\ncopie disponibili: ");
		scanf("%d", v[i].copie_disp);
		printf("data di riconsegna del libro");
		scanf("%d", v[i].res.giorno);
		scanf("%d", v[i].res.mese);
		scanf("%d", v[i].res.anno);
}
void scaduti(libro v[], int n){
	int i;
	for(i=0; i<n; i++){
		if(v[i].copie_disp<v[i].copie_totali){
			printf("\ntitolo: ");
			scanf("%s", v[i].titolo);
			printf("autore: ");
        	scanf("%s", v[i].autore);
        	printf("\nISBN: ");
        	scanf("%d", &v[i].isbn);
        	printf("\nlibri in totale:");
			printf("\ncopie disponibili: ");
			scanf("%d", v[i].copie_disp);
			printf("\ndata di restituzione: ");
			printf("\n%d", v[i].res.giorno);
			printf("\n%d", v[i].res.mese);
			printf("\n%d", v[i].res.anno);
		}
	}
}
void stampaPres(){
	int i;
	
	for(i=0; i<n; i++){
		if()
	}
}
void menu(){// funzione che stampa il menu e permette di compiere la scelta
	int scelta=0;
	libro libri;
		do{

		printf("=====Biblioteca=====");
		printf("==menų==\n");
		printf("\n1)inserisci un libro");
		printf("\n2)cerca il libro tramite ISBN");
		printf("\n3)visualizza tutti i libri ");
		printf("\n4)libri scaduti");
		printf("\n5)libri in prestito");
		printf("\n0)esci");
		
	}while(scelta==0);
	switch(scelta){
		case 1:{
			caricaLibro(libri, n);
			break;
		}
		case 2:{
			presLibro(libri, n);
			break;
		}
		case 3:{
			stampaLibri(libri, n);
			break;
		}
		case 4:{
			scaduti(libri, n);
			break;
		}
		case5:{
			stampaPres(libri, n);
			break;
		}
		default:{
			printf("operazione invalida");
			break;
		}
		
	}
}
int main(){
	int n;
	
	do{
		printf("\nquanti libri devi inserire?: ");
		scanf("%d", &n);
	}while(n<1);
	 menu();
	return 0; 
	
}