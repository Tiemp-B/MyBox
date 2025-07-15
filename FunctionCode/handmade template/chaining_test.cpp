#include <iostream>
#include <unordered_set>
#include <cstdio>
using namespace std;

int main() {
    unordered_set<int> uset;
    cout << "initial bucket count: " << uset.bucket_count() << '\n';

    int B = uset.bucket_count(); // 현재 bucket 수
    cout << "bucket count: " << B << '\n';

    for(int i=0; i<10000;++i){
        uset.insert(i);
    }
    for(int i=0; i<10000;++i){
        cout << "key " << i << " bucket: " << uset.bucket(i) << '\n';
    }
    uset.insert(2000000000);
    cout << "key " << 2000000000 << " bucket: " << uset.bucket(2000000000) << '\n';
    


    // if (uset.bucket(k1) == uset.bucket(k2)) {
    //     cout << "chaining occur!\n";
    // } else {
    //     cout << "no chaining\n";
    // }

    return 0;
}