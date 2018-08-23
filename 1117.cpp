#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int N, i;
	cin >> N;
	vector<int> dist(N);
	for (i = 0; i < N; i++)
		cin >> dist[i];
	sort(dist.begin(), dist.end(), cmp);
	for (i = 0; i < N; i++)
	{
		if (dist[i] <= i + 1)
			break;
	}
	cout << i;
	return 0;
}
