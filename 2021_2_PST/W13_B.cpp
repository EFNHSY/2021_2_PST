#include <bits/stdc++.h>
using namespace std;
int t, n, m;

int main()
{
	cin >> t;
	while (t--)
	{
		
		cin >> n >> m;
		vector<int> msg(m, 0);
		vector<bool> check(n, false);
		vector<int> ans(m, 0);

		for (int& x : msg) cin >> x;
		int read = n;
		for (int i = m - 1; i >= 0; i--)
		{
			if (!check[msg[i]])
			{
				check[msg[i]] = true;
				read--;
				ans[i] = read;
				
			}
			else
			{
				ans[i] = read;
			}

		}
		for (auto u : ans)
		{
			cout << u << "\n";
		}
	}

	return 0;
}