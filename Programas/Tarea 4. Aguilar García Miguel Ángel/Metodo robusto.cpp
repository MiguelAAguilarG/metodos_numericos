/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 10 de Junio de 2014*/
/*Metodo Robusto*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double m,ya,yb,ym,x,y,gxk,t,e,yxkprima,ymenosuno,xkmenosuno,yxkmenosuno,yxcero,xcero,xmenosuno,yxmenosuno,ykmenosuno,xk,xkmasuno,ycero,yxk,yxkmasuno,yxkdobleprima,aux,yxceroprima,a,b,c,fa,fb,fc,u,v,w,p,q,d,fd;
int i,n,r,z;
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
               \nMetodo Robusto\n\n");
               
printf("Este programa iniciara con el metodo de biseccion,\
\ndespués cambiara a otro metodo cuando |f(m)|<=.01 y\
\n'm' sera el valor de entrada al siguiente programa\n\n");
                       
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
               
printf("\nIntroduce la opción que desees para continuar despues del metodo de la bisección");               
               
printf(         "1. Metodo de punto fijo\
                \n2. Metodo de Newton\
                \n3. Metodo de la secante\
                \n4. Metodo de Newton-Raphson de segundo orden\
                \n5. Metodo de von Misses\
                \n6. Metodo de la interpolacion inversa");   
                            
printf("\n\nCual opcion eliges: ");
scanf("%d",&z);
fflush(stdin);
               i=0;
               printf("\nk\ta\tb\tm\tf(a)\t\tf(b)\t\tf(m)");               
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
                             printf("\t%.10lf",ya);
                             printf("\t%.10lf",yb);
                             printf("\t%.10lf",ym);

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
               }while((i<=n)&&(fabs(ym)>.01));

switch(z)
 {
  case 1:
  {
  printf("\n1. Metodo de punto fijo\n\n");
  xk=m;
  printf("\nk\tx k\t\tg(x k+1)\t\tf(x k)");
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
  break;
  }
  
  case 2:
  {
       printf("\n2. Metodo de Newton\n\n");
               printf("\nk\tx k\t\tx k+1\t\tf(x k)\t\tf(x k+1)");
               xcero=m;
               xk=xcero;
               do
               {
                   
                             /*x^2-x-2 modifica para cambiar la función*/
                             yxk=xk*xk-xk-2;
                             yxkprima=2*xk-1;
                             xkmasuno=xk-(yxk/yxkprima);
                             yxkmasuno=xkmasuno*xkmasuno-xkmasuno-2;
                             /*************************************************************************/
                             printf("\n%d",i);
                             printf("\t%.10lf",xk);
                             printf("\t%.10lf",xkmasuno);
                             printf("\t%.10lf",yxk);
                             printf("\t%.10lf",yxkmasuno);

               i++;
               e=fabs(xkmasuno-xk);
               xk=xkmasuno;
               }while((i<=n)&&(e>t)&&(yxkmasuno!=0));


printf("\nx k=%.20lf",xk);
printf("\nx k+1=%.20lf",xkmasuno);
printf("\nf(x k)=%.20lf",yxk);
printf("\nf(x k+1)=%.20lf",yxkmasuno);
  break;
  }
  
  case 3:
  {            do
               {
               printf("\n3. Metodo de la secante\n\n");
               r=0; 
               printf("Inserte x-1: ");
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
  break;
  }
  
  case 4:
  {
               do
               {
               r=0; 
               printf("\n4. Metodo de Newton-Raphson de Segundo Orden\n\n");
               xcero=m;

               /*x^2-x-2 modifica para cambiar la función*/
               ycero=xcero*xcero-xcero-2;
               /***************************************************************************************************/

               if(ycero==0)
               {
                      r=1;
                      printf("\nf(x0)=0");
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
               
               printf("\nk\tx k\t\tx k+1\tf(x k)\t\tf'(x k)\tf''(xk)\tf(xk+1)");
               xk=xcero;
               do
               {
                   
                            /*x^2-x-2 modifica para cambiar la función*/
                             yxk=xk*xk-xk-2;
                             yxkprima=2*xk-1;
                             yxkdobleprima=2;
                             aux=((yxkdobleprima)/(2*(yxkprima)))-((yxkprima)/(yxk));
                             xkmasuno=xk+1/aux;
                             yxkmasuno=xkmasuno*xkmasuno-xkmasuno-2;
                             /*************************************************************************/
                             printf("\n%d",i);
                             printf("\t%.10lf",xk);
                             printf("\t%.4lf",xkmasuno);
                             printf("\t%.10lf",yxk);
                             printf("\t%.4lf",yxkprima);
                             printf("\t%.4lf",yxkdobleprima);
                             printf("\t%.10lf",yxkmasuno);

               i++;
               e=fabs(xkmasuno-xk);
               xk=xkmasuno;
               }while((i<=n)&&(e>t)&&(yxkmasuno!=0));


printf("\nx k=%.20lf",xk);
printf("\nx k+1=%.20lf",xkmasuno);
printf("\nf(x k)=%.20lf",yxk);
printf("\nf(x k+1)=%.20lf",yxkmasuno);

  break;
  }
  
  case 5:
  {
              do
               {
               r=0; 
               printf("\n5. Metodo de von Misses\n\n");
               xcero=m;
               /*x^2-x-2 modifica para cambiar la función*/
               ycero=xcero*xcero-xcero-2;
               /***************************************************************************************************/

               if(ycero==0)
               {
                      r=1;
                      printf("\nf(x0)=0");
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
               
               printf("\nk\tx k\t\tx k+1\t\tf(x k)\t\tf(x k+1)");
               xk=xcero;
               /*x^2-x-2 modifica para cambiar la función*/
               yxceroprima=2*xcero-1;
               /*************************************************************************/
               do
               {
                   
                             /*x^2-x-2 modifica para cambiar la función*/
                             yxk=xk*xk-xk-2;
                             yxkprima=2*xk-1;
                             xkmasuno=xk-(yxk/yxceroprima);
                             yxkmasuno=xkmasuno*xkmasuno-xkmasuno-2;
                             /*************************************************************************/
                             printf("\n%d",i);
                             printf("\t%.10lf",xk);
                             printf("\t%.10lf",xkmasuno);
                             printf("\t%.10lf",yxk);
                             printf("\t%.10lf",yxkmasuno);

               i++;
               e=fabs(xkmasuno-xk);
               xk=xkmasuno;
               }while((i<=n)&&(e>t)&&(yxkmasuno!=0));


printf("\nx k=%.20lf",xk);
printf("\nx k+1=%.20lf",xkmasuno);
printf("\nf(x k)=%.20lf",yxk);
printf("\nf(x k+1)=%.20lf",yxkmasuno);
  break;
  }
  
  case 6:
  {
              do
               {
               r=0; 
printf("\n\n6.Metodo de Interpolacion Cuadratica Inversa\n\n");
                       
               printf("\nSe va a utilizar la siguiente sustitucion:");
               printf("\na=m-.01");
               printf("\nb=m");
               printf("\nc=m+.01\n");
               a=m-.01;
               b=m;
               c=m+.01;
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

  break;
  }
  
  default:
  {
  printf("\n\nERROR.Opcion no valida: ");
  break;
  }
  
 }

printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
