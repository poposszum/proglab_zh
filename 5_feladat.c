/*
5. feladat
Irjon programot, mely egy 4x4-es meretu veletlen elemekkel (1-100 kozott) feltoltott matrix minden soranak az atlagat
megjeleniti a kimeneten (soronkent 1 db atlag). A program ezutan irja ki azon sor indexet, amelyik a legnagyobb atlagu volt.

*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	
	int matrix[5][5], i, j, poz = 0, max = -1;
	double avg;
	srand(time(NULL));
	
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			matrix[i][j] = rand() % 100 + 1;
			
			for (i = 0; i < 4; i++){
				for (j = 0; j < 4; j++)
					printf("%d ",matrix[i][j]);
				printf("\n");
			}
			
			for (i = 0; i < 4; i++){
				int atlag, sum = 0;
				for (j = 0; j < 4; j++)
					sum+= matrix[i][j];
					
					avg = (double) sum / 4;
		
					if (avg > max){
						max = avg;
						poz = i;
					}
					
				printf("%lf\n",avg);
						
			}
			printf("%d",poz);
	return 0;
}
