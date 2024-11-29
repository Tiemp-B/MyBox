#include <iostream>

using namespace std;

int main()
{
    string score;
    cin >> score;

    int front = 0, back = 0;

    int l = score.size() / 2;

    for (int i = 0; i <= l; i++)
    {
        front += score[i];
        back += score[i];
    }
    if (front == back)
        cout <<"LUCKY";
    else
        cout <<"READY";

    return 0;
}
