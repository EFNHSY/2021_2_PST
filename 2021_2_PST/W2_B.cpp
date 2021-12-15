#include <bits/stdc++.h>
using namespace std;
int t, n;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if ((a.first + a.second) == (b.first + b.second))
	{
		return a.first > b.first;
	}
	return (a.first + a.second) > (b.first + b.second);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		vector<pair<int, int>> v;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a, b; cin >> a >> b;
			v.push_back({ a,b });
			
		}
		sort(v.begin(), v.end(), cmp);
		int inha=0, dragon=0;
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0) inha += v[i].first;
			else dragon += v[i].second;
		}
		cout << inha - dragon << "\n";
	}
	return 0;
}