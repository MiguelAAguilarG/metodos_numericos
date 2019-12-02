/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 10 de Junio de 2014*/
/*Metodo de la secante*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double ymenosuno,xkmenosuno,yxkmenosuno,yxcero,xcero,xmenosuno,yxmenosuno,ykmenosuno,xk,xkmasuno,ycero,yxk,yxkmasuno,t,e;
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
               \nMetodo de la secante\n\n");
               
               
                       
               printf("Inserte x0: ");
               scanf("%lf",&xcero);
               printf("Inserte x-1: ");
               scanf("%lf",&xmenosuno);
               printf("\nInserte numero maximo de iteraciones n= ");
               scanf("%d",&n);
               fflush(stdin);
               printf("\nInserte tolerancia= ");
               scanf("%lf",&t);
               fflush(stdin);
               /*x^2-x-2 modifica para cambiar la función*/
               ycero=xcero*xcero-xcero-2;
               ymenosuno=xmenosuno*xmenosuno-xmenosuno-2;
               /***************************************************************************************************/

               if(ycero==0)
               {
                      r=1;
                      printf("\nf(x0)=0");
                      printf("\n");
                      system("pause");
                      exit(0);
               }
               else if(ymenosuno==0)
               {
                      r=1;
                      printf("\nf(x-1)=0");
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
               else if(ycero<0&&ymenosuno<0)
               {
                      r=1;
                      printf("\nERROR. f(x0) y f(x-1)<0, deben ser de distinto signo. Ingrese nuevos valores a x0 y x-1");
                      printf("\n");
                      system("pause");
               }
               else if(ycero>0&&ymenosuno>0)
               {
                      r=1;
                      printf("\nERROR. f(x0) y f(x-1)>0, deben ser de distinto signo. Ingrese nuevos valores a x0 y x-1");
                      printf("\n");
                      system("pause");
               }
               
               }while(r==1);
               
               printf("\nk\tx k\t\tx k+1\t\tf(x k)\t\tf(x k+1)");
               i=-1;
               xk=xcero;
               xkmenosuno=xmenosuno;
               yxkmenosuno=ymenosuno;
               do
               {

                             /*x^2-x-2 modifica para cambiar la función*/
                             yxk=xk*xk-xk-2;
                             xkmasuno=xk-(((xk-xkmenosuno)*yxk)/(yxk-yxkmenosuno));
                             yxkmasuno=xkmasuno*xkmasuno-xkmasuno-2;
                             /*************************************************************************/
                             if(i==-1)
                             {
                             printf("\n%d",i);
                             printf("\t%.10lf",xmenosuno);
                             printf("\t%.10lf",xcero);
                             printf("\t%.10lf",ymenosuno);
                             printf("\t%.10lf",ycero);
                             }
                             else
                             {
                             printf("\n%d",i);
                             printf("\t%.10lf",xk);
                             printf("\t%.10lf",xkmasuno);
                             printf("\t%.10lf",yxk);
                             printf("\t%.10lf",yxkmasuno);
                             }
                             

               i++;
               e=fabs(xkmasuno-xk);
               
               yxkmenosuno=yxk;
               yxk=yxkmasuno;
               xkmenosuno=xk;
               xk=xkmasuno;
               }while((i<=n)&&(e>t)&&(yxkmasuno!=0));


printf("\nx k=%.20lf",xk);
printf("\nx k+1=%.20lf",xkmasuno);
printf("\nf(x k)=%.20lf",yxk);
printf("\nf(x k+1)=%.20lf",yxkmasuno);

printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
