#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool marked[10000];
vector<vector<int>> G(10000);
int estate[10000], area[10000];

struct family
{
	int id = 10000, size = 0;
	double estate = 0.0, area = 0.0;
};

void connect(int id)
{
	int t;
	cin >> t;
	if (t >= 0)
	{
		G[id].push_back(t);
		G[t].push_back(id);
	}
}

void dfs(int s, family& f)
{
	marked[s] = true;
	f.size++;
	if (s < f.id) f.id = s;
	f.area += area[s];
	f.estate += estate[s];
	for (int w : G[s])
		if (!marked[w]) dfs(w, f);
}

bool cmp(family a, family b)
{
	if (a.area != b.area) return a.area > b.area;
	else return a.id < b.id;
}

int main()
{
	int N;
	cin >> N;
	int i, j, id, k;
	vector<int> allId;
	for (i = 0; i < N; i++)
	{
		cin >> id;
		allId.push_back(id);
		for (j = 0; j < 2; j++)
			connect(id);
		cin >> k;
		for (j = 0; j < k; j++)
			connect(id);
		cin >> estate[id] >> area[id];
	}
	vector<family> v;
	for (int id : allId)
	{
		if (!marked[id])
		{
			family f;
			dfs(id, f);
			f.area /= f.size;
			f.estate /= f.size;
			v.push_back(f);
		}
	}
	sort(v.begin(), v.end(), cmp);
	cout << v.size() << endl;
	for (i = 0; i < v.size(); i++)
		printf("%04d %d %.3f %.3f\n", v[i].id, v[i].size, v[i].estate, v[i].area);
	return 0;
}
