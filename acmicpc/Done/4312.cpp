#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll dec18 = 100000000000000000;
vector<deque<ll>> box= {{1}, {3}, {9}, {27}};

int func(ull d){
    int ret = 0;

    while(d>0){
        ret++;
        d /= 10;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    while(68 > box.size()){
        auto prev = box.back();
        deque<ll> next;
        ll throwup = 0;
        for(int i = prev.size() - 1; i >= 0; i--){
            ll d = prev[i] * 3 + throwup;
            next.push_front(d % dec18);
            throwup = d / dec18;
        }
        if(throwup != 0)
            next.push_front(throwup);
        box.push_back(next);
    }

    while(true){
        ull inp;
        cin >> inp;
        // cout <<"inp: ";
        if(inp-- == 0)
            break;
        
        cout <<"{ ";
        int cnt = 0;
        bool num = false;

        while(inp > 0){
            if(inp & 1){
                if(num)
                    cout <<", ";
                num = true;
                
                for(long unsigned int i=0; i<box[cnt].size();i++){
                    if (i == 0){
                        cout << box[cnt][i];
                    }else{
                        int ctt = func(box[cnt][i]);
                        for(int t=0; t<17-ctt; t++){
                            cout << 0;
                        }
                        cout <<box[cnt][i];
                    }
                }
            }

            cnt++;
            inp = inp >> 1;
        }
        if(num)
            cout << " ";
        cout <<"}"<<endl;
    }

    return 0;
}

/* 디버깅 리스트
1. 수의 제한. 19자리 최대수는 ll이 아닌 ull로 표기해야 한다.
2. 3의 제곱수는 그보다 큰 수가 된다
3. 큰 수를 dq로 표현하는 과정 중 올림수 적용에 에러가 존재
4. 출력 과정중 0 출력 위치의 오류

*/