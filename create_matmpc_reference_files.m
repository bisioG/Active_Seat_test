%% file to creat rif_pressione.mat and rif_params.mat to be used in MATMPC

clear all;
clc;

%% ***** SETTING PATHS

%path of \function_gen_ref_hp (Reference_generation)
addpath(genpath('C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\Reference_generation\gen_rif\gen_rif_with_HP_filter\function_gen_ref_hp'));

%path MATMPC/examples

path_examples = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\MATMPC\examples';

%path main MATMPC

path_main_matmpc = 'C:\Users\giulio\Desktop\UNIVERSITA\TESI\active seat\MATMPC';

%% ****** test name setting

test_name = 'test_file_v5_lat';

%% ***** load data cueing
mainfolder = pwd;
cd([mainfolder,'\data\', test_name]);
load_ws = [test_name,'_cueing.mat'];
%load_ws2= [test_name,'_input_simulation.mat'];
load(load_ws)
%load(load_ws2)

% acc data

ax = resample(AS_data(:,1),4,5)'; %simulation acc on x
ay = resample(AS_data(:,2),4,5)'; %simulation acc on y

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

%% ***** create the pressure reference

% ODE nonLin

% parametri modello pressorio gli stessi con cui creo il modello mpc


cd (path_examples);
run Pressure_model_params_nonLin
cd(mainfolder);

A = 0.016; %area di contatto
tspan = tt;

y0 = [0;0;0;0]; % cond iniziali

ode_function = @(t,y) odefun_nonlin_hpfilter(t,y,tspan,ay,m,k1,k2,c1,c2,sigma_0,vs,alpha,MM,ax,g,Fs,Fc,tau_hp,A);
[t,y] = ode45(ode_function, tspan, y0); %  (funzione da integrare, intervallo di integrazione, cond iniziali)

%calcolo le uscite al modello pressorio NON_LINEARE
[ F_el_nonLin,F_att,damping_nonLin,ay_corpo_nonLin,pos_nonLin,vel_nonLin,zm,elastic_effect,damping_effect,Output_NL,ypf_NL,yp_NL]= make_ref_nonLin_HP(Ts,Tf,ay,m,k1,k2,c1,c2,sigma_0,tau_hp,A,y);


%% ODE nonLin_WOfriction

% parametri modello pressorio sono gli stessi del caso non-lineare

y0 = [0;0;0]; % cond iniziali

ode_function = @(t,y) odefun_nonlin_WOfriction_hpfilter(t,y,tspan,ay,m,k1,k2,c1,c2,tau_hp,A);
[t,y] = ode45(ode_function, tspan, y0); %  (funzione da integrare, intervallo di integrazione, cond iniziali)

%calcolo le uscite al modello pressorio WOfriction
[F_el_nonLin_WOfriction,damping_nonLin_WOfriction,ay_corpo_nonLin_WOfriction,pos_nonLin_WOfriction,vel_nonLin_WOfriction,Output_NL_WOfriction,ypf_NL_WOfriction,yp_NL_WOfriction ]  = make_ref_nonLin_WOfriction_HP(Ts,Tf,ay,m,k1,k2,c1,c2,tau_hp,A,y);


%% ODE Lin

% parametri LIN modello pressorio gli stessi con cui creo il modello mpc

current_path =pwd;
cd (path_examples);
run Pressure_model_params_Lin
cd(current_path);


y0 = [0;0;0]; % cond iniziali

ode_function = @(t,y) odefun_lin_hpfilter(t,y,tspan,ay,m,k2,c2,tau_hp,A);
[t,y] = ode45(ode_function, tspan, y0); %  (funzione da integrare, intervallo di integrazione, cond iniziali)

%calcolo le uscite al modello pressorio LINEARE
[F_pres_Lin,damping_Lin,ay_corpo_Lin,pos_Lin,vel_Lin,Output_L,ypf_L,yp_L] = make_ref_Lin_HP(Ts,Tf,ay,m,k2,c2,tau_hp,A,y); 


%****************** GRAFICI

%% plots delle componenti del segnale pressorio NON filtrato (studio del segnale pressorio)
 param_name = 'test AS';
 run plot_rif_pres_laterale

%% plots confronto tra segnali filtrati e non filtrati

run plot_rif_pres_laterale_HP


%% ************** CREAZIONE DEL FILE DI RIFERIMENTO DI PRESSIONE PER MATMPC

rif_pressione = ypf_NL; % il riferimento scelto (rif_pressione variabile utilizzata in matmpc)

% tipi:
% 
% ypf_NL
% ypf_NL_WOfriction
% ypf_L

cd([pwd,'\data\',test_name,'\rif_pressure_saved']);
label = test_name;
save('rif_pressione','rif_pressione','test_name');
cd('..');

%% *************** CREAZIONE DEI PARAMETRI DI ACCX,ACCY,ROLL DA UTILIZZARE NEL MODELLO MPC
    
rif_accX = acc_lin(:,1)';
rif_accY = acc_lin(:,2)';
rif_roll = pos_ang(:,1)';
    
% to have 25s of simulation

if N_sim*Ts < Tf
    
    N_zeros = (Tf/Ts)-N_sim;
    rif_accX = [rif_accX,zeros(1,N_zeros)];
    rif_accY = [rif_accY,zeros(1,N_zeros)];
    rif_roll = [rif_roll,zeros(1,N_zeros)];
    
end
if N_sim*Ts > Tf
    
    N_end = Tf/Ts;
    rif_accX = rif_accX(1,1:N_end);
    rif_accY = rif_accY(1,1:N_end);
    rif_roll = rif_roll(1,1:N_end);
end

    save([pwd,'\rif_params_saved\rif_params'],'rif_accX','rif_accY','rif_roll');
    
%% *************** COPIARE IN MATMPC/DATA RIFERIMENTO DI PRESSIONE CREATO E PARAMETRI

cd([pwd,'\rif_params_saved']);
copyfile('rif_params.mat',[path_main_matmpc,'\data\ActiveSeat_onlyP'])
cd('..\.')
cd([pwd,'\rif_pressure_saved']);
copyfile('rif_pressione.mat',[path_main_matmpc,'\data\ActiveSeat_onlyP'])
cd(path_main_matmpc);


%% *************** FINE CREAZIONE RIFERIMENTO DI PRESSIONE E PARAMETRI ON-LINE

clc;
display('                           ');
display('Pressure Reference created.');
display('                           ');
display('On-line params file created.');
display('                           ');
display('You can simulate with the current reference files.');


