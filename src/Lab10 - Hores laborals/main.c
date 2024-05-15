#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>

int llegir;
char cadena[40];
int vector[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void escriure_taula()
{
    char llegir;
    int i;
    i=0;
    printf("\nEscriu el teu nom i cognom i apreta intro quan acabis\n");
    while (llegir!='\r')
    {
        llegir=getche();
        cadena[i]=llegir;
        i++;
    }
}

void escriure_vector()
{
    int i;
    i=0;
    printf("\nEscriu el nombre de minuts treballat corresponents al dia indicat i prem intro cada cop\n");
    while (i<13)
    {
        if (i>0){i++;}
        if (i==0) {printf("\nDILLUNS: ");}
        if (i==2) {printf("\nDIMARTS: ");}
        if (i==4) {printf("\nDIMECRES: ");}
        if (i==6) {printf("\nDIJOUS: ");}
        if (i==8) {printf("\nDIVENDRES: ");}
        if (i==10) {printf("\nDISSABTE: ");}
        if (i==12) {printf("\nDIUMENGE: ");}
        scanf("%i", &vector[i]);
        i++;
        vector[i]=-1;
    }
    vector[i]=-2;
}

void cadena_versales()
{
bool flag;
int i;
i=0;
if ((cadena[0]>96)&&(cadena[0]<123))
{
    cadena[0]=cadena[0]-32;
    i++;
}
while (cadena[i]!='\0')
{
    if (cadena[i]==32)
    {
        flag=true;
    }
	if ((cadena[i]>96)&&(cadena[i]<123)&&(flag==true))
    {
        cadena[i]=cadena[i]-32;
        flag=false;
    }
    if ((flag==false)&&(cadena[i]>64)&&(cadena[i]<91))
    {
        cadena[i]=cadena[i]+32;
    }
    i++;
}
}

float comptahores()
{
int i, dies;
float acumextra;
bool flag;
flag=false;
i=0;
dies=0;
acumextra=0;
while (vector[i]!=-2)
{
    if (vector[i]==-1)
    {
        i++;
        dies++;
    }
    if ((dies==5)||(dies==6))
    {
        flag=true;
    }
    if (flag==false)
    {
        if (vector[i]>480)
        {
            acumextra=acumextra+vector[i]-480;
            i++;
        }
    }
    else
    {
        acumextra=acumextra+vector[i];
        i++;
    }
}
return acumextra;
}


float calcula_mitjana()
{
float acumf, mitjana;
int i, acum;
i=0;
acum=0;
while (i<13)
{
    acum=acum+vector[i];
	i=i+2;
}
acumf=acum;
mitjana=(acumf/420);
return mitjana;
}

int main()
{
float mitjana, horesextra, minutsextra;
int i;
i=0;
minutsextra=0;
escriure_taula();
escriure_vector();
cadena_versales();
minutsextra=comptahores();
mitjana=calcula_mitjana();
horesextra=minutsextra/60;
printf("\nEl treballador ");
while (cadena[i]!='\r')
    {
        printf("%c",cadena[i]);
        i++;
    }
printf(" ha treballat:");
printf("\n %f hores extra", horesextra);
printf("\n %f hores de mitjana setmanals", mitjana);
getch();
system("cls");
main();
return 0;
}



