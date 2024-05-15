#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
int x, y, z, w, r1, r2, r3, r4;
x=4;
y=7;
z=3;
w=2;
r1=x+y*x/z-w*x;
printf("El valor de r1 es: %d \n", r1);
r2=(x+y)*x/(z-w)*x;
printf("El valor de r2 es: %d \n", r2);
r3=(x+y*x)/(z-w*x);
printf("El valor de r3 es: %d \n", r3);
r4=x+(y*x)/z-(w*x);
printf("El valor de r4 es: %d \n", r4);
getch();
return 0;

}
