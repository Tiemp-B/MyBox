#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> people;

int N, M;
int box[101][101];// i-1날 청소를 하였음 j날 청소를 할 예정

void fill(){
    int now = 0;
    int dirt = 0;
    for(int i=1; i < N+1; i++){
        for(int j=i+1;j < N+1 ; j++){
            box[i][j] += dirt * people[j-1];
            dirt += people[j-1];
        }
    }
}

vector<int> ans;
queue<int> as;

void calc(){
    calc();
}

int comb(int n, int m){ // n C m
    long long int ans = 1;
    for(int i=0; i<m; i++){
        ans *= (n-i)/(i+1);
    }

    return ans;
}

int main(){
    cin >>N >>M;

    for(int i=0, temp; i<N; i++){
        cin >>temp;
        people.push_back(temp);
    }
    fill();
    for(int i = 1; i<=M; i++) ans.push_back(i);

    int cnt = comb(100, 10); // 가짓수
    
    cout <<cnt;
    


    return 0;
}