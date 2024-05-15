#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
char nom[20];
int puntuacio;
}records_tipus;
records_tipus taula[11];

void INICIALITZA_TAULA(){
int i,k;
k=0;
taula[0].puntuacio=2147483647;
i=1;
while (i<11)
{
    while (k<20)
    {
        taula[i].nom[k]='\0';
        k++;
    }
taula[i].puntuacio=-1;
k=0;
i++;
}
}

int AFEGIR_RECORD (){
records_tipus record;
char lectura;
int i,j,k,flag;
flag=0;
i=0;
j=0;
system("cls");
printf("Introdueix el nom del record i apreta intro quan acabis: ");
while (lectura!='\r')
{
    lectura=getche();
    record.nom[i]=lectura;
    i++;
}
system("cls");
printf("Introdueix la puntuacio: ");
scanf("%i",&record.puntuacio);
i=10;
k=10;
while (i>=0)
{
    if ((taula[i].puntuacio>record.puntuacio) && (taula[i+1].puntuacio<=record.puntuacio))
    {
        flag=1;
        while (k!=i)
        {
            if (k!=10)
            {
                taula[k+1].puntuacio=taula[k].puntuacio;
                while (taula[k].nom[j]!='\0')
                {
                    taula[k+1].nom[j]=taula[k].nom[j];
                    j++;
                }
            }
        k--;
        j=0;
        }
        taula[i+1].puntuacio=record.puntuacio;
        k=0;
        while (record.nom[k]!='\r')
        {
            taula[i+1].nom[k]=record.nom[k];
            k++;
        }
    }
    i--;
}
return (flag);
}

void IMPRIMIR_RECORDS(){
int i, k;
i=1;
k=0;
system("cls");
printf ("Nom                 Puntuacio\n");
while (i<11)
{
    if (taula[i].puntuacio!=-1)
    {
        while (taula[i].nom[k]!='\0')
        {
        printf("%c",taula[i].nom[k]);
        k++;
        }
        while (k!=20)
        {
            printf(" ");
            k++;
        }
        printf ("%i", taula[i].puntuacio);
        printf("\n");
        k=0;
    }
    i++;
}
getch();
}





int main()
{
int opcio,correcte;
INICIALITZA_TAULA();
while (0!=1)
{
    system("cls");
    while ((opcio!=1) && (opcio!=2))
    {
            printf("que vols?\n");
            printf("1.- Introduir record\n");
            printf("2.- Veure records\n");
            scanf("%i", &opcio);
    }
    if (opcio==1)
    {
        correcte=AFEGIR_RECORD();
        system("cls");
        if (correcte==1)
        {
            printf("Record afegit satisfactoriament!");
        }
        else
        {
            printf("Sembla que el tu record no s'ha afegit...");
        }
        getch();
        opcio=0;
    }
    else
    {
        IMPRIMIR_RECORDS();
        opcio=0;
    }
}
return 0;
}
