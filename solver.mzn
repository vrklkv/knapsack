int: n;
int: K;
array[1..n] of int: data_v; 
array[1..n] of int: data_w;
array[1..n] of var 0..1: x;

constraint sum(i in 1..n)(data_w[i]*x[i])<=K;
solve maximize sum(i in 1..n)(data_v[i]*x[i]);

output [show(sum(i in 1..n)(data_v[i]*x[i]*x[i])), "\n"];
output [show(x[i])++" "| i in 1..n];