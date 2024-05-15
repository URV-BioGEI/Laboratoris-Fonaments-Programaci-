#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float n;
    double acumq, mitjana, i;
    FILE *num;
    FILE *res;
    num = fopen("numeros.txt","r");
    res = fopen("resultat.txt","w");
    i=0;
    n=0;
    if(num!=NULL)
        {
        if (!feof(num))
        {
            while(!feof(num))
                {
                n=n+1;
                fscanf(num,"%d ",&i);
                acumq=acumq+pow(i,2);
                }
            mitjana=sqrt(acumq/n);
            printf("La mitjana es %d", mitjana);
        }
        else
            {
            printf("El fitxer esta buit");
            getch();
            }
        }
    else
        {
        printf("El fitxer numeros.txt no existeix");
        getch();
        }
    fclose(num);
    fclose(res);
return 0;
}

