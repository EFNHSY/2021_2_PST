#include <bits/stdc++.h> 
#define MAXN 50001
using namespace std;
int t, n;
vector<int> adj[MAXN];
int dir_size[MAXN];
bool visited[MAXN];
int dist[MAXN];
void dfs(int x)
{
	visited[x] = true;
	for (auto u : adj[x])
	{
		if (!visited[u])
		{
			visited[u] = true;
			dist[u] = dist[x] + 1 + dir_size[u];
			dfs(u);
		}
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}
		for (int i = 1; i <= n; i++)
		{
			string s; cin >> s;
			dir_size[i] = s.size();
		}
		dist[1] = dir_size[1];
		dfs(1);
		for (int i = 1; i <= n; i++)
		{
			cout << dist[i] << "\n";
		}
		for (int i = 1; i <= n; i++)
		{
			adj[i].clear();
			dist[i] = dir_size[i]= 0; visited[i] = false;
		}
	}

	return 0;
}