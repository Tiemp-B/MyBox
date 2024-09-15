#include <iostream>

using namespace std;


int main(){
    int N, M;
    int helmet=0, mail=0;
    cin >>N>>M;
    for(int i=0, temp; i<N; i++){
        cin >>temp;
        if(helmet< temp) helmet =temp;
    }

    for(int j=0, temp; j<M;j++){
        cin >>temp;
        if(mail <temp) mail = temp;
    }

    cout <<helmet + mail;

    return 0;
}