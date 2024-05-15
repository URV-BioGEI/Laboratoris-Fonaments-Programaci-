#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main() {
    srand(time(NULL));
    char vmin;
    int vmaxn, rang, vminn, r1, r2;

    printf("Introdueixi la lletra: ");
    scanf("%s", &vmin);
    printf("Introdueixi el rang: ");
    scanf("%d", &rang);
    vmaxn=vmin+rang;
    vminn=vmin;
    r1=vminn+(rand()%(vmaxn-vminn+1));
    r2=vminn+(rand()%(vmaxn-vminn+1));

    printf("%c \n", r1);
    printf("%c", r2);
    getch();
    return 0;
}
