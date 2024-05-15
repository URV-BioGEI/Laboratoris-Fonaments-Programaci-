#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>
#include "funcions.h"
#define DIM 8
#define VECTOR 40
int llegir;
char cadena[VECTOR];
int vector[DIM];

void escriure_taula()
{
    char llegir;
    int i;
    i=0;
    printf("\nEscriu el nom de l'empresa i apreta intro quan acabis\n");
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
    printf("\nEscriu el nombre d'incidencies corresponents al dia indicat i prem intro cada cop\n");
    while (i<7)
    {
        if (i==0) {printf("\nDILLUNS: ");}
        if (i==1) {printf("\nDIMARTS: ");}
        if (i==2) {printf("\nDIMECRES: ");}
        if (i==3) {printf("\nDIJOUS: ");}
        if (i==4) {printf("\nDIVENDRES: ");}
        if (i==5) {printf("\nDISSABTE: ");}
        if (i==6) {printf("\nDIUMENGE: ");}
        scanf("%i", &vector[i]);
        i++;
    }
    vector[i]=-2;
}

void cadena_versales()
{
int i;
i=0;
if ((cadena[0]>96)&&(cadena[0]<123))
{
    cadena[0]=cadena[0]-32;
    i++;
}
while (cadena[i]!='\r')
{
    if ((cadena[i]>64)&&(cadena[i]<91))
    {
         cadena[i]=cadena[i]+32;
    }
    i++;
}
}

int max()
{
    int i, mayor;
    i=0;
    mayor=0;
    for (i=0; i<7; i++)
    {
    if (vector[i]>mayor)
    {
    mayor=vector[i];
    }
    }
return (mayor);
}

int min()
{
    int i, menor;
    i=0;
    menor=vector[i];
    for (i=0; i<7; i++)
    {
    if (vector[i]<menor)
    {
    menor=vector[i];
    }
    }
return (menor);
}
