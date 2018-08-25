#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Node *Tree;
struct Node
{
	int data;
	Tree left;
	Tree right;
};

Tree insert(Tree T, int data);
int getHeight(Tree T);
Tree LL(Tree T);
Tree LR(Tree T);
Tree RR(Tree T);
Tree RL(Tree T);
vector<int> levelOrder(Tree T, bool& isComplete);

int main()
{
	int N, i, t;
	cin >> N;
	Tree root = NULL;
	for (i = 0; i < N; i++)
	{
		cin >> t;
		root = insert(root, t);
	}
	bool isComplete;
	vector<int> v = levelOrder(root, isComplete);
	cout << v[0];
	for (i = 1; i < v.size(); i++)
		cout << " " << v[i];
	printf("\n%s", isComplete ? "YES" : "NO");
	return 0;
}

Tree insert(Tree T, int data)
{
	if (T == NULL)
	{
		T = new Node;
		T->data = data;
		T->left = T->right = NULL;
	}
	else if (data < T->data)
	{
		T->left = insert(T->left, data);
		if (getHeight(T->left) - getHeight(T->right) == 2)
		{
			if (data < T->left->data)
				T = LL(T);
			else
				T = LR(T);
		}
	}
	else
	{
		T->right = insert(T->right, data);
		if (getHeight(T->right) - getHeight(T->left) == 2)
		{
			if (data > T->right->data)
				T = RR(T);
			else
				T = RL(T);
		}
	}
	return T;
}

int getHeight(Tree T)
{
	if (T == NULL) return 0;
	int a = getHeight(T->left);
	int b = getHeight(T->right);
	return (a > b) ? (a + 1) : (b + 1);
}

Tree LL(Tree T)
{
	Tree tmp = T->left;
	T->left = tmp->right;
	tmp->right = T;
	return tmp;
}

Tree LR(Tree T)
{
	T->left = RR(T->left);
	return LL(T);
}

Tree RR(Tree T)
{
	Tree tmp = T->right;
	T->right = tmp->left;
	tmp->left = T;
	return tmp;
}

Tree RL(Tree T)
{
	T->right = LL(T->right);
	return RR(T);
}

vector<int> levelOrder(Tree T, bool& isComplete)
{
	vector<int> v;
	isComplete = true;
	queue<Tree> q;
	q.push(T);
	bool hasEmpty = false;
	while (!q.empty())
	{
		Tree T = q.front();
		q.pop();
		v.push_back(T->data);
		if (T->left != NULL)
		{
			q.push(T->left);
			//已经出现过空子树但是现在子树又不空，那么不是完全二叉树
			if (hasEmpty) isComplete = false;
		}
		else
			hasEmpty = true;
		if (T->right != NULL)
		{
			q.push(T->right);
			if (hasEmpty) isComplete = false;
		}
		else
			hasEmpty = true;
	}
	return v;
}
