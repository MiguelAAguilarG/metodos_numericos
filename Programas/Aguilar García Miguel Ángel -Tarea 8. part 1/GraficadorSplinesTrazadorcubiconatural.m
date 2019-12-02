%Miguel Angel Aguilar Garcia
%Metodos numericos
%Fecha de entrega: Martes 26 de Agosto de 2014
%Graficador Splines Trazador cubico natural     

clear all;
clc;

disp('Graficador Splines Trazador cubico natural');

      d=input('\nIntroduce el nombre del fichero que desea abir (nombre.txt): ','s');
      fclose('all');
      system(d);
      f1=fopen(d,'r');
      [A,cont]=fscanf(f1,'%f');
      fclose(f1);
      
cont1=1;
      
for i=1:6:cont-5
    
jo(cont1)=A(i);

xv(cont1)=A(i+1);

yv(cont1)=A(i+2);

b(cont1)=A(i+3);

c(cont1)=A(i+4);

de(cont1)=A(i+5);

cont1=cont1+1;
end

for i=1:cont1-1
    fprintf('%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n',jo(i),xv(i),yv(i),b(i),c(i),de(i));  
end

syms x;

for i=1:cont1-2
f(i)=yv(i) + b(i).*(x-xv(i)) + c(i).*((x-xv(i)).^2) + de(i).*((x-xv(i)).^3);
ezplot(f(i),[xv(i),xv(i+1)]);
hold on;
grid ON;
axis image;
end

disp('1. Repetir programa');
    disp('o presiona cualquier otro numero para terminar');
    des=input('Selecciona la opción: ');
    
    if des==1
        GraficadorSplinesTrazadorcubiconatural;
    end