#include <iostream>
#include <vector>

using namespace std;

vector<string> box;

void fillBox(int l){
    string arr_s;
    cin >>arr_s;
    string temp;
    for(char c: arr_s){
        if(c =='[') continue;
        if(c == ',' || c==']' ){
            if(temp.empty()) continue;
            box.push_back(temp);
            temp.clear();
            continue;
        }
        temp.push_back(c);
    }

}

void func(string cmd){
    int head = 0;
    int tail = box.size()-1;
    bool err = false;
    bool direction = true; //true: 정방향, false: 역방향
    for(char c: cmd){
        if(c =='R') direction = !direction;
        else if(c =='D'){
            //cout<<"head: "<<head<<", tail: "<<tail<<endl;
            if(head > tail) {
                err = true;
                break;
            }
            if(direction) head++;
            else tail--;
        }
    }

    if(err){
        cout<<"error\n";
        return;
    }
    if(direction){
        cout<<"[";
        for(int i= head; i<=tail; i++){
            cout<<box[i];
            if(i!=tail) cout<<",";
        }
        cout<<"]\n";
    }else{
        cout<<"[";
        for(int i=tail; i>=head; i--){
            cout<<box[i];
            if(i!=head) cout<<",";
        }
        cout<<"]\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T;
    cin >>T;
    for(int tc=1; tc<=T; tc++){
        if(!box.empty()) box.clear();
        int len;
        string cmd;
        cin >>cmd >> len;
        fillBox(len);
        func(cmd);

    }


    return 0;
}