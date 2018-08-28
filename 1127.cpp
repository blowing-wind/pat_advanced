#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, in[30], post[30];

typedef struct Node *Tree;
struct Node
{
	int data, depth;
	Tree left, right;
};

Tree createTree(Tree T, int begin, int end, int root, int depth);
vector<vector<int>> level(Tree T, int &maxDepth);

int main()
{
	int i, maxDepth;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> in[i];
	for (i = 0; i < N; i++)
		cin >> post[i];
	Tree T = NULL;
	T = createTree(T, 0, N - 1, N - 1, 0);
	vector<vector<int>> v = level(T, maxDepth);
	cout << T->data;
	for (i = 1; i <= maxDepth; i++)
	{
		if (i % 2 == 1)
		{
			for (int j : v[i])
				cout << " " << j;
		}
		else
		{
			for (int j = v[i].size() - 1; j >= 0; j--)
				cout << " " << v[i][j];
		}
	}
	return 0;
}

Tree createTree(Tree T, int begin, int end, int root, int depth)
{
	if (begin > end) return NULL;
	if (T == NULL)
	{
		T = new Node;
		T->depth = depth;
		T->data = post[root];
		T->left = T->right = NULL;
	}
	int p;
	for (p = begin; p <= end; p++)
	{
		if (in[p] == post[root]) break;
	}
	T->left = createTree(T->left, begin, p - 1, root - end + p - 1, depth + 1);
	T->right = createTree(T->right, p + 1, end, root - 1, depth + 1);
	return T;
}

vector<vector<int>> level(Tree T, int &maxDepth)
{
	maxDepth = -1;
	vector<vector<int>> v(N);
	queue<Tree> q;
	q.push(T);
	while (!q.empty())
	{
		Tree t = q.front();
		q.pop();
		if (t->depth > maxDepth) maxDepth = t->depth;
		v[t->depth].push_back(t->data);
		if (t->left != NULL) q.push(t->left);
		if (t->right != NULL) q.push(t->right);
	}
	return v;
}
