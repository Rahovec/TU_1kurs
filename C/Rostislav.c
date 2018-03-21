#include <stdio.h>

int main(){

int row,col,n;
printf("vuvedi n\n");
scanf("%d", &n);

if(n<=2 || n>=50){
	printf("nevalidno 4islo\n");
	return 1;
}

for (row = 0; row != n; row++) {
	for (col = 0; col != n; col++ ) {
	    if ((row == 0) || (row == n-1) || (col == n-1) || (col == 0)){
	        printf("*");
        }
        else
             printf(" ");
        }
        printf("\n");
	}



return 0;
}

