#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
int dia, mes, any;
char tema[20];
}dades;
int diames,  mesmes, anymes, opcio;
dades prestecs[30];

void TEMA_MESPRESTAT(){
int i, comp1, comp2;
char tema[20], temames[20];
i=0;
strcpy(tema, prestecs[i].tema);
i++;
comp1=1;
while (i<30)
{
    if (strcmp(tema, prestecs[i].tema)==0)
    {
        comp1++;
    }
    else
    {
        strcpy(tema, prestecs[i-1].tema);
        if (comp1>comp2)
        {
            comp2=comp1;
            strcpy(temames, tema);
            comp1=0;
        }
    }
i++;
}
printf("El tema del que més llibres s'han prestat es de %s", temames);
}

void TEMES_DATA(int dia, int mes, int any)
{
int i;
while (i<30)
{

if ((prestecs[i].dia==dia)&&(prestecs[i].mes==mes)&&(prestecs[i].any==any))
{
    printf("%s, ", prestecs[i].tema);
}
i++;
}}

void DATA_MES_PRESTECS(int * diames, int * mesmes, int * anymes)
{
int dia, mes, any,i, comp1, comp2;
i=0;
dia=prestecs[i].dia;
mes=prestecs[i].mes;
any=prestecs[i].any;
i++;
comp1=1;
while (i<30)
{
    if ((dia==prestecs[i].dia)&&(mes==prestecs[i].mes)&&(any==prestecs[i].any))
    {
        comp1++;
    }
    else
    {
        dia=prestecs[i].dia;
        mes=prestecs[i].mes;
        any=prestecs[i].any;
        if (comp1>comp2)
        {
            comp2=comp1;
            *diames=prestecs[i].dia;
            *mesmes=prestecs[i].mes;
            *anymes=prestecs[i].any;
        }
    }
i++;
}}


void CARREGAR_PRESTECS(){
FILE * f1;
char lectura;
int flagd, num, pos, i, k;
pos=0;
flagd=0;
i=0;
k=0;
f1=fopen("llibres.txt","r");
while (f1==0)
{
    f1=fopen("llibres.txt","r");
    printf("El fitxer no existeix!");
    getch();
}
while (!feof(f1))
{
    while (lectura!='\n')
    {
        fscanf(f1,"%c", &lectura);
        if ((lectura>='a')&&(lectura<='z'))
        {
            prestecs[i].tema[k]=lectura;
            k++;
        }
        if (lectura=='/')
        {
             pos++;
        }
        if (pos==2)
        {
            fscanf(f1, "%i", &num);
        }
        if (((lectura>='0')&&(lectura<='9'))||(pos==2))
        {
            if ((flagd==0)&&(pos!=2))
            {
                num=(lectura-48)*10;
                flagd=1;
            }
            else
            {
                if (pos!=2)
                {
                    num=num-48+lectura;
                    flagd=0;
                }
                switch (pos)
                {
                    case 0:
                    prestecs[i].dia=num;
                    break;
                    case 1:
                    prestecs[i].mes=num;
                    break;
                    case 2:
                    prestecs[i].any=num;
                    pos=0;
                    break;
                }
            }
        }
    }
i++;
getch();
pos=0;
k=0;
}
fclose(f1);
}

int NOMBRE_TEMA (char tema[20]){
int i, nombre;
i=0;
nombre=0;
while (i>30)
{
    if (prestecs[i].tema==tema)
    {
        nombre++;
    }
i++;
}
return(nombre);
}


int main()
{
char tema[20], lectura;
int dia,mes,any,i;
CARREGAR_PRESTECS();
printf("1.- Quants llibres d'un tema concret s'han prestat");
printf("2.- A quina data s'han fet més prèstecs");
printf("3.- A quins temes pertanyen els llibre prestats en una data concreta");
printf("4.- A quin tema corresponen els llibres que més s'ha prestat");
printf("Que vols saber?");
scanf("%i", &opcio);
switch(opcio)
{
    case 1:
        printf("sobre quin tema vols saber-ho?");
        while (lectura!='\r')
        {
            lectura=getche();
            tema[i]=lectura;
            i++;
        }
        printf("Hi han %i prestats del tema %s", NOMBRE_TEMA(tema), tema);
    break;
    case 2:
        DATA_MES_PRESTECS(&diames, &mesmes, &anymes);
        printf("La data amb més prèstecs es %i/%i/%i", diames, mesmes, anymes);
    break;
    case 3:
        opcio=0;
        while ((opcio!=1) && (opcio!=2))
        {
            printf("De que vols saber el temes:");
            printf("1.- De la data amb més prèstecs");
            printf("2.- Una data que tu introdueixis");
            scanf("%i", &opcio);
        }
        if (opcio==1)
        {
            DATA_MES_PRESTECS(&diames, &mesmes, &anymes);
            TEMES_DATA(diames, mesmes, anymes);
        }
        else
        {
            printf("Introdueix el dia");
            scanf("%i", &dia);
            printf("Introdueix el mes");
            scanf("%i", &mes);
            printf("Introdueix l'any");
            scanf("%i", &any);
            TEMES_DATA(dia, mes, any);
        }
    break;
    case 4:
    TEMA_MESPRESTAT();
    break;
}
    return 0;
}
