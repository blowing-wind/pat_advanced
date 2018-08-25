#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool G[201][201];

int main()
{
	int N, M, i, v, w;
	cin >> N >> M;
	for (i = 0; i < M; i++)
	{
		cin >> v >> w;
		G[v][w] = true;
		G[w][v] = true;
	}
	int K, n, first, j;
	cin >> K;
	for (i = 0; i < K; i++)
	{
		bool flag = true;
		bool occured[201] = {};
		cin >> n >> first;
		if (n != N + 1) flag = false;
		occured[first] = true;
		v = first;
		for (j = 1; j < n - 1; j++)
		{
			cin >> w;
			if (occured[w]) flag = false;
			occured[w] = true;
			if (!G[v][w]) flag = false;
			v = w;
		}
		cin >> w;
		if (!G[v][w] || w != first) flag = false;
		if (!flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
