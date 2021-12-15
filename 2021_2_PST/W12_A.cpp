#include <bits/stdc++.h>
#define INF 987654321
#define MAXN 101
using namespace std;

int t, n, board[101][101], dp[101][101];

int main()
{
	cin >> t;
	while (t--)
	{
		

		for (int i = 0; i < MAXN; i++)
		{
			for (int j = 0; j < MAXN; j++)
			{
				dp[i][j] = board[i][j] = INF;
			}
				
		}
		

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cin >> board[i][j];
				
			}
		}

		dp[1][1] = board[1][1];

		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + board[i][j];
			}
		}

		int ans = INF;
		
		for (int j = 1; j <= n; j++)
		{
			ans = min(ans, dp[n][j]);
		}
		cout << ans << "\n";
		
	}

	return 0;
}