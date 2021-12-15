#include <bits/stdc++.h>
#define MAX 9
using namespace std;
int n, m;
vector<int> permutation;
bool chosen[MAX];

void search(int k)
{
	if (permutation.size() == m)
	{
		for (auto u : permutation)
		{
			cout << u << " ";
		}cout << "\n";
		return;
	}
	else
	{
		for (int i = k; i <= n; i++)
		{
			permutation.push_back(i);
			search(i);
			permutation.pop_back();
		}
	}
}
int main()
{
	cin >> n >> m;

	search(1);
	return 0;
}