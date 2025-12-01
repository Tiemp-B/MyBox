#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void func1(){
    int X, K;
    cin >>X >>K;
    unordered_map<int, long long int> left, right;

    for(int i=0, temp; i<X; i++){
        cin >>temp;
        left[temp]++;
    }

    // cout <<"left size: "<< left.size()<<endl;
    for(int i=0, temp; i<X; i++){
        cin >>temp;
        right[temp]++;
    }
    // cout <<"right size: "<< right.size()<<endl;

    long long int ans = 0;
    for(auto color: left){
        if(right.find(color.first) == right.end()){
            ans += X * left[color.first];
        }else{
            ans += (X-right[color.first]) * left[color.first];
        }
    }

    cout << ans;
}

void func2(){
    int X, K;
    cin >> X >>K;

    vector<long long int> left(K+1,0);
    vector<long long int> right(K+1,0);
    
    for(int i=0, temp; i<X; i++){
        cin >>temp;
        left[temp]++;
    }
    for(int i=0, temp; i<X; i++){
        cin >>temp;
        right[temp]++;
    }
    
    long long int ans = 0;
    for(int i=1; i<=K;i++){
        if(left[i]>0){
            ans += (X-right[i])*left[i];
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    func2();
    

    return 0;
}