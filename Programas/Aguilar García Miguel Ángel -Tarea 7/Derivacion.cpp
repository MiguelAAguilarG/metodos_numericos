/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 12 de Agosto de 2014*/
/*Derivacion*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double h,x,c,der=0,xi[12],f[12];
int i,j,k,z=0,q=0,d,e,n;
int wm4=0,wm3=0,wm2=0,wm1=0,w0=0,w1=0,w2=0,w3=0,w4=0;
char op;

int main()
{
      
do
{
system("cls");

printf("Derivacion\n\n");
/******************************************************************************/
do
{ 
q=0;              
printf("Esquema: \
        \n1. forward\
        \n2. central\
        \n3. backward");
        
printf("\n\nElige una opcion: ");
scanf("%d",&e);
fflush(stdin);

if(e!=1&&e!=2&&e!=3)
{
printf("\n\nError. Esquema no valido\n");
system("pause");
q=1;
}

}while(q==1);
/******************************************************************************/
do
{ 
q=0;              
printf("\nDerivada (Primera a la cuarta): ");
scanf("%d",&d);
fflush(stdin);

if(d!=1&&d!=2&&d!=3&&d!=4)
{
printf("\n\nError. Derivada no valida\n");
system("pause");
q=1;
}

}while(q==1);        
/******************************************************************************/
do
{ 
q=0;              

if(e==1)
{
    if(d==1)
    {
            
    printf("\n\nOpciones para numero de puntos:2,3,4,5\nn= ");
    scanf("%d",&n);
    fflush(stdin);
    
    if(n!=2&&n!=3&&n!=4&&n!=5)
    {
    printf("\n\nError. Numero de puntos no valido\n");
    system("pause");
    q=1;
    } 
       
    }
    else if(d==2)
    {

    printf("\n\nOpciones para numero de puntos:3,4,5\nn= ");
    scanf("%d",&n);
    fflush(stdin);
    
    if(n!=3&&n!=4&&n!=5)
    {
    printf("\n\nError. Numero de puntos no valido\n");
    system("pause");
    q=1;
    }
    
    }
    else if(d==3)
    {

    printf("\n\nOpciones para numero de puntos:4,5\nn= ");
    scanf("%d",&n);
    fflush(stdin);
    
    if(n!=4&&n!=5)
    {
    printf("\n\nError. Numero de puntos no valido\n");
    system("pause");
    q=1;
    }
    
    }
    else if(d==4)
    {

    printf("\n\nOpciones para numero de puntos:5\nn= ");
    scanf("%d",&n);
    fflush(stdin);
    
    if(n!=5)
    {
    printf("\n\nError. Numero de puntos no valido\n");
    system("pause");
    q=1;
    }
    
    }
    else
    {
    printf("\n\nError. Derivada no valida\n");
    system("pause");
    q=1;
    }        
}
else if(e==2)
{
    if(d==1)
    {
            
    printf("\n\nOpciones para numero de puntos:3,5,7\nn= ");
    scanf("%d",&n);
    fflush(stdin);
    
    if(n!=3&&n!=5&&n!=7)
    {
    printf("\n\nError. Numero de puntos no valido\n");
    system("pause");
    q=1;
    } 
       
    }
    else if(d==2)
    {

    printf("\n\nOpciones para numero de puntos:3,5,7\nn= ");
    scanf("%d",&n);
    fflush(stdin);
    
    if(n!=3&&n!=5&&n!=7)
    {
    printf("\n\nError. Numero de puntos no valido\n");
    system("pause");
    q=1;
    }
    
    }
    else if(d==3)
    {

    printf("\n\nOpciones para numero de puntos:5,7\nn= ");
    scanf("%d",&n);
    fflush(stdin);
    
    if(n!=5&&n!=7)
    {
    printf("\n\nError. Numero de puntos no valido\n");
    system("pause");
    q=1;
    }
    
    }
    else if(d==4)
    {

    printf("\n\nOpciones para numero de puntos:5,7\nn= ");
    scanf("%d",&n);
    fflush(stdin);
    
    if(n!=5&&n!=7)
    {
    printf("\n\nError. Numero de puntos no valido\n");
    system("pause");
    q=1;
    }
    
    }
    else
    {
    printf("\n\nError. Derivada no valida\n");
    system("pause");
    q=1;
    }
}
else if(e==3)
{
    if(d==1)
    {
            
    printf("\n\nOpciones para numero de puntos:2,3,4,5\nn= ");
    scanf("%d",&n);
    fflush(stdin);
    
    if(n!=2&&n!=3&&n!=4&&n!=5)
    {
    printf("\n\nError. Numero de puntos no valido\n");
    system("pause");
    q=1;
    } 
       
    }
    else if(d==2)
    {

    printf("\n\nOpciones para numero de puntos:3,4,5\nn= ");
    scanf("%d",&n);
    fflush(stdin);
    
    if(n!=3&&n!=4&&n!=5)
    {
    printf("\n\nError. Numero de puntos no valido\n");
    system("pause");
    q=1;
    }
    
    }
    else if(d==3)
    {

    printf("\n\nOpciones para numero de puntos:4,5\nn= ");
    scanf("%d",&n);
    fflush(stdin);
    
    if(n!=4&&n!=5)
    {
    printf("\n\nError. Numero de puntos no valido\n");
    system("pause");
    q=1;
    }
    
    }
    else if(d==4)
    {

    printf("\n\nOpciones para numero de puntos:5\nn= ");
    scanf("%d",&n);
    fflush(stdin);
    
    if(n!=5)
    {
    printf("\n\nError. Numero de puntos no valido\n");
    system("pause");
    q=1;
    }
    
    }
    else
    {
    printf("\n\nError. Derivada no valida\n");
    system("pause");
    q=1;
    }     
}
else
{
printf("\n\nError. Esquema no valido\n");
system("pause");
q=1;
}

}while(q==1); 
/******************************************************************************/

