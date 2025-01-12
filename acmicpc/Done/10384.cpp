#include <iostream>

using namespace std;

void func(int T)
{

	string str;
	getline(cin, str);

	int ans = 31;
	int box[26];

	for (int i = 0; i < 26; i++)
		box[i] = 1;

	for (auto c : str)
	{
		if ('a' <= c && c <= 'z')
		{
			box[c - 'a'] = (box[c - 'a'] << 1) + 1;
		}
		else if ('A' <= c && c <= 'Z')
		{
			box[c - 'A'] = (box[c - 'A'] << 1) + 1;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		ans &= box[i];
	}

	cout << "Case " << T << ": ";
	switch (ans)
	{
	case 1:
		cout << "Not a pangram" << endl;
		break;
	case 3:
		cout << "Pangram!" << endl;
		break;
	case 7:
		cout << "Double pangram!!" << endl;
		break;
	case 15:
		cout << "Triple pangram!!!" << endl;
		break;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	string trash;
	getline(cin, trash);

	for (int i = 1; i <= N; i++)
	{
		func(i);
	}

	return 0;
}
