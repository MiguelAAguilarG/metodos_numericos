/*Miguel Angel Aguilar Garcia*/
/*Metodos numericos*/
/*Fecha de entrega: Jueves 31 de Julio de 2014*/
/*Factorizacion QR*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

int main()
{
    
int z=0,i=1,j=1,n,m,r=0,e=0,t=0,q,x=0,nn=0,mm=0,ii=0,jj=0,kk=0,mm2=0,x2=0,k=0,t2=0,nn3=0,mm3=0,r3=0,e3=0,x3=0,t3=0,iter=0;
char op,a,c,d[40],d2[40],cc,cc2,d3[40],cc3; 
double sum=0,amold=0,amnew=0,aux=0,auxb=0,auxa[100],auxm[100][100],mi[100][100],minew[100][100],manew[100][100],var=0;
double ma[100][100],xold[100][100],xnew[100][100];
double tol=0,er1=0,er2=0,max=0,res[100],sumaux3=0,suma3=0,tol2=0;
double v[100][100],mmaux[100][100],maux[100][100],mad[100][100],mat[100][100],xoldt[100][100];
double maold[100][100],maoldkt[100][100],maoldi[100][100],u[100][100],maq[100][100],maqt[100][100],vq[100][100],uni=0,uni2=0;
double maux1=0,maux2=0,mauxc3=0,maux3[100][100],maux4[100][100],maux5[100][100];
FILE *f1,*f2,*f3;

do
{
      do
      {
      q=0;
      system("cls");
      fclose(f1);
      printf("Factorizacion QR\n");
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
/*Insertar tolerancia e iteraciones*/
               do
               {
               r=0; 
               system("cls");              
               printf("Inserte numero maximo de iteraciones n= ");
               scanf("%d",&iter);
               fflush(stdin);       
               
               if(iter<0)
               {
                      r=1;
                      printf("\nERROR. \"n\" no es valida n<0");
                      printf("\n");
                      system("pause");
               }
               
               }while(r==1);
               
/*Factorizacion QR***********/

/*Igualar maold=ma*/
for(ii=1;ii<=mm;ii++)
{
    for(jj=1;jj<=nn;jj++)
    {
         maold[ii][jj]=ma[ii][jj];                                
    }
}
/****************/ 

