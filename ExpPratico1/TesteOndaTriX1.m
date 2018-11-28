entrada = quad(4,:);
saida = quad(2,:)/180;
hold on 
plot(entrada)
plot(saida)
grid on 
ylim([-2.2 2.2])
hold off 

y1 = [entrada(1529) entrada(5716)]