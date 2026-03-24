/*1. chide all'utente quanti numeri interi vuole inserire
2. alloca dinamicamente un array di quella dimensione con malloc() 
3. permette all' utente di inserire i numeri 
4. chiede all' utente se vuole aumentare la dimensione dell' array
5. stampa tutti gli elementi*/
#include <stdio.h>
#include <stdlib.h>
void menu();
int* allocazione(int *v, int dim);
void stampa(int *v, int dim);
void inserisci(int *v,int dim);
int aggiungi(int *v,int dim);
 int main(){
 	int scelta;
 	int dim=0;
 	int *v=NULL;
 	
 	
 	do{
 		
 		menu();
 		printf("scelta: ");
 		scanf("%d", &scelta);
 		
 		switch (scelta){
 			case 1:{
			 	printf("numeri da inserire: ");
 				scanf("%d",&dim);
				break;
			 }
			 case 2:{
			 	allocazione(v, dim);
				break;
			 }
			 case 3:{
			 	inserisci(v,dim);
				break;
			 }
			 case 4:{
			 	dim=aggiungi(v,dim);
				break;
			 }
 			case 5:{
 				stampa(v,dim);
				break;
			 }
			 defaut:{
			 	printf("errore");
			 }	
		 }
 		
	 }while(scelta!=0);
	 free(v);
	 return 0;
 }
 void menu(){
 	printf("1. chide all'utente quanti numeri interi vuole inserire\n");
 	printf("2. alloca dinamicamente un array di quella dimensione con malloc()\n");
 	printf("3. permette all' utente di inserire i numeri\n");
 	printf("4. chiede all' utente se vuole aumentare la dimensione dell' array\n");
 	printf("5. stampa tutti gli elementi\n");
 	printf("0. esci\n");
 }
 int* allocazione(int *v, int dim){
 	v=(int*)malloc(dim*sizeof(int));
 	if(v==NULL){
 		printf("errore");
 		return NULL;
	 }
	 return v;
 }
 void stampa(int *v, int dim){
 	int i;
 	for(i=0;i<dim;i++){
 		printf("%d", v[i]);
	 }
	getchar();
 }
 void inserisci(int *v,int dim){
 	int i;
 	int num;
 	for(i=0;i<dim;i++){
 		printf("inserisci un numero: ");
 		scanf("%d", &num);
 		*v[i]=num;
	 }
 }
 int aggiungi(int *v,int dim){
 	int n;
 	printf("che numero vuoi aggiungere: ");
 	scanf("%d",&n);
 	v=(int*)realloc(v,(dim+1)*sizeof(int));
 	v[dim]=n;
 	dim++;
 	printf("numero aggiunto\n");
 	return dim;
 }
    