#include <bits/stdc++.h>
#define MAXN 16
using namespace std;

int n,cnt=0;

void search(int y, int x, bool state[][MAXN])
{
	bool temp_state[MAXN][MAXN];
	//cout << "----------------------------------------\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			temp_state[i][j] = state[i][j];
			
		}
	}
	if (y == n)
	{
		cnt++;
		return;
	}
	else
	{
		//cout << y << " " << x << "\n";
		for (int nextY = y; nextY <= n; nextY++)
		{
			state[nextY][x] = true;
		}
		int idx = 1;
		for (int nextY = y+1; x-idx>=1 && nextY <= n; nextY++)
		{
			state[nextY][x - idx] = true;
			idx++;
		}
		idx = 1;
		for (int nextY = y + 1; x + idx <= n && nextY <= n; nextY++)
		{
			state[nextY][x + idx] = true;
			idx++;
		}

		for (int i = 1; i <= n; i++)
		{
			if (!state[y + 1][i])
			{
				search(y + 1, i, state);
				
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				state[i][j] = temp_state[i][j];
			}
		}
	}
}

int main()
{
	cin >> n;

	bool state[MAXN][MAXN] = { false, };

	for (int i = 1; i <= n; i++)
	{
		search(1, i, state);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				state[i][j] = false;
			}
		}
	}


	cout << cnt << "\n";

	return 0;
}