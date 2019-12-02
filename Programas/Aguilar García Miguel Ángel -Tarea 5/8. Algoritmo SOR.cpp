/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Martes 1 de Julio de 2014*/
/*8. Algoritmo SOR*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

int main()
{
    
int i=1,j=1,n,m,r=0,e=0,t=0,aux=0,q,x=0,nn=0,mm=0,r2=0,e2=0,nn2=0,mm2=0,x2=0,k=0,t2=0,nn3=0,mm3=0,r3=0,e3=0,x3=0,t3=0,iter;
char op,a,c,d[40],d2[40],cc,cc2,d3[40],cc3; 
double sum0=0,sumn=0;double ma[100][100];double ma2[100][100],ma3[100][100],maux3[100][100],tol=0,er1=0,er2=0,max=0,res[100],sumaux3=0,suma3=0,tol2=0,ma3old[100][100],w=1.5,ma3ee[100][100],ma3e[100][100];
FILE *f1,*f2,*f3;

do
{
      do
      {
      q=0;
      system("cls");
      fclose(f1);
      printf("8. Algoritmo SOR\n");
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
      
/*****************************************************************************************************************************/      
do
      {
      
      q=0;
      system("cls");
      fclose(f3);
      printf("Para el vector columna 'x0'\n");
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
      scanf("%s",&d3);
      fflush(stdin);
      
      f3=fopen(d3,"a");
      fclose(f3);
      system(d3);/*Abrir blog de notas*/
      f3=fopen(d3,"r");
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
      scanf("%s",&d3);
      fflush(stdin);
      f3=fopen(d3,"r");
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

      if(f3!=NULL)
      {
       a=0;/*Se ponen los valores para evitar errores al momento de la repeticion*/
       i=1;
       j=1;
       n=0;
       m=0;
       r3=0;
       e3=0;
       t3=0;        
       system("cls");  
       printf("Se ha abierto correctamente");
         
  while((cc3=fgetc(f3))!=EOF)
 {                                    
   if(cc3=='\n')
   {
   e3++;/*Contador de filas*/      
   }                                                  
 }
 
fseek(f3,0,SEEK_SET);
  
   while((cc3=fgetc(f3))!='\n')
 {                                    
   if((cc3=='\t')||(cc3==' '))
   {
   t3++;/*Contador de columnas*/          
   }                                                 
 }
fseek(f3,0,SEEK_SET);

  while((cc3=fgetc(f3))!=EOF)
 {                                      
   if((cc3=='\t')||(cc3==' '))
   {
   r3++;/*Contador de elementos totales*/       
   }                                                     
 }

printf("\nElementos totales= %d",r3);
printf("\nFilas= %d",e3);
printf("\nColumnas= %d",t3);

m=e3+1;
n=t3+1;

fseek(f3,0,SEEK_SET);
x3=0;
       for(i=1;i<m;i++)
       {
                           for(j=1;j<n;j++)
                           {
                                            
                                            if(a!=EOF)
                                            {
                                            fscanf(f3,"%lf",&ma3[i][j]);/*Asignar elementos a matriz*/
                                            fflush(stdin);
                                            x3++;
                                            }
                           } 
       }

fclose(f3);

printf("\n\nElementos totales= %d",x3); 
nn3=n-1;
mm3=m-1;
              if(x3!=r3)
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
                           printf("%lf ",ma3[i][j]);/*Imprimir matriz*/     
                           }
                   printf("\n");        
       }
       
printf("\n\nVerifique que su matriz es la correcta,\nsi hay algun error verifique su matriz,\nsi persiste el error, introducir desde cero su matriz");
system(d3);/*Abrir blog de notas*/ 
      }
     
      else
      {
       printf("\nError al abrir el archivo\n");
       system("pause");
      }
      
