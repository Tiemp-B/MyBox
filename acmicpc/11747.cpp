#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>

using namespace std;


string addOne(string str){
    string ret(str.size()+1, '0');
    int carry = 0;
    


    return ret;
};

int main(){
    int N;
    cin >> N;
    set<string> st;
    vector<string> box;
    for(int i=0; i<N; i++){
        char temp;
        cin >> temp;
        cout << temp << endl;
        string t = "";
        
        int cnt = box.size();

        for(int i=0; i<cnt ;i++){
            t = "";
            t += box[i];
            t += temp;
            box.push_back(t);
        }

        t = "";
        t += temp;
        box.push_back(t);
    }
    int ans = -1;

    for(string e : box){
        st.insert(e);
    }
    int mem[1001]= {};
    int mp[1001];
    set<string> mem2[1001];
    mp[0] = 1;
    for(int i=1;i<=N; i++){
        mp[i] = mp[i-1]*10;
    }
    mp[0] = 0;
    for(auto e : st){
        mem[e.size()]++;
        mem2[e.size()].insert(e);
    }
    int flag;
    for(int i=1; i<=N; i++){
        if(mem[i] != mp[i]-mp[i-1]){
            flag = i;
            break;
        }
    }
    int tt = mp[flag-1];
    string ans = "";

    for(int temp = mp[flag-1];temp>0; temp/=10){
        ans += (temp%10)+'0';
    }
    for(auto e : mem2[flag]){
        cout << e << endl;
    }
    return 0;
}