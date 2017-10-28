/*Да се състави програма за обработка на два масива A[N,N], където данните са реални числа в интервала [-1000;1000] програмата да извърши следните действия
отпечатване на условието
въвеждане на входните данни
 отпечатване на входните данни 
а)да се образува едномерен масив C, елементите на който са средно аритметичните стойности на редовете на масива A;
б) получения масив да се сортира по големина
отпечатване на получените резултати след обработката а) и след обработката б)
*/
////////////////////////////////////////////////
#include <stdio.h>

int main(){
	int N;
	printf ("Vuvedete razmer na masiv");
	scanf("%d", &N);
	int A[N][N];
	float C[N];
	int row, column;
	int sum = 0;
////////////////////////////////////////////////
	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			printf("Vuvedi A[%d][%d]\n",row,column);
			scanf("%d", &A[row][column]);
			if(A[row][column] < -1000 || A[row][column] > 1000){
				printf("4isloto trqbva da e ot -1000 do 1000 ama v uslovieto nqma error handling :/ \n");
			}
		} 
	}
////////////////////////////////////////////////	
	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			printf("%d ",A[row][column]);
			if (column == N - 1){printf("\n");}
		}
	}
////////////////////////////////////////////////	
	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			sum += A[row][column];
			if (column == N - 1){C[row] = sum/N;sum=0;}
		}
	}
////////////////////////////////////////////////
	printf("srednoaritmeti4nite sa:\n");
	for(row=0; row < N; row++){
		printf("%f ", C[row]);
	}
	printf("\n");

////////////////////////////////////////////////
//column and sum not used as planed
	for(row=0; row < (N - 1); row++){
		for(column=0; column < (N-row-1); column++){
			if(C[column] > C[column+1]){
				sum = C[column];
				C[column] = C[column + 1];
				C[column + 1] = sum;
			}
		}	
	}
	printf("sortiranite srednoaitmeti4nii:\n");
	for(row=0; row < N; row++){
		printf("%f ", C[row]);
	}
	printf("\n");

	return 0;
}
