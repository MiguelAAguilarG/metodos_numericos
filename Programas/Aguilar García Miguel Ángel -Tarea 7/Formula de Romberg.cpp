/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 12 de Agosto de 2014*/
/*Formula de Romberg*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double a,b,sum=0,inte=0,inteold,x=0,tol,e;
int i,j,k,z=0,iter=0;
char op;

int main()
{
      
do
{
      
do
{
system("cls");

printf("Formula de Romberg\n\n");
               
printf("Inserte a: ");
scanf("%lf",&a);
fflush(stdin);
printf("\nInserte b: ");
scanf("%lf",&b);
fflush(stdin);
printf("\nInserte numero de iteraciones= ");
scanf("%d",&iter);
fflush(stdin);
printf("\nInserte tolerancia: ");
scanf("%lf",&tol);
fflush(stdin);

z=0;
if(b-a==0)
{
printf("\n\nError. Los puntos a y b son iguales\n");
system("pause");
z=1;
}
if(iter<0)
{
printf("\n\nError. Las iteraciones son menores que 0\n");
system("pause");
z=1;
}
if(tol<=0)
{
printf("\n\nError. La tolerancia es igual o menor que 0\n");
system("pause");
z=1;
}

}while(z==1);               

k=0;
do
{
    
sum=0;    
for(i=1;i<=pow(2,(k-1))-1;i++)
{
/*exp(-(x*x))*/
/*sqrt(tan(x))*/
/*log(x)*/ 
/*sum+=(a+(i*((b-a)/(pow(2,k-1)))))*(a+(i*((b-a)/(pow(2,k-1)))));*/
/*sum+=exp(-((a+(i*((b-a)/(pow(2,k-1)))))*(a+(i*((b-a)/(pow(2,k-1)))))));*/
/*sum+=sqrt(tan((a+(i*((b-a)/(pow(2,k-1)))))));*/
sum+=log((a+(i*((b-a)/(pow(2,k-1))))));
}

/*inte=(b-a)/pow(2,(k))*((a*a)+(2*sum)+(b*b));*/
/*inte=(b-a)/pow(2,(k))*((exp(-(a*a)))+(2*sum)+(exp(-(b*b))));*/
/*inte=(b-a)/pow(2,(k))*((sqrt(tan(a)))+(2*sum)+(sqrt(tan(b))));*/ 
inte=(b-a)/pow(2,(k))*((log(a))+(2*sum)+(log(b)));            

e=100;
if(k>=1)
{
e=fabs(inte-inteold);        
}

inteold=inte;
k++;
}while(k<iter&&e>tol);

printf("\nLa iteracion es: %d",k);
printf("\nLa integral es: %.12lf",inte);


printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
