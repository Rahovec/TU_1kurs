#include <stdio.h>
int main(){
	int N;	
	printf("Да се състави програма за обработка на два масива A[N,N], където данните са реални числа в интервала [-1000;1000] програмата да извърши следните действия:\n *отпечатване на условието\n*Отпечатване на имената на автора на програмата \n*въвеждане на входните данни \n*отпечатване на входните данни\nа)да се образува едномерен масив C, елементите на който са елементите от масива А със сбор от индексите си четно число;  \nб) получения масив да се сортира по големина\n*отпечатване на получените резултати след обработката а) и след обработката б)\n");
	
	printf ("\nАвтор: Денислава Николова ТФ 66гр. №141217012\n");
	printf ("\nВъведете размер на масиив:");
	scanf("%d", &N);
	int A[N][N];
	int C[N];
	int row, column, i = 0;
	int a,b,c; //спомагателни променливи
//////////////////////////////////////////////////////////////
//Този цикъл въвежда елементите(числата) в масива А;
	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			printf("\nВъведи А[%d][%d]\n",row,column);
			scanf("%d", &A[row][column]);
		} 
	}

/////////////////////////////////////////////////////////////
//Този цикъл принтира входните данни, които са въведени в горния цикъл
	printf ("\nВходни данни:\n");	
	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			printf("%d ",A[row][column]);
			if (column == N - 1){printf("\n");}
		}
	}

/////////////////////////////////////////////////////////////
//Този цикъл обработва масива С.
for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			if((row+column)%2 == 0){
				C[i] = A[row][column];
				i++;
			}
		} 
	}
/////////////////////////////////////////////////////////////
//Този цикъл показва масив С след 1вата обработка
	printf("\nМасив С след 1вата обработка е::\n");
	for(i=0; i < N; i++){
		printf("%d ", C[i]);
	}
	printf("\n");
/////////////////////////////////////////////////////////////
//Този цикъл сортира по-големина масива С и го показва на екрана
	for(a=0; a < (N - 1); a++){
		for(b=0; b < (N-a-1); b++){
			if(C[b] > C[b+1]){
				c = C[b];
				C[b] = C[b + 1];
				C[b + 1] = c;
			}
		}	
	}
	printf("\nСортираният по големина масив С е::\n");
	for(a=0; a < N; a++){
		printf("%d ", C[a]);
	}
	printf("\n"); 
return 0;
}