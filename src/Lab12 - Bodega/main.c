#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funcions.h"

int matriu[6][5];
int k;

int main()
{
int opcio;
int k;
k=-1;
while ((k==-1) || (k==-2))
{
    k=CARREGAR_MATRIU();
    switch(k)
    {
        case -1:
            printf("El fitxer no existeix\n");
            getch();
            break;
        case -2:
            printf("El fitxer esta buit\n");
            getch();
            break;
    }
}

while ((opcio<1) || (opcio>3))
{
    printf ("Que vols fer? Escriu el nombre i despres apreta intro");
    printf ("\n 1.- Quin a ha estat el mes amb mes vendes");
    printf ("\n 2.- Hi ha alguna seccio que tingui un increment creixent en els 6 mesos");
    printf ("\n 3.- En quin mes i en quina seccio s'han venuts menys botelles");
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



