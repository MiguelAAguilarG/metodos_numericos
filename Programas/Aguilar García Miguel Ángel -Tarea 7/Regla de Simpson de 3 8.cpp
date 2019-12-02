/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 12 de Agosto de 2014*/
/*Regla de Simpson de 3/8*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double a,b,h,sum2=0,sum3=0,inte=0,x=0;
int i,j,k,n,z=0;
char op;

int main()
{
      
do
{
      
do
{
system("cls");

printf("Regla de Simpson de 3/8\n\n");
               
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
sum3=0;
for(i=1;i<=n-1;i++)
{
    x=(i*h)+a;
    if(i%3==0)
    {
    /*exp(-(x*x))*/
    /*sqrt(tan(x))*/
    /*log(x)*/          
    /*sum2+=x*x;*/
    /*sum2+=exp(-(x*x));*/ 
    sum2+=sqrt(tan(x));
    /*sum2+=log(x);*/            
    }
    else
    {
    /*sum3+=x*x;*/
    /*sum3+=exp(-(x*x));*/
    /*sum3+=sqrt(tan(x));*/  
    sum3+=log(x);           
    }

}

/*inte=(3*h/8)*((a*a)+(2*sum2)+(3*sum3)+(b*b));*/
/*inte=(3*h/8)*((exp(-(a*a)))+(2*sum2)+(3*sum3)+(exp(-(b*b))));*/
/*inte=(3*h/8)*((sqrt(tan(a)))+(2*sum2)+(3*sum3)+(sqrt(tan(b))));*/
inte=(3*h/8)*((log(a))+(2*sum2)+(3*sum3)+(log(b)));              

printf("\nLa integral es: %.12lf",inte);


printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
