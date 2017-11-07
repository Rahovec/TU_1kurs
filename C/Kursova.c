
#include <stdio.h>

int main(){
	int N;
	printf("Да се състави програма за обработка на два масива PR[N,N], където данните са реални числа в интервала [-1000;1000] програмата да извърши следните действия:\n *отпечатване на условието\n*Отпечатване на имената на автора на програмата \n*въвеждане на входните данни \n*отпечатване на входните данни\nа)да се образува едномерен масив C, елементите на който са средно аритметичнито от елементите на съответната колона от масива PR[N] \nб) получения масив да се сортира по големина\n*отпечатване на получените резултати след обработката а) и след обработката б)\n");
	
	printf ("\nАвтор: Константин Тодоров ТФ 66гр. №141217005\n");
	printf ("\nВъведете размер на масиив:");
	scanf("%d", &N);
	int PR[N][N];
	float C[N];
	int row, column;
	int sum = 0;
////////////////////////////////////////////////
	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			printf("\nВъведи PR[%d][%d]\n",row,column);
			scanf("%d", &PR[row][column]);
			if(PR[row][column] < -1000 || PR[row][column] > 1000){
				printf("\nЧслото трябва да е от -1000 до 1000 но в условието не е указано как се обработват този тип грешки :/ \n");
			}
		} 
	}
////////////////////////////////////////////////	
	printf ("\nВходни данни:\n");	
	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			printf("%d ",PR[row][column]);
			if (column == N - 1){printf("\n");}
		}
	}
////////////////////////////////////////////////	
	for(column = 0; column < N; column ++){
		for(row = 0; row < N; row ++){
			sum += PR[row][column];
			if (row == N - 1){C[column] = sum/N;sum=0;}
		}
	}
////////////////////////////////////////////////
	printf("\nСредноаритметчните са:\n");
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
	printf("\nсортираните средноариитметични са:\n");
	for(row=0; row < N; row++){
		printf("%f ", C[row]);
	}
	printf("\n");

	return 0;
}
