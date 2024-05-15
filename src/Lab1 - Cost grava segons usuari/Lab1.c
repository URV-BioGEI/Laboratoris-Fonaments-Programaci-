/*----------------------------------------------------------------
|	Autor: Professors de Fonaments de Programacio                 |
|	Data: Setembre 2015                 Versio: 1.0	             |
|-----------------------------------------------------------------|
|	Nom: Lab1.c                                                   |
|   Descripcio del Programa:   Calcular la zona de jardi que es   |
|                              pot cobrir amb grava.              |
|  								                                  |
| ----------------------------------------------------------------*/

/* Incloure E/S i Llibreries Standard */
#include <stdio.h>
#include <math.h>

/* Programa Principal */
int main ()
{
    /* Zona de Declaracio de Variables del Programa principal  */
    float diners, preu, gruix, volum, area_cercle, radi, gruix_m;

    /* obtenir_diners */
    printf( "\nIndica els diners que vols gastar (euros):   " );
    scanf( "%f", &diners );

    /* obtenir_preu_grava */
    printf( "Indica el preu de la grava (euros m3):   ");
    scanf( "%f", &preu );

    /* obtenir_gruix_grava */
    printf( "Indica el gruix de la grava (cm):   ");
    scanf( "%f", &gruix );
    /* Convertir els centimetres a metres */
    gruix_m = gruix / 100;

    /* calcular_area_i_radi_cercle */
    volum = diners / preu;
    area_cercle = volum / gruix_m;
    /* La constant PI esta definida a la llibreria math.h */
    radi = sqrt(area_cercle / M_PI);

    /* mostrar_radi */
    printf("\nEl radi de jardi que es pot cobrir es: %.04f cm\n", radi);

    return 0;           /* Retorna al S.O. sense cap error */
}

