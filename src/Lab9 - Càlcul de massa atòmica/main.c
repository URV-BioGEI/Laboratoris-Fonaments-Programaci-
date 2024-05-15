#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdbool.h>
#include "proc.h"
char troleo;
int error;

int main()
{
    char formula[15];
    int a, b, c, d, e, f, acum, digit, cont, i, k, angelaguapa;
    i=0;
    cont=0;
    printf("Introdueix la formula quimica i quan acabis, apreta 'enter'.\n");
    while(i<15)
    {
        formula[i]=106;
        i++;
    }
    i=0;
    troleo=0;
    while(troleo!='\r')
    {
        troleo=getche();
        if ((troleo>47)&&(troleo<58)&&(i==0))
        {
            error=0;
            mostrar_error(error);
            main();
        }
        if ((!((troleo>47)&&(troleo<58)))&&(troleo!='\r'))
        {
            cont=0;
            if ((troleo>96)&&(troleo<123))
            {
                a_majuscules(troleo);
            }
            angelaguapa=caracter_valid(troleo);
            if (angelaguapa==0)
            {
                error=-1;
                mostrar_error(error);
                main();
            }
        }
        else
        {
            if (troleo=='\r')
            {
                cont--;
            }
            cont++;
            if (cont==3)
            {
                error=-2;
                mostrar_error(error);
                main();
            }
        }
        formula[i]=troleo;
        i++;
    }
k=i-1;
acum=0;
e=0;
c=0;
a=0;
b=0;
d=0;
f=1;
i=i-2;
while (i!=-1)
{
    digit=es_digit(i,formula[i]);
    if (digit!=-1)
        {
            if (d==1)
            {
                b=(formula[i]-48)*10;
                e=e+b;
                c=c+b;
                d=0;
            }
            else
            {
                a=formula[i]-48;
                d=1;
                e=e+a;
                c=a+c;
            }
            f=0;
        }
    else
        {
            if (f==1)
            {
                c=c+1;
                e=e+1;
            }
            switch (formula[i])
            {
                case 'C':
                    acum=c*12+acum;
                    c=0;
                break;
                case 'H':
                    acum=c*1+acum;
                    c=0;
                break;
                case 'N':
                    acum=c*14+acum;
                    c=0;
                break;
                case 'O':
                    acum=c*16+acum;
                    c=0;
                break;
                case 'S':
                    acum=c*32+acum;
                    c=0;
                break;
            }
        f=1;
        d=0;
        }
    i=i-1;
}
i=0;
printf("\n\nL'aminoacid ");
while (k!=i)
{
    printf("%c", formula[i]);
    i++;
}
printf(" te %i atoms", e);
printf(" i una massa molecular de %i", acum);
getch();
printf("\n\n");
main();
    return(0);
}
