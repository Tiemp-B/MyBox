#include <iostream>

using namespace std;

void func(){

	string str;
	getline(str, cin);

	int ans =0;


	
	switch(ans){
		case 0:
			cout << "Not a pangram"<<endl;
			break;
		case 1:
			cout << "Pangram!" <<endl;
			break;
		case 2:
			cout << "Double pangram!!"<<endl;
			break;
		case 3:
			cout << "Triple pangram!!!" <<endl;
			break;
	}
}


int main(){
	string str;
	getline(str, cin);

	

	return 0;
}
