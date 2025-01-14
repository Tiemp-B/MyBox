#include <iostream>
#include <set>

using namespace std;

struct cmp{
    bool operator()(const string &a, const string &b) const {
        if (a.length() == b.length())
            return a < b; // 사전순
        return a.length() < b.length(); // 길이순 
    }
};


int main()
{
    int N, M;
    cin >> N >> M;
    set<string, cmp> cla[11];

    int clas;
    string name;
    while (true)
    {
        cin >> clas >> name;
        
        if (clas == 0)
            break;
        if (cla[clas].size() == static_cast<size_t>(M))
            continue;
        
        cla[clas].insert(name);
    }

    for (int i = 1; i <= N / 2; i++)
        for (auto n : cla[i * 2 - 1])
            cout << i * 2 - 1 << " " << n << endl;

    for (int i = 1; i <= N / 2; i++)
        for (auto n : cla[i * 2])
            cout << i * 2 << " " << n << endl;

    return 0;
}