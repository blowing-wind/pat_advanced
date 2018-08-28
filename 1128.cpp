#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int K, N, i, j, k, t;
	cin >> K;
	for (i = 0; i < K; i++)
	{
		cin >> N;
		bool ans = true;
		vector<int> v;
		vector<bool> occupied(N + 1, false);
		for (j = 1; j <= N; j++)
		{
			cin >> t;
			if (!ans) continue;
			if (occupied[t]) ans = false;
			for (k = 0; k < v.size(); k++)
			{
				if (k + 1 - j == v[k] - t) ans = false;
			}
			occupied[t] = true;
			v.push_back(t);
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}
