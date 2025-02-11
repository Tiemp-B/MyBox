#include <iostream>
#include <queue>
#include <cstdio>
#include <unordered_map>

// #define DEBUG
// #define MAX

using namespace std;

typedef struct{
    long long height;
    long long cost = 0;
    long long left_cost = 0;
    long long left_idx = 0;
    long long left_value = 0;
    long long right_cost = 0;
    long long right_idx = 0;
    long long right_value = 0;
} dat;

int main(int argc, char** argv){
    // init 
    long long N, K;
    long long highest = 0;
#ifndef MAX
    cin >> N >> K;
#else
    N = 100000;
    K = 1000000000000000000;
#endif

    vector<dat> tower(N);
    vector<dat> node(N);
    unordered_map<long long, long long> dict; // dict for lowest cost 
    
    for(int i=0; i<N; i++){
#ifndef MAX
        cin >> node[i].height;
#else
        node[i].height = 2;
#endif
        if(highest < node[i].height)
            highest = node[i].height;
        if(i>0){
            if(node[i].height >node[i-1].height){
                node[i].left_cost = node[i-1].left_cost + 1;
                node[i].left_idx = node[i-1].left_idx;
                node[i].left_value = node[i-1].left_value;
            }else{
                node[i].left_cost = 0;
                node[i].left_idx = i;
                node[i].left_value = node[i].height;
            }
        }
        else{
            node[i].left_cost = 0;
            node[i].left_idx = i;
            node[i].left_value = node[i].height;
        }
    }

    queue<int> order;

    node[N-1].right_cost = 0;
    node[N-1].right_idx = N-1;
    node[N-1].right_value = node[N-1].height;

    if(node[N-1].left_cost + node[N-1].right_cost <=K)
        order.push(N-1);

    for(int i=N-2; i>=0; i--){
        if(node[i].height > node[i+1].height){
            node[i].right_cost  = node[i+1].right_cost + 1;
            node[i].right_idx   = node[i+1].right_idx;
            node[i].right_value = node[i+1].right_value;
        }else{
            node[i].right_cost = 0;
            node[i].right_idx  = i;
            node[i].right_value  = node[i].height;
        }
        if(node[i].left_cost + node[i].right_cost <=K)
        order.push(i);
    }

    for(int i=0; i<N; i++)
        tower[i] = node[i];

#ifdef DEBUG
    cout << "idx    : ";
    for(int i=0; i<N; i++){
        printf("%2d ", i);
    }
    cout << "\ndata   : ";
    for(int i=0; i<N; i++){
        printf("%2d ", tower[i]);
    }
    cout << "\nl_cost : ";
    for(int i=0; i<N; i++){
        printf("%2d ", tower[i].left_cost);
    }
    cout << "\nl_idx  : ";
    for(int i=0; i<N; i++){
        printf("%2d ", tower[i].left_idx);
    }
    cout << "\nl_value: ";
    for(int i=0; i<N; i++){
        printf("%2d ", tower[i].left_value);
    }

    cout << "calcing..." <<endl;
#endif

    // calc
    int ans = 0;
    while(!order.empty()){
        auto top = order.front();
        order.pop();

        if(ans < node[top].height)
            ans = node[top].height;

#ifdef DEBUG
        if(top >=0)
            printf("\nidx: %2d height: %2d cost: %2d l_idx: %2d l_value: %2d r_idx: %2d r_value: %2d", top, node[top].height, node[top].cost, node[top].left_idx, node[top].left_value, node[top].right_idx, node[top].right_value);
#endif        

        // height increase

        if(node[top].left_idx == 0 && node[top].right_idx == N-1){ // all move
            long long left = K - node[top].cost;
            node[top].height += left/N;
            if(ans < node[top].height)
                ans = node[top].height;
            continue;
        }

        node[top].height++;
        node[top].cost += node[top].left_cost + node[top].right_cost + 1;

        node[top].left_value++;
        if(node[top].left_idx > 0){ // left element exist
            if(tower[node[top].left_idx - 1].height < node[top].left_value){ // left element affect over itself
                node[top].left_cost += tower[node[top].left_idx - 1].left_cost + 1;
                node[top].left_value = tower[node[top].left_idx - 1].left_value;
                node[top].left_idx   = tower[node[top].left_idx - 1].left_idx;
            }
        }

        node[top].right_value++;
        if(node[top].right_idx < N-1){ // right element exist
            if(tower[node[top].right_idx + 1].height < node[top].right_value){
                node[top].right_cost += tower[node[top].right_idx + 1].right_cost + 1;
                node[top].right_value = tower[node[top].right_idx + 1].right_value;
                node[top].right_idx   = tower[node[top].right_idx + 1].right_idx;
            }
        }
        
        if(node[top].cost <= K)
            order.push(top);
    }

#ifdef DEBUG
    cout << "\ncalc done\nidx    : ";
    for(int i=0; i<N; i++){
        printf("%2d ", i);
    }
    cout << "\nheight : ";
    for(int i=0; i<N; i++){
        printf("%2d ", node[i].height);
    }
    cout << "\ncost   : ";
    for(int i=0; i<N; i++){
        printf("%2d ", node[i].cost);
    }
    cout << "\nl_cost : ";
    for(int i=0; i<N; i++){
        printf("%2d ", node[i].left_cost);
    }
    cout << "\nl_idx  : ";
    for(int i=0; i<N; i++){
        printf("%2d ", node[i].left_idx);
    }
    cout << "\nl_value: ";
    for(int i=0; i<N; i++){
        printf("%2d ", node[i].left_value);
    }
    cout << "\nr_cost : ";
    for(int i=0; i<N; i++){
        printf("%2d ", node[i].right_cost);
    }
    cout << "\nr_idx  : ";
    for(int i=0; i<N; i++){
        printf("%2d ", node[i].right_idx);
    }
    cout << "\nr_value: ";
    for(int i=0; i<N; i++){
        printf("%2d ", node[i].right_value);
    }
    cout <<endl;
#endif

    cout << ans;


    return 0;
}