#include <iostream>
#include <vector>
using namespace std;

int N, K;
int ans = 0;

int *W;
int *V;

int main()
{
    cin >> N >> K;
    W = new int[N];
    V = new int[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> W[i] >> V[i];
    }

    int *value = new int[K + 1]();
    bool **use = new bool *[K + 1];

    for (int i = 0; i < K + 1; ++i)
    {
        use[i] = new bool[N]();
    }

    for (int i = 0; i < K; ++i)
    {
        for (int p = 0; p < N; ++p)
        {
            if (use[i][p])
            {
                continue;
            }
            int newW = i + W[p];
            int newV = value[i] + V[p];
            if (newW > K)
                continue;
            if (newV <= value[newW])
                continue;
            for (int j = 0; j < N; ++j)
                use[newW][j] = use[i][j];
            use[newW][p] = true;
            value[newW] = newV;
        }
    }

    int ans = 0;

    for (int i = 1; i <= K; ++i)
    {
        if (value[i] > ans)
            ans = value[i];
    }

    cout << ans;

    return 0;
}
