/*

Kiss Istvan;11111111111111
Kovacs Erika;11110011111111
Kiss Gusztav;11111211011011
Nagy Peter;11111111110000

*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Hallgato{
	char nev[36];
	char hianyzas[15];
}Hallgato;

int tobbMintHarom(Hallgato *Hallgatok, int hossz);
int hasonlit(const void *a, const void *b);

int main(){
	
	char beOlvas[100];
	Hallgato Hallgatok[25];
	int i = 0, j;
	
	while (gets(beOlvas) != NULL){
	
	char *token;
	
	token = strtok(beOlvas, ";");
	strcpy(Hallgatok[i].nev, token);
	
	token = strtok(NULL, ";");
	strcpy(Hallgatok[i++].hianyzas, token);
	
	//printf("%s\n",Hallgatok[i].nev);
	//printf("%s\n",Hallgatok[i].hianyzas);
	
	
	
}

	printf("%d\n", tobbMintHarom(Hallgatok, i));
	
	qsort(Hallgatok, i, sizeof(Hallgato), hasonlit);
	
	for (j = i; j >= 0; j--)
			printf("%s\n", Hallgatok[j].nev);
	
	return 0;
}

int tobbMintHarom(Hallgato *Hallgatok, int hossz){
	
	int i, k = 0, db = 0, hianyzasok;
	
	while (k < hossz){
		hianyzasok = 0;
	
	for (i = 0; i < strlen(Hallgatok[k].hianyzas); i++)
		if (Hallgatok[k].hianyzas[i] == '0'){
			hianyzasok++;
			//printf("%s hianyzott\n", Hallgatok[k].nev);
		}
			
			if (hianyzasok > 3){
				//printf("hianyzott\n");
				db++;
			}
				
			k++;
		}
		
	return db;
}

int hasonlit(const void *a, const void *b){
	Hallgato *h1 = (Hallgato*)a;
	Hallgato *h2 = (Hallgato*)b;
	
	if (h1->hianyzas == h2->hianyzas)
		return strcmp(h1->nev, h2->nev);
	else return h1->hianyzas > h2->hianyzas;
}
