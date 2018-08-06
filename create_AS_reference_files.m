%% file to creat rif_pressione.mat and rif_params.mat to be used in MATMPC

clear all;
close all;
clc;

%% ***** SETTING PATHS

%path of \function_gen_ref_hp (Reference_generation)
addpath(genpath('C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Reference_Generation\gen_rif\gen_rif_LAT_LONG\functions'));

%path main MATMPC

path_main_matmpc = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\MATMPC';

%local folder to save reference and online params

save_local = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test'; 

%% ****** TEST FILE NAME SETTINGS AND TYPE

sim_type = 'test_file_v4_lat';
type = 2; % 1= lateral 2=longitudinal pressure model

param_name = 'AS'; %plot title name

%% ************** SET THE REFERENCE TYPE

rif_type = 'Linear longitudinal HP';

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

ax = (resample(AS_data(:,1),4,5)'); %simulation acc on x 
ay = (resample(AS_data(:,2),4,5)'); %simulation acc on y 

Ts = 1/200; %sampling time
Tf = 25; %simulation fixed time
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

