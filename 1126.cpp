#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G;
bool marked[501];


void dfs(int s)
{
	marked[s] = true;
	for (int w : G[s])
	{
		if (!marked[w]) dfs(w);
	}
}

bool isConnected()
{
	dfs(1);
	for (int i = 1; i < G.size(); i++)
	{
		if (!marked[i]) return false;
	}
	return true;
}

int main()
{
	int N, M;
	cin >> N >> M;
	G.resize(N + 1);
	int i, v, w;
	for (i = 0; i < M; i++)
	{
		cin >> v >> w;
		G[v].push_back(w);
		G[w].push_back(v);
	}
	int even, odd;
	even = odd = 0;
	for (i = 1; i <= N; i++)
	{
		if (i > 1) cout << " ";
		cout << G[i].size();
		if (G[i].size() % 2 == 0) even++;
		else odd++;
	}
	cout << endl;
	if (isConnected())
	{
		if (even == N) cout << "Eulerian";
		else if (odd == 2) cout << "Semi-Eulerian";
		else cout << "Non-Eulerian";
	}
	else cout << "Non-Eulerian";
	return 0;
}
