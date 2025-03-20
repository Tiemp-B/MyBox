#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

string add(string a, string b)
{
	int n = max(a.size(), b.size());
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;

	int carry = 0;
	string ans(n, '0');
	for (int i = n - 1; i >= 0; i--)
	{
		int res = (a[i] - '0' + b[i] - '0' + carry)%10;
		carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
		ans[i] = res + '0';
	}
	if (carry)
		ans = '1' + ans;

	return ans;
}

string sub(string a, string b)
{
	int n = max(a.size(), b.size());
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;

	int carry = 0;
	string ans(n, '0');
	for (int i = n - 1; i >= 0; i--)
	{
		int res = ((a[i] - '0') - (b[i] - '0') - carry) % 10;
		if (res < 0) res += 10;
		carry = ((a[i] - '0') - (b[i] - '0') - carry) < 0;
		ans[i] = res + '0';
	}

	int ix = 0;
	while (ans[ix] == '0')
		ix++;

	ans = ans.substr(ix);

	return ans;
}


string multiply(string a, string b)
{
	int m = max(a.size(), b.size());
	a = string(m - a.size(), '0') + a;
	b = string(m - b.size(), '0') + b;
	int n = a.size() + b.size();

	string ans(n, '0');
	vector<int> tmp(n);
	for (int i = 0; i <m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int res = (a[m - j - 1] - '0')* (b[m - i - 1] - '0');
			tmp[n - (i + j) - 1] += res % 10;
			tmp[n - (i + j) - 2] += res / 10;
		}
	}

	for (int i = n - 1; i > 0; i--)
	{
		ans[i] = tmp[i] % 10+'0';
		tmp[i - 1] += tmp[i] / 10;
	}
	ans[0] = tmp[0] % 10 + '0';

	int ix = 0;
	while (ans[ix] == '0')
		ix++;

	ans = ans.substr(ix);

	return ans;
}

bool operator<=(string a, string b)
{
	if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == b[i])continue;
			return a[i] < b[i];
		}
		return true;
	}
	return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string n;
	cin >> n;
	if (n.size() % 2)
	{
		n = '0'+n;
	}

	string cur = "";
	string l = "";
	string ans = "";
	for (int i = 0; i < n.size(); i += 2)
	{
		cur = cur + n.substr(i, 2);
		int ix = 0;
		while (cur[ix] == '0')
			ix++;
		if (ix == cur.size())
			cur = "0";
		else
			cur = cur.substr(ix);
		if (i == 0)
		{
			int j = 0;
			while ((j+1) * (j+1) <= stoi(cur))
				j++;
			cur = to_string(stoi(cur) - j * j);
			l = to_string(j + j);
			ans += (char)(j + '0');
		}
		else
		{
			int j = 0;
			string tmp = multiply(add(l + '0', to_string(j + 1)), to_string(j+1));
			while (tmp <= cur)
			{
				j++;
				tmp = multiply(add(l + '0', to_string(j + 1)), to_string(j + 1));
			}
			cur = sub(cur, multiply(add(l + '0', to_string(j)), to_string(j)));
			l = add(l+'0',to_string(2 * j));
			ans += (char)(j + '0');
		}
	}
	cout << ans;


	return 0;
}