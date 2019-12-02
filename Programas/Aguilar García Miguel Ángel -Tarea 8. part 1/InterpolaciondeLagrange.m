%Miguel Angel Aguilar Garcia
%Metodos numericos
%Fecha de entrega: Martes 26 de Agosto de 2014
%Interpolacion de Lagrange
q=1;
while q==1
clear all;
clc;

disp('Interpolacion de Lagrange');
      fprintf('Para ingresar la tabla de valores x/y hacerlo por fichero como si fuera una\nmatriz\ndel lado izquierdo ''x'' y del lado derecho ''y''\n');
      fprintf('Desea:\n1. Hacer un fichero nuevo o abrir para modificar\n2. Abrir un fichero existente');
      fprintf('\n\n******NOTA IMPORTANTE:Cuando se acaben de poner todos los elementos de la matriz\nse debera anadir un enter\n(es decir,situar el cursor debajo del ultimo renglon)\nde lo contrario saldran errores,\nademas se debera poner un espacio finalizado un renglon,\nde lo contrario saldran errores');         
      q=input('\nElige una opcion: ');
      
switch q
               case 1
      fprintf('\n1. Hacer un fichero nuevo o abrir para modificar');  
      fprintf('\n\nNota: Para seguir con el proceso se debe guardar\nlas modificaciones que se hicieron en el blog de notas\ny cerrarlo');     
      d=input('\n\nIntroduce el nombre del fichero que desea crear o modificar (nombre.txt): ','s');
      fclose('all');
      f1=fopen(d,'r+');
      fclose(f1);
      system(d);
      f1=fopen(d,'r');
      [A,cont]=fscanf(f1,'%f');
      fclose(f1);
      
      cont1=1;
      cont2=1;
for i=1:cont
if(mod(i,2)==0)
yv(cont1)=A(i);
cont1=cont1+1;
end
if(mod(i,2)~=0)
xv(cont2)=A(i);
cont2=cont2+1;
end
end

for i=1:cont1-1
    fprintf('%.2f\t%.2f\n',xv(i),yv(i));  
end

      q=0;
               case 2
      fprintf('\n2. Abrir un fichero existente');       
      d=input('\nIntroduce el nombre del fichero que desea abir (nombre.txt): ','s');
      fclose('all');
      system(d);
      f1=fopen(d,'r');
      [A,cont]=fscanf(f1,'%f');
      fclose(f1);
      
      cont1=1;
      cont2=1;
      
for i=1:cont
if(mod(i,2)==0)
yv(cont1)=A(i);
cont1=cont1+1;
end
if(mod(i,2)~=0)
xv(cont2)=A(i);
cont2=cont2+1;
end
end

for i=1:cont1-1
    fprintf('%.2f\t%.2f\n',xv(i),yv(i));  
end
      q=0;
      
      
    otherwise
               a=0;
               fprintf('\n\nERROR.Opcion no valida\n\n');
               pause;
               q=1;
end

end

syms x;
n=cont1-1;
prod=1;
sum=0;
for i=1:n
    prod=1;
    for j=1:n
    
        if(i~=j)
        prod=prod*(x-xv(j))/(xv(i)-xv(j));
        end
    end
prod=prod*yv(i);
sum=sum+prod;
end

disp(' ');
disp('La funcion es: ');
disp(sum);

ezplot(sum,[1.5,2]);
hold on;
grid ON;

disp('1. Repetir programa');
    disp('o presiona cualquier otro numero para terminar');
    des=input('Selecciona la opción: ');
    
    if des==1
        InterpolaciondeLagrange;
    end