clear all;
close all;

%%% Leitura do arquivo de dados
load dados;

t = dados(1,:)';
dx_dt = dados(2,:)';
x = dados(3,:)';
u = dados(4,:)';
v = dados(5,:)';

%%% Curvas básicas
figure;
plot(t,v,'b',t,u,'r--');
ax = axis; axis([ax(1) ax(2) -2.5 2.5]);
xlabel('t [s]'); ylabel('u,v [V])');
legend({'Entrada (u)' 'Entrada com proteção (v)'});

figure;
subplot(211); 
plot(t,x,'b'); grid on;
xlabel('t [s]'); ylabel('x [mm]');
title('(a) Posição do carro');
subplot(212); 
plot(t,dx_dt,'b'); grid on;
xlabel('t [s]'); ylabel('dx/dt [mm/s]');
title('(b) Velocidade linear do carro');