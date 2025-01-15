#include <iostream>

using namespace std;

string A, B;



int main(){
	cin >> A >>B;

	string a, r, xr, na, nb;

	for(int i=0; i<A.size();i++){
		a.push_back((A[i]-'0')&(B[i]-'0')?'1':'0');
		r.push_back((A[i]-'0')|(B[i]-'0')?'1':'0');
		xr.push_back((A[i]-'0')^(B[i]-'0')? '1':'0');
		na.push_back(!(A[i]-'0')?'1':'0');
		nb.push_back(!(B[i]-'0')?'1':'0');
	}

	cout << a <<endl << r <<endl<< xr << endl<< na<<endl<<nb;

	return 0;

}
