clc;
%{
    d- demand
    p- price per unit
    q- quantity in each order
    h- holding cost
    o- price per order
 %}
syms d p q h o

%our cost function
cost = d*p+h*q/2+d*o/q;

%differentiation of cost
diffcost = diff(cost,q);

%calculating EOQ function
q = solve(diffcost==0,q);

q = matlabFunction(q(1,1));
cost = matlabFunction(cost);

%Given problems
%{
    1- demand
    2- price per unit
    3- holding cost
    4- price per order
 %}
x1 = [200,50,25,25];
x2 = [350,45,19,21];
x3 = [400,68,36,25];

%calculating EOQ
q1 = q(x1(1),x1(3),x1(4));
q2 = q(x2(1),x2(3),x2(4));
q3 = q(x3(1),x3(3),x3(4));

%converting solutions into integers
q1 = floor(q1);
q2 = floor(q2);
q3 = floor(q3);

%calculating final cost
c1 = cost(x1(1),x1(2),x1(3),x1(4),q1);
c2 = cost(x2(1),x2(2),x2(3),x2(4),q2);
c3 = cost(x3(1),x3(2),x3(3),x3(4),q3);

disp('Solution')
fprintf(1, '\n');

%For Product A
disp(['Total Cost for Product A: ' num2str(c1)])
disp(['EOQ for Product A = ' num2str(q1)])
fprintf(1, '\n');

%For Product B
disp(['Total Cost for Product B: ' num2str(c2)])
disp(['EOQ for Product B = ' num2str(q2)])
fprintf(1, '\n');

%For Product C
disp(['Total Cost for Product C: ' num2str(c3)])
disp(['EOQ for Product C = ' num2str(q3)])

