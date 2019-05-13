#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double median(int *tomb, int n);

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
			}
			
			printf("%lf\n", median(tomb, beolvas));
				}	
			}
	return 0;
}

double median(int *x, int n){
	
	int temp, i, j;
	
	
	for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(x[j] < x[i]) {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
    
    if(n%2==0) {
        return((x[n/2] + x[n/2 - 1]) / 2.0);
    } else {
        return x[n/2];
    }
}
