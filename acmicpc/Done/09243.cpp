#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    string before, after;
    cin >> N >>before >>after;
    bool ans = true;
    for(int i=0; i<before.size(); i++){
        if (N %2 == 0){
            ans &= before[i] == after[i];
        }else{
            ans &= before[i] != after[i];
        }
    }
    if (ans)
        cout << "Deletion succeeded";
    else
        cout << "Deletion failed";

    return 0;
}