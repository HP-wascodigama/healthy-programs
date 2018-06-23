fc=100000;
fs=1000000;
f=1000;
m=0.5;
t=0:1/fs:((2/f)-(1/fs));
[x1]=en_m(y1,f,fs); subplot(321); plot(x1); title('env. det.,m=0.5');
[x2]=en_m(y2,f,fs); subplot(323); plot(x2); title('env. det.,m=1.0');
[x3]=en_m(y3,f,fs); subplot(325); plot(x3); title('env. det.,m=1.2');

[x1]=demod(y1,fc,fs,'amdsb-tc');
subplot(322); plot(x1); title('coherent det., m=0.5');
[x2]=demod(y1,fc,fs,'amdsb-tc');
subplot(324); plot(x1); title('coherent det., m=1.0');
[x3]=demod(y1,fc,fs,'amdsb-tc');
subplot(326); plot(x1); title('coherent det., m=1.2');
