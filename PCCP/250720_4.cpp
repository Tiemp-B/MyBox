#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

vector<string> name;
vector<string> query;
vector<int> ans;

void init(int n = -1, int m = -1){
    random_device rd;
    // mt19937 gen(rd());
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dis1(1,5);
    uniform_int_distribution<int> dis2(0,25);
    uniform_int_distribution<int> siz(1, 100000);

    int name_cnt = siz(gen);
    int query_cnt = siz(gen);

    if(n!=-1){
        name_cnt = n;
        query_cnt = m;
    }

    while(name_cnt-->0){
        int l = dis1(gen);
        string s(l, 'A');
        for(int i=0;i<l;++i)
            s[i] += dis2(gen);
        name.push_back(s);
    }
    while(query_cnt-->0){
        int l = dis1(gen);
        string s(l, 'A');
        for(int i=0;i<l;++i)
            s[i] += dis2(gen);
        query.push_back(s);
    }
    ans.resize(query.size(), 0);
    cout << "name size : "<<name.size()<< "\nquery size : "<< query.size()<<endl;
}

void submit_calc(){
    unordered_map<string, int> name_map;
    unordered_map<string, int> query_map;
    for(auto e : name)
        name_map[e]++;
    int idx=0;
    for(auto query_data : query){
        if(query_map[query_data] != 0){
            ans[idx++] = query_map[query_data];
            continue;
        }
        for(auto name_data : name_map){
            int cnt = 0;
            for(int i=0; i<name_data.first.size() && i<query_data.size() ;++i){
                cnt++;
                if(name_data.first[i] != query_data[i]) break;
            }
            ans[idx] += cnt * name_data.second;
        }
        query_map[query_data] = ans[idx];
        idx++;
    }
}

struct node {
    int cnt=0;
    unordered_map<char, node*> nex;
};
void calc2(){
    node *head= new node;
    for(auto s : name){
        node *now = head;
        for(auto c : s){ 
            now->cnt++;
            if(now->nex.find(c) == now->nex.end())
                now->nex[c] = new node;
            now = now->nex[c];
        }
    }
    for(int idx=0; idx<query.size(); ++idx){
        string s = query[idx];
        node *now = head;
        for(int i=0; i<s.size();++i){
            ans[idx] += now->cnt;
            if(now->nex.find(s[i]) == now->nex.end()) // 해당 문자 없음
                break;
            now = now->nex[s[i]];
        }
    }
}

void print(){
    // for(auto s : name)
    //     cout <<s<<" ";
    // cout <<"\n------\n";
    // for(auto s : query)
    //     cout <<s<<" ";
    // cout <<"\n------\n";

    for(auto e : ans)
        cout << e<<" ";
}

int main(){
    int n=100;
    init(n, n);
    auto st = chrono::system_clock::now();
    // submit_calc();
    calc2();
    auto fn = chrono::system_clock::now();
    if(true) print();
    chrono::duration<double, milli> msec = fn-st;
    
    cout << "\nactivate in "<< msec.count() << " ms";
    return 0;
}