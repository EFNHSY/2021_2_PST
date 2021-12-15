#include <bits/stdc++.h>

using namespace std;
int t, n;

int main()
{
	cin >> t;
	while (t--)
	{
		stack<int> max_s, min_s;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int query; cin >> query;
			if (query == 1)
			{
				int x; cin >> x;
				if (max_s.empty())
				{
					max_s.push(x); min_s.push(x);
				}
				else
				{
					if (max_s.top() >= x)
					{
						max_s.push(max_s.top());

					}
					else
					{
						max_s.push(x);
					}
					if (min_s.top() <= x) {
						min_s.push(min_s.top());
					}
					else
					{
						min_s.push(x);
					}
				}

				cout << min_s.top() << " " << max_s.top() << "\n";
			}
			else
			{
				if (!max_s.empty())
				{
					max_s.pop(); min_s.pop();
				}
			}
		}
	}

	return 0;
}