// #include <iostream>
// #include <string>
// #include <vector>
// #include <cstdio>

// using namespace std;


// string ladd(string str1, string str2){
//     vector<char> ans;
//     int throwup=0;
//     for(int i1=str1.size()-1, i2=str2.size()-1; i1>=0||i2>=0 ; --i1, --i2){
//         int e1=0, e2=0;
//         if(i1>=0) e1=str1[i1]-'0';
//         if(i2>=0) e2=str2[i2]-'0';
//         int a = e1 + e2 + throwup;
//         throwup = 0;
//         if(a>9){
//             a%=10;
//             throwup = 1;
//         }
//         ans.push_back(a+'0');
//     }
//     if(throwup>0)
//         ans.push_back(throwup+'0');
//     string ret(ans.rbegin(), ans.rend());
//     return ret;
// }

// int bigger(string str1, string str2){
//     bool flag = str1.size() < str2.size();
//     bool same = true;
//     if(str1.size()==str2.size()){
//         for(int i=0; i<str1.size();++i){
//             int e1= str1[i]-'0';
//             int e2= str2[i]-'0';
//             if(e1<e2){
//                 flag = true;
//                 same = false;
//                 break;
//             }else if(e1>e2){
//                 same = false;
//                 break;
//             }
//         }
//     }else{
//         same = false;
//     }


//     if(same) {
//         return 0;
//     }else if(flag){ //str2 is big
//         return 1;
//     }else{  // str1 is big
//         return -1;
//     }

// }

// void lsub(string str1, string str2){
//     vector<char> ans;
//     int taker=0;
//     for(int i1=str1.size()-1, i2=str2.size()-1; i1>=0||i2>=0 ; --i1, --i2){
//         int e1=0, e2=0;
//         if(i1>=0) e1=str1[i1]-'0';
//         if(i2>=0) e2=str2[i2]-'0';
        
//         int a = e1-taker - e2;
//         taker = 0;
//         if(a<0){
//             a+=10;
//             taker = 1;
//         }
//         ans.push_back(a+'0');
//     }
//     bool front = true;
//     for(int i =ans.size()-1; i>=0; --i){
//         if(front&&ans[i]=='0') continue;
//         else if(front && ans[i]!='0')
//             front = false;
//         cout <<ans[i];
//     }
//     cout <<"\n";
// }

// string lmul(string str1, string str2){
//     vector<char> ans;
//     vector<vector<char>> dat;
//     int dec = 0;
//     for(int i1=str1.size()-1; i1>=0 ;--i1){
//         vector<char> base;
//         for(int d=0; d<dec;++d)
//             base.push_back('0');
//         dec++;
//         long long throwup=0;
//         for(int i2=str2.size()-1; i2>=0; --i2){
//             long long e1=0, e2=0;
//             e1=str1[i1]-'0';
//             e2=str2[i2]-'0';
//             long long a = e1*e2+throwup;
//             throwup=0;
//             if(a>9){
//                 throwup= a/10;
//                 a%=10;
//             }
//             base.push_back(a+'0');
//         }
//         while(throwup>0){
//             base.push_back(throwup%10 +'0');
//             throwup /=10;
//         }
//         dat.push_back(base);
//     }
//     string ret="0";
//     for(int r=0; r<dat.size();++r){
//         string temp(dat[r].rbegin(), dat[r].rend());
//         ret = ladd(ret, temp);
//     }
//     return ret;
// }


// int main(){
//     string A, B;
//     bool a=false, b=false;
    
//     cin >>A >>B;

//     if(A[0]=='-'){
//         a = true;
//         A = A.substr(1);
//     }
//     if(B[0]=='-'){
//         b=true;
//         B=B.substr(1);
//     }
//     int check = bigger(A, B); // 1: B가 큼, 0: 동일, -1: A가 큼
//     // A+B
//     if(a!=b){// 부호가 다르다
//         if(check==0) cout <<"0\n";
//         else if(a){// A만 음수 
//             if(check==1)
//                 lsub(B, A);
//             else{
//                 cout <<"-";
//                 lsub(A, B);
//             }
//         }else if(b){// B만 음수
//             if(check==1){
//                 cout <<"-";
//                 lsub(B, A);
//             }else{
//                 lsub(A, B);
//             }
//         }
//     }else{ //부호가 동일
//         if(a) cout << "-";
//         cout<<ladd(A, B)<<endl;
//     }
//     // A-B
//     if(a!=b){// 부호가 다름 -A-B, A+B
//         if(a)// A가 음수, B는 양수
//             cout <<"-";
//         cout << ladd(A, B)<<endl;
//     }else{ //부호가 같음 B-A or A-B
//         if(check == 0)
//             cout<<"0\n";
//         else if(a){//둘 다 음수 : B-A
//             if(check==1)
//                 lsub(B, A);
//             else{
//                 cout <<"-";
//                 lsub(A, B);
//             }
//         }else {// 둘 다 양수
//             if(check==1){//B가 큼
//                 cout <<"-";
//                 lsub(B, A);
//             }else if(check==0){
//                 cout <<"0\n";
//             }else{
//                 lsub(A, B);
//             }
//         }
//     }
//     // A*B
//     if(a!=b) cout <<"-";
//     string mul_ans = lmul(A, B);
//     cout <<mul_ans<<endl;

