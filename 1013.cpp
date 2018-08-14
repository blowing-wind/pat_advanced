#include <iostream>
using namespace std;

int N, M, K;
int G[1001][1001];

int connectCnt(int city);
void dfs(int s, bool marked[]);

int main()
{
	int i, v, w, c;
	scanf("%d%d%d", &N, &M, &K);
	for (i = 0; i < M; i++)
	{
		scanf("%d%d", &v, &w);
		G[v][w] = 1;
		G[w][v] = 1;
	}
	for (i = 0; i < K; i++)
	{
		scanf("%d", &c);
		printf("%d\n", connectCnt(c));
	}
	return 0;
}

int connectCnt(int city)
{
	int v, cnt = 0;
	bool marked[1001] = {};
	marked[city] = true;
	for (v = 1; v <= N; v++)
	{
		if (!marked[v])
		{
			dfs(v, marked);
			cnt++;
		}
	}
	return cnt - 1;
}

void dfs(int s, bool marked[])
{
	marked[s] = true;
	for (int v = 1; v <= N; v++)
	{
		if (!marked[v] && G[s][v])
			dfs(v, marked);
	}
}