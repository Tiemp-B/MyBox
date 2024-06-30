#include <iostream>
#include <queue>

using namespace std;

struct city{
	int price;
	int customer;
	
	bool operator<(const city next)const{
		float rate = (float)customer/(float)price;
		float rateNext = (float)next.customer/(float)next.price;
		
		if(rate == rateNext) return price > next.price;
		
		return rate < rateNext;
	}
};

int C, N;

priority_queue<city> cities;

int main(){
	cin >>C >>N;
	
	for(int i=0, C, P; i<N; i++){
		cin >> P >> C;
		cities.push(city{P, C});
	}
	int ans =0;
	int check = N;
	while(!cities.empty() && C>0&&check!=0){
		city now = cities.top(); cities.pop();
		if(now.customer > C){
			now.customer = C;
			cities.push(now);
			check--;
			continue;
		}
		check = N;
		int cnt = C/now.customer;
		C -= now.customer * cnt;
		ans += cnt * now.price;
	}
	if(C > 0){
		city now = cities.top();
		ans += now.price;
	}
	
	cout <<ans;
	
	return 0;
}
