#include <iostream>
#include <vector>
using namespace std;

void judge(vector<int> T);
void postOrder(vector<int> T, vector<int>& v, int root);

int main()
{
	int M, N, i, j;
	cin >> M >> N;
	for (i = 0; i < M; i++)
	{
		vector<int> T(N);
		for (j = 0; j < N; j++)
			cin >> T[j];
		judge(T);
	}
	return 0;
}

void judge(vector<int> T)
{
	int i, father;
	bool maxHeap, minHeap;
	maxHeap = minHeap = true;
	for (i = 1; i < T.size(); i++)
	{
		father = (i - 1) / 2;
		if (T[i] > T[father]) maxHeap = false;
		if (T[i] < T[father]) minHeap = false;
	}
	if (maxHeap) printf("Max Heap\n");
	else if (minHeap) printf("Min Heap\n");
	else printf("Not Heap\n");
	vector<int> post;
	postOrder(T, post, 0);
	cout << post[0];
	for (i = 1; i < post.size(); i++)
		cout << " " << post[i];
	cout << endl;
}

void postOrder(vector<int> T, vector<int>& v, int root)
{
	if (root >= T.size()) return;
	postOrder(T, v, 2 * root + 1);
	postOrder(T, v, 2 * root + 2);
	v.push_back(T[root]);
}
