#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> box;
int N, M;
vector<int> logg;

void pnt() {
    for (int a : logg) {
        cout << a << " ";
    }
    cout << endl;
}

void tracking(int i, int lv) {
    if (lv == M) {
        pnt();
        return;
    }
    for (int j = i; j < box.size(); ++j) {
        logg.push_back(box[j]);
        tracking(j, lv + 1);
        logg.pop_back();
    }
}

int main() {
    cin >> N >> M;

    bool appear[10001] = {};

    for (int i = 0, temp; i < N; i++) {
        cin >> temp;
        if (appear[temp]) continue;
        appear[temp] = true;
        box.push_back(temp);
    }

    sort(box.begin(), box.end());

    tracking(0, 0);

    return 0;
}