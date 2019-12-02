/*Miguel Angel Aguilar Garcia*/
/*Tarea 3: Metodos numericos*/
/*Fecha de entrega: Martes, 3 de junio de 2014*/
/*Problema 5: Programa donde se genere la distancia entre n+1 puntos igualmente espaciados entre a y b, ademas de posicion que tendran*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double a,b,h,x[99999999];
int i,j,k,n;
char op;

main()
{
      
do
{
system("cls");

printf(         "Miguel Angel Aguilar Garcia\
               \nTarea 3: Metodos numericos\
               \nFecha de entrega: Martes, 3 de junio de 2014\
               \nProblema 5: Programa donde se genere la distancia entre n+1 \npuntos igualmente espaciados entre a y b, ademas de posicion que tendran\n\n");
               
               printf("Inserte a: ");
               scanf("%lf",&a);
               fflush(stdin);
               printf("\nInserte b: ");
               scanf("%lf",&b);
               fflush(stdin);
               printf("\nInserte numero de puntos n= ");
               scanf("%d",&n);
               fflush(stdin);
               
               h=(b-a)/n;
               printf("\n\nDistancia entre puntos: %lf\n",h);
printf("\n\nMetodo 1");
               

               x[0]=a;
               printf("\nx0= %lf",x[0]); 
               for(i=1;i<=n;i++)
               {
               x[i]=x[i-1]+h; 
               printf("\nx%d= %lf",i,x[i]);
               }
               
printf("\n\nMetodo 2");

               for(i=0;i<=n;i++)
               {
               x[i]=a+(i*h);
               printf("\nx%d= %lf",i,x[i]);
               }

printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
