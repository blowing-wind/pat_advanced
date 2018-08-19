#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> post, in, level(100000, -1);
void getLevel(int root, int begin, int end, int index);

int main()
{
	int N, i;
	cin >> N;
	post.resize(N);
	in.resize(N);
	for (i = 0; i < N; i++)
		cin >> post[i];
	for (i = 0; i < N; i++)
		cin >> in[i];
	getLevel(N - 1, 0, N - 1, 0);
	int cnt = 0;
	for (int i : level)
	{
		if (i != -1)
		{
			if (cnt > 0)
				cout << " ";
			cnt++;
			cout << i;
			if (cnt == N)
				break;
		}
	}
	return 0;
}

void getLevel(int root, int begin, int end, int index)
{
	if (begin > end) return;
	level[index] = post[root];
	int p;
	for (p = begin; p <= end; p++)
	{
		if (in[p] == post[root])
			break;
	}
	getLevel(root - end + p - 1, begin, p - 1, 2 * index + 1);
	getLevel(root - 1, p + 1, end, 2 * index + 2);
}