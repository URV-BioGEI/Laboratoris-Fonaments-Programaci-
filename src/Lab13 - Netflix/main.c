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
int accio, terror, ciencia, comedies, romantiques, i;
char temames[20];
i=0;
accio=0;
ciencia=0;
comedies=0;
terror=0;
romantiques=0;
while (i<9)
{
    if ((strcmp("Accio", prestecs[i].tema))==0)
    {
        accio++;
    }
    if ((strcmp("Ciencia-Ficcio", prestecs[i].tema))==0)
    {
        ciencia++;
    }
    if ((strcmp("Comedies", prestecs[i].tema))==0)
    {
        comedies++;
    }
    if ((strcmp("Terror", prestecs[i].tema))==0)
    {
       terror++;
    }
    if ((strcmp("Romantiques", prestecs[i].tema))==0)
    {
        romantiques++;
    }
    i++;
}
system("cls");
if ((accio > ciencia)&&(accio > comedies)&&(accio > terror)&&(accio > romantiques)) {strcpy(temames,"Accio ");}
if ((ciencia > accio)&&(ciencia > comedies)&&(ciencia > terror)&&(ciencia > romantiques)) {strcpy(temames,"Ciencia-Ficcio ");}
if ((comedies > accio)&&(comedies > ciencia)&&(comedies > terror)&&(comedies > romantiques)) {strcpy(temames,"Comedies ");}
if ((terror > accio)&&(terror > ciencia)&&(terror > comedies)&&(terror > romantiques)) {strcpy(temames,"Terror ");}
if ((romantiques > accio)&&(romantiques > ciencia)&&(romantiques > comedies)&&(romantiques > terror)) {strcpy(temames,"Romantiques ");}
printf("El tipus de serie que mes s'ha visualitzat es ");
i=0;
while (temames[i]!=' ')
{
    printf("%c",temames[i]);
    i++;
}
getch();
system("cls");
}

void TEMES_DATA(int dia, int mes, int any, char tema[20]){
int i,k;
i=0;
k=0;
while (i<9)
{
    if ((prestecs[i].dia==dia)&&(prestecs[i].mes==mes)&&(prestecs[i].any==any))
    {
        if ((strncmp(prestecs[i].tema, tema,5))==0)
        {
            k++;
        }
    }
    i++;
}
system("cls");
printf("S'han emes %i tipus de serie a la data seleccionada", k);
getch();
}

void DATA_MES_PRESTECS(int * diames, int * mesmes, int * anymes){
int dia, mes, any,i, comp1, comp2;
i=0;
dia=prestecs[i].dia;
mes=prestecs[i].mes;
any=prestecs[i].any;
i++;
comp1=1;
comp2=50;
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
        if (comp1<comp2)
        {
            comp2=comp1;
            *diames=prestecs[i-1].dia;
            *mesmes=prestecs[i-1].mes;
            *anymes=prestecs[i-1].any;
        }
    comp1=1;
    }
i++;
}}

void CARREGAR_PRESTECS(){
FILE * f1;
char lectura;
int num, i, k;
i=0;
k=0;
f1=fopen("series.txt","r");
while (f1==0)
{
    f1=fopen("series.txt","r");
    printf("El fitxer no existeix!");
    getch();
}
while (i<9)
{
    while ((lectura!='\n'))
    {
        while (lectura!=' ')
        {
            if (k!=0)
            {
                 prestecs[i].tema[k-1]=lectura;
            }
            k++;
            fscanf(f1,"%c", &lectura);
        }
        fscanf(f1,"%i", &num);
        prestecs[i].dia=num;
        fscanf(f1,"%c", &lectura);
        fscanf(f1,"%i", &num);
        prestecs[i].mes=num;
        fscanf(f1,"%c", &lectura);
        fscanf(f1,"%i", &num);
        prestecs[i].any=num;
        fscanf(f1,"%c", &lectura);
        prestecs[i].tema[k-1]=lectura;
    }
i++;
lectura=0;
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
int i,dia,mes,any;
char lectura, tema[20];
CARREGAR_PRESTECS();
while (dia!=40)
{
    while ((opcio!=1)&&(opcio!=2)&&(opcio!=3)&&(opcio!=4))
{
    system("cls");
    printf("1.- A quina data s'han visualitzat menys series\n");
    printf("2.- Quantes series d'un tipus concret s'han visualitzat en una data concreta.\n");
    printf("3.- Quin tipus de serie es el que mes s'ha visualitzat\n");
    printf("Que vols saber? ");
    scanf("%i", &opcio);
}
switch(opcio)
{
    case 1:
        DATA_MES_PRESTECS(&diames, &mesmes, &anymes);
        system("cls");
        printf("La data amb menys prestecs es %i/%i/%i", diames, mesmes, anymes);
        getch();
        opcio=0;
    break;
    case 2:
        i=0;
        while (i<20)
        {
            tema[i]='\0';
            i++;
        }
        opcio=0;
        i=0;
        system("cls");
        printf("Introdueix el dia: ");
        scanf("%i", &dia);
        printf("Introdueix el mes: ");
        scanf("%i", &mes);
        printf("Introdueix l'any: ");
        scanf("%i", &any);
        printf("Introdueix la serie: ");
        while (lectura!='\r')
        {
            lectura=getche();
            tema[i]=lectura;
            i++;
        }
        TEMES_DATA(dia, mes, any, tema);
        opcio=0;
    break;
    case 3:
    TEMA_MESPRESTAT();
    opcio=0;
    getch();
    break;
}}
    return 0;
}
