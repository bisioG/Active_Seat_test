%% file to create chassis_acceleration workspace with real data to use it with vigrade simulink model

clear all;
close all;
clc;

%% ***** SETTING PATHS

%local folder to save reference and online params

save_local = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\vigrade_offline_test\Real_data'; 
data_path = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\data';

%% ****** TEST FILE NAME SETTINGS AND TYPE

sim_type = 'test_file_v4_lat';

%% ***** load data cueing

cd([data_path,'\', sim_type]);
load_ws = [sim_type,'_cueing.mat'];
load(load_ws)

% acc data

ax = (resample(AS_data(:,1),4,5)'); %simulation acc on x 
ay = (resample(AS_data(:,2),4,5)'); %simulation acc on y 
az = (resample(AS_data(:,3),4,5)'); %simulation acc on y 

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

cd(save_local)
save('chassis_accelerations', 'chassis_accelerations','sim_type','tt');
