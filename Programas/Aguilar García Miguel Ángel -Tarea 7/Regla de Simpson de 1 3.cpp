/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 12 de Agosto de 2014*/
/*Regla de Simpson de 1/3*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double a,b,h,sum2=0,sum4=0,inte=0,x=0;
int i,j,k,n,z=0;
char op;

int main()
{
      
do
{
      
do
{
system("cls");

printf("Regla de Simpson de 1/3\n\n");
               
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
sum2=0;
sum4=0;
for(i=1;i<=n-1;i++)
{
    x=(i*h)+a;
    if(i%2==0)
    {
    /*exp(-(x*x))*/
    /*sqrt(tan(x))*/
    /*log(x)*/          
    /*sum2+=x*x;*/
    /*sum2+=exp(-(x*x));*/
    /*sum2+=sqrt(tan(x));*/ 
    sum2+=log(x);        
    }
    else
    {
    /*sum4+=x*x;*/
    /*sum4+=exp(-(x*x));*/
    /*sum4+=sqrt(tan(x));*/  
    sum4+=log(x);   
    }

}

/*inte=(h/3)*((a*a)+(2*sum2)+(4*sum4)+(b*b));*/ 
/*inte=(h/3)*((exp(-(a*a)))+(2*sum2)+(4*sum4)+(exp(-(b*b))));*/
/*inte=(h/3)*((sqrt(tan(a)))+(2*sum2)+(4*sum4)+(sqrt(tan(b))));*/
inte=(h/3)*((log(a))+(2*sum2)+(4*sum4)+(log(b)));              

printf("\nLa integral es: %.12lf",inte);


printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
