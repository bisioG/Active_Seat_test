% script to compare input signal control real and simulated (MPC)

clear all;
clc;

%% path settings

real_data_path = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\vigrade_offline_test\Real_data';
sim_data_path = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\vigrade_offline_test\MATMPC_data';
main_path = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\vigrade_offline_test';

%% plot settings
legend_size=12; %LEGEND SIZE SETTINGS
title_size=19;  %TITLE SIZE SETTINGS

%% scale factor settings in order to compare the waveform

scale_factor=2500;

%% load data

cd(real_data_path)
load chassis_accelerations.mat
sim_type_real = sim_type;
cd(sim_data_path)
load lateral_control.mat
sim_type_sim1 = sim_type;
load longitudinal_control.mat
sim_type_sim2 = sim_type;

if strcmp(sim_type_real, sim_type_sim1)&& strcmp(sim_type_real, sim_type_sim2)

    real_lateral = chassis_accelerations.lateral;
    real_longitudinal = chassis_accelerations.longitudinal;
    real_vertical = chassis_accelerations.vertical;

    sim_lateral = lateral_control;
    sim_longitudinal = longitudinal_control;
else
    error('different sim_type, prepare the data correctly!!');
end

%% plots

% compare lateral

figure;        
plot(tt,real_lateral,'b','Linewidth',1);
hold on; grid on;
plot(tt,sim_lateral(1:end-1)/scale_factor,'r--','Linewidth',1);
lgd = legend('Real input control','Simulation (MPC) input control');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[Pa] [m/s]^2');
title(['Compare AS lateral input control, Simulation: ',sim_type],'FontSize',title_size,'Interpreter', 'none')

% compare longitudinal

figure;        
plot(tt,real_longitudinal,'b','Linewidth',1);
hold on; grid on;
plot(tt,sim_longitudinal(1:end-1)/scale_factor,'r--','Linewidth',1);
lgd = legend('Real input control','Simulation (MPC) input control');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[Pa] [m/s]^2');
title(['Compare AS longitudinal input control, Simulation: ',sim_type],'FontSize',title_size,'Interpreter', 'none')

