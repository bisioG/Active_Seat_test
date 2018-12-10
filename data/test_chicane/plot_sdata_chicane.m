 

%%
clc;
clear all;
load('sdata_chicane')

%%
figure
plot(sdata.time_TIME, sdata.cueing_acceleration_lateral,'r')
hold on
plot(sdata.time_TIME, sdata.in_chassis_acceleration_lateral.*9.81,'b')
plot(sdata.time_TIME, sdata.actual_acc_y,'g')
plot(sdata.time_TIME, IN1_YX.*9.81,'m')

