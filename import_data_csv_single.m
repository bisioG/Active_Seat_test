% crea crea i workspace _cueing _simulation contenuti nella cartella \data
% estrandevo i dati dai file .csv

clear all;
clc;

%%***** SETTING PATH FUNCTIONS
addpath(genpath('C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\functions'));

%% file name settings

test_name = 'test_chicane'; %folder and test name
file_name = 'test_chicane'; %file name to be import

% import cuening signals

[ pos_lin pos_ang vel_lin vel_ang acc_lin acc_ang AS_data full_data] = import_data_cueing(test_name, file_name );

%% simulation virtual data import

N_sample = length(full_data)*4; %numer of sample to import (based on full_data length) 250 hz to 1000 hz

if strcmp(file_name,'test_chicane')
else
[ SIM_acc_lin_full, SIM_acc_lin_small ] = import_AS_data( test_name, N_sample);
end


