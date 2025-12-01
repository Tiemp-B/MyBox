#include <iostream>

using namespace std;

int main(){
    int ans[6] = {1,1,2,2,2,8};
    for(int i=0,temp; i<6; i++){
        cin >>temp;
        cout << ans[i]-temp<<" ";
    }


    return 0;
}