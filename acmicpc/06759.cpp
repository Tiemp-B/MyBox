#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<pair<int, int>> child;

void init(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N; cin>>N; // N ~400,000
    parent.resize(N+1);
    child.resize(N+1);

    for(int i=1, a, b; i<N;++i){
        cin >>a >>b;
        // 트리 생성
    }
    
}

int main(){
    

    return 0;
}