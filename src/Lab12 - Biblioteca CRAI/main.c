#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int matriu[7][5]={{15,16,13,14,17},
                  {13,14,15,16,17},
                  {13,18,14,13,14},
                  {11,12,13,14,18},
                  {16,16,19,14,16},
                  {11,15,16,12,11},
                  {11,12,13,12,11}};
int k;

void PRESTECS_DIARIS()
{
int i, j, acum;
acum=0;
i=0;
j=0;
printf("\n\nEls resultats estan situats de dilluns a divendres d'esquerra a dreta\n\n");
while (j<5)
{
    while (i<7)
    {
        acum=matriu[i][j]+acum;
        i++;
    }
    printf("%i, ", acum);
    i=0;
    j++;
    acum=0;
}}


void CRAIMESRECURSOS()
{
int i,j, moar, acum;
i=0;
j=0;
acum=0;
moar=0;
while (i<7)
{
    while (j<5)
    {
    acum=matriu[i][j]+acum;
    j++;
    }
    if (moar<acum)
    {
        moar=acum;
        k=i+1;
    }
    j=0;
    acum=0;
    i++;
}
printf("\n El CRAI amb mes recursos prestats durant la setmana es el %i\n\n", k);
acum=0;
j=0;
moar=0;
getch();
while (j<5)
{
    while (i<7)
    {
        acum=matriu[i][j]+acum;
        i++;
    }
    if (moar<acum)
    {
        moar=acum;
        k=j+1;
    }
    i=0;
    j++;
}
switch (k)
{
    case 1:
    printf("El dia que mes prestecs s'han fet es dilluns");
    break;
    case 2:
    printf("El dia que mes prestecs s'han fet es dimarts");
    break;
    case 3:
    printf("El dia que mes prestecs s'han fet es dimecres");
    break;
    case 4:
    printf("El dia que mes prestecs s'han fet es dijous");
    break;
    case 5:
    printf("El dia que mes prestecs s'han fet es divendres");
    break;
}
}

void MITJANAPRESTECS(){
int i,j;
float acum, mitjana;
mitjana=0;
acum=0;
i=0;
j=0;
while (j<7)
{
    while (i<5)
    {
        acum=matriu[j][i]+acum;
        i++;
    }
    mitjana=acum/5;
    printf("\nCRAI %i te una mitjana de %.2f", j+1,mitjana);
    i=0;
    acum=0;
    j++;
}
}

int main()
{
int opcio;
while ((opcio<1) || (opcio>3))
{
    printf ("Que vols fer? Escriu el nombre i despres apreta intro");
    printf ("\n 1.- Total de prestecs diaris");
    printf ("\n 2.- CRAI que ha prestat mes recursos");
    printf ("\n 3.- Mitjana de prestecs de cada CRAI");
    scanf ("%d", &opcio);
}
switch(opcio)
{
    case 1:
    PRESTECS_DIARIS();
    break;
    case 2:
    CRAIMESRECURSOS();
    break;
    case 3:
    MITJANAPRESTECS();
    break;
}
getch();
system("cls");
main();
return 0;}
