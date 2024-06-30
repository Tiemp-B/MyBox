#include <iostream>
#include <vector>
using namespace std;

bool *sw;
int N;

void prnt(){
	for(int i=1; i<= N ;i++){
		if(sw[i]) cout<< 1;
		else cout<< 0;
		if(i%20 == 0) cout <<endl;
		else cout<<" ";
	}
}

int main(){
	cin >> N;
	sw = new bool[N+1]();
	
	for(int i = 0, temp; i<N; i++){
		cin >>temp;
		if(temp ==1) sw[i+1]= true; 
	}
	int N2;
	
	cin >>N2;
	int G, D;
	for(int i=0; i<N2;++i){
		cin >>G >>D;
		int Dp = D;
		if(G == 1){
			while(Dp<=N){
				sw[Dp] = !sw[Dp];
				Dp += D;
			}
		}
		else {
			vector<int> index;
			index.push_back(D);
			int s=D, e=D;
			while(true){
				--s; ++e;
				if(s<1 || e>N) break;
				if(sw[s] != sw[e]) break;
				index.push_back(s);
				index.push_back(e);
			}
			for(int i=0 ;i<index.size();i++) {
				sw[index[i]] = !sw[index[i]];
			}
		}
		//prnt(); cout<<endl;
	}
	
	prnt();
	
	
	return 0;
}
