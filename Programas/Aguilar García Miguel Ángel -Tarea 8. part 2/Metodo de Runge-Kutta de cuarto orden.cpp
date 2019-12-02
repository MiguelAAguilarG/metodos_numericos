/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 26 de Agosto de 2014*/
/*Metodo de Runge-Kutta de cuarto orden*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double a,b,h,ya,w,wold1,wold2,wold3,t,tnew,f,fmo1,fmo2,fmo3,k1,k2,k3,k4,t2;
int i,n,z=0;
char op;

int main()
{
      
do
{
      
do
{
system("cls");

printf("Metodo de Runge-Kutta de cuarto orden\n\n");
               
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
f=w-t*t+1; 
/*f=1-((t-w)*(t-w));*/       
k1=h*f;                              
wold1=w+k1/2;
tnew=t+h/2;
fmo1=wold1-tnew*tnew+1;
/*fmo1=1-((tnew-wold1)*(tnew-wold1));*/
k2=h*fmo1;
wold2=w+k2/2;
fmo2=wold2-tnew*tnew+1;
/*fmo2=1-((tnew-wold2)*(tnew-wold2));*/
k3=h*fmo2;
wold3=w+k3;
t2=t+h;
fmo3=wold3-t2*t2+1;
/*fmo3=1-((t2-wold3)*(t2-wold3));*/
k4=h*fmo3;        
w=w+(k1+2*k2+2*k3+k4)/6;

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
