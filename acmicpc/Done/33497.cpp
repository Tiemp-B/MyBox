#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main(){
    // cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;// N: 학생수, M: 일수
    cin >>N >>M;
    vector<int> A(M), B(M);
    vector<vector<char>> sched(N, vector<char>(M, '0'));
    bool err = false;
    int emp=0;
    for(int i=0; i<M;++i){
        cin >>A[i] >>B[i];
        if(A[i]+B[i] > N) err = true;
        emp += N-A[i]-B[i];
    }
    err |= emp<N; // 

    if(err){
        cout <<"NO";
        return 0;
    }
    int st = 0;
    cout <<"YES\n";
    for(int day=0; day<M;++day){
        int run = N-A[day]-B[day];
        int a = A[day];
        int b = B[day];
        for(int stu=0; stu<N;++stu){
            if(stu>=st&& run>0){
                sched[stu][day] = 'X';
                run--;
                st++;
            }else if(a>0){
                sched[stu][day] = '+';
                a--;
            }else if(b>0){
                sched[stu][day] = '-';
                b--;
            }else{
                sched[stu][day] = '+';
            }
        }
    }

    for(int s=0;s<N;++s){
        for(int d=0;d<M;++d){
            cout <<sched[s][d];
        }
        cout <<endl;
    }
    return 0;
}