/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 26 de Agosto de 2014*/
/*Metodo de Heun*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double a,b,h,ya,w,wold,t,tnew,f,fmo;
int i,n,z=0;
char op;

int main()
{
      
do
{
      
do
{
system("cls");

printf("Metodo de Heun\n\n");
               
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
for(i=0;i<=n-1;i++)
{
f=1-(t-w)*(t-w);                     
wold=w+2/3*h*f;
tnew=t+2/3*h;
fmo=1-(tnew-wold)*(tnew-wold);            
w=w+(h/4)*(f+3*fmo);
t=a+(i+1)*h;
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
