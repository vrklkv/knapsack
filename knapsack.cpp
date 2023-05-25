#include <fstream>
#include <iostream>

using namespace std;

int main(){ 
    long n,K,i,j; 
    cin >> n >> K;

    ofstream input;
	input.open("input.dzn");
    input<<"K = "<< K <<";"<<endl;

    long data[n][2];
    for(i=0;i<n;i++)
        cin >> data[i][0] >> data[i][1];

    input<<"data_v = [";
	for(i=0; i<n;i++){
		input<<data[i][0]<<",";
	}
	input << "];"<< endl;
    input<<"data_w = [";
	for(i=0; i<n;i++){
		input<<data[i][1]<<",";
	}
	input << "];"<< endl;

	input<<"n = "<< n <<";"<<endl;
	input.close();
	system("minizinc --solver Gecode solver.mzn input.dzn --time-limit 420000");
	return 0;
}