//     return 0;
// }


/*---------------------*/
#include <iostream>
using namespace std;

string A, B, p, m, M;
bool a, b;
int Alen, Blen;

int check(){
    int n = A.size()-B.size();
    if(n!=0) return n;

    for(int i=0; i<A.size();++i){
        if(A[i]==B[i]) continue;
        if(A[i]>B[i]) return 1;
        return -1;
    }
    return 0;
}

int main(){// string 의 cout은 \0나오기 전까지만
    cin >> A >>B;
    a = A[0]=='-', b = B[0]=='-';
    if(a) A=A.substr(1);
    if(b) B=B.substr(1);
    Alen=A.size(), Blen=B.size();
    int i, j, k, state;
    state = check();
    
    //A+B, A-B
    int mxlen = (Alen>Blen?Alen:Blen)+2;
    p.resize(mxlen,0);
    m.resize(mxlen,0);
    k = mxlen-1;
    for(i=A.size()-1, j=B.size()-1; i>=0||j>=0 ; --i,--j,--k){
        if(i<0){
            p[k]+=B[j];
            m[k]+=B[j];
        }else if(j<0){
            p[k]+=A[i];
            m[k]+=A[i];
        }else if(a^b){
            m[k] += A[i]+B[j]-'0';
            if(state>0)
                p[k] += A[i]-B[j]+'0';
            else
                p[k] += B[j]-A[i]+'0';
        }else{
            p[k] += A[i]+B[j]-'0';
            if(state>0)
                m[k] += A[i]-B[j]+'0';
            else
                m[k] += B[j]-A[i]+'0';
        }

        if(p[k]>'9'){
            p[k-1]++;
            p[k] -=10;
        }else if(p[k]<'0'){
            p[k-1]--;
            p[k] +=10;
        }

        if(m[k]>'9'){
            m[k-1]++;
            m[k] -=10;
        }else if(m[k]<'0'){
            m[k-1]--;
            m[k] += 10;
        }
    }
    p[k]+='0';
    m[k]+='0';
    // 맨 앞의 문자 위치 찾기
    for(i=0;i<p.size()&&(p[i]==0||p[i]=='0');++i);
    for(j=0;j<m.size()&&(m[j]==0||m[j]=='0');++j);
    //(큰A가음수) (큰 B가 음수) (둘 다 음수)
    if((state>0 && a)||(state<0 && b) ||(a && b))
        p[--i]='-';
    if(i==p.size()) i--; // 0 출력을 위해;
    cout<< p.substr(i)<<"\n";
    // (큰A가 음수) (큰 B가 양수)
    if((state>0 && a) || (state<0 && (!b)))
        m[--j]='-';
    if(j==m.size()) j--;
    cout<< m.substr(j)<<"\n";

    // 곱셈 시작
    M.resize(Alen+Blen+4, 0);
    for(i=Alen-1;i>=0;--i){
        for(j=Blen-1, k=M.size()-(Alen-i); j>=0 ;--j, --k){
            M[k] += (A[i]-'0')*(B[j]-'0');
            M[k-1] += M[k]/10;
            M[k] %= 10;
        }
    }

    for(auto &e : M) e+='0';
    for(i=0; i<M.size()&&(M[i]=='0') ; ++i);

    if(a^b)
        M[--i]='-';
    
    cout <<M.substr(i);
    return 0;
}



// #include<bits/stdc++.h>

// char a[1010],b[1010],p[1010],m[1010],s,M[1000010];// s: 동일함
// int C=1000009;
// int main(){
//     scanf("%s%s",a,b);
//     // A: a의 길이, B: b의 길이, x: a의 부호, y: b의 부호(true면 음수), i, j, k;
//     int A=strlen(a)-1, B=strlen(b)-1, x= (a[0]=='-'), y=(b[0]=='-'), i, j, k=1008;
//     if(A-x==B-y) // A의 길이, B의 길이가 동일한가
//         s=strcmp(a+x,b+y); // 동일여부 확인 동일시 0이 반환, 사전순으로 A가 작으면 음수, 크면 양수 
//     else 
//         s= A-x>B-y?1:-1; // 길이가 긴 항목은? s=1: a가 김, -1: b가 김