/****************/ 
z=1;
do
{
/****************/ 


    for(k=1;k<=mm;k++)
    {
    /***********************************************************/
    
    /****************/
    for(kk=1;kk<=mm;kk++)
    {
     for(ii=1;ii<=nn;ii++)
     {
      maux4[kk][ii]=0; 
     }         
    } 
    /****************/
    
    for(i=1;i<=k-1;i++)/*Ciclo sumatoria*/
    { 
        
        /*sustitucion 'maold' a 'maoldi'*/
        for(ii=1;ii<=mm;ii++)
        {
             maoldi[ii][1]=vq[ii][i];           
        }
        /*********************/
        
        /*Producto de 'maold' por 'maoldi'*/
           auxb=0;                 
              for(kk=1;kk<=nn;kk++)
              {
              auxa[kk]=maold[kk][k]*maoldi[kk][1];          
              }
              for(kk=1;kk<=nn;kk++)
              {            
              auxb=auxa[kk]+auxb;         
              } 
           maux1=auxb;                               
        /****************/
        
        /*Producto de 'maoldi' por 'maoldi'*/
           auxb=0;                 
              for(kk=1;kk<=nn;kk++)
              {
              auxa[kk]=maoldi[kk][1]*maoldi[kk][1];          
              }
              for(kk=1;kk<=nn;kk++)
              {            
              auxb=auxa[kk]+auxb;         
              } 
           maux2=auxb;                               
        /****************/
        
        /*Division 'maux1' entre 'maux2'*/            
              mauxc3=maux1/maux2;                                
        /****************/
        
        /*Producto de 'maux3' por 'maoldi'*/                 
              for(kk=1;kk<=nn;kk++)
              {
              maux3[kk][1]=mauxc3*maoldi[kk][1];          
              }               
        /****************/           
      
        /*suma 'maux4' mas 'maux3'*/            
              for(kk=1;kk<=nn;kk++)
              {
              maux4[kk][1]=maux4[kk][1]+maux3[kk][1];          
              }                        
        /****************/
    }
    
    /*Resta*/
    for(ii=1;ii<=nn;ii++)
    {
    u[ii][k]=maold[ii][k]-maux4[ii][1];
    }
    /****************/
    
        /***********************************************************/
    /*Norma 2 de 'u'*/
       auxb=0;                 
          for(kk=1;kk<=nn;kk++)
          {
          auxa[kk]=u[kk][k]*u[kk][k];          
          }
          for(kk=1;kk<=nn;kk++)
          {            
          auxb=auxa[kk]+auxb;         
          } 
       uni=sqrt(auxb);                         
    /****************/
    
    /*Formar 'q'*/
    for(ii=1;ii<=nn;ii++)
    {
    vq[ii][k]=u[ii][k]/uni;
    }
    /****************/
    }
    /***********************************************************/
    
    

    for(k=1;k<=mm;k++)
    {
                      
    /*Formar 'maq'*/
    for(ii=1;ii<=nn;ii++)
    {
    maq[ii][k]=vq[ii][k];
    }
    /****************/
    
    }
    /***********************************************************/  


    /*transpuesta de 'maqt'*/
    for(ii=1;ii<=mm;ii++)
    {
        for(jj=1;jj<=nn;jj++)
        {
         maqt[jj][ii]=maq[ii][jj]; 
        }          
    }
    /*********************/ 
    
/*Multiplicacion de'maqt' por 'maold'*/
for(ii=1;ii<=mm;ii++)
{
   for(jj=1;jj<=nn;jj++)
   {
   auxb=0;                 
      for(kk=1;kk<=nn;kk++)
      {
      auxa[kk]=maqt[ii][kk]*maold[kk][jj];          
      }
      for(kk=1;kk<=nn;kk++)
      {            
      auxb=auxa[kk]+auxb;         
      } 
   maux5[ii][jj]=auxb;                
   }
}
/*********************/

/*Multiplicacion de'maux5' por 'maq'*/
for(ii=1;ii<=mm;ii++)
{
   for(jj=1;jj<=nn;jj++)
   {
   auxb=0;                 
      for(kk=1;kk<=nn;kk++)
      {
      auxa[kk]=maux5[ii][kk]*maq[kk][jj];          
      }
      for(kk=1;kk<=nn;kk++)
      {            
      auxb=auxa[kk]+auxb;         
      } 
   manew[ii][jj]=auxb;                
   }
}
/*********************/

/*Determinar error*/
    /*Resta de las diagonales de 'maold' menos 'manew*/
    sum=0;
    for(ii=1;ii<=mm;ii++)
    {
        v[i][1]=maold[ii][ii]-manew[ii][ii];
        v[i][1]=v[i][1]*v[i][1];
        sum=sum+v[i][1];
    }
    /****************/ 
er1=sqrt(sum);
/****************/ 


/*Igualar 'maold'='manew'*/
for(ii=1;ii<=mm;ii++)
{
    for(jj=1;jj<=nn;jj++)
    {
         maold[ii][jj]=manew[ii][jj];                                
    }
}
/****************/ 
                        
z++;
}while(z<=iter);

/****************/ 
system("cls");        
printf("El resultado de aplicarle 'factorizacion QR' a la matriz 'A' da como resultado:\n\n");

for(ii=1;ii<=mm;ii++)
{
    for(jj=1;jj<=nn;jj++)
    {
    printf("%lf ",manew[ii][jj]);                                
    }
printf("\n");
}
/****************/ 

printf("\n\nDesea repetir (S/N): ");
scanf("%c",&op);
fflush(stdin);

}
while(op=='s'||op=='S');

printf("\n\n");
system("pause");
}

