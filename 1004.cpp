#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> tree(101);

void createTree();
void dfs();
void dfs2(int root, int depth, int cnt[], int& maxDepth);

int main()
{
	cin >> n >> m;
	createTree();
	dfs();
	return 0;
}

void createTree()
{
	int id, k, child, i, j;
	for (i = 0; i < m; i++)
	{
		cin >> id >> k;
		for (j = 0; j < k; j++)
		{
			cin >> child;
			tree[id].push_back(child);
		}
	}
}

void dfs()
{
	int maxDepth = -1;
	int cnt[101] = {};
	
	dfs2(1, 1, cnt, maxDepth);
	for (int i = 1; i <= maxDepth; i++)
	{
		cout << cnt[i];
		if (i != maxDepth)
			cout << " ";
	}
}

void dfs2(int root, int depth, int cnt[], int& maxDepth)
{
	if (depth > maxDepth)
		maxDepth = depth;
	if (tree[root].size() == 0)
	{
		cnt[depth]++;
		return;
	}
	for (int i : tree[root])
		dfs2(i, depth + 1, cnt, maxDepth);
}