//     for(i=A,j=B;  i>=x||j>=y;  i--,j--,k--) {
//         // 부호 전까지의 숫자를 끝에서부터 가져옴.
//         if(i<x){// i가 접근불가영역인 경우
//             p[k]+=b[j]; // p[k]에 b[j]문자 더함
//             m[k]+=b[j]; // m[k]에 b[j]문자 더함
//         }
//         else if(j<y){// i가 접근 가능이며 j가 접근 불가
//             p[k]+=a[i]; // p[k]에 a[i]문자 더함
//             m[k]+=a[i]; // m[k]에 a[i]문자 더함
//         }
//         else if(x^y){// i에 접근 가능, j에 접근 가능, a,b는 부호가 다름
//             m[k] += a[i]+b[j]-'0'; //m[k] 에 a[i]+b[j]-'0'를 더한다.
//             if(s>0) // A의 절댓값이 더 큼
//                 p[k]+=a[i]-b[j]+'0'; // p[k]에 a[i]-b[j]+'0' 를 더함
//             else    // B의 절댓값이 더 큼
//                 p[k]+=b[j]-a[i]+'0'; //p[k]에 b[j]-a[i]+'0' 를 더함
//         }else{// i에 접근 가능, j에 접근 가능, a, b는 부호가 같음
//             p[k]+=a[i]+b[j]-'0'; // p[k]에 a[i]+b[j]-'0'를 더함;
//             if(s>0) // A의 절댓값이 클 때
//                 m[k]+=a[i]-b[j]+'0'; // m[k]에 a[i]-b[j]+'0'을 더함
//             else    // B의 절댓값이 클 때
//                 m[k]+=b[j]-a[i]+'0'; // m[k]에 b[j]-a[i]+'0'을 더함
//         }

//         if(p[k]>'9'){ // p[k]가 10보다 크다면?
//             p[k-1]++; // p[k-1]값을 1 증가 :    이걸 반영하기 위해 위에서 더해주는 연산을 함
//             p[k]-=10; // p[k] 보정
//         }
//         if(p[k]<'0'){ // p[k]가 0보다 작아지면?
//             p[k-1]--; // p[k-1]값 1 감소
//             p[k]+=10; // p[k] 보정
//         }
//         if(m[k]>'9'){ // m에 대해서도 같은 연산
//             m[k-1]++; 
//             m[k]-=10;
//         }
//         if(m[k]<'0'){
//             m[k-1]--;
//             m[k]+=10;
//         }
//     }
    
//     if(!s&&x^y)// 길이가 동일, 부호가 다름 : 결과가 0인 경우...?
//         i=9999;
//     else    // 그 외 
//         i=0;

//     int j2=0;
//     for(; i<1008&&(!p[i]||p[i]=='0') ;i++); // 앞자리가 0이 된 것을 건너 뛰는 작업
//     for(; j2<1008&&(!m[j2]||m[j2]=='0') ;j2++);

//     if(p[i]<'0') // 자릿수가 변하면 맨 앞자리가 변함 이를 반영하기 위한 p[i]
//         p[i]+='0'; 
//     if(m[j2]<'0')
//         m[j2]+='0';

//     if(i&&((s>0&&x)||(s<0&&y)||(!s&&x&&y)))// A+B가 음수결과인 경우 i가 0이 아니며, (A절대값이 크며 A는 음수 혹은  )
//         p[--i]='-';
//     if(j2&&((s>0&&x)||(s<0&&!y)||(!s&&x&&!y))) // A-B가 음수결과인 경우
//         m[--j2]='-';
//     printf("%s\n%s\n",p+i,m+j2);// A+B, A-B의 결과 출력 +i, +j2는 앞의 필요없는 영역을 없애는 역할.

    
//     // 곱셈 시작
//     for(i=B;i>=y;i--){
//         for(j=A, k=1000008+i-B; j>=x ;j--,k--){
//             M[k]+=(b[i]-'0')*(a[j]-'0'); // 곱한 값을 추가
//             M[k-1]+=M[k]/10; // 몫을 k-1칸에 추가.
//             M[k]%=10; // k칸의 값 보정 : 음수 갈 일 없음, 숫자 그대로 보관이 될 예정
//         }
//     }
//     int t=0;
//     while(t<C && !M[t])t++; //t 가 1000009보다 작으며, M[t]가 0이 아니면 t가 증가.
//     if(x^y && t<C) //부호가 다르며 t가 1000009보다 작다는 것은 0이 아닌 수가 존재한다는 것이다.
//         putchar('-');
    
//     if(t==C) // 결과가 모든 수가 0이다 -> 답이 0이다
//         putchar('0');
//     else 
//         for(;t<C;t++)
//             printf("%d",M[t]);
// }
