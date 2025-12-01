#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> mem(s1.size()+1, vector<int>(s2.size()+1));
    int ans = 0;
    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            if(s1[i] == s2[j]){
                mem[i+1][j+1] = (mem[i][j]+1);
                if(ans < mem[i+1][j+1])
                    ans = mem[i+1][j+1]; 
            }else{
                mem[i+1][j+1] = (mem[i][j+1] > mem[i+1][j])? mem[i][j+1] : mem[i+1][j];
            }
        }
    }


    cout << ans;

    return 0;
}