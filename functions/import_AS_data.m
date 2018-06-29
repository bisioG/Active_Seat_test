function [ AS_acc_lin_full, AS_acc_lin_small ] = import_AS_data( test_name, N_sample)

% import file csv simulation VI

file_name_sim_acc = '0.data.AS.acc';

mainfolder = pwd;
cd([mainfolder,'\data\', test_name]);
import_data_acc = dlmread([file_name_sim_acc,'.csv'],';',0,0);


%% linear accelerations extraction
AS_acc_lin_full = import_data_acc(:,1:3);

%% delate extra samples (zeros)

AS_acc_lin_small = AS_acc_lin_full(1:N_sample,:);

%% save workspace variable
save([test_name,'_input_simulation'],'AS_acc_lin_full','AS_acc_lin_small');
cd(mainfolder);

end

