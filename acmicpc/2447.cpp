#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<char>> out;

void func(int N)
{
    /* 5중 for문을 통한 공백 위치 계산*/
    int k = 1;
    for (int s = 3; s <= N; s *= 3, k *= 3)
        for (int i = 1; i <= N; i += s)
            for (int j = 1; j <= N; j += s)
                for (int y = 0; y < k; y++)
                    for (int x = 0; x < k; x++)
                        out[i + k + y][j + k + x] = ' ';

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << out[i][j];
        cout << endl;
    }
}


map<int, vector<string>> mp;
void div_con(int siz);

void func2(int N)
{
    mp.insert({3, {{"***"}, {"* *"}, {"***"}}});

    div_con(N);

    for (auto e : mp[N])
    {
        cout << e << endl;
    }
}

void div_con(int siz)
{
    if (mp.find(siz) != mp.end())
        return;
    if (mp.find(siz / 3) == mp.end())
        div_con(siz / 3);
    vector<string> temp(siz, "");
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (r == c && r == 1)
            {
                string blank(siz / 3, ' ');
                for (int l = 0; l < siz / 3; l++)
                    temp[siz / 3 + l] += blank;
            }
            else
                for (int l = 0; l < siz / 3; l++)
                {
                    temp[r * siz / 3 + l] += mp[siz / 3][l];
                }
        }
    }

    mp[siz] = temp;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    // 최대 범위 2187 * 2187
    out.resize(N + 1, vector<char>(N + 1, '*'));

    func2(N);
}