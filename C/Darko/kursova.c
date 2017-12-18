/*Да се състави програма за обработка на масива А[N, N], където данните са цели числа в интервала [-1000;1000].
Програмата да извърши следните действия:
*отпечатване на условието на задачата;
*отпечатване на имената на автора на програмата;
*въвеждане на входните данни;
*а)да се нулират елементите в масива А, за които сумата със съответния елемент в масив В е четно число принадлежащо на зададен интервал [K -L];
*да се определи броя на променените елементи в масива А;
*отпечатване на получените резултати след обработка а) и след обработка б)
*/

#include <stdio.h>

int main(){
	int N, K, L;
	int change_counter=0;
	int row, column;
	int res = 0 ;
	printf("Да се състави програма за обработка на масива А[N, N], където данните са цели числа в интервала [-1000;1000].\nПрограмата да извърши следните действия:\n*отпечатване на условието на задачата;\n*отпечатване на имената на автора на програмата;\n*въвеждане на входните данни;\n*а)да се нулират елементите в масива А, за които сумата със съответния елемент в масив В е четно число принадлежащо на зададен интервал [K -L];\n*да се определи броя на променените елементи в масива А;\n*отпечатване на получените резултати след обработка а) и след обработка б)\n");

	printf("Darko Stojmanovski\n");
	printf("\nVuvedete razmer na masiv A i B:");
	scanf("%d", &N);
	int A[N][N];
	int B[N][N];
	printf("\nVuvedete na4alo na interval[K,L]:");
	scanf("%d", &K);
	printf("\nVuvedete krai na interval[K,L]:");
	scanf("%d", &L);
//Vuvejdane na masiv A
	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			printf("\nВъведи A[%d][%d]\n",row,column);
			scanf("%d", &A[row][column]);
			
		}
	}
//vuvejdane na masiv B

	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			printf("\nВъведи B[%d][%d]\n",row,column);
			scanf("%d", &B[row][column]);
			
		}
	}


//sravnqvane na masivite i obrabotka a)
	
	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			res = A[row][column] + B[row][column];
			if(res%2==0 && res>K && res<L){
					A[row][column] = 0;
					change_counter ++;
				}
		}
	}

//printirane na rezultatite
	printf("\nMasiv A sled obrabotka:");
	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			printf("%d ",A[row][column]);
			if (column == N - 1){printf("\n");}
		}
	}

	printf("bqha izvursheni %d broi promeni v masiv A", change_counter);


return 0;
}
