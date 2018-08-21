#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, N2, M, K;
	cin >> N >> M;
	int i, j, v, w;
	vector<vector<int>> G(N);
	for (i = 0; i < M; i++)
	{
		scanf("%d%d", &v, &w);
		G[v].push_back(w);
	}
	cin >> K;
	for (i = 0; i < K; i++)
	{
		scanf("%d", &N2);
		bool flag = true, arr[10000] = {};
		for (j = 0; j < N2; j++)
		{
			scanf("%d", &v);
			arr[v] = true;
		}
		for (v = 0; v < N; v++)
		{
			if (arr[v]) continue;
			for (int w : G[v])
			{
				if (!arr[w])
				{
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
