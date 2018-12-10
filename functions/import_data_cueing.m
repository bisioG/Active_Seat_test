function [ pos_lin pos_ang vel_lin vel_ang acc_lin acc_ang AS_data full_data] = import_data_cueing( test_name, file_name )

% import file csv active seat

% R_xpy_rpy = [ 1 -1 -1 1 -1 -1]; 
% R = [R_xpy_rpy R_xpy_rpy R_xpy_rpy 1 1/3.6 1 1 1 1];


mainfolder = pwd;
cd([mainfolder,'\data\', test_name]);
%import_data = bsxfun(@times,dlmread([file_name,'.csv'],',',0,0),R);

if strcmp(file_name,'test_chicane')
    
import_data = dlmread([file_name,'.csv'],';',0,0);

sdata = resreader('Acc_DLC_Dec.csv');

else
import_data = dlmread([file_name,'.csv'],',',0,0);



%% linear position extraction
pos_lin = import_data(:,1:3);

%% angular position extraction
pos_ang = import_data(:,4:6);

%% linear velocity extraction
vel_lin = import_data(:,7:9);

%% angular velocity extraction
vel_ang = import_data(:,10:12);

%% linear acceleration extraction
acc_lin = import_data(:,13:15);

%% angular acceleration extraction
acc_ang = import_data(:,16:18);

%% AS_data  extraction
AS_data = import_data(:,21:24);

%% compressed data (avoid zeros)

full_data = [ pos_lin pos_ang vel_lin vel_ang acc_lin acc_ang AS_data];

end
%% return to main folder

save([test_name,'_cueing'],'pos_lin','pos_ang','vel_lin','vel_ang','acc_lin','acc_ang','AS_data','full_data')
cd(mainfolder);

end

