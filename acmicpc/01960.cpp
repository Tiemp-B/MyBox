#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N;
vector<vector<int>> arr;
bool avail=false;
vector<int> row, col;
int row_sum=0;
int col_sum=0;
map<int, vector<int>> row_el, col_el;
vector<int> row_idx, col_idx;

void init(){
    cin >>N;
    arr.resize(N, vector<int>(N));
    row.resize(N);
    col.resize(N);
    for(int i=0;i<N;++i){
        cin >> row[i];
        row_sum += row[i];
        row_el[row[i]].push_back(i);
    }
    for(int i=0;i<N;++i){
        cin >> col[i];
        col_sum += col[i];
        col_el[col[i]].push_back(i);
    }

    for(auto e : row_el){
        for(auto i : e.second){
            row_idx.push_back(i);
        }
    }
    for(auto e : col_el){
        for(auto i : e.second){
            col_idx.push_back(i);
        }
    }
}

bool calc(){
    if(row_sum != col_sum) return false; // 행방향과 열방향의 1의 수가 다르면 오류

    for(int i=N-1; i>=0; --i){
        int r = row_idx[i];
        int j=N-1;
        int c = col_idx[j];
        while(row[r]!=0){
            if(col[c]>0){
                arr[r][c] = 1;
                row[r]--;
                col[c]--;
            }
            if(--j == -1){
                if(row[r]!=0) return false;// 분배 실패시 에러
                else break;
            }
            c = col_idx[j];
        }
    }
    return true;
}


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    if(calc()){
        cout <<"1\n";
        for(int i=0; i<N;++i){
            for(int j=0;j<N;++j){
                cout<<arr[i][j];
            }
            cout<<"\n";
        }
    }
    else cout <<-1;

    return 0;
}