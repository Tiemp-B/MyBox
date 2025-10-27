#include <iostream>
#include <vector> 

using namespace std;

int operator>>(pair<int, int> A, pair<int, int> B){
    return abs(A.first-B.first) + abs(A.second-B.second);
}

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int N, D, H;
pair<int, int> end_point;
pair<int, int> start_point;

vector<pair<int,int>> umb;


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >>H >>D;

    

    return 0;
}