/*****************************************************************************************************************************/      
r=0;
if(nn!=mm)
{
printf("\n\nError.'A' no es una matriz cuadrada\n");
       r=1;
}
if(mm!=mm2)
{
printf("\n\nError .La matriz 'A' y el vector columna 'b'\nno concuerdan en el numero de filas\n");
       r=1;
}
if(mm!=mm3)
{
printf("\n\nError .La matriz 'A'y el vector columna 'x0'\nno concuerdan en el numero de filas\n");
       system("pause");
       r=1;
} 
if(nn2!=1)
{
printf("\n\nError .El vector columna 'b' no es un vector columna\n");
       r=1;
}
if(nn3!=1)
{
printf("\n\nError .El vector columna 'x0' no es un vector columna\n");
       exit(0);
}
if(r==1)
{
       system("pause");
       exit(0);
}
/*Insertar tolerancia e iteraciones*/
                do
               {
               r=0; 
               system("cls");              
               printf("Inserte numero maximo de iteraciones n= ");
               scanf("%d",&iter);
               fflush(stdin);
               printf("Inserte w (w>=0)= ");
               scanf("%lf",&w);
               fflush(stdin);
               printf("\nInserte tolerancia para error 1\n(valor absoluto de la diferencia de maginitudes del vector nuevo y antiguo)= ");
               scanf("%lf",&tol);
               fflush(stdin);
               printf("\nInserte tolerancia para error 2\n(maximo valor del valor absoluto de la diferencia de cada x del vector nuevo y antiguo)= ");
               scanf("%lf",&tol2);
               fflush(stdin);
               
               if(iter<0)
               {
                      r=1;
                      printf("\nERROR. \"n\" no es valida n<0");
                      printf("\n");
                      system("pause");
               }
               else if(w<0)
               {
                      r=1;
                      printf("\nERROR. 'w' no es valida w<0");
                      printf("\n");
                      system("pause");
               }
               else if(tol<0)
               {
                      r=1;
                      printf("\nERROR. \"t\" no es valida t<0");
                      printf("\n");
                      system("pause");
               }
               else if(tol2<0)
               {
                      r=1;
                      printf("\nERROR. \"t\" no es valida t<0");
                      printf("\n");
                      system("pause");
               }
               
               }while(r==1);
               
               
/*Metodo gauss-seidel***********/
sum0=0;
sumn=0;
k=0;
printf("\n\tVector SOR\t\tVector Gauss-Seidel");
printf("\nk");
/*************************/
for(i=1;i<=mm;i++)
{
printf("\tx%d",i);
}
/*************************/
/*************************/
for(i=1;i<=mm;i++)
{
printf("\tx%d",i);
}
/*************************/
printf("\n%d",k);
for(i=1;i<=mm;i++)
{
printf("\t%.2lf",ma3[i][1]);
}

do
{
       
/*Agregado metodo sor*/
      if(k>0)
     {
for(i=1;i<=mm;i++)
{
     ma3[i][1]=(1-w)*ma3old[i][1]+w*ma3[i][1];                                
}
     }
/****************/
/****************/
if(k>0)
{                             
for(i=1;i<=mm;i++)
{
     ma3e[i][1]=ma3old[i][1];
     ma3ee[i][1]=ma3[i][1];                                
}
}                 
/****************/

/*Imprimir x(k)*/ 
      if(k>0)
     {                         
printf("\n%d",k);

for(i=1;i<=mm;i++)
{
printf("\t%.4lf",ma3[i][1]);                                
}
     }
/****************/ 

/****************/                           
for(i=1;i<=mm;i++)
{                 sum0=0;
                  sumn=0;
     for(j=i+1;j<=mm;j++)
     {
     sum0=sum0-ma[i][j]*ma3[j][1];              
     }
     for(j=1;j<=i-1;j++)
     {
     sumn=sumn-ma[i][j]*ma3[j][1];
     }
     maux3[i][1]=(ma2[i][1]+sum0+sumn)/ma[i][i];
     /*Sustituir maux3=ma3*/
     ma3old[i][1]=ma3[i][1];
     ma3[i][1]=maux3[i][1];                                
     /****************/     
}  

/*Imprimir x(k)*/                          
for(i=1;i<=mm;i++)
{
printf("\t%.2lf",ma3[i][1]);                                
}
/****************/ 

/*Determinar error 1*/
if(k>0)
{
sumaux3=0;
for(i=1;i<=mm;i++)
{
sumaux3=sumaux3+ma3ee[i][1]*ma3ee[i][1];
}
sumaux3=sqrt(sumaux3); 

suma3=0;
for(i=1;i<=mm;i++)
{
suma3=suma3+ma3e[i][1]*ma3e[i][1];
}
suma3=sqrt(suma3);

er1=fabs(sumaux3-suma3);
}
/************************/

/*Determinar error 2*/
if(k>0)
{
for(i=1;i<=mm;i++)
{
res[i]=ma3ee[i][1]-ma3e[i][1];
res[i]=fabs(res[i]);
}

for(i=2;i<=mm;i++)
{
                  if(res[i]>res[i-1])
                  {
max=res[i];
                  }
}
er2=max;
}
/************************/
if(k>0)
{
printf("\ter1=%.3lf",er1); 
printf(" er2=%.3lf",er2);
}
if(k==0)
{
er1=10;
er2=10;
}
k++;
}while(k<=iter&&er1>tol&&er2>tol2);

printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);

}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}
