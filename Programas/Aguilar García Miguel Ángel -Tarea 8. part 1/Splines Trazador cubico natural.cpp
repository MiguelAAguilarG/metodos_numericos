/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 26 de Agosto de 2014*/
/*Splines Trazador cubico natural*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

double xv[1000],yv[1000],h[1000],alpha[1000],ele[1000],mu[1000],zeta[1000],ce[1000],be[1000],de[1000];

int i=1,j=1,n=0,m=0,r=0,e=0,t=0,q=0,x=0,nn=0,mm=0;
char op,a,d[40],cc; 
double ma[1000][1000];
FILE *f1,*f2;

int main()
{
      
do
{
      do
      {
      q=0;
      system("cls");
      fclose(f1);
      printf("Splines Trazador cubico natural\n\n");
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
n=mm-1;
/*Hacer los vectores 'x' y 'y'*/
for(i=0;i<=n;i++)
{
    xv[i]=ma[i+1][1];
    yv[i]=ma[i+1][2];
    
}
/******************************************************************************/
for(i=0;i<=n-1;i++)
{
h[i]=xv[i+1]-xv[i];
}

for(i=1;i<=n-1;i++)
{
alpha[i]=(3/h[i])*(yv[i+1]-yv[i])-(3/h[i-1])*(yv[i]-yv[i-1]);
}

ele[0]=1;
mu[0]=0;
zeta[0]=0;

for(i=1;i<=n-1;i++)
{
ele[i]=(2*(xv[i+1]-xv[i-1]))-(h[i-1]*mu[i-1]);
mu[i]=h[i]/ele[i];
zeta[i]=(alpha[i]-(h[i-1]*zeta[i-1]))/ele[i];
}

ele[n]=1;
zeta[n]=0;
ce[n]=0;

for(j=n-1;j>=0;j--)
{
ce[j]=zeta[j]-mu[j]*ce[j+1];
be[j]=((yv[j+1]-yv[j])/h[j])-(h[j]*(ce[j+1]-2*ce[j])/3);
/*be[j]=((yv[j+1]-yv[j])/h[j])-(h[j]*(ce[j+1]-ce[j])/3);*/
/*be[j]=((yv[j+1]-yv[j])/h[j])-(h[j]*(ce[j+1]-2*ce[j]));*/
/*be[j]=((yv[j+1]-yv[j])/h[j])-((ce[j+1]-2*ce[j])/(3*h[j]));*/
de[j]=(ce[j+1]-ce[j])/(3*h[j]);
}

/******************************************************************************/
system("cls");

for(j=0;j<=n-1;j++)
{
printf("%d\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",j,xv[j],yv[j],be[j],ce[j],de[j]);
}
printf("%d\t%.2lf\t%.2lf\t0\t0\t0\n",n,xv[n],yv[n]);
/******************************************************************************/
printf("\n\nSe creara un fichero de resultados.txt");

     f2=fopen("resultados.txt","w");
     if(f2==NULL)
     {
     printf("\n\nNo se pudo crear el fichero resultados.txt\n");
     system("pause");
     return 1;
     }
for(j=0;j<=n-1;j++)
{
fprintf(f2,"%d\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",j,xv[j],yv[j],be[j],ce[j],de[j]);
}     
fprintf(f2,"%d\t%.2lf\t%.2lf\t0\t0\t0\n",n,xv[n],yv[n]);
     
fclose(f2);
/******************************************************************************/

printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);
}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
