#include <iostream>
#include <unordered_map>

using namespace std;

struct element{
    int value;
    unordered_map<int, int> loc;
};

string itos(int a){
    string ret = "";
    while(a>0){
        ret += (a%10) +'0';
        a /= 10;
    }
    return ret;
}

int main(){
    int N; 
    cin >> N;

    element box[1000];
    int header[10]={-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    for(int i=0; i<N; i++){
        cin >> box[i].value;
        if(header[box[i].value] == -1)
            header[box[i].value] = i;
        for(int j=0; j < i; j++){
            if(box[j].loc.find(box[i].value) == box[j].loc.end())
                box[j].loc[box[i].value] = i;
        }
    }

    int ans = 0;

    if(header[0] == -1){
        cout << ans;
        return 0;
    }

    ans++;

    while(true){
        string str = itos(ans);
        bool flag = false;
        int head = str.back()-'0';
        
        if(header[head] == -1){
            break;
        }
        head = header[head];
        for(int i = str.size()-2; i>=0; i--){
            if(ans == 15){

            }
            int target = str[i]-'0';
            if(box[head].loc.find(target) == box[head].loc.end()){
                flag = true;
                break;
            }
            head = box[head].loc[target];
        }
        if(flag)
            break;
        ans++;
    }
    cout << ans;

    return 0;
}