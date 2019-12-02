/*Miguel Angel Aguilar GarcIa*/
/*Tarea 3: Metodos numericos*/
/*Fecha de entrega: Martes, 3 de junio de 2014*/
/*Problema 6: Programa que calcula la constante numerica e*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

double a,b,e,n;
int c,i;

main()
{
      
printf("Miguel Angel Aguilar Garcia\
               \nTarea 3: Metodos numericos\
               \nProblema 6: Programa que calcula la constante numerica e \n\n"); 
      
      for(i=1;i<=20;i++)
      {
           n=pow(10,i);
           e=pow((1+(1/n)),n);
           printf("k = %d ......El valor aproximado de e es: %1.20lf \n\n",i,e); 
           fflush(stdin);
      }        
      
     printf("El valor real de e=2.718281828 \n\n");            
     system("pause");
}
