#include <iostream>
#include <vector>
using namespace std;

vector<int> pre, in;

int post(int begin, int end, int root);

int main()
{
	int N, i;
	cin >> N;
	pre.resize(N);
	in.resize(N);
	for (i = 0; i < N; i++)
		cin >> pre[i];
	for (i = 0; i < N; i++)
		cin >> in[i];
	cout << post(0, N - 1, 0);
	return 0;
}

int post(int begin, int end, int root)
{
	if (begin > end) return -1;
	int p;
	for (p = begin; p <= end; p++)
	{
		if (in[p] == pre[root]) break;
	}
	int left = post(begin, p - 1, root + 1);
	int right = post(p + 1, end, root + p - begin + 1);
	if (left > 0) return left;
	if (right > 0) return right;
	return pre[root];
}
