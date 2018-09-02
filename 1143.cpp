#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int M, N, i;
	cin >> M >> N;
	vector<int> vec(N);
	map<int, bool> mp;
	for (i = 0; i < N; i++)
	{
		cin >> vec[i];
		mp[vec[i]] = true;
	}
	int u, v, a;
	for (i = 0; i < M; i++)
	{
		cin >> u >> v;
		for (int j : vec)
		{
			if (u >= j && v <= j || v >= j && u <= j)
			{
				a = j;
				break;//必须有break
			}
		}
		if (!mp[v] && !mp[u]) printf("ERROR: %d and %d are not found.", u, v);
		else if (!mp[u] || !mp[v]) printf("ERROR: %d is not found.", mp[u] ? v : u);
		else
		{
			if (a == u) printf("%d is an ancestor of %d.", u, v);
			else if (a == v) printf("%d is an ancestor of %d.", v, u);
			else printf("LCA of %d and %d is %d.", u, v, a);
		}
		printf("\n");
	}
	return 0;
}
