#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(10001, -1);

void _union(int a, int b);
int find(int a);

int main()
{
	int N, K, B, i, j, t;
	cin >> N;
	int num = -1;
	for (i = 0; i < N; i++)
	{
		cin >> K;
		for (j = 0; j < K; j++)
		{
			cin >> B;
			if (B > num) num = B;
			if (j > 0) _union(t, B);
			t = B;
		}
	}
	int cnt = 0;
	for (i = 1; i <= num; i++)
	{
		if (arr[i] < 0) cnt++;
	}
	cout << cnt << " " << num << endl;
	int Q, v, w;
	cin >> Q;
	for (i = 0; i < Q; i++)
	{
		cin >> v >> w;
		if (find(v) == find(w)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

void _union(int a, int b)
{
	int root1 = find(a);
	int root2 = find(b);
	if (root1 == root2) return;
	if (arr[root1] < arr[root2])
	{
		arr[root1] += arr[root2];
		arr[root2] = root1;
	}
	else
	{
		arr[root2] += arr[root1];
		arr[root1] = root2;
	}
}

int find(int a)
{
	while (arr[a] > 0)
	{
		a = arr[a];
	}
	return a;
}
