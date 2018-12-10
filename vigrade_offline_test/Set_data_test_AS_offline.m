
%crea chassis_acceleration utilizzate dal controllo in acc (stato dell'arte)
%carica i segnali di controllo precedentemente elaborati facendo girare MATMPC----> serve la simulazione sia laterale che longitudinale
% in MATMPC/Simulation.mat alla fine salva i segnali di controllo elaborati: vigrade_offline_test\MATMPC_controls
%(il segnale di controllo verticale non considerato posto uguale nei due casi)

clear all;
%close all;
clc;

%% ***** SETTING PATHS

%local folder to save reference and online params

set_real_local = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\vigrade_offline_test\Real_data'; 
set_mpc_local = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\vigrade_offline_test\MATMPC_data';
real_data_path = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\data';
mpc_data_path = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\vigrade_offline_test\MATMPC_controls';

%% ****** TEST FILE NAME SETTINGS AND TYPE

sim_type = 'Calabogie_track' %'test_file_v6_lat'; %'test_file_v1_8_long'; [per i nomi vedi cartelle \MATMPC_controls]

%% set real data test

% ***** load data cueing

if strcmp(sim_type,'Calabogie_track')
        cd([real_data_path,'\', sim_type]);
        g=9.81;
        load ('ay.mat')
        load ('ax.mat')
        N_sim = 5000;
        ax = IN1_XY(1:N_sim);
        ay = IN1_YX(1:N_sim);
        az = IN1_XY(1:N_sim); %non ho l'info su z
else

        cd([real_data_path,'\', sim_type]);
        load_ws = [sim_type,'_cueing.mat'];
        load(load_ws)

        % acc data

        ax = (resample(AS_data(:,1),4,5)')./9.81; %simulation acc on x 
        ay = (resample(AS_data(:,2),4,5)')./9.81; %simulation acc on y 
        az = (resample(AS_data(:,3),4,5)')./9.81; %simulation acc on y 
        
end

Ts = 1/200; %sampling time
Tf = 25; %simulation fixed time
N_sim = length(ax); %sample
tt=Ts:Ts:Tf; %time (25s fixed simulation)

%% to have 25s of simulation

if N_sim*Ts < Tf
    
    N_zeros = (Tf/Ts)-N_sim;
    ax = [ax,zeros(1,N_zeros)];
    ay = [ay,zeros(1,N_zeros)];
    az = [az,zeros(1,N_zeros)];
    
end
if N_sim*Ts > Tf
    
    N_end = Tf/Ts;
    ax = ax(1,1:N_end);
    ay = ay(1,1:N_end);
    az = az(1,1:N_end);
    
end

chassis_accelerations.longitudinal = ax;
chassis_accelerations.lateral = ay;
chassis_accelerations.vertical = az;

cd(set_real_local)
save('chassis_accelerations', 'chassis_accelerations','sim_type','tt');


%% simulation MPC

cd([mpc_data_path,'\',sim_type]);
copyfile('lateral_control.mat',set_mpc_local);
copyfile('longitudinal_control.mat',set_mpc_local);


%% display

disp (['simulation type set:', sim_type]);
disp ('you can compare AS input  + simulate and compare outuput valves signal');
