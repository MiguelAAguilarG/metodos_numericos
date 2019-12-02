/*Miguel Angel Aguilar Garcia*/
/*Tarea 3: Metodos numericos*/
/*Fecha de entrega: Martes, 3 de junio de 2014*/
/*Problema 7: Programa que calcula la funcion exponencial e^x*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double e[35],x,rr,r,q,w; 
int a,b,i,k,j;
unsigned long long int f; 
char op;

main()
{

do
{
      system("cls");
      
printf(         "Miguel Angel Aguilar Garcia\
               \nTarea 3: Metodos numericos\
               \nFecha de entrega: Martes, 3 de junio de 2014\
               \nProblema 7: Programa que calcula la funcion exponencial e^x\n\n");
               
printf("Ingrese el valor de x: ");  
scanf("%lf",&x); 
fflush(stdin);  
               e[0]=1;
               k=30;
               i=1;
               for(i=1;i<=k;i++)
               {
                          
                          /*Programa para hacer el factorial de un numero*/
                          f=1;
                          for(j=i;j>=1;j--)
                          {
                                     f=f*j;
                          }
                          /************************************************/
                          e[i]=e[i-1]+(pow(x,i))/f;

                          
            printf("k= %d  con ******   x=%lf   ******  es igual a: %20.15lf \n\n",i,x,e[i]);        
               
               }
               
               rr=exp(x);
               
               printf("El valor calculado en el lenguaje c \ncon la funcion exp(x)= %20.15lf",rr);
               
               a=0;
               for(i=1;i<=k;i++)
               {
                                if(e[i]>=rr&&a==0)
                                {
                                                  q=e[i]-rr;
                                                  w=rr-e[i-1];
                                                  if(w<q)
                                                  {
                                            r=e[i-1];
                                            b=i-1;
                                            a=1;
                                            }
                                            else
                                            {
                                                r=e[i];
                                                b=i;
                                                a=1;
                                            }
                                }
               }
printf("\n\nEl valor calculado que mas se acerca al valor real de e^x es: ");
printf("\nk= %d  con ******   x=%lf   ******  es igual a: %20.15lf \n\n",b,x,r);
     
printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);

}
while(op=='s'||op=='S');
      
system ("pause");
}
