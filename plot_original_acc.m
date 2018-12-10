%% plot accelerazioni manovra originale

figure;
plot(tt,ay,'r','linewidth',2);
hold on;
grid on;
plot(tt,ax,'b','linewidth',2);
legend('lateral acceleration a_y','longitudinal acceleration a_x');
xlabel('time [s]')
ylabel('[(m/s)^2]')


%% plot accelerazione laterale originale e acc lat in piattaforma

figure;
plot(tt,ay,'r','linewidth',2);
hold on;
grid on
plot(tt,rif_accY,'b','linewidth',2);
legend('real car lateral acceleration','platform lateral acceleration');
xlabel('time [s]')
ylabel('[(m/s)^2]')
