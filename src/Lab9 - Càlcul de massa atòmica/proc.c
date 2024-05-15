#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdbool.h>
char troleo;
int error;

void a_majuscules()
{
        troleo=troleo-32;
}

int caracter_valid(char troleo)
{
    int i, conte=0;
    char valids[5];
    valids[0]='O';
    valids[1]='C';
    valids[2]='N';
    valids[3]='S';
    valids[4]='H';
    i=0;
    while (i<=5)
    {
        if (valids[i]==troleo)
        {
            conte=1;
        }
    i++;
    }
    return(conte);
}

int es_digit(int i, char k)
{
    int num;
    if((k<=57) && (k>=48)){
        num=(int)k-48;
    }
    else{
        num=-1;
    }
    return(num);
}

void mostrar_error(int error)
{
    if(error==0){
        printf("\nFormula erronia: (error 0) .\n\n");
    }
    else if(error==-1){
        printf("\nFormula erronia: (error -1) Hi ha elements quimics desconeguts.\n\n");
    }
    else{
        printf("\nFormula erronia: (error -2) No poden haver-hi tants atoms!.\n\n");
    }
}

