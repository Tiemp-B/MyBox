#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n = 1;
    int test_case = 0;
    cin >> n;
    while (n != 0)
    {
        test_case++;
        vector<string> nameList;
        unordered_set<int> appear;
        
        for (int i = 0; i <= n; i++)
        {
            string temp;
            getline(cin, temp);
            nameList.push_back(temp);
        }

        for (int i=0; i<2*n-1; i++){
            int a; char b;
            cin >>a >>b;
            if (appear.find(a) == appear.end()){
                appear.insert(a);
            }else{
                appear.erase(a);
            }
        }
        
        for(auto a : appear){
            cout << test_case <<" "<<nameList[a]<<endl;
        }

        cin >> n;
    }

    return 0;
}