#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<int> box;

void numBox(int N, mt19937& gen, uniform_int_distribution<int>& dis) {
    if (!box.empty()) box.clear();
    box.resize(N);

    for (int i = 0; i < N; ++i) {
        box[i] = dis(gen);
    }
}

void getBox(int N){
    if (!box.empty()) box.clear();
    box.resize(N);

    for(int i=0;i<N;++i)
        cin >>box[i];
}

long long int calc1(int N) {
    long long int running = 0, ans = 0;

    for (int i = N - 1; i >= 0; i--) {
        ans += box[i] * running;
        running += box[i];
    }
    return ans;
}

int calc2(int N) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans += box[i] * box[j];
        }
    }
    return ans;
}

int calc3(int N){
    int ans = 0;
    int temp = 0;
    for(int i=0; i<N;i++) temp += box[i];

    for(int i=0; i<N;i++){
        temp -= box[i];
        ans += temp* box[i];
    }
    return ans;
}

int main() {
    int N, ans = 0;
    bool DEBUG = false;
    // 랜덤 생성기 초기화
    
    if (DEBUG){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(-100, 100);

        while (true) {
            cout << "Enter : ";
            cin >> N;
            if (N == 0) break;  // 종료 조건

            numBox(N, gen, dis);
            int ans1 = calc1(N);
            int ans2 = calc2(N);
            int ans3 = calc3(N);
            cout << ans1 <<"  "<<ans2<< "  "<<ans3<<endl;
            
        }
    }else{
        cin >>N;
        getBox(N);
        long long int ans = calc1(N);
        cout <<ans;
    }

    return 0;
}
