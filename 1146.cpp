#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G;
bool judge(vector<int> inDegree);

int main()
{
	int N, M, K;
	cin >> N >> M;
	G.resize(N + 1);
	vector<int> inDegree(N + 1, 0);
	int i, v, w;
	for (i = 0; i < M; i++)
	{
		cin >> v >> w;
		G[v].push_back(w);
		inDegree[w]++;
	}
	cin >> K;
	bool first = true;
	for (i = 0; i < K; i++)
	{
		if (!judge(inDegree))
		{
			if (!first) cout << " ";
			else first = false;
			cout << i;
		}
	}
	return 0;
}

bool judge(vector<int> inDegree)
{
	bool ans = true;
	int i, v, N = G.size() - 1;
	for (i = 0; i < N; i++)
	{
		cin >> v;
		if (!ans) continue;
		if (inDegree[v] > 0) ans = false;
		else
		{
			for (int w : G[v])
				inDegree[w]--;
		}
	}
	return ans;
}
