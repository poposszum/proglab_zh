/*
1.feladat

Irjon programot, amely a standard bemenetrol soronkent egy vagy tobb nem negativ szamot olvas!
Ha a sor elsokent beolvasott szama 0, a program fejezze be a mukodeset. Ha a sor elso szama pozitiv,
akkor az azt jelenti, hogy a sorban hany tovabbi szam talalhato. A program irja ki minden sor eseten pontosan
egy szokoz karakterrel elvalasztva a masodik elemtol aaz utolso elemig vett elemek atlagat es azt a szamot az elobb felsoroltak kozul,
mely a legkozelebb esik az atlaghoz. Ha tobb ilyen elem is lenne, akkor a felsorolasban legeloszor szereplo elemet irja ki.
5 1 2 3 4 5
4 5 5 5 1
0
3.0 3
4.0 5
*/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
	
	int beolvas;
	
	while (scanf("%d", &beolvas) != 0){
		int sum, min, poz;
		double atlag;
				
		if (beolvas > 0){
			int i,beolvastomb;
			int *tomb = (int *) malloc(beolvas * sizeof(int));
			sum = 0;
			for (i = 0; i < beolvas; i++){
				scanf("%d", &beolvastomb);
				tomb[i] = beolvastomb;
				sum+= beolvastomb;
			}
			atlag = sum / beolvas;
			
			min = abs(tomb[0] - (int)atlag), poz = 0;
			for (i = 1; i < beolvas; i++){
				printf("%d %d\n",tomb[i], abs(tomb[i] - (int)atlag));
				if (abs(tomb[i] - (int)atlag) < min){
					min = abs(tomb[i] - (int)atlag);
					poz = i;
				}
			}
				printf("%lf %d", atlag, tomb[poz]);
		}	
	}
	
	return 0;
}
