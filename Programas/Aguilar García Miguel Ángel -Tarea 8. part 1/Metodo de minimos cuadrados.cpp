/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 26 de Agosto de 2014*/
/*Metodo de minimos cuadrados*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double xval,xv[1000],yv[1000],mapol[1000][1000],mapolinv[1000][1000],mapolt[1000][1000],manew[1000][1000],mabnew[1000][1000];
int k,grado;

double sum=0,auxb,auxa[1000],maux[1000][1000],mb[1000][1000],mu[1000][1000],ml[1000][1000],mi[1000][1000],ma3[1000][1000];
int mm2,nn2;

int i=1,j=1,n=0,m=0,r=0,e=0,t=0,q=0,x=0,nn=0,mm=0;
char op,a,d[40],cc; 
double ma[1000][1000];
FILE *f1;

int main()
{
      
do
{
      do
      {
      q=0;
      system("cls");
      fclose(f1);
      printf("Metodo de minimos cuadrados\n\n");
      printf("Para ingresar la tabla de valores x/y hacerlo por fichero como si fuera una\nmatriz\ndel lado izquierdo 'x' y del lado derecho 'y'\n");
      printf("Desea:\
               \n1. Hacer un fichero nuevo o abrir para modificar\
               \n2. Abrir un fichero existente");
      printf("\n\n******NOTA IMPORTANTE:Cuando se acaben de poner todos los elementos de la matriz\nse debera anadir un enter\n(es decir,situar el cursor debajo del ultimo renglon)\nde lo contrario saldran errores,\nademas se debera poner un espacio finalizado un renglon,\nde lo contrario saldran errores");         
      printf("\n\nElige una opcion: ");
      scanf("%d",&q);
      fflush(stdin);
      switch(q)
      {
               case 1:
                    {
      a=0;
      system("cls");  
      printf("1. Hacer un fichero nuevo o abrir para modificar");  
      printf("\n\nNota: Para seguir con el proceso se debe guardar\nlas modificaciones que se hicieron en el blog de notas\ny cerrarlo\n\n");       
      printf("\nIntroduce el nombre del fichero que desea crear o modificar (nombre.txt): ");
      scanf("%s",&d);
      fflush(stdin);
      
      f1=fopen(d,"a");
      fclose(f1);
      system(d);/*Abrir blog de notas*/
      f1=fopen(d,"r");
      printf("\n\nContinuar si ya ha guardado el blog de notas\n\n");
      system("pause");
      q=0;
                        break;
                    }
               case 2:
                    {

      a=0;
      system("cls");  
      printf("2. Abrir un fichero existente");       
      printf("\nIntroduce el nombre del fichero que desea abir (nombre.txt): ");
      scanf("%s",&d);
      fflush(stdin);
      f1=fopen(d,"r");
      q=0;
                        break;
                    }
               default:
               {
               a=0;
               printf("\n\nERROR.Opcion no valida\n\n");
               system("pause");
               q=1;
               break;
               }
      }
      
      }while(q==1);

      if(f1!=NULL)
      {
       a=0;/*Se ponen los valores para evitar errores al momento de la repeticion*/
       i=1;
       j=1;
       n=0;
       m=0;
       r=0;
       e=0;
       t=0;    
       system("cls");  
       printf("Se ha abierto correctamente");
         
  while((cc=fgetc(f1))!=EOF)
 {                                    
   if(cc=='\n')
   {
   e++;/*Contador de filas*/      
   }                                                  
 }
 
fseek(f1,0,SEEK_SET);
  
   while((cc=fgetc(f1))!='\n')
 {                                    
   if((cc=='\t')||(cc==' '))
   {
   t++;/*Contador de columnas*/          
   }                                                 
 }
fseek(f1,0,SEEK_SET);

  while((cc=fgetc(f1))!=EOF)
 {                                      
   if((cc=='\t')||(cc==' '))
   {
   r++;/*Contador de elementos totales*/       
   }                                                     
 }
printf("\nElementos totales= %d",r);
printf("\nFilas= %d",e);
printf("\nColumnas= %d",t);

m=e+1;
n=t+1;
fseek(f1,0,SEEK_SET);
x=0;
       for(i=1;i<m;i++)
       {
                           for(j=1;j<n;j++)
                           {
                                            
                                            if(a!=EOF)
                                            {
                                            fscanf(f1,"%lf",&ma[i][j]);/*Asignar elementos a matriz*/
                                            fflush(stdin);
                                            x++;
                                            }
                           } 
       }

fclose(f1);

printf("\n\nElementos totales= %d",x); 
nn=n-1;
mm=m-1;
              if(x!=r)
              {
              printf("\n\nERROR. Posiblemente las filas no estan completas o le faltan elementos,\
              \nverifique que en todas las filas el numero de columnas es igual\
              \nsi faltan elementos complete con ceros\n\n");
              system("pause");
              exit(0);
              }
                     
       printf("\nSu matriz es:");  
       printf("\n");  
       for(i=1;i<m;i++)
       {
                           for(j=1;j<n;j++)
                           {
                           printf("%lf ",ma[i][j]);/*Imprimir matriz*/     
                           }
                   printf("\n");        
       }
       
printf("\n\nVerifique que su matriz es la correcta,\nsi hay algun error verifique su matriz,\nsi persiste el error, introducir desde cero su matriz");
system(d);/*Abrir blog de notas*/ 
      }
     
      else
      {
       printf("\nError al abrir el archivo\n");
       system("pause");
      }
      
