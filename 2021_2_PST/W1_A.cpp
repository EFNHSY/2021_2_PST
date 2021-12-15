#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int t, k;

int main()
{
	FAST;
	cin >> t;
	while (t--)
	{
		string s; cin >> s; cin >> k; int n = s.size();
		int x = 2;
		if (k > n)
		{
			cout << s << "\n";
			continue;
		}
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < n; j += 2 * k)
			{
				cout << s[i + j];
				if (j + 2 * k - (i + 1) < n)
				{
					cout << s[j + 2 * k - (i + 1)];
				}
			}
		}
		cout << "\n";
	}


	return 0;
}