do
{ 
q=0;              
printf("\n\n(Delta de x)h: ");
scanf("%lf",&h);
fflush(stdin);

if(h<=0)
{
printf("\n\nError. h menor o igual que 0\n");
system("pause");
q=1;
}

}while(q==1); 
/******************************************************************************/
printf("\n\nx: ");
scanf("%lf",&x);
fflush(stdin);
/******************************************************************************/              
wm4=0;
wm3=0;
wm2=0;   
wm1=0;
w0=0;
w1=0;
w2=0;
w3=0;   
w4=0;
/******************************************************************************/
switch(e)
{
    case 1:
    {
        if(d==1)
        {
            if(n==2)
            {
            w0=-1;
            w1=1;   
            c=1/h;    
            }
            else if(n==3)
            {
            w0=-3;
            w1=4;
            w2=-1; 
            c=1/(2*h);                   
            }
            else if(n==4)
            {
            w0=-11;
            w1=18;
            w2=-9;
            w3=2;  
            c=1/(6*h);                
            }
            else if(n==5)
            {
            w0=-25;
            w1=48;
            w2=-36;
            w3=16;   
            w4=-3;
            c=1/(12*h);                   
            }
            else
            {
            printf("\n\nError. Numero de puntos no valido\n");    
            system("pause");   
            }       
        }
        else if(d==2)
        {
            if(n==3)
            {
            w0=1;
            w1=-2;
            w2=1; 
            c=1/(h*h);                   
            }
            else if(n==4)
            {
            w0=2;
            w1=-5;
            w2=4;
            w3=-1;  
            c=1/(h*h*h);                
            }
            else if(n==5)
            {
            w0=35;
            w1=-104;
            w2=114;
            w3=-56;   
            w4=11;
            c=1/(12*h*h);                   
            }
            else
            {
            printf("\n\nError. Numero de puntos no valido\n");  
            system("pause");     
            }                 
        }
        else if(d==3)
        {
            if(n==4)
            {
            w0=-1;
            w1=3;
            w2=-3;
            w3=1;  
            c=1/(h*h*h);                
            }
            else if(n==5)
            {
            w0=-5;
            w1=18;
            w2=-24;
            w3=14;   
            w4=-3;
            c=1/(2*h*h*h);                   
            }
            else
            {
            printf("\n\nError. Numero de puntos no valido\n"); 
            system("pause");      
            }                 
        }
        else if(d==4)
        {

            if(n==5)
            {
            w0=1;
            w1=-4;
            w2=6;
            w3=-4;   
            w4=1;
            c=1/(h*h*h*h);                   
            }
            else
            {
            printf("\n\nError. Numero de puntos no valido\n");  
            system("pause");     
            }                
        }
        else
        {
        printf("\n\nError. Derivada no valida\n");   
        system("pause");    
        }
    break;
    }
/******************************************************************************/
    case 2:
    {
        if(d==1)
        {
            if(n==3)
            {
            wm1=-1;
            w0=0;
            w1=1;   
            c=1/2*h;    
            }
            else if(n==5)
            {
            wm2=1;
            wm1=-8;               
            w0=0;
            w1=8;
            w2=-1; 
            c=1/(12*h);                   
            }
            else if(n==7)
            {
            wm3=-1;
            wm2=9;               
            wm1=-45;                 
            w0=0;
            w1=45;
            w2=-9;
            w3=1;  
            c=1/(60*h);                
            }
            else
            {
            printf("\n\nError. Numero de puntos no valido\n");    
            system("pause");   
            }       
        }
        else if(d==2)
        {
            if(n==3)
            {
            wm1=1;
            w0=-2;
            w1=1;   
            c=1/(h*h);                    
            }
            else if(n==5)
            {
            wm2=-1;
            wm1=16;               
            w0=-30;
            w1=16;
            w2=-1; 
            c=1/(12*h*h);                   
            }
            else if(n==7)
            {
            wm3=2;
            wm2=-27;               
            wm1=270;                 
            w0=-490;
            w1=270;
            w2=-27;
            w3=2;  
            c=1/(180*h*h);                 
            }
            else
            {
            printf("\n\nError. Numero de puntos no valido\n");     
            system("pause"); 
            }                 
        }
        else if(d==3)
        {
            if(n==5)
            {
            wm2=-1;
            wm1=2;               
            w0=0;
            w1=-2;
            w2=1; 
            c=1/(2*h*h*h);                
            }
            else if(n==7)
            {
            wm3=1;
            wm2=-8;               
            wm1=13;                 
            w0=0;
            w1=-13;
            w2=8;
            w3=-1;  
            c=1/(8*h*h*h);               
            }
            else
            {
            printf("\n\nError. Numero de puntos no valido\n");   
            system("pause");    
            }                 
        }
        else if(d==4)
        {

            if(n==5)
            {
            wm2=1;
            wm1=-4;               
            w0=6;
            w1=-4;
            w2=1; 
            c=1/(h*h*h*h);                 
            }
            else if(n==7)
            {
            wm3=-1;
            wm2=12;               
            wm1=-39;                 
            w0=56;
            w1=-39;
            w2=12;
            w3=-1;  
            c=1/(6*h*h*h*h);                       
            }
            else
            {
            printf("\n\nError. Numero de puntos no valido\n");    
            system("pause");   
            }                
        }
        else
        {
        printf("\n\nError. Derivada no valida\n"); 
        system("pause");      
        }
    break;
    }
/******************************************************************************/
    case 3:
    {
        if(d==1)
        {
            if(n==2)
            {
            w0=1;
            wm1=-1;   
            c=1/h;    
            }
            else if(n==3)
            {
            w0=3;
            wm1=-4;
            wm2=1; 
            c=1/(2*h);                   
            }
            else if(n==4)
            {
            w0=11;
            wm1=-18;
            wm2=9;
            wm3=-2;  
            c=1/(6*h);                
            }
            else if(n==5)
            {
            w0=25;
            wm1=-48;
            wm2=36;
            wm3=-16;   
            wm4=3;
            c=1/(12*h);                   
            }
            else
            {
            printf("\n\nError. Numero de puntos no valido\n");   
            system("pause");    
            }       
        }
        else if(d==2)
        {
            if(n==3)
            {
            w0=1;
            wm1=-2;
            wm2=1; 
            c=1/(h*h);                   
            }
            else if(n==4)
            {
            w0=2;
            wm1=-5;
            wm2=4;
            wm3=-1;  
            c=1/(h*h);                
            }
            else if(n==5)
            {
            w0=35;
            wm1=-104;
            wm2=114;
            wm3=-56;   
            wm4=11;
            c=1/(12*h*h);                   
            }
            else
            {
            printf("\n\nError. Numero de puntos no valido\n");
            system("pause");       
            }                 
        }
        else if(d==3)
        {
            if(n==4)
            {
            w0=1;
            wm1=-3;
            wm2=3;
            wm3=-1;  
            c=1/(h*h*h);                
            }
            else if(n==5)
            {
            w0=5;
            wm1=-18;
            wm2=24;
            wm3=-14;   
            wm4=3;
            c=1/(2*h*h*h);                   
            }
            else
            {
            printf("\n\nError. Numero de puntos no valido\n"); 
            system("pause");      
            }                 
        }
        else if(d==4)
        {

            if(n==5)
            {
            w0=1;
            wm1=-4;
            wm2=6;
            wm3=-4;   
            wm4=1;
            c=1/(h*h*h*h);                   
            }
            else
            {
            printf("\n\nError. Numero de puntos no valido\n");    
            system("pause");   
            }                
        }
        else
        {
        printf("\n\nError. Derivada no valida\n");     
        system("pause");  
        }
    break;
    } 
    default:
    {
    printf("\n\nError. Esquema no valido\n");
    system("pause");
    break;
    }
}
/******************************************************************************/
for(i=-4;i<=4;i++)
{
xi[i+5]=x+(i*h);                  
}
/******************************************************************************/
for(i=-4;i<=4;i++)
{
/*sin(x)*/
/*1/cosh(x)/
/*x*x*x-2*x*x+4*/ 
/*f[i+5]=xi[i+5]*xi[i+5];*/
/*f[i+5]=sin(xi[i+5]);*/  
/*f[i+5]=1/cosh(xi[i+5]);*/ 
f[i+5]=xi[i+5]*xi[i+5]*xi[i+5]-2*xi[i+5]*xi[i+5]+4;                   
}
/******************************************************************************/

der=c*(wm4*f[1]+wm3*f[2]+wm2*f[3]+wm1*f[4]+w0*f[5]+w1*f[6]+w2*f[7]+w3*f[8]+w4*f[9]);

printf("\nLa derivada es: %.12lf",der);


printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
