/*
Да се състави програма за обработка на два масива A[N,N], където данните са реални числа в интервала [-1000;1000] програмата да извърши следните действия
отпечатване на условието
въвеждане на входните данни
 отпечатване на входните данни 
а)да се образува едномерен масив C, елементите на който са средно аритметичните стойности на редовете на масива A;
б) получения масив да се сортира по големина
отпечатване на получените резултати след обработката а) и след обработката б)
*/

#include <iostream>
using namespace :: std;

int main(){

	int N;
	cout << "Enter size" << endl;
	cin >> N;
	int A[N][N];
	float C[N];
	int sum = 0;
	for(int row=0; row<N; row++){
		for(int column = 0; column < N; column ++){
			cout<<"Enter["<<row<<"]["<<column<<"]"<<endl;
			cin >> A[row][column];
		}
	}

	for(int row=0; row<N; row++){
		for(int column = 0; column < N; column ++){
			cout<<A[row][column] << " ";
			if(column==N-1){cout<<endl;}
		}
	}

	for(int row=0; row<N; row++){
		for(int column = 0; column < N; column ++){
			sum += A[row][column];
			
		}
		C[row] = sum/N;
		sum = 0;
	}

	for(int row=0; row<N; row++){
		cout << C[row] << " ";
	}

	for(int a=0; a<=N-1; a++){
		for(int b=0; b<N-a-1;b++){
			if(C[b] < C[b+1]){
				int swap = C[b];
				C[b] = C[b+1];
				C[b+1] = swap;
			}
		}
	}

	cout << "\n" << "Sorted c[] is:"<<endl;
	for(int row=0; row<N; row++){
		cout << C[row] << " ";
	}
	return 0;
}
