#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funcions.h"

int matriu[6][5];
int k;

int CARREGAR_MATRIU()
{
    int troll,i,j,k,retorn;
    char brossa;
    FILE * fitxer;
    fitxer=fopen("vins.txt", "r");
    if (fitxer==NULL)
    {
        retorn=-1;
    }
    else
    {
        fscanf(fitxer, "%i", &troll);
        i=0;
        j=0;
        k=0;
        while ((i<6)&&!feof(fitxer))
        {
            while (j<5)
            {
                if (k!=0)
                {
                    fscanf(fitxer, "%i", &troll);
                }
                matriu[i][j]=troll;
                j++;
                k=5;
                fscanf(fitxer, "%c", &brossa);
            }
        fscanf(fitxer, "%c",&brossa);
        j=0;
        i++;
        retorn=0;
        }
    }
    if (i==0)
    {
        retorn=-2;
    }
return (retorn);
}
void PRESTECS_DIARIS()
{
int i, j, k, acum, moar;
acum=0;
i=0;
j=0;
while (i<6)
{
    while (j<5)
    {
        acum=matriu[i][j]+acum;
        j++;
    }
    if (acum>moar)
    {
        moar=acum;
        k=i+1;
    }
    j=0;
    i++;
    acum=0;
}
printf("\nEl mes en que s'han venut mes productes es el %i", k);
}
void CRAIMESRECURSOS()
{
int i,j,k, flag, flagk;
i=0;
j=0;
k=0;
flag=0;
flagk=0;
while (j<5)
{
    i=0;
    while (i<6)
    {
        if (k<matriu[i][j])
        {
            k=matriu[i][j];
        }
        else
        {
            flag=1;
        }
    i++;
    }
    if (flag!=1)
    {
        printf("\n\nLa seccio de ");
        switch(j)
        {
        case 0:
            printf("vins negres");
            break;
        case 1:
            printf("vins blancs");
            break;
        case 2:
            printf("vins rosats");
            break;
        case 3:
            printf("caves");
            break;
        case 4:
            printf("licors");
            break;
        }
        printf(" ha tingut un increment creixent en els sis mesos");
        flagk=1;
    }
    flag=0;
    k=0;
    j++;
}
if (flagk==0)
{
        printf("\n No hi ha cap seccio amb un increment durant 6 mesos");
}
}
void MITJANAPRESTECS(){
int k,i,j,pos,acum;
acum=0;
i=0;
j=0;
k=9999;
while (j<6)
{
    while (i<5)
    {
        acum=matriu[j][i]+acum;
        i++;
    }
    if (acum<k)
    {
        k=acum;
        pos=j+1;
    }
    i=0;
    acum=0;
    j++;
}
printf("\nEl mes amb menys vendes ha sigut %i", pos);
k=9999;
j=0;
i=0;
while (i<5)
{
    while (j<6)
    {
        acum=matriu[j][i]+acum;
        j++;
    }
    if (acum<k)
    {
        k=acum;
        pos=i;
    }
    j=0;
    acum=0;
    i++;
}
printf ("\nLa seccio amb menys vendes ha sigut la de ");
switch(pos)
        {
        case 0:
            printf("vins negres");
            break;
        case 1:
            printf("vins blancs");
            break;
        case 2:
            printf("vins rosats");
            break;
        case 3:
            printf("caves");
            break;
        case 4:
            printf("licors");
            break;
        }
}
