clear all;
close all;

%%% Leitura do arquivo de dados
load dados;

t = dados(1,:)';
w = dados(2,:)';
theta = dados(3,:)';
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
plot(t,theta,'b'); grid on;
xlabel('t [s]'); ylabel('\theta [deg]');
title('(a) Ângulo do eixo');
subplot(212); 
plot(t,w,'b'); grid on;
xlabel('t [s]'); ylabel('\omega [deg/s]');
title('(b) Velocidade rotacional do eixo');