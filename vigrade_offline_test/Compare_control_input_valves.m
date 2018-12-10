% script to compare input VALVES signal control USING state of art and MPC INPUTS

clear all;
clc;

%% path settings

real_data_path = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\vigrade_offline_test\Real_data';
sim_data_path = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\vigrade_offline_test\MATMPC_data';
main_path = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\vigrade_offline_test';

%% plot settings
legend_size=12; %LEGEND SIZE SETTINGS
title_size=19;  %TITLE SIZE SETTINGS


%% load data

cd(real_data_path)
load real_out_valves.mat
sim_type_real = sim_type;
cd(sim_data_path)
load sim_out_valves.mat
sim_type_sim = sim_type;


if strcmp(sim_type_real, sim_type_sim)
    
    sim_valve_1 = lateral_out.signals.values(:,1);
    sim_valve_2 = lateral_out.signals.values(:,3);
    sim_valve_3 = rear_out.signals.values(:,2);
    sim_valve_4 = rear_out.signals.values(:,1);
    sim_valve_5 = lateral_out.signals.values(:,4);
    sim_valve_6 = lateral_out.signals.values(:,2);
%     sim_valve_7 =
%     sim_valve_8 =

    cd(real_data_path)
    load real_out_valves.mat
    
    real_valve_1 = lateral_out.signals.values(:,1);
    real_valve_2 = lateral_out.signals.values(:,3);
    real_valve_3 = rear_out.signals.values(:,2);
    real_valve_4 = rear_out.signals.values(:,1);
    real_valve_5 = lateral_out.signals.values(:,4);
    real_valve_6 = lateral_out.signals.values(:,2);
%     real_valve_7 =
%     real_valve_8 =

    time = lateral_out.time;
    
else
    error('different sim_type, prepare the data output correctly!!');
end

%% plots

% valve 1

figure;
plot(time,real_valve_1,'b','Linewidth',1);
hold on; grid on;
ylim([0 1.5]);
plot(time,sim_valve_1,'r','Linewidth',1);
lgd = legend('VI-Grade input valve','MPC input valve');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[Bar]');
title(['Compare [valve 1: lateral bottom left] input control, Simulation: ',sim_type],'FontSize',title_size,'Interpreter', 'none')

%% valve 2
figure;
plot(time,real_valve_2,'b','Linewidth',2);
hold on; grid on;
%ylim([0 1.5]);
plot(time,sim_valve_2,'r','Linewidth',2);
lgd = legend('VI-Grade input valve','UniPD-MPC input valve');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[Bar]');
%title(['Compare [valve 2: lateral top left] input control, Simulation: ',sim_type],'FontSize',title_size,'Interpreter', 'none')

%% valve 3
figure;
plot(time,real_valve_3,'b','Linewidth',1);
hold on; grid on;
ylim([0 1.5]);
plot(time,sim_valve_3,'r','Linewidth',1);
lgd = legend('VI-Grade input valve','MPC input valve');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[Bar]');
title(['Compare [valve 3: rear left] input control, Simulation: ',sim_type],'FontSize',title_size,'Interpreter', 'none')

%% valve 4
figure;
plot(time,real_valve_4,'b','Linewidth',1);
hold on; grid on;
ylim([0 1.5]);
plot(time,sim_valve_4,'r','Linewidth',1);
lgd = legend('VI-Grade input valve','MPC input valve');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[Bar]');
title(['Compare [valve 4: rear right] input control, Simulation: ',sim_type],'FontSize',title_size,'Interpreter', 'none')

%% valve 5
figure;
plot(time,real_valve_5,'b','Linewidth',2);
hold on; grid on;
ylim([0 1.5]);
plot(time,sim_valve_5,'r','Linewidth',2);
lgd = legend('VI-Grade input valve','UniPD-MPC input valve');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[Bar]');
%title(['Compare [valve 5: lateral top right] input control, Simulation: ',sim_type],'FontSize',title_size,'Interpreter', 'none')

%% valve 6
figure;
plot(time,real_valve_6,'b','Linewidth',1);
hold on; grid on;
ylim([0 1.5]);
plot(time,sim_valve_6,'r','Linewidth',1);
lgd = legend('VI-Grade input valve','MPC input valve');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[Atm]');
title(['Compare [valve 6: lateral bottom right] input control, Simulation: ',sim_type],'FontSize',title_size,'Interpreter', 'none')