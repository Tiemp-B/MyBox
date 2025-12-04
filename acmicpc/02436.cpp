#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;



int main()
{
    int GSD, LCM;
    cin >> GSD >> LCM;

    int ans_sum = 200000000;
    long long int A, B;

    int gap = LCM / GSD;

    vector<pair<int, int>> el; // {원소, 포함수수}
    set<int> ordered_el;
    vector<int> el2;

    // 소인수분해 신형형
    for(int i=2; i<=LCM/(GSD*2) && gap>1; i++){
        if(gap%i!=0)
            continue;
        int value=1;
        while(gap%i==0){
            value *= i;
            gap/= i;
        }
        // ordered_el.insert(value);
        el2.push_back(value);
    }

    // alpha, beta 연산산
    int e_cnt = el2.size();
    int t = 0;
    int upper_bound = 1; // 2^el.size()
    for (int i = 0; i < e_cnt-1; i++)
        upper_bound *= 2;
    gap = LCM/GSD;

    while (t < upper_bound)
    {
        int alpha = 1, beta = 1;
        for (int i = 0; i < el2.size(); i++)
        {
            if ((t >> i) & 1 == 1)
                alpha *= el2[i];
        }
        beta = gap / alpha;

        int temp_A = alpha * GSD;
        int temp_B = beta * GSD;

        if (ans_sum > temp_A + temp_B)
        {
            ans_sum = temp_A + temp_B;
            A = temp_A;
            B = temp_B;
        }
        t++;
    }


    if (A > B)
    {
        cout << B << " " << A;
    }
    else
    {
        cout << A << " " << B;
    }

    return 0;
}