/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 10 de Junio de 2014*/
/*Metodo de Interpolacion Cuadratica Inversa*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double a,b,c,fa,fb,fc,u,v,w,p,q,d,fd,t,e;
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
               \nMetodo de Interpolacion Cuadratica Inversa\n\n");
                       
               printf("Inserte a: ");
               scanf("%lf",&a);
               fflush(stdin);
               printf("Inserte b: ");
               scanf("%lf",&b);
               fflush(stdin);
               printf("Inserte c: ");
               scanf("%lf",&c);
               fflush(stdin);
               printf("\nInserte numero maximo de iteraciones n= ");
               scanf("%d",&n);
               fflush(stdin);
               printf("\nInserte tolerancia= ");
               scanf("%lf",&t);
               fflush(stdin);
               /*x^2-x-2 modifica para cambiar la función*/
               fa=a*a-a-2;
               fb=b*b-b-2;
               fc=c*c-c-2;
               /***************************************************************************************************/

               if(fa==0)
               {
                      r=1;
                      printf("\nf(a)=0");
                      printf("\n");
                      system("pause");
                      exit(0);
               }
               else if(fb==0)
               {
                      r=1;
                      printf("\nf(b)=0");
                      printf("\n");
                      system("pause");
                      exit(0);
               }
               else if(fc==0)
               {
                      r=1;
                      printf("\nf(c)=0");
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
               
               printf("\nk\tx*=d\t\tf(d)\t\terror(d-b)");
               i=1;
               d=c;
               c=b;
               b=a;
               do
               {
                              a=b;
                              b=c;
                              c=d;
               /*x^2-x-2 modifica para cambiar la función*/
               fa=a*a-a-2;
               fb=b*b-b-2;
               fc=c*c-c-2;
               /***************************************************************************************************/
                             u=fb/fc;
                             v=fb/fa;
                             w=fa/fc;
                             p=v*(w*(u-w)*(c-b)-(1-u)*(b-a));
                             q=(w-1)*(v-1)*(u-1);
                             d=b+(p/q);

                             e=fabs(d-b);
                             /*x^2-x-2 modifica para cambiar la función*/
                             fd=d*d-d-2;
                             /*************************************************************************/
                             printf("\n%d",i);
                             printf("\t%.10lf",d);
                             printf("\t%.10lf",fd);
                             printf("\t%.10lf",e);

                             

               i++;

               }while((i<=n)&&(e>t)&&(fd!=0));


printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
