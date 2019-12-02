/*Miguel Angel Aguilar Garcia*/
/*Tarea 3: Metodos numericos*/
/*Fecha de entrega: Martes, 3 de junio de 2014*/
/*Problema 8: Programa para resolver una ecuacón cuadratica*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

float a,b,c,d,r,x1,x2,rneg,y,z;
char op;

main()
{
 
do
{
system("cls"); 

printf(         "Miguel Angel Aguilar Garcia\
               \nTarea 3: Metodos numericos\
               \nFecha de entrega: Martes, 3 de junio de 2014\
               \nProblema 8: Programa para resolver una ecuacón cuadratica\n\n");
          
printf("Ingrese a: ");
scanf("%f",&a);
fflush(stdin);

printf("Ingrese b: ");
scanf("%f,",&b);
fflush(stdin);

printf("Ingrese c: ");
scanf("%f",&c);
fflush(stdin);

if(a==0)
 {
 printf("ERROR. Valor de 'a' no valido");
 }
else
 {
 d=(b*b)-(4*a*c);
 
  if(d<0)
  {
  rneg=d*(-1);
  z=(rneg)/(2*a);
  y=((-1)*b)/(2*a);
  printf("La primera solucion es: %f+%fi",y,z);
  printf("\nLa segunda solucion es: %f-%fi",y,z);
  }
  
  else
  {
  r=sqrt(d);
  x1=(-b+r)/(2*a);
  x2=(-b-r)/(2*a);
  printf("La primera solucion es: %f",x1);
  printf("\nLa segunda solucion es: %f",x2);
  }
 } 
 
printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);

}
while(op=='s'||op=='S');

system("pause");
}
