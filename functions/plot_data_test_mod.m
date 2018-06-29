%% plot data of a single test 
clear all;
clc;
% ***** settings

test_name = 'test_file_v4_lat'; %folder and test name

Ts = 1/250; %sampling time

legend_size=12; %LEGEND SIZE SETTINGS
title_size=19;  %TITLE SIZE SETTINGS


%% ***** load data cueing
mainfolder = pwd;
cd([mainfolder,'\data\', test_name]);
load_ws = [test_name,'_cueing.mat'];
load_ws2= [test_name,'_input_simulation.mat'];
load(load_ws)
load(load_ws2)

%% ***** plot data
N_sim = length(full_data);

tt=Ts:Ts:N_sim*Ts;


%% ***** linear positions

figure;
plot(tt,pos_lin(:,1),'b','Linewidth',1);
hold on;
plot(tt,pos_lin(:,2),'r','Linewidth',1);
plot(tt,pos_lin(:,3),'g','Linewidth',1);
lgd = legend('Position X', 'Position Y','Position Z');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[m]');
title('Linear Position','FontSize',title_size)


%% ***** angular position

figure;
plot(tt,pos_ang(:,1),'b','Linewidth',1);
hold on;
plot(tt,pos_ang(:,2),'r','Linewidth',1);
plot(tt,pos_ang(:,3),'g','Linewidth',1);
lgd = legend('roll','pitch','yaw');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[rad]');
title('Angular Position','FontSize',title_size)

%% ***** angular velocities

figure;
plot(tt,vel_ang(:,1),'b','Linewidth',1);
hold on;
plot(tt,vel_ang(:,2),'r','Linewidth',1);
plot(tt,vel_ang(:,3),'g','Linewidth',1);
lgd = legend('roll','pitch','yaw');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[rad/s]');
title('Angular Velocities','FontSize',title_size)

%% ***** linear velocities

figure;
plot(tt,vel_lin(:,1),'b','Linewidth',1);
hold on;
plot(tt,vel_lin(:,2),'r','Linewidth',1);
plot(tt,vel_lin(:,3),'g','Linewidth',1);
lgd = legend('Velocity X','Velocity Y','Velocity Z');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[m/s]');
title('Linear Velocities','FontSize',title_size)

%% ***** linear accelerations

figure;
plot(tt,acc_lin(:,1),'b','Linewidth',1);
hold on;
plot(tt,acc_lin(:,2),'r','Linewidth',1);
plot(tt,acc_lin(:,3),'g','Linewidth',1);
lgd = legend('Acceleration X','Acceleration Y','Acceleration Z');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[(m/s)^2]');
title('Linear Accelerations','FontSize',title_size)

%% ***** angular accelerations

figure;
plot(tt,acc_ang(:,1),'b','Linewidth',1);
hold on;
plot(tt,acc_ang(:,2),'r','Linewidth',1);
plot(tt,acc_ang(:,3),'g','Linewidth',1);
lgd = legend('Acceleration roll','Acceleration pitch','Acceleration yaw');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[(rad/s)^2]');
title('Angular Accelerations','FontSize',title_size)


%% ***** AS_outputs

figure;
plot(tt,AS_data(:,1),'b','Linewidth',1);
hold on;
plot(tt,AS_data(:,2),'r','Linewidth',1);
plot(tt,AS_data(:,3),'g','Linewidth',1);
lgd = legend('AS1','AS2','AS3');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[m]');
title('Active Seat input','FontSize',title_size)

%% ***** AS_input_0_data_real

N_sim2 = length(SIM_acc_lin_small);
Ts2 = 1/1000;

tt2=Ts2:Ts2:N_sim2*Ts2;

figure;
plot(tt2,SIM_acc_lin_small(:,2),'b','Linewidth',1);
hold on;
plot(tt2,-SIM_acc_lin_small(:,1),'r','Linewidth',1);
plot(tt2,SIM_acc_lin_small(:,3),'g','Linewidth',1);
lgd = legend('AS1','AS2','AS3');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[m]');
title('Active Seat input','FontSize',title_size)


%% ***** linear accelerations compare two files

figure;
plot(tt,AS_data(:,2),'b','Linewidth',1);
hold on;
down_SIM_acc_lin_x = downsample(-SIM_acc_lin_small(:,1),4).*9.81;
plot(tt,down_SIM_acc_lin_x,'r--','Linewidth',1);
lgd = legend('AS_1','AS_1 0.data');
set(lgd, 'Interpreter', 'none')
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[(m/s)^2]');
title('Active seat input compare','FontSize',title_size,'Interpreter', 'none')


