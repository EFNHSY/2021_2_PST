#include <bits/stdc++.h>
#define MAXN 3000
using namespace std;
int n, m;
char board[MAXN][MAXN];

vector<int> failure(string p)
{
	int m = p.size(),j=0;
	vector<int> fail(m, 0);

	for (int i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j]) j = fail[j - 1];
		if (p[i] == p[j]) fail[i] = ++j;
	}

	return fail;
}

bool kmp(string s, string p)
{
	vector<int> ans;
	int n = s.size(), m = p.size(), j =0;
	auto fail = failure(p);

	for (int i = 0; i < n; i++)
	{
		while (j > 0 && s[i] != p[j]) j = fail[j - 1];
		if (s[i] == p[j])
		{
			if (j == m - 1)
			{
				ans.push_back(i - m + 1);
				j = fail[j];
				return true;
			}
			else
			{
				j++;
			}
		}
	}
	
	return false;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	vector<string> Text;
	vector<string> Pattern(m);
	for (string& x : Pattern) cin >> x;

	// 가로 방향
	for (int i = 0; i < n; i++)
	{
		string temp = "";	
		
		for (int j = 0; j < n; j++)
		{
			temp += board[i][j];
		}
		Text.push_back(temp);
	}
	// 세로방향 
	for (int i = 0; i < n; i++)
	{
		string temp = "";
		for (int j = 0; j < n; j++)
		{
			temp += board[j][i];
		}
		Text.push_back(temp);
	}
	// 대각선 방향
	for (int i = 1; i < n; i++)
	{
		string temp1= "", temp2 = "";
		for (int j = 0; j < n - i; j++)
		{
			temp1 += board[j + i][j];
			temp2 += board[j][i + j];
		}
		Text.push_back(temp1); 
		Text.push_back(temp2);
	}
	
	for (auto u : Pattern)
	{
		bool flag = false;
		for (auto x : Text)
		{
			if (kmp(x,u))
			{
				cout << "1\n";
				flag = true;
				break;
			}
		}
		if (!flag) cout << "0\n";
	}
	return 0;
}