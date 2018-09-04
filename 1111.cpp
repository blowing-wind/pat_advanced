#include <iostream>
#include <vector>
using namespace std;

const int inf = 999999999;
int Length[500][500], Time[500][500];
int N, M, src, dst;

vector<int> shortestPath(int& l);
vector<int> fastestPath(int& t);
int findMinDist(bool collect[], int dist[]);
bool cmp(vector<int> a, vector<int> b);
void print(vector<int> p);

int main()
{
	cin >> N >> M;
	fill(Length[0], Length[0] + 500 * 500, inf);
	fill(Time[0], Time[0] + 500 * 500, inf);
	int v, w, o, l, t, i;
	for (i = 0; i < M; i++)
	{
		cin >> v >> w >> o >> l >> t;
		Length[v][w] = l;
		Time[v][w] = t;
		if (o == 0)
		{
			Length[w][v] = l;
			Time[w][v] = t;
		}
	}
	cin >> src >> dst;
	vector<int> p1 = shortestPath(l);
	vector<int> p2 = fastestPath(t);
	if (cmp(p1, p2))
	{
		printf("Distance = %d; Time = %d: ", l, t);
		print(p1);
	}
	else
	{
		printf("Distance = %d: ", l);
		print(p1);
		printf("Time = %d: ", t);
		print(p2);
	}
	return 0;
}

vector<int> shortestPath(int& l)
{
	int dist[500], time[500], path[500];
	bool collect[500] = {};
	fill(dist, dist + 500, inf);
	fill(time, time + 500, inf);
	fill(path, path + 500, -1);
	dist[src] = time[src] = 0;
	while (true)
	{
		int v = findMinDist(collect, dist);
		if (v == dst) break;
		collect[v] = true;
		for (int w = 0; w < N; w++)
		{
			if (Length[v][w] < inf)
			{
				if (dist[v] + Length[v][w] < dist[w])
				{
					dist[w] = dist[v] + Length[v][w];
					time[w] = time[v] + Time[v][w];
					path[w] = v;
				}
				else if (dist[v] + Length[v][w] == dist[w])
				{
					if (time[v] + Time[v][w] < time[w])
					{
						time[w] = time[v] + Time[v][w];
						path[w] = v;
					}
				}
			}
		}
	}
	l = dist[dst];
	vector<int> vec;
	int p = dst;
	while (p != -1)
	{
		vec.push_back(p);
		p = path[p];
	}
	return vec;
}

vector<int> fastestPath(int& t)
{
	int cnt[500], time[500], path[500];
	bool collect[500] = {};
	fill(cnt, cnt + 500, 0);
	fill(time, time + 500, inf);
	fill(path, path + 500, -1);
	cnt[src] = time[src] = 0;
	while (true)
	{
		int v = findMinDist(collect, time);
		if (v == dst) break;
		collect[v] = true;
		for (int w = 0; w < N; w++)
		{
			if (Time[v][w] < inf)
			{
				if (time[v] + Time[v][w] < time[w])
				{
					time[w] = time[v] + Time[v][w];
					cnt[w] = cnt[v] + 1;
					path[w] = v;
				}
				else if (time[v] + Time[v][w] == time[w])
				{
					if (cnt[v] + 1 < cnt[w])
					{
						cnt[w] = cnt[v] + 1;
						path[w] = v;
					}
				}
			}
		}
	}
	t = time[dst];
	vector<int> vec;
	int p = dst;
	while (p != -1)
	{
		vec.push_back(p);
		p = path[p];
	}
	return vec;
}

int findMinDist(bool collect[], int dist[])
{
	int minV = -1, min = inf;
	for (int v = 0; v < N; v++)
	{
		if (!collect[v] && dist[v] < min)
		{
			min = dist[v];
			minV = v;
		}
	}
	return minV;
}

bool cmp(vector<int> a, vector<int> b)
{
	if (a.size() != b.size()) return false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}

void print(vector<int> p)
{
	for (int i = p.size() - 1; i > 0; i--)
		printf("%d -> ", p[i]);
	printf("%d\n", p[0]);
}
