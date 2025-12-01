#include <iostream>
#include <map>
#include <vector>

using namespace std;

void method1(){ // 8ms
	int test_case;
	cin >> test_case;
	for(int T=1; T<=test_case; T++){
		int N;
		cin >>N;
		int total=0;
		map<int, vector<int>> mp;
		
		for(int n=1, temp; n<=N; n++){
			cin >>temp;
			total += temp;
			mp[temp].push_back(n);
		}

		auto last = prev(mp.end());

		if(last->second.size() != 1){
			cout << "no winner"<<endl;
		}
		else if (last->first * 2 > total ){
			cout << "majority winner " << last->second[0] <<endl;
		}
		else{
			cout << "minority winner " << last->second[0] <<endl;
		}

	}
}

void method2(){
	int test_case;
	cin >> test_case;
	for(int T=1, N; T<=test_case; T++){
		pair<int, int> winner = {0, 0};
		cin >>N;
		int total=0;

		for(int n=1, temp; n<=N; n++){
			cin >>temp;
			total += temp;
			
			if (winner.first < temp){
				winner.first = temp;
				winner.second = n;
			}else if (winner.first == temp){
				winner.second = 0;
			}
		}

		if(winner.second == 0){
			cout << "no winner"<<endl;
		}
		else if (winner.first + winner.first > total ){
			cout << "majority winner " << winner.second <<endl;
		}
		else{
			cout << "minority winner " << winner.second <<endl;
		}

	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	method2();

	return 0;
}
