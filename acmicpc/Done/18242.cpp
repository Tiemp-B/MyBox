#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> li(N, vector<char>(M));

    pair<int, int> leftUp = {-1, -1};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> li[i][j];
            if (leftUp.first == -1 && li[i][j] == '#')
                leftUp = {i, j};
        }
    }

    int L = 0;

    while (true)
    {
        if (li[leftUp.first + L][leftUp.second] != li[leftUp.first][leftUp.second + L])
        {
            if (li[leftUp.first + L][leftUp.second] == '.')
            {
                cout << "LEFT";
                return 0;
            }
            if (li[leftUp.first][leftUp.second + L] == '.')
            {
                cout << "UP";
                return 0;
            }
        }
        else
        {
            if (li[leftUp.first + L][leftUp.second] == '.')
                break;
        }
        L++;
        if (leftUp.first + L == N || leftUp.second + L == M)
            break;
    }

    for (int i = 0; i < L; i++)
    {
        if (li[leftUp.first + L - 1][leftUp.second + i] == '.')
        {
            cout << "DOWN";
            return 0;
        }
        if (li[leftUp.first + i][leftUp.second + L - 1]== '.')
        {
            cout << "RIGHT";
            return 0;
        }
    }

    return 0;
}