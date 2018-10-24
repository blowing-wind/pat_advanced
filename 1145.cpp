#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> H;

bool isPrime(int a);
bool insert(int a);
int find(int a);

int main()
{
	int S, N, M;
	cin >> S >> N >> M;
	while (!isPrime(S)) S++;
	H.resize(S);
	int i, t, cnt;
	for (i = 0; i < N; i++)
	{
		cin >> t;
		if (!insert(t)) printf("%d cannot be inserted.\n", t);
	}
	int sum = 0;
	for (i = 0; i < M; i++)
	{
		cin >> t;
		sum += find(t);
	}
	printf("%.1lf", (double)sum / M);
	return 0;
}

bool isPrime(int a)
{
	if (a < 2) return false;
	int t = sqrt(a);
	for (int i = 2; i <= t; i++)
	{
		if (a % i == 0) return false;
	}
	return true;
}

bool insert(int a)
{
	int p, q = a % H.size(), cnt = 0;
	p = q;
	while (H[p])
	{
		cnt++;
		p = (q + cnt * cnt) % H.size();
		if (cnt == H.size()) break;
	}
	if (cnt == H.size()) return false;
	H[p] = a;
	return true;
}

int find(int a)
{
	int p, q = a % H.size(), cnt = 0;
	p = q;
	while (true)
	{
		cnt++;
		if (H[p] == a || H[p] == 0 || cnt == H.size() + 1) break;
		p = (q + cnt * cnt) % H.size();
	}
	return cnt;
}
