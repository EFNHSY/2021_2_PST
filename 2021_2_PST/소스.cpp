#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;

int n;
long long max_ans=-INF, min_ans=INF;
long long oper[4],arr[11];


void search1(int k, int cur_oper, long long cur_ans)
{
	if (k == n)
	{
		max_ans = max(max_ans, cur_ans);
		min_ans = min(min_ans, cur_ans);
		return;
	}
	else
	{
		long long temp_ans = cur_ans;
		if (cur_oper == 0)
		{
			temp_ans += arr[k];
		}
		else if (cur_oper == 1)
		{
			temp_ans -= arr[k];
		}
		else if (cur_oper == 2)
		{
			temp_ans *= arr[k];
		}
		else
		{
			temp_ans /= arr[k];
		}
		for (int i = 0; i < n; i++)
		{
			if (oper[i] > 0)
			{
				oper[i]--;
				search1(k + 1, i, temp_ans);
				oper[i]++;
			}
		}
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		cin >> oper[i];
	}
	
	search1(0, 0, 0);

	cout << max_ans << "\n" << min_ans << "\n";

	return 0;
}