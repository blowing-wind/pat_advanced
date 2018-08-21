#include <iostream>
#include <math.h>
using namespace std;

typedef struct Node *Tree;
struct Node
{
	int data;
	bool isRed;
	Tree left, right;
};

Tree insert(Tree T, int data);
bool judge(Tree T);
bool judge1(Tree T);
bool judge2(Tree T, int& cnt);

int main()
{
	int K, N;
	cin >> K;
	int i, j, t;
	for (i = 0; i < K; i++)
	{
		cin >> N;
		Tree root = NULL;
		for (j = 0; j < N; j++)
		{
			cin >> t;
			root = insert(root, t);
		}
		if (judge(root))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

Tree insert(Tree T, int data)
{
	if (T == NULL)
	{
		T = new Node;
		T->data = (data > 0) ? data : (-data);
		T->isRed = (data > 0) ? false : true;
		T->left = T->right = NULL;
	}
	else if (abs(data) < T->data)
		T->left = insert(T->left, data);
	else
		T->right = insert(T->right, data);
	return T;
}

bool judge(Tree T)
{
	int t;
	return !T->isRed && judge1(T) && judge2(T, t);
}

bool judge1(Tree T)
{
	if (T == NULL) return true;
	if (T->isRed)
	{
		if (T->left != NULL && T->left->isRed)
			return false;
		if (T->right != NULL && T->right->isRed)
			return false;
	}
	return judge1(T->left) && judge1(T->right);
}

bool judge2(Tree T, int& cnt)
{
	if (T == NULL)
	{
		cnt = 0;
		return true;
	}
	int r, l;
	bool b1 = judge2(T->left, l);
	bool b2 = judge2(T->right, r);
	if (!b1 || !b2 || l != r) return false;
	cnt = T->isRed ? r : (r + 1);
	return true;
}
