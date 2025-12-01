#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int correct = 0;
        for (int q = 1; q <= 10; q++)
        {
            int a;
            cin >> a;
            if (a == (q - 1) % 5 + 1)
                correct++;
        }
        if (correct == 10)
        {
            cout << i << endl;
        }
    }

    return 0;
}