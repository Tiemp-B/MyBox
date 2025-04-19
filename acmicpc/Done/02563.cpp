#include <iostream>

using namespace std;

int main(){

    int N;
    cin >> N;
    bool field[100][100]={};
    for(int i=0;i<N;i++){
        int y, x;
        cin >> y>>x;
        for(int m=0; m<10;m++)
            for(int n=0;n<10;n++)
                field[y+m][x+n] = true;

    }
    int ans=0;
    for(int i=0; i<100;i++)
        for(int j=0;j<100;j++)
            if(field[i][j]) ans++;

    cout << ans;
    

    return 0;
}
