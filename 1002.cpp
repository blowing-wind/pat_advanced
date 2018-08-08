#include <iostream>
#include <vector>
using namespace std;

void add(double c[]);

int main()
{
	double c[1001] = {};
	add(c);
	add(c);
	int i, cnt = 0;
	for (i = 0; i < 1001; i++)
	{
		if (c[i] != 0)
			cnt++;
	}
	cout << cnt;
	for (i = 1000; i >= 0; i--)
	{
		if (c[i] != 0)
			printf(" %d %.1f", i, c[i]);
	}
}

void add(double c[])
{
	int m, exp, i;
	double coe;
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> exp >> coe;
		c[exp] += coe;
	}
}