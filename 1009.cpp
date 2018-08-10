#include <iostream>
#include <vector>
using namespace std;

struct pol
{
	int exp;
	double coe;
};

int main()
{
	int k1, k2, i, j;
	double mul[2001] = {};
	pol t;
	cin >> k1;
	vector<pol> v(k1);
	for (i = 0; i < k1; i++)
	{
		cin >> t.exp >> t.coe;
		v[i] = t;
	}

	cin >> k2;
	for (i = 0; i < k2; i++)
	{
		cin >> t.exp >> t.coe;
		for (j = 0; j < k1; j++)
			mul[t.exp + v[j].exp] += t.coe * v[j].coe;
	}

	int cnt = 0;
	for (i = 2000; i >= 0; i--)
	{
		if (mul[i] != 0.0)
			cnt++;
	}
	cout << cnt;
	for (i = 2000; i >= 0; i--)
	{
		if (mul[i] != 0.0)
			printf(" %d %.1f", i, mul[i]);
	}
	return 0;
}
