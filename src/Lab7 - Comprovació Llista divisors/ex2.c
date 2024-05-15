#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int x,y,n;
    n=0;
    printf("\nIntrodueix llistat finalitzat en -1 \n");

    while (x!=-1)
    {
         scanf("%i", &x);
         if ((y%x!=0)&&(n!=0))
         {
             goto nodiv;
         }
         if ((x==-1)&&(n==0))
         {
             printf("Secuencia buida, torna a comencar\n");
             getch();
             main();
         }
         if (x==-1)
         {
             goto batutdemaduixa;
         }
         scanf("%i", &y);
         if (y==-1)
         {
             goto batutdemaduixa;
         }
         n=n+1;
         if (x%y!=0)
         {
             goto nodiv;
         }
    }
    batutdemaduixa:
        printf("Son divisors\n");
        getch();
        main();

    nodiv:
        printf("No son divisors\n");
        getch();
        main();
return 0;
}

