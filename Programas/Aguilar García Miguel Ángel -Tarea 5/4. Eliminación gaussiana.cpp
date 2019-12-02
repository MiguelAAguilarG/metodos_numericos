/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 1 de Julio de 2014*/
/*4. Eliminación gaussiana*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

int main()
{
    
int i=1,j=1,n,m,r=0,e=0,t=0,aux=0,q,z=0,x=0,nn=0,mm=0,r2=0,e2=0,aux2=0,nn2=0,mm2=0,x2=0,k=0,tt=0,ee=0,auxx2=0,tt2=0,ee2=0,t2,auxx=0;
char op,a,c,d[40],d2[40],cc,cc2; 
double sum;double ma[100][100];double ma2[100][100],mu[100][100],maux[100][100],mb[100][100],ma3[100][100];
FILE *f1,*f2;

do
{
      do
      {
      q=0;
      system("cls");
      fclose(f1);
      printf("4. Eliminación gaussiana\n");
      printf("Para la matriz 'A'\n");
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
       tt=0;
       ee=0;
       aux=0; 
       auxx=0;         
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
      do
      {
      
      q=0;
      system("cls");
      fclose(f2);
      printf("Para el vector columna 'b'\n");
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
      scanf("%s",&d2);
      fflush(stdin);
      
      f2=fopen(d2,"a");
      fclose(f2);
      system(d2);/*Abrir blog de notas*/
      f2=fopen(d2,"r");
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
      scanf("%s",&d2);
      fflush(stdin);
      f2=fopen(d2,"r");
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

      if(f2!=NULL)
      {
       a=0;/*Se ponen los valores para evitar errores al momento de la repeticion*/
       i=1;
       j=1;
       n=0;
       m=0;
       r2=0;
       e2=0;
       t2=0;
       tt2=0;
       ee2=0;
       aux2=0; 
       auxx2=0;         
       system("cls");  
       printf("Se ha abierto correctamente");
         
  while((cc2=fgetc(f2))!=EOF)
 {                                    
   if(cc2=='\n')
   {
   e2++;/*Contador de filas*/      
   }                                                  
 }
 
fseek(f2,0,SEEK_SET);
  
   while((cc2=fgetc(f2))!='\n')
 {                                    
   if((cc2=='\t')||(cc2==' '))
   {
   t2++;/*Contador de columnas*/          
   }                                                 
 }
fseek(f2,0,SEEK_SET);

  while((cc2=fgetc(f2))!=EOF)
 {                                      
   if((cc2=='\t')||(cc2==' '))
   {
   r2++;/*Contador de elementos totales*/       
   }                                                     
 }

printf("\nElementos totales= %d",r2);
printf("\nFilas= %d",e2);
printf("\nColumnas= %d",t2);

m=e2+1;
n=t2+1;

fseek(f2,0,SEEK_SET);
x2=0;
       for(i=1;i<m;i++)
       {
                           for(j=1;j<n;j++)
                           {
                                            
                                            if(a!=EOF)
                                            {
                                            fscanf(f2,"%lf",&ma2[i][j]);/*Asignar elementos a matriz*/
                                            fflush(stdin);
                                            x2++;
                                            }
                           } 
       }

fclose(f2);

printf("\n\nElementos totales= %d",x2); 
nn2=n-1;
mm2=m-1;
              if(x2!=r2)
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
                           printf("%lf ",ma2[i][j]);/*Imprimir matriz*/     
                           }
                   printf("\n");        
       }
       
printf("\n\nVerifique que su matriz es la correcta,\nsi hay algun error verifique su matriz,\nsi persiste el error, introducir desde cero su matriz");
system(d2);/*Abrir blog de notas*/ 
      }
     
      else
      {
       printf("\nError al abrir el archivo\n");
       system("pause");
      }
if(nn!=mm)
{
printf("\n\nError en la matriz triangular superior. No es una matriz cuadrada\n");
       system("pause");
       exit(0);
} 
if(mm!=mm2)
{
printf("\n\nError .La matriz tirnagular superior y el vector columna\nno concuerdan en el numero de filas\n");
       system("pause");
       exit(0);
} 
if(nn2!=1)
{
printf("\n\nError .El vector columna no es un vector columna\n");
       system("pause");
       exit(0);
} 

/*Duplicar U=A*/
for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
     mu[i][j]=ma[i][j];                    
     }             
}

/*Duplicar maux=A*/
for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
     maux[i][j]=ma[i][j];                    
     }             
}
/*Duplicar mb=b*/
for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
     mb[i][j]=ma2[i][j];                    
     }             
}

/*Eliminación gaussiana*/
for(i=1;i<=mm-1;i++)
{
     for(k=i+1;k<=mm;k++)
     {
          maux[k][i]=(mu[k][i])/(mu[i][i]);      
          for(j=i;j<=mm;j++)
          {
          mu[k][j]=mu[k][j]-(maux[k][i])*(mu[i][j]);/*Sustitucion para la matriz 'A'*/
          }
          ma2[k][1]=ma2[k][1]-(maux[k][i])*(ma2[i][1]);/*Sustitucion para el vector columna 'b'*/
     }
}
/***************************/
system("cls");
printf("El resultado de aplicarle la eliminacion gaussiana a la matriz 'A' es:\n\n");

for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
     printf("%lf ",mu[i][j]);                   
     } 
     printf("\n");            
}
printf("\nEl resultado de aplicarle la eliminacion gaussiana al vector 'b' es:\n\n");

for(i=1;i<=mm;i++)
{
     printf("%lf\n",ma2[i][1]);                               
}

/*Asignar ma=mu*/
for(i=1;i<=mm;i++)
{
     for(j=1;j<=nn;j++)
     {
     ma[i][j]=mu[i][j];                    
     }             
}

/*Sustitucion hacia atras U*/
k=mm2;
for(k;k>=1;k--)
{
              sum=0;
      if(k+1<=mm2)
      {    
      j=k+1;  
      for(j;j<=mm2;j++)
      { 
      sum=sum+((ma[k][j])*(ma3[j][1]));
      }
      
      }
  ma3[k][1]=ma2[k][1]-sum;  
  ma3[k][1]=ma3[k][1]/ma[k][k];
}
/***************************/

printf("\nLa solucion del sistema es: \n\n");
for(k=1;k<=mm2;k++)
{
  printf("x[%d]= %lf\n",k,ma3[k][1]);
}

printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);

}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
