#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};
typedef struct Node *Tree;
Tree createTree(int post[], int b1, int e1, int in[], int b2, int e2);
void levelOrder(Tree T, vector<int>& v);

struct queue
{
	Tree data[31];
	int begin, end;
};
typedef struct queue *Queue;
void enQueue(Queue q, Tree T);
Tree deQueue(Queue q);
bool isEmpty(Queue q);

int main()
{
	int N, i;
	cin >> N;
	int post[30], in[30];
	for (i = 0; i < N; i++)
		cin >> post[i];
	for (i = 0; i < N; i++)
		cin >> in[i];
	Tree T = createTree(post, 0, N - 1, in, 0, N - 1);
	vector<int> v;
	levelOrder(T, v);
	cout << v[0];
	for (i = 1; i < v.size(); i++)
		cout << " " << v[i];
	return 0;
}

Tree createTree(int post[], int b1, int e1, int in[], int b2, int e2)
{
	if (b1 > e1)
		return NULL;
	Tree T = new Node;
	T->data = post[e1];
	int p;
	for (p = b2; p <= e2; p++)
	{
		if (in[p] == post[e1])
			break;
	}
	int c = p - b2 - 1;
	T->left = createTree(post, b1, b1 + c, in, b2, p - 1);
	T->right = createTree(post, b1 + c + 1, e1 - 1, in, p + 1, e2);
	return T;
}

void levelOrder(Tree T, vector<int>& v)
{
	Queue q = new queue;
	q->begin = q->end = 0;
	enQueue(q, T);
	while (!isEmpty(q))
	{
		Tree temp = deQueue(q);
		v.push_back(temp->data);
		if (temp->left != NULL)
			enQueue(q, temp->left);
		if (temp->right != NULL)
			enQueue(q, temp->right);
	}
}

void enQueue(Queue q, Tree T)
{
	q->data[q->end++] = T;
}
Tree deQueue(Queue q)
{
	return q->data[q->begin++];
}
bool isEmpty(Queue q)
{
	return q->begin == q->end;
}