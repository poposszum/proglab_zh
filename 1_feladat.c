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
