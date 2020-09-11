clc;

syms d p q h o

%our objective function
objective = @(x) x(1)^2+2*x(2)^2+3*x(3)^2+50*x(1)+25*x(2)-4500;

% initial guess
x0 = [60,60,60];

%linear inequality constraints
%{
    x1>=60 ==>  -x1<=-60
    x1+x2>=120 ==> -x1-x2<=-120
%}
A=[-1,0,0;-1,-1,0];
B=[-60;-120];

%linear equality constraints
% x1+x2+x3=180
Aeq=[1,1,1];
Beq=180;

% optimize with fmincon
%[X] = fmincon(FUN,X0,A,B,Aeq,Beq)
x = fmincon(objective,x0,A,B,Aeq,Beq);
disp(x);

%converting solutions into integers
x(1)=ceil(x(1));
x(2)=floor(x(2));
x(3)=floor(x(3));

% show final objective
disp(['Final Objective: ' num2str(objective(x))])
fprintf(1, '\n');

% print solution
disp('Solution')
disp(['x1 = ' num2str(x(1))])
disp(['x2 = ' num2str(x(2))])
disp(['x3 = ' num2str(x(3))])
