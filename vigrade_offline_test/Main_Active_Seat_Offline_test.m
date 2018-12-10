% SCRIPT TO SIMULATE CONTROL VALVES 
% real_data = acc control
% matmpc = pressure control
% salva i workspace elaborati nei percorsi definiti


%% 
%clear all;
% close all;
clc;

%% SETTINGS PART

% path settings
matmpc_data_path = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\vigrade_offline_test\MATMPC_data';
real_data_path = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\vigrade_offline_test\Real_data';

test_type = 0; 
%0 if AS real data / 1 if AS simulation MATMPC data

%SCALE FACTOR (SIMULATION MATLAB)
scale_factor = 10^5; % bar conversion

%plot settings
legend_size=12; %LEGEND SIZE SETTINGS
title_size=19;  %TITLE SIZE SETTINGS

%%
% params VIgrade simulink model
filter_pars.fcx = 4;    %cutoff frequency acceleration x
filter_pars.fcy = 0.7;    %cutoff frequency acceleration y
filter_pars.fcz = 5;    %cutoff frequency acceleration z
filter_pars.Ts = 0.005; %sampling time

%%

cd(real_data_path)
load chassis_accelerations;
cd('..')


if test_type == 0
    
    lateral_control_signal = timeseries(chassis_accelerations.lateral,tt);
    longitudinal_control_signal = timeseries(chassis_accelerations.longitudinal,tt);
    vertical_control_signal = timeseries(chassis_accelerations.vertical,tt);
    
    sim Active_seat_04_OFFLINE
    clc;
    
    
elseif test_type == 1
    
    cd(matmpc_data_path)
    load longitudinal_control;
    load lateral_control;
    
    lateral_control_signal = timeseries(lateral_control(1:end)/scale_factor,tt);
    longitudinal_control_signal = timeseries(longitudinal_control(1:end)/scale_factor,tt);    
    vertical_control_signal = timeseries(chassis_accelerations.vertical,tt); %tengo lo stesso segnale (no modello verticale)
    
    sim Active_seat_04_OFFLINE_vMPC
    clc;
else
    error('wrong test type set!!');
end





%% plot lateral signal


figure;
plot(lateral_out.time,lateral_out.signals.values(:,1),'b','Linewidth',1);
hold on;
plot(lateral_out.time,lateral_out.signals.values(:,2),'r','Linewidth',1);
plot(lateral_out.time,lateral_out.signals.values(:,3),'g','Linewidth',1);
plot(lateral_out.time,lateral_out.signals.values(:,4),'m','Linewidth',1);
plot(lateral_out.time,lateral_out.signals.values(:,5),'k--','Linewidth',1);
lgd = legend('Valve 1(bottom left)', 'Valve 6(bottom right)','Valve 2(top left)','Valve 5(top right)','lateral input control');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[Bar]');
title('Lateral valves signals','FontSize',title_size)

%% plot longitudinal signal

figure;
plot(lateral_out.time,rear_out.signals.values(:,1),'b','Linewidth',1);
hold on;
plot(lateral_out.time,rear_out.signals.values(:,2),'r','Linewidth',1);
plot(lateral_out.time,rear_out.signals.values(:,3),'k--','Linewidth',1);
plot(lateral_out.time,rear_out.signals.values(:,4),'g--','Linewidth',1);
lgd = legend('Valve 4(rear right)', 'Valve 3(rear left)','lateral input control','longitudinal input control');
lgd.FontSize= legend_size;
xlabel('time [s]'); ylabel('[Bar]');
title('Longitudinal valves signals','FontSize',title_size)


%% SAVE DATA TO COMPARE

if test_type ==0
    cd(real_data_path)
    save('real_out_valves','rear_out','lateral_out','sim_type')
else
    cd(matmpc_data_path )
    save('sim_out_valves','rear_out','lateral_out','sim_type')
end
