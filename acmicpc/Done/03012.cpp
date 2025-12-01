#include <iostream>
#include <vector>
#define ll long long
#define mxN 201

using namespace std;

int N;
string str;

ll cnt = 1;

vector<vector<ll>> mem1(mxN, vector<ll>(mxN, -1)); // i가 열고, j가 닫는 형식만
vector<vector<ll>> mem2(mxN, vector<ll>(mxN, -1)); // i~j 가능한 모든 가짓수

void init(){
    // cin.tie(nullptr)->sync_with_stdio(false);
    cin >>N >>str;
    for(int i=0; i<N;++i){
        mem1[i][i] = 0;
        mem2[i][i] = 0;
    }
}

// 여는 괄호 체크
inline int opener(int idx){
    switch(str[idx]){
        case '?':
            return 0;
            break;
        case '(':
            return 1;
            break;
        case '{':
            return 2;
            break;
        case '[':
            return 3;
            break;
        default:
            return -1;
    }
}

// 닫힌 괄호 체크
inline int closer(int idx){
    switch(str[idx]){
        case '?':
            return 0;
            break;
        case ')':
            return 1;
            break;
        case '}':
            return 2;
            break;
        case ']':
            return 3;
            break;
        default:
            return -1;
    }
}

ll f(int i, int j); // i가 연 것을 j가 닫는 경우의 수
ll g(int i, int j); // i부터 j까지 가능한 경우의 수

/*
아이디어
구간 (s, e)가 옳은 경우일 때 str[s]는 무조건 여는 괄호이며
s에서 시작한 괄호가 닫히는 e가 되는 지점은 (s, s+1), (s, s+3) ... (s, e) 이다
각 경우에서의 가짓수는 (첫번째 구간의 경우의 수)*(뒤에서 나올 수 있는 모든 경우의 수)
즉, f(s, t) * g(t+1, e) 의 총합이다.

f(s, e) = (str[s]와 str[e]의 가능한 조합 수) x (s+1 에서 g-1까지 가능한 조합의 수)
        = (3, 1, 0) x g(s+1, g-1)

g(s, e) = f(s, e) + sum( f(s, t) x g(t+1, e) )

*/


// st가 열고, ed가 닫는 가짓 수 -> mem1 저장
ll f(int st, int ed){
    // 기록된 항목 반환
    if(mem1[st][ed]!=-1) return mem1[st][ed]; 
    
    // 여는 괄호, 닫는 괄호 확인
    int op=opener(st), cl=closer(ed);
    
    if(op<0 || cl<0) // str[st]가 닫는 괄호이거나 str[ed]가 여는 괄호인 경우
        return mem1[st][ed]=0;
    else if(op==0 && cl==0) // 여는 괄호: ? 닫는 괄호 : ?
        mem1[st][ed] = 3;
    else if(op!=cl && op!=0 &&cl!=0) // str[st]의 타입과 str[ed]의 타입이 다른 경우
        return mem1[st][ed]=0;
    else // 한가지 경우로 정해진 경우 : ?A), (A?, (A)
        mem1[st][ed] = 1;
    
    // 2글자 길이면 그대로 반환
    if(st+1 == ed) return mem1[st][ed];

    // 
    mem1[st][ed] *= g(st+1, ed-1);
    mem1[st][ed] %= 1000000;
    return mem1[st][ed];
}

// st~ed 에서 가능한 모든 문자열의 수 -> mem2 저장
ll g(int st, int ed){
    if(mem2[st][ed] != -1) return mem2[st][ed];

    int op=opener(st), cl=closer(ed);
    if(op<0||cl<0) return mem2[st][ed]=0; // str[st]가 닫거나 str[ed]가 여는 경우
    
    ll ss= f(st, ed);
    for(int t=st+1; t<ed-1; t+=2){
        ss += f(st, t) * g(t+1, ed);
    }
    return mem2[st][ed] = ss%1000000;
}

ll b (int st, int ed){
    int op = opener(st), cl = closer(ed);
    ll base=0;
    if(op<0 || cl<0) return 0;
    if(op==0 && cl==0) base = 3;
    else if(op==0 || cl==0 || op == cl) base = 1;
    else return 0;

    return base;
}

ll recur(int st, int ed){
    if(st >= ed) return mem1[st][ed]=1;

    mem1[st][ed]=0;
    for(int j=ed; j>st; j-=2){
        ll base = b(st, j);
        ll o1 = mem1[st+1][j-1]==-1? recur(st+1, j-1) : mem1[st+1][j-1];
        ll o2 = mem1[j+1][ed]==-1 ? recur(j+1, ed) : mem1[j+1][ed];
        ll o = base * o1 * o2;
        // ll o = b(st, j) * recur(st+1, j-1) * recur(j+1, ed); 
        mem1[st][ed] += o;
    }

    // printf("(%d, %d)\n",st, ed);
    // for(int j=ed; j>st; j-=2){
    //     int base = b(st, j);
    //     int o1 = mem1[st+1][j-1]==-1? recur(st+1, j-1) : mem1[st+1][j-1];
    //     int o2 = mem1[j+1][ed]==-1 ? recur(j+1, ed) : mem1[j+1][ed];
    //     int o = base * o1 * o2;
    //     printf("  b(%d, %d) : %d, f(%d, %d) : %d, f(%d, %d) : %d, => %d\n", st, j, base, st+1, j-1, o1, j+1, ed, o2, o);
    //     // ll o = b(st, j) * recur(st+1, j-1) * recur(j+1, ed); 
    //     // mem1[st][ed] += o;
    // }

    return mem1[st][ed] %=100000;
}


int main(){
    init();

    // if(N%2!=0) cout <<0;
    // else cout << g(0, N-1)%100000;
    
    ll ans = g(0, N-1);
    if(ans>=100000){
        printf("%05lld", ans%100000);
    }else
        cout << ans%100000;

    return 0;
}