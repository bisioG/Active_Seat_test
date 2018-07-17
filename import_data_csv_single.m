clear all;
clc;

%%***** SETTING PATH FUNCTIONS
addpath(genpath('C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Active_Seat_test\functions'));

%% file name settings

test_name = 'test_file_v6_lat'; %folder and test name
file_name = 'lat_acc6_v18_R54_results_250Hz'; %file name to be import

% import file csv active seat/ cuening signals

[ pos_lin pos_ang vel_lin vel_ang acc_lin acc_ang AS_data full_data] = import_data_cueing(test_name, file_name );

%% simulation virtual data import

N_sample = length(full_data)*4; %numer of sample to import (based on full_data length) 250 hz to 1000 hz

[ SIM_acc_lin_full, SIM_acc_lin_small ] = import_AS_data( test_name, N_sample);


