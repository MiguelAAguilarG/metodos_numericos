/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Jueves 31 de Julio de 2014*/
/*Teorema de Gerschgorin*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

int main()
{
    
int i=1,j=1,n,m,r=0,e=0,t=0,q,x=0,nn=0,mm=0,k=0;
char op,a,c,cc,d[40]; 
double sum=0,auxb=0,auxa[100];
double ma[100][100];
double map[100][100],centro[100][100],radio[100][100],rango[100][100];
FILE *f1,*f2,*f3;

do
{
      do
      {
      q=0;
      system("cls");
      fclose(f1);
      printf("Teorema de Gerschgorin\n");
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

/*****************************************************************************************************************************/         

r=0;
if(nn!=mm)
{
printf("\n\nError.'A' no es una matriz cuadrada\n");
       r=1;
}
if(r==1)
{
       system("pause");
       exit(0);
}

/******************************/    

/*Teorema de Gerschgorin*/ 

/*Guardar centros 'c'*/
for(i=1;i<=mm;i++)
{
centro[i][1]=ma[i][i];
}
/********************/

/*Matriz positiva 'map'*/
   for(i=1;i<=mm;i++)
   {                
      for(j=1;j<=mm;j++)
      {
                        
      if(ma[i][j]<=0)
      {
      map[i][j]=ma[i][j]*(-1);
      }
      else
      {
      map[i][j]=ma[i][j];       
      }
      
      }              
   }
/********************/


/*Sumatoria de la fila para 'radio'*/
   for(i=1;i<=mm;i++)
   {
   auxb=0;                 
      for(j=1;j<=mm;j++)
      {
                        
      if(i!=j)
      {
      auxb=auxb+map[i][j];
      }
             
      }
   radio[i][1]=auxb;                
   }
/********************/

/*Determinar 'rango'*/
for(i=1;i<=mm;i++)
{
rango[i][1]=centro[i][1]-radio[i][1];
rango[i][2]=centro[i][1]+radio[i][1];
}
/********************/

/*Imprimir 'rango'*/ 
system("cls");        
printf("Aplicando el 'Teorema de Gerschgorin' a la matriz 'A'\npara determinar el rango de sus valores propios\nLos valores propios estan:\n\n");

    for(i=1;i<=mm;i++)
    {
    printf("Entre %lf y %lf para la fila %d\n",rango[i][1],rango[i][2],i);                                
    }
/********************/ 
/************************/              


printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);

}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}

