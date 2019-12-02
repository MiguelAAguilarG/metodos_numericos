/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 12 de Agosto de 2014*/
/*Derivar e integrar polinomios*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double x[100],xi[100];
int i,j,k,z=0,q;
int g,d,e;
char op;

int main()
{
      
do
{

do
{ 
q=0;

system("cls");
              
printf("Derivar e integrar polinomios: \
        \n1. Derivar\
        \n2. Derivar n-veces\
        \n3. Integrar");
        
printf("\n\nElige una opcion: ");
scanf("%d",&e);
fflush(stdin);

if(e!=1&&e!=2&&e!=3)
{
printf("\n\nError. Opcion no valida\n");
system("pause");
q=1;
}

}while(q==1);
/*************************************************************************************************************************/
if(e==1)
{
/******************************************************************************/       
do
{
system("cls");

printf("1. Derivar\n\n");
               
printf("Grado del polinomio: ");
scanf("%d",&g);
fflush(stdin);

z=0;
if(g<0)
{
printf("\n\nError. El grado del polinomio es menor a 0\n");
system("pause");
z=1;
}

}while(z==1);  
/******************************************************************************/
for(i=0;i<100;i++)
{
x[i]=0;
}
/******************************************************************************/
printf("\nInserte constantes del polinomio\n");
for(i=0;i<=g;i++)
{
printf("x^%d= ",i);
scanf("%lf",&x[i]);
fflush(stdin);
}            
/******************************************************************************/
printf("\n");
for(i=0;i<=g;i++)
{
printf("x^%d\t",i);
}   
/******************************************************************************/
printf("\n");
for(i=0;i<=g;i++)
{
x[i]=(i+1)*x[i+1];
printf("%.2lf\t",x[i]);
}
/******************************************************************************/ 
}
/*************************************************************************************************************************/
if(e==2)
{
/******************************************************************************/      
do
{
system("cls");

printf("Derivar n-veces\n\n");
               
printf("Grado del polinomio: ");
scanf("%d",&g);
fflush(stdin);

printf("Derivada-n: ");
scanf("%d",&d);
fflush(stdin);

z=0;
if(g<0)
{
printf("\n\nError. El grado del polinomio es menor a 0\n");
system("pause");
z=1;
}
if(d<=0)
{
printf("\n\nError. La derivada es igual o menor que 0\n");
system("pause");
z=1;
}

}while(z==1);  
/******************************************************************************/
for(i=0;i<100;i++)
{
x[i]=0;
}
/******************************************************************************/
printf("\nInserte constantes del polinomio\n");
for(i=0;i<=g;i++)
{
printf("x^%d= ",i);
scanf("%lf",&x[i]);
fflush(stdin);
}            
/******************************************************************************/
printf("\n\nDer");
for(i=0;i<=g;i++)
{
printf("\tx^%d",i);
}   
/******************************************************************************/
k=0;
printf("\n%d",k);
for(i=0;i<=g;i++)
{
printf("\t%.2lf",x[i]);
}   
/******************************************************************************/
k=1;
do
{
printf("\n%d",k);    
for(i=0;i<=g;i++)
{
x[i]=(i+1)*x[i+1];
printf("\t%.2lf",x[i]);
}
   
k++;
}while(k<=d);
/******************************************************************************/
}
/*************************************************************************************************************************/
if(e==3)
{
/******************************************************************************/
do
{
system("cls");

printf("3. Integrar\n\n");
               
printf("Grado del polinomio: ");
scanf("%d",&g);
fflush(stdin);

z=0;
if(g<0)
{
printf("\n\nError. El grado del polinomio es menor a 0\n");
system("pause");
z=1;
}

}while(z==1);  
/******************************************************************************/
for(i=0;i<100;i++)
{
x[i]=0;
}
for(i=0;i<100;i++)
{
xi[i]=0;
}
/******************************************************************************/
printf("\nInserte constantes del polinomio\n");
for(i=0;i<=g;i++)
{
printf("x^%d= ",i);
scanf("%lf",&x[i]);
fflush(stdin);
}
/******************************************************************************/
for(i=0;i<=g;i++)
{
xi[i]=x[i];
}        
/******************************************************************************/
printf("\nSu integral es:\n\n");
for(i=0;i<=g+1;i++)
{
printf("x^%d\t",i);
}   
/******************************************************************************/
for(i=0;i<=g+1;i++)
{
x[i+1]=xi[i]/(i+1);   
}
/******************************************************************************/
printf("\n");
for(i=0;i<=g+1;i++)
{
   if(i==0)
   {
   printf("C");       
   }
   else
   {
   printf("\t%.2lf",x[i]);       
   }
}  
/******************************************************************************/
} 
printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
