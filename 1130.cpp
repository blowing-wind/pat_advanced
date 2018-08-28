#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
	string data;
	int left, right;
};
vector<Node> v;

void inOrder(int root, string &s, bool isRoot);

int main()
{
	int N, i, root;
	cin >> N;
	v.resize(N + 1);
	vector<bool> isRoot(N + 1, true);
	for (i = 1; i <= N; i++)
	{
		cin >> v[i].data >> v[i].left >> v[i].right;
		if (v[i].left > 0) isRoot[v[i].left] = false;
		if (v[i].right > 0) isRoot[v[i].right] = false;
	}
	for (i = 1; i <= N; i++)
	{
		if (isRoot[i]) root = i;
	}
	string ans;
	inOrder(root, ans, true);
	cout << ans;
	return 0;
}

void inOrder(int root, string &s, bool isRoot)
{
	if (root == -1) return;
	if (!isRoot && (v[root].left != -1 || v[root].right != -1))
		s += "(";
	inOrder(v[root].left, s, false);
	s += v[root].data;
	inOrder(v[root].right, s, false);
	if (!isRoot && (v[root].left != -1 || v[root].right != -1))
		s += ")";
}
