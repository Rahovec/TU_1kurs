#include <stdio.h>
#include <stdlib.h>

int main()
{
   int N;
    printf("Da se sustavi programa za obrabotka na masiva A[N][N], kudeto dannite sa celi 4isla v intervala [-500][1000]\n");
    printf("Programata da izvurshi slednite deistviq:\n");
    printf("otpe4atvan na uslovieto na zada4ata\n");
    printf("otpe4atvane na imenata na avtora\n");
    printf("vuvejdane na vhodnite danni\n");
    printf("otpe4atvane na vhodnite danni\n");
    printf("a)da se obrazuva masiv C[N], elementite na koito sa nai malkite stoinosti na vseki red na masiva A\n");
    printf("b)polu4eniq masiv da se sortira po golemina\n");
    printf("otpe4atvane na polu4enite rezultati sled a) i b)\n");
    printf("Author: Ioan Ivanov");
    printf("\n Vuvedi N:\n");
    scanf("%d", &N);
    int A[N][N];
    int C[N];
    int c,small,row, column, i = 0;

	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			printf("\nVuvedi A[%d][%d]\n",row,column);
			scanf("%d", &A[row][column]);
		}
	}


	printf ("\nVhodni danni:\n");
	for(row = 0; row < N; row ++){
		for(column = 0; column < N; column ++){
			printf("%d ",A[row][column]);
			if (column == N - 1){printf("\n");}
		}
	}

 row=0;column=0;i=0;small=0;
    for(i=0; i < N; i++){
		C[i]=0;
	}

   for(row = 0; row < N; row ++){
        small = A[row][0];
		for(column = 0; column < N; column ++){
			if(A[row][column]<=small){
			    C[row] = A[row][column];
			}
		}
	}

	printf("\n a) Masiv C predi sortiraneto po golemina e:\n");
	for(i=0; i < N; i++){
		printf("%d ", C[i]);
	}
	printf("\n");

	for(row=0; row < (N - 1); row++){
		for(column=0; column < (N-row-1); column++){
			if(C[column] > C[column+1]){
				c = C[column];
				C[column] = C[column + 1];
				C[column + 1] = c;
			}
		}
	}
    printf("\n b) Masiv C sled sortiraneto po golemina e:\n");
	for(i=0; i < N; i++){
		printf("%d ", C[i]);
	}
	printf("\n");
    return 0;
}
