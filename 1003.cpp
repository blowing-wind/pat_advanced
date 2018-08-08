#include <iostream>
using namespace std;

int n, m, s, d;
int G[500][500], teamNumber[500];
const int maxValue = 999999999;

void createGraph();
void dijkstra();
int findMinDist(int dist[], bool collected[]);

int main()
{
	cin >> n >> m >> s >> d;
	createGraph();
	dijkstra();
	return 0;
}

void createGraph()
{
	int i, j, v, w, l;
	for (i = 0; i < n; i++)
		cin >> teamNumber[i];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			G[i][j] = maxValue;
	}
	for (i = 0; i < m; i++)
	{
		cin >> v >> w >> l;
		G[v][w] = l;
		G[w][v] = l;
	}
}

void dijkstra()
{
	int v, w;
	bool collected[500];
	int dist[500], num[500], team[500];
	
	for (v = 0; v < n; v++)
	{
		dist[v] = maxValue;
		team[v] = 0;
		collected[v] = false;
		num[v] = 0;
	}

	dist[s] = 0;
	team[s] = teamNumber[s];
	num[s] = 1;

	while (true)
	{
		v = findMinDist(dist, collected);
		if (v == d || v == -1)
			break;
		collected[v] = true;
		for (w = 0; w < n; w++)
		{
			//未被收录且和v相邻
			if (!collected[w] && G[v][w] < maxValue)
			{
				if (dist[v] + G[v][w] < dist[w])
				{
					dist[w] = dist[v] + G[v][w];
					team[w] = team[v] + teamNumber[w];
					num[w] = num[v];
				}
				else if (dist[v] + G[v][w] == dist[w])
				{
					num[w] += num[v];
					if (team[v] + teamNumber[w] > team[w])
						team[w] = team[v] + teamNumber[w];
				}
			}
		}
	}

	cout << num[d] << " " << team[d];
}

int findMinDist(int dist[], bool collected[])
{
	int minv, v; 
	int min = maxValue;

	for (v = 0; v < n; v++)
	{
		if (!collected[v] && dist[v] < min)
		{
			min = dist[v];
			minv = v;
		}
	}
	if (min == maxValue)
		return -1;
	return minv;
}