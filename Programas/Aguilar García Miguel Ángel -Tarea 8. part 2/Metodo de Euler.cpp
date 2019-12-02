/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 26 de Agosto de 2014*/
/*Metodo de Euler*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double a,b,h,ya,w,t,f;
int i,n,z=0;
char op;

int main()
{
      
do
{
      
do
{
system("cls");

printf("Metodo de Euler\n\n");
               
printf("Inserte a: ");
scanf("%lf",&a);
fflush(stdin);
printf("\nInserte b: ");
scanf("%lf",&b);
fflush(stdin);
printf("\nInserte y(a): ");
scanf("%lf",&ya);
fflush(stdin);
printf("\nInserte numero de puntos n= ");
scanf("%d",&n);
fflush(stdin);

z=0;
if(b-a==0)
{
printf("\n\nError. Los puntos a y b son iguales\n");
system("pause");
z=1;
}
if(n<=0)
{
printf("\n\nError. n es igual o menor que 0\n");
system("pause");
z=1;
}

}while(z==1);               
               
h=(b-a)/n;
t=a;
w=ya;
for(i=1;i<=n;i++)
{
f=1-(t-w)*(t-w);
w=w+h*f;
t=a+i*h;
} 

printf("\nEl resultado de la ED es: %lf",w);

printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
