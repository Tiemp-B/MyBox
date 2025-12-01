#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_set<string> st;
int N, M;


void init(){
    cin >>N >>M;
    string s;
    for(int i=0; i<N;++i){
        cin >>s;
        st.insert(s);
    }
}

void calc(){
    string str;
    for(int i=0; i<M;++i){
        cin >>str;
        str+=",";
        string word="";
        int stt=0, comma=0;
        while(stt<str.size()){
            comma = str.find(',', stt);
            word = str.substr(stt, comma-stt);
            if(st.find(word)!=st.end()) {
                st.erase(word);
            }
            stt = comma+1;
        }
        cout << st.size()<<"\n";    
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr)->sync_with_stdio(false);
    init();
    calc();
    return 0;
}
