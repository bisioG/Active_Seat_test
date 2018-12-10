%% file to creat rif_pressione.mat and rif_params.mat to be used in MATMPC

clear all;
% close all;
clc;

%% ***** SETTING PATHS

%path of \function_gen_ref_hp (Reference_generation)
addpath(genpath('C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Reference_Generation\gen_rif\gen_rif_LAT_LONG\functions'));

%path main MATMPC

path_main_matmpc = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\MATMPC';

%local folder to save reference and online params

save_local = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test'; 

%% ****** TEST FILE NAME SETTINGS AND TYPE

sim_type = 'test_file_v6_lat'%'test_file_v5_lat';
type = 1; % 1= lateral 2=longitudinal pressure model

platform_action=0; % 0= no platform action, 1= with platform action

param_name = 'AS'; %plot title name

%% ************** SET THE REFERENCE TYPE

rif_type = 'Non linear lateral HP';

% TYPE:

% Non linear lateral
% Non linear lateral HP
% Linear lateral
% Linear lateral HP
% Non linear lateral WOfriction
% Non linear lateral WOfriction HP
% Linear longitudinal
% Linear longitudinal HP


%% ***** load data cueing
mainfolder = pwd;
cd([mainfolder,'\data\', sim_type]);
load_ws = [sim_type,'_cueing.mat'];
%load_ws2= [test_name,'_input_simulation.mat'];
load(load_ws)
%load(load_ws2)

% acc data

%dowsample at 200 Hz (campionato a 1000 hz)
ax_nf = (resample(AS_data(:,1),4,5)'); %simulation acc on x 
ay_nf= (resample(AS_data(:,2),4,5)'); %simulation acc on y 

Ts = 1/200; %sampling time

% filtraggio a 30 hz (pulire il segnale)
ax= filter([0 1-exp(-Ts/0.03)],[1 -exp(-Ts/0.03)],ax_nf);
ay= filter([0 1-exp(-Ts/0.03)],[1 -exp(-Ts/0.03)],ay_nf);

Tf = 65 %25; %simulation fixed time
N_sim = length(ax); %sample
tt=Ts:Ts:Tf; %time (25s fixed simulation)

%% to have 25s of simulation

if N_sim*Ts < Tf
    
    N_zeros = (Tf/Ts)-N_sim;
    ax = [ax,zeros(1,N_zeros)];
    ay = [ay,zeros(1,N_zeros)];
    
end
if N_sim*Ts > Tf
    
    N_end = Tf/Ts;
    ax = ax(1,1:N_end);
    ay = ay(1,1:N_end);
    
end

%% create the references

run create_matmpc_reference_files.m
run set_ref_type.m
run plot_all.m
run save_and_move_ref.m


