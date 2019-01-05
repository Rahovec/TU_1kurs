#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
     char fakultet[30];
     char ime[30];
     float ocenka;
};

int main()
{
     int FKSU_broi=0;
     float FKSU_ocenka=0;
     int FOE_broi=0;
     float FOE_ocenka=0;
     int TF_broi=0;
     float TF_ocenka=0;
     FILE *f;
     int i;
     int broi;
     printf("Vuvedi broi studenti:\n");
     scanf("%d", &broi);
     struct student *zapis;
     zapis = (int*)malloc(broi * sizeof(int));

     for(i=0; i<broi; i++)
     {
         printf("Vuvedi ime na student : %d \n", i+1);
         scanf("%s", &zapis[i].ime);
         printf("Vuvedi fakultet na student %d \n", i+1);
         scanf("%s", &zapis[i].fakultet);
         printf("Vuvedi ocenka na student: %d \n", i+1);
         scanf("%f", &zapis[i].ocenka);

     }

    int dadena_ocenka;
    printf("\nVuvedi dadena ocenka: ");
    scanf("%d", &dadena_ocenka);
    printf("\nstudenti s po golqma ocenka:\n");
    for(i=0; i<broi; i++)
    {
        if(zapis[i].ocenka > dadena_ocenka)
        {
            printf("Ime: %s \n", zapis[i].ime);
            printf("Fakultet: %s \n", zapis[i].fakultet);
            printf("Ocenka is: %f\n\n",zapis[i].ocenka);
        }
    }


        for(i=0; i<broi; i++)
        {
            if(strcmp(zapis[i].fakultet, "FKSU")==0)
            {
                FKSU_broi++;
                FKSU_ocenka += zapis[i].ocenka;

            }
            else if(strcmp(zapis[i].fakultet, "FOE")==0)
            {
                FOE_broi++;
                FOE_ocenka += zapis[i].ocenka;
            }

            else if(strcmp(zapis[i].fakultet, "TF")==0)
            {
                TF_broi++;
                TF_ocenka += zapis[i].ocenka;
            }

        }
        if(FKSU_broi > 0)
            {printf("\nSredno za FKSU: %f",FKSU_ocenka/FKSU_broi);}

        if(FOE_broi > 0)
            {printf("\nSredno za FOE: %f",FOE_ocenka/FOE_broi);}

        if(TF_broi > 0)
            {printf("\nSredno za TF: %f",TF_ocenka/TF_broi);}


            /*f = fopen("C:\\Users\\Konstantin\\Desktop\\ada6a\\f_fksu.txt", "w");
                fprintf(f,"Ime: %s\n",zapis[i].ime);
                fprintf(f,"Fakultet: %s\n",zapis[i].fakultet);
                fprintf(f,"Ocenka: %d\n",zapis[i].ocenka);
                fclose(f);*/

        for(i=0; i<broi; i++)
        {
            if(strcmp(zapis[i].fakultet, "FKSU")==0)
            {
                f = fopen("f_fksu.txt", "w");
                if(f == NULL)
               {
                  printf("Error!");
                  exit(1);
               }
                fprintf(f,"Ime: %s\n",zapis[i].ime);
                fprintf(f,"Fakultet: %s\n",zapis[i].fakultet);
                fprintf(f,"Ocenka: %f\n",zapis[i].ocenka);
                fclose(f);

            }
            else if(strcmp(zapis[i].fakultet, "FOE")==0)
            {
                f = fopen("f_fksu.txt", "w");
                if(f == NULL)
               {
                  printf("Error!");
                  exit(1);
               }
                fprintf(f,"Ime: %s\n",zapis[i].ime);
                fprintf(f,"Fakultet: %s\n",zapis[i].fakultet);
                fprintf(f,"Ocenka: %f\n",zapis[i].ocenka);
                fclose(f);
            }

            else if(strcmp(zapis[i].fakultet, "TF")==0)
            {
                f = fopen("f_fksu.txt", "w");
                if(f == NULL)
               {
                  printf("Error!");
                  exit(1);
               }
                fprintf(f,"Ime: %s\n",zapis[i].ime);
                fprintf(f,"Fakultet: %s\n",zapis[i].fakultet);
                fprintf(f,"Ocenka: %f\n",zapis[i].ocenka);
                fclose(f);
            }

        }
     return 0;
}
