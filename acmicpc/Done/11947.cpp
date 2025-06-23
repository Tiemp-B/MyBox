#include <iostream>
#include <deque>
using namespace std;

pair<long long int, long long int> trans(string str){
    long long int out1=0, out2=0;
    int dec = 1;
    for(int i=str.size()-1; i>=0;--i, dec*=10){
        long long int a = (str[i]-'0');
        long long int b = 9-(str[i]-'0');
        out1 += a*dec;
        out2 += b*dec;
    }
    return {out1, out2};
}

long long int calc(string str){
    auto lli = trans(str);
    return lli.first * lli.second;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int T;
    cin >>T;
    string temp;
    for(int t=0; t<T;++t){
        cin >> temp;
        if(temp.front()-'0'>=5){
            temp[0] = '4';
            for(int i=1; i<temp.size();++i)
                temp[i] = '9';
            cout << calc(temp)<<endl;
        }else{
            cout << calc(temp)<< endl;
        }
    }

    return 0;
}