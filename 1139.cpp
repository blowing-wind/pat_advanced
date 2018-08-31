#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool gender[10000], G[10000][10000];
vector < vector<int>> G2(10000);
struct bridge
{
	int f1, f2;
};

bool cmp(bridge a, bridge b)
{
	if (a.f1 != b.f1) return a.f1 < b.f1;
	return a.f2 < b.f2;
}

int main()
{
	int N, M, K;
	cin >> N >> M;
	int i, v, w;
	string s1, s2;
	for (i = 0; i < M; i++)
	{
		cin >> s1 >> s2;
		v = abs(stoi(s1));
		w = abs(stoi(s2));
		if (s1[0] == '-') gender[v] = true;
		if (s2[0] == '-') gender[w] = true;
		G[v][w] = true;
		G[w][v] = true;
		G2[v].push_back(w);
		G2[w].push_back(v);
	}
	cin >> K;
	for (i = 0; i < K; i++)
	{
		scanf("%d%d", &v, &w);
		v = abs(v);
		w = abs(w);
		vector<bridge> vec;
		for (int c : G2[v])
		{
			if (c == w) continue;
			if (!G[v][c] || (gender[c] != gender[v])) continue;
			for (int d : G2[c])
			{
				if (d == v) continue;
				if (G[d][c] && G[d][w] && gender[d] == gender[w])
				{
					bridge b;
					b.f1 = c;
					b.f2 = d;
					vec.push_back(b);
				}
			}
		}
		sort(vec.begin(), vec.end(), cmp);
		printf("%d\n", vec.size());
		for (bridge b : vec)
			printf("%04d %04d\n", b.f1, b.f2);
	}
	return 0;
}
