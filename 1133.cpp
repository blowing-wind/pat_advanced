#include <iostream>
#include <vector>
using namespace std;

int Next[100000], Data[100000];
struct node
{
	int add, data;
};

int main()
{
	int first, N, K;
	int a, d, n, i;
	cin >> first >> N >> K;
	for (i = 0; i < N; i++)
	{
		cin >> a >> d >> n;
		Next[a] = n;
		Data[a] = d;
	}
	vector<node> v(N), v2;
	int cnt = 0;
	while (first != -1)
	{
		v[cnt].add = first;
		v[cnt].data = Data[first];
		first = Next[first];
		cnt++;
	}
	for (i = 0; i < cnt; i++)
	{
		if (v[i].data < 0)
			v2.push_back(v[i]);
	}
	for (i = 0; i < cnt; i++)
	{
		if (v[i].data >= 0 && v[i].data <= K)
			v2.push_back(v[i]);
	}
	for (i = 0; i < cnt; i++)
	{
		if (v[i].data > K)
			v2.push_back(v[i]);
	}
	for (i = 0; i < cnt; i++)
	{
		printf("%05d %d", v2[i].add, v2[i].data);
		if (i != cnt - 1)
			printf(" %05d\n", v2[i + 1].add);
		else
			printf(" -1\n");
	}
	return 0;
}
