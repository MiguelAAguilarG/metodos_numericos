/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 10 de Junio de 2014*/
/*Metodo de biseccion*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double a,b,m,ya,yb,ym,x,y,t;
int i,n,r;
char op;

main()
{  
do
{
              do
               {
               r=0; 
system("cls");

printf(         "Miguel Angel Aguilar Garcia\
               \nMetodos numericos\
               \nFecha de entrega: Martes 10 de Junio de 2014\
               \nMetodo de biseccion\n\n");
               
               
                       
               printf("Inserte a: ");
               scanf("%lf",&a);
               fflush(stdin);
               printf("\nInserte b: ");
               scanf("%lf",&b);
               fflush(stdin);
               printf("\nInserte numero maximo de iteraciones n= ");
               scanf("%d",&n);
               fflush(stdin);
               printf("\nInserte tolerancia= ");
               scanf("%lf",&t);
               fflush(stdin);
               /*x^2-x-2 modifica para cambiar la función*/
               ya=a*a-a-2;
               yb=b*b-b-2;
               /***************************************************************************************************/
               if(ya>0)
               {
                      r=1;
                      printf("\nERROR. \"a\" no es valida f(a)>0");
                      printf("\n");
                      system("pause");
               }
               else if(yb<0)
               {
                      r=1;
                      printf("\nERROR. \"b\" no es valida f(b)<0");
                      printf("\n");
                      system("pause");
               }
               else if(yb==0)
               {
                      r=1;
                      printf("\nf(b)=0");
                      printf("\n");
                      system("pause");
                      exit(0);
               }
               else if(ya==0)
               {
                      r=1;
                      printf("\nf(a)=0");
                      printf("\n");
                      system("pause");
                      exit(0);
               }
               else if(n<0)
               {
                      r=1;
                      printf("\nERROR. \"n\" no es valida n<0");
                      printf("\n");
                      system("pause");
               }
               else if(t<0)
               {
                      r=1;
                      printf("\nERROR. \"t\" no es valida t<0");
                      printf("\n");
                      system("pause");
               }
               
               }while(r==1);
               
               printf("\nk\ta\tb\tm\tf(a)\t\tf(b)\t\tf(m)");
               i=0;
               do
               {
                   
                             m=(a+b)/2;
                             /*x^2-x-2 modifica para cambiar la función*/
                             ya=a*a-a-2;
                             yb=b*b-b-2;
                             ym=m*m-m-2;
                             /*************************************************************************/
                             printf("\n%d",i);
                             printf("\t%.5lf",a);
                             printf("\t%.5lf",b);
                             printf("\t%.5lf",m);
                             printf("\t%.8lf",ya);
                             printf("\t%.8lf",yb);
                             printf("\t%.8lf",ym);

                             if(ym<0&&ya<0)
                             {
                             a=m;      
                             }
                             else if(ym>0&&ya>0)
                             {
                             a=m;
                             }
                             else if(ym<0&&yb<0)
                             {
                             b=m;         
                             }
                             else if(ym>0&&yb>0)
                             {
                             b=m;
                             }
               i++;
               }while((i<=n)&&(fabs(ym)>t));
printf("\n\na= %.15lf ",a);
printf("\nf(a)= %.15lf ",ya);
printf("\nb= %.15lf ",b);
printf("\nf(b)= %.15lf ",yb);
printf("\nm= %.15lf ",m);
printf("\nf(m)= %.15lf ",ym);

printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
