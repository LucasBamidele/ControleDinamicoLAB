pkg load control
A =  2833503.99512;
B =  3359.82171445;
C =  18360.920369;

deltam = -0.3657
deltap = 0.3286

%A =  -193486006.196;
%B =  -227139.064677;
%C =  -1268758.61431;


%A=  20792.397543
%B=  25.2695060487
%C= 147.029170433

A=  31221.9101993
B=  36.0565536834
C=  215.379515402
pause()
x = csvread('Quad2_Tr.csv');

outp = x(2:end,2);
inpt = x(2:end,4);
time = x(2:end,1);
for a =1:length(inpt)
	if(inpt(a) < deltam)
		inpt(a) = inpt(a) + deltam;
	elseif (inpt(a) < deltap)
		inpt(a) = 0;
	else
		inpt(a) = inpt(a) + deltap;
	end
end
%exit()
s = [1 B C];
roots(s);
%pause()
%read csv and get real stuff




myG = tf(1*[A],[1 B C])
%k = step(myG);
k = lsim(myG, inpt, time);
plot(k);
hold on;
plot(outp, 'r');
print -djpg image.jpg;

%pause()