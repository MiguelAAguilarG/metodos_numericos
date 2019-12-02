/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 10 de Junio de 2014*/
/*Metodo de Punto Fijo*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double xk,yxk,gxk,t,e;
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
               \nMetodo de punto fijo\n\n");
               
               
                       
               printf("Inserte x0: ");
               scanf("%lf",&xk);
               printf("\nInserte numero maximo de iteraciones n= ");
               scanf("%d",&n);
               fflush(stdin);
               printf("\nInserte tolerancia= ");
               scanf("%lf",&t);
               fflush(stdin);
               /*x^2-x-2 modifica para cambiar la función*/
               yxk=xk*xk-xk-2;
               gxk=1+(2/xk);
               /***************************************************************************************************/

               if(yxk==0)
               {
                      r=1;
                      printf("\nf(x0)=0");
                      printf("\n");
                      system("pause");
                      exit(0);
               }
               if(gxk==0)
               {
                      r=1;
                      printf("\ng(x0)=0");
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
               
               printf("\nk\tx k\t\tg(x k+1)\t\tf(x k)");
               i=0;
               do
               {
                   
               /*x^2-x-2 modifica para cambiar la función*/
               yxk=xk*xk-xk-2;
               gxk=1+(2/xk);
               /***************************************************************************************************/

                             printf("\n%d",i);
                             printf("\t%.10lf",xk);
                             printf("\t%.10lf",gxk);
                             printf("\t%.10lf",yxk);

                             

               i++;
               e=fabs(gxk-xk);
               
               xk=gxk;
               }while((i<=n)&&(e>t)&&(gxk!=0));


printf("\nx k=%.20lf",xk);
printf("\ng(x k)=%.20lf",gxk);
printf("\nf(x k)=%.20lf",yxk);

printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