/*******************************************************************************************************************/      
/*Hacer los vectores 'x' y 'y'*/
for(i=1;i<=mm;i++)
{
    xv[i]=ma[i][1];
    yv[i]=ma[i][2];
    
}
/******************************************************************************/
system("cls");

printf("Metodo de minimos cuadrados\n\n");
               
printf("Inserte el grado del polinomio: ");
scanf("%d",&grado);
fflush(stdin);

/*Hacer mapolinv*/
for(i=0;i<=grado;i++)/*Para elevar hasta el grado correcto*/
{
    for(j=1;j<=mm;j++)/*Para desplazarse en las filas*/
    {
         mapolinv[j][i]=pow(xv[j],i);                                
    }
}
/******************************************************************************/
/*Hacer mapol*/
for(i=0;i<=grado;i++)/*Para cambiar columnas*/
{
    for(j=1;j<=mm;j++)/*Para desplazarse en las filas*/
    {
         mapol[j][i+1]=mapolinv[j][grado-i];                              
    }
}
/******************************************************************************/
/*transpuesta de 'mapolt'*/
    for(i=1;i<=mm;i++)
    {
        for(j=1;j<=grado+1;j++)
        {
         mapolt[j][i]=mapol[i][j]; 
        }          
    }
/******************************************************************************/
/*Multiplicacion de 'mapolt' por 'mapol'*/
for(i=1;i<=grado+1;i++)
{
   for(j=1;j<=grado+1;j++)
   {
   auxb=0;                 
      for(k=1;k<=mm;k++)
      {
      auxa[k]=mapolt[i][k]*mapol[k][j];          
      }
      for(k=1;k<=mm;k++)
      {            
      auxb=auxa[k]+auxb;         
      } 
   manew[i][j]=auxb;                
   }
}
/******************************************************************************/
/*Multiplicacion de 'mapolt' por 'yv*/
for(i=1;i<=grado+1;i++)
{
   auxb=0;                 
      for(k=1;k<=mm;k++)
      {
      auxa[k]=mapolt[i][k]*yv[k];          
      }
      for(k=1;k<=mm;k++)
      {            
      auxb=auxa[k]+auxb;         
      } 
   mabnew[i][1]=auxb;                
}
/***************************************************************************************************************************/
/*Sustituacion para Factorizacion LU*/
mm=grado+1;
nn=grado+1;
mm2=grado+1;
nn2=grado+1;
/******************************************************************************/
/*Formar matriz identidad*/
for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
                       if(j==i)
                       {
                       mi[i][j]=1;
                       }
                       else
                       {
                       mi[i][j]=0;
                       }
     }             
}

/*Duplicar B=A*/
for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
     mb[i][j]=manew[i][j];                    
     }             
}

/*Duplicar maux=A*/
for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
     maux[i][j]=manew[i][j];                    
     }             
}

/*Factorización LU*/
for(i=1;i<=mm-1;i++)
{
     for(k=i+1;k<=mm;k++)
     {
          maux[k][i]=(mb[k][i])/(mb[i][i]);      
          for(j=i;j<=mm;j++)
          {
          mb[k][j]=mb[k][j]-(maux[k][i])*(mb[i][j]);
          }
          mi[k][i]=maux[k][i];
     }
}
/*Sustituir mu=mb*/
for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
     mu[i][j]=mb[i][j];                    
     }             
}
/*Sustituir ml=mi*/
for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
     ml[i][j]=mi[i][j];                    
     }             
}

/*Sustituir matriz L para meter en sustitución hacia delante*/       
for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
     manew[i][j]=ml[i][j];                    
     }             
}

/*Sustitucion hacia adelante*/
k=1;
for(k;k<=mm2;k++)
{
              sum=0;
if(k-1>=1)
{
      for(j=1;j<=k-1;j++)
      { 
      sum=sum+((manew[k][j])*(ma3[j][1]));
      }
}
  ma3[k][1]=mabnew[k][1]-sum;  
  ma3[k][1]=ma3[k][1]/manew[k][k];
}

/*Sustituir matriz U para meter en sustitución hacia atras*/       
for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
     manew[i][j]=mu[i][j];                    
     }             
}
/*Sustituir 'y'=ma3 por vector 'b'=ma2*/    
/*Es decir ma2=ma3*/    
for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
     mabnew[i][j]=ma3[i][j];                    
     }             
}
/*Sustitucion hacia atras*/
k=mm2;
for(k;k>=1;k--)
{
              sum=0;
      if(k+1<=mm2)
      {    
      j=k+1;  
      for(j;j<=mm2;j++)
      { 
      sum=sum+((manew[k][j])*(ma3[j][1]));
      }
      
      }
  ma3[k][1]=mabnew[k][1]-sum;  
  ma3[k][1]=ma3[k][1]/manew[k][k];
}
/***************************************************************************************************************************/
printf("\nLa solucion del sistema es: \n\n");
for(k=1;k<=mm2;k++)
{
  printf("x[%d]= %lf\n",k,ma3[k][1]);
}
/***************************************************************************************************************************/
printf("\nEl polinomio es: \n\n");
printf("y=");
i=grado;
for(k=1;k<=mm2;k++)
{
  printf("(%lf)x^%d",ma3[k][1],i);
  if(k!=mm2)
  {
  printf("+");
  }
  i=grado-k;
}

printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
