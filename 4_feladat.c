/*
4.feladat
Irjon programot, amely a standard bemenetrol allomanyvegjelig soronkent egy-egy hallgato adatait olvassa be.
Minden sor felepitese a kovetkezo: Neptun-kod;Nev;Eletkor;Atlag
A Neptun-kod egy legfeljebb 6 karakter hosszu, csak az angol ABC betuket tartalmazo vagy szokozt tartalmazo sztring.
Az eletkor egy 0 es 100 kozotti egesz szam. Az atlag pedig 0 es 5 kozti szam. A program irja ki a standard kimenet
elso soraba, hogy mennyi volt a beolvasott hallgatok atlag eletkora. A kovetkezo sorokba irja ki azon hallgatokat atlaguk szerint csokkeno sorrendbe,
akik fiatalabbak az atlagnal. Ha a ket hallgato atlaga megegyezne, akkor oket Neptun-kodjuk szerint ABC sorrendbe rendezze.
ABC123;Nagy Gusztav;22;4.5
DF12DD;Kiss Istvan;23;3.9
DF123D;Alma Janos;23;4
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Hallgato{
	char neptunKod[7];
	char nev[51];
	int eletKor;
	double atlag;
}Hallgato;

double atlagEletkor(Hallgato *Hallgatok, int hossz);
int hasonlit(const void *a, const void *b);

int main(){
	
	char beOlvas[100];
	Hallgato Hallgatok[50];
	int i = 0, j;
	
	while (gets(beOlvas) != NULL){
	
	char *token;
	
	token = strtok(beOlvas, ";");
	strcpy(Hallgatok[i].neptunKod, token);
	
	token = strtok(NULL, ";");
	strcpy(Hallgatok[i].nev, token);
	
	token = strtok(NULL, ";");
	Hallgatok[i].eletKor = atoi(token);
	
	token = strtok(NULL, ";");
	Hallgatok[i++].atlag = atoi(token);

	}
	
	
	printf("%lf\n", atlagEletkor(Hallgatok, i));
	
	qsort(Hallgatok, i, sizeof(Hallgato), hasonlit);
	
	for (j = 0; j < i; j++)
		if (Hallgatok[j].eletKor < atlagEletkor(Hallgatok, i))
			printf("%s\n", Hallgatok[j].nev);
	
	return 0;
}

double atlagEletkor(Hallgato *Hallgatok, int hossz){
	int i, sum = 0;
	
	for (i = 0; i < hossz-1; i++)
		sum+= Hallgatok[i].eletKor;
		
		return (double) sum / i;
}

int hasonlit(const void *a, const void *b){
	Hallgato *h1 = (Hallgato*)a;
	Hallgato *h2 = (Hallgato*)b;
	
	if (h1->atlag == h2->atlag)
		return strcmp(h1->nev, h2->nev);
	else return -1 * (h1->atlag > h2->atlag);
}

