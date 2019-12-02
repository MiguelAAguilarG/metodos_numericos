/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 12 de Agosto de 2014*/
/*Metodo del trapecio*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double a,b,h,sum=0,inte=0,x=0;
int i,j,k,n,z=0;
char op;

int main()
{
      
do
{
      
do
{
system("cls");

printf("Metodo del trapecio\n\n");
               
printf("Inserte a: ");
scanf("%lf",&a);
fflush(stdin);
printf("\nInserte b: ");
scanf("%lf",&b);
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
sum=0; 
for(i=1;i<=n-1;i++)
{
x=(i*h)+a;
/*exp(-(x*x))*/
/*sqrt(tan(x))*/
/*log(x)*/
/*sum+=x*x;*/
/*sum+=exp(-(x*x));*/
/*sum+=sqrt(tan(x));*/
sum+=log(x);
}

/*inte=(h/2)*((a*a)+(2*sum)+(b*b));*/
/*inte=(h/2)*((exp(-(a*a)))+(2*sum)+(exp(-(b*b))));*/
/*inte=(h/2)*((sqrt(tan(a)))+(2*sum)+(sqrt(tan(b))));*/ 
inte=(h/2)*((log(a))+(2*sum)+(log(b)));  

printf("\nLa integral es: %.12lf",inte);


printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
