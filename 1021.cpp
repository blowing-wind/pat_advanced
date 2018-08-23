#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> G;
void dfs(int s, bool marked[]);
int components();
int depth(int v, int father);

int main()
{
	int i, v, w, t;
	cin >> N;
	G.resize(N + 1);
	for (i = 0; i < N - 1; i++)
	{
		cin >> v >> w;
		G[v].push_back(w);
		G[w].push_back(v);
	}
	t = components();
	if (t > 1)
		printf("Error: %d components", t);
	else
	{
		int max = -1;
		vector<int> ans;
		for (v = 1; v <= N; v++)
		{
			t = depth(v, 0);
			if (t > max)
			{
				max = t;
				ans.clear();
				ans.push_back(v);
			}
			else if (t == max)
				ans.push_back(v);
		}
		for (int v : ans)
			cout << v << endl;
	}
	return 0;
}

void dfs(int s, bool marked[])
{
	marked[s] = true;
	for (int w : G[s])
	{
		if (!marked[w])
			dfs(w, marked);
	}
}

int components()
{
	int i, cnt = 0;
	bool marked[10001] = {};
	for (i = 1; i <= N; i++)
	{
		if (!marked[i])
		{
			dfs(i, marked);
			cnt++;
		}
	}
	return cnt;
}

int depth(int v, int father)
{
	if (G[v].size() == 1 && G[v][0] == father)
		return 1;
	int t, max = -1;
	for (int w : G[v])
	{
		if (w == father) continue;
		t = depth(w, v);
		if (t > max)
			max = t;
	}
	return max + 1;
}
