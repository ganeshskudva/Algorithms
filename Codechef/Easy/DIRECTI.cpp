#include <string>
#include <iostream>
using namespace std;

int T, N;
string turn[100], road[100];

int main(){
	cin>>T;
	while(T--){
		string line;
		cin>>N;
		// This call to getline consumes the newline after N
		getline(cin, line);
		for(int i=0; i<N; i++){
			// The first token is the turn, and the remainder
			// of the line is the road.
			cin>>turn[i];
			getline(cin, road[i]);
		}
		for(int i=0; i<N; i++){
			// The first line uses "Begin".  Other lines
			// take a turn from the input (in reverse order)
			// and change its direction.
			if(i==0)
				cout<<"Begin";
			else if(turn[N-i]=="Left")
				cout<<"Right";
			else
				cout<<"Left";
			// The i-th road in the output is the (N-1-i)th
			// road from the input.
			cout<<road[N-1-i]<<endl;
		}
		cout<<endl;
	}
	return 0;
}
