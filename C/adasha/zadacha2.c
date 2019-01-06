#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item
{
     char ime[30];
     float cena;
     int broi;
};

int main()
{
    int i,j,k;
    int broi;

    printf("vuvedete broi produkti \n");
    scanf("%d", &broi);

    struct item *A;
    A = (int*)malloc(broi * sizeof(int));

    struct item *B;
    B = (int*)malloc(broi * sizeof(int));

    struct item *C;
    C = (int*)malloc(broi * sizeof(int));

    struct item *D;
    D = (int*)malloc(broi * sizeof(int));

    struct item *E;
    E = (int*)malloc(broi * sizeof(int));

    for(i=0;i<broi;i++){
        printf("vuvedi ime na produkt A[%d]\n", i+1);
        scanf("%s", &A[i].ime);
        printf("vuvedi kolichestvo na produkt A[%d]\n", i+1);
        scanf("%d", &A[i].broi);
        printf("vuvedi cena na produkt A[%d]\n", i+1);
        scanf("%f", &A[i].cena);
    }
    for(i=0;i<broi;i++){
        printf("vuvedi ime na produkt B[%d]\n", i+1);
        scanf("%s", &B[i].ime);
        printf("vuvedi kolichestvo na produkt B[%d]\n", i+1);
        scanf("%d", &B[i].broi);
        printf("vuvedi cena na produkt B[%d]\n", i+1);
        scanf("%f", &B[i].cena);
    }

    for(i=0;i<broi;i++){
        printf("vuvedi ime na produkt C[%d]\n", i+1);
        scanf("%s", &C[i].ime);
        printf("vuvedi kolichestvo na produkt C[%d]\n", i+1);
        scanf("%d", &C[i].broi);
        printf("vuvedi cena na produkt C[%d]\n", i+1);
        scanf("%f", &C[i].cena);
    }

    for(i=0;i<broi;i++){
        strcpy(D[i].ime, A[i].ime);
        D[i].cena=A[i].cena;
        D[i].broi=A[i].broi;
    }
    for(i=0,j=broi; j<(2*broi) && i<broi; i++, j++){
        strcpy(D[j].ime, B[i].ime);
        D[j].cena=B[i].cena;
        D[j].broi=B[i].broi;
    }
    for(i=0,j=(broi*2); j<(3*broi) && i<broi; i++, j++){
        strcpy(D[j].ime, C[i].ime);
        D[j].cena=C[i].cena;
        D[j].broi=C[i].broi;
    }



    printf("\nElementi s koli4estvo>1000 i cena<500:\n");
    for(i=0;i<sizeof(D);i++){
        if(D[i].broi>1000 && D[i].cena<500){
            printf("D[%d] ime: %s\n",i, D[i].ime);
            printf("D[%d] cena: %f\n",i, D[i].cena);
            printf("D[%d] kolichestvo: %d\n",i, D[i].broi);
        }
    }

    printf("\n Sortirane vuv nizhodqsht red po cena\n");
    for(i=0;i<sizeof(D);i++){
        for(j=0;j<sizeof(D);j++){
            if(D[j].cena<D[i].cena){
                //tmp=d[i]
                strcpy(E[i].ime, D[i].ime);
                E[i].cena=D[i].cena;
                E[i].broi=D[i].broi;
                //ai=aj
                strcpy(D[i].ime, D[j].ime);
                D[i].cena=D[j].cena;
                D[i].broi=D[j].broi;
                //aj = tmp
                strcpy(D[j].ime, E[i].ime);
                D[j].cena=E[i].cena;
                D[j].broi=E[i].broi;
            }
        }
    }
    for(i=0;i<(3*broi);i++){
        printf("D[%d] ime: %s\n",i, D[i].ime);
        printf("D[%d] cena: %f\n",i, D[i].cena);
        printf("D[%d] kolichestvo: %d\n",i, D[i].broi);

    }

    printf("\n Sortirane vuv nizhodqsht red po koli4estvo\n");
    for(i=0;i<sizeof(D);i++){
        for(j=0;j<sizeof(D);j++){
            if(D[j].broi<D[i].broi){

                strcpy(E[i].ime, D[i].ime);
                E[i].cena=D[i].cena;
                E[i].broi=D[i].broi;

                strcpy(D[i].ime, D[j].ime);
                D[i].cena=D[j].cena;
                D[i].broi=D[j].broi;

                strcpy(D[j].ime, E[i].ime);
                D[j].cena=E[i].cena;
                D[j].broi=E[i].broi;
            }
        }
    }
    for(i=0;i<(3*broi);i++){
        printf("D[%d] ime: %s\n",i, D[i].ime);
        printf("D[%d] cena: %f\n",i, D[i].cena);
        printf("D[%d] kolichestvo: %d\n",i, D[i].broi);

    }

    FILE *fptr;
    fptr=fopen("mon.dat", "w");
    for(i=0;i<(3*broi);i++){
        fprintf(fptr,"D[%d] ime: %s\n",i, D[i].ime);
        fprintf(fptr,"D[%d] cena: %f\n",i, D[i].cena);
        fprintf(fptr,"D[%d] kolichestvo: %d\n",i, D[i].broi);

    }
    fclose(fptr);


    return 0;
}
