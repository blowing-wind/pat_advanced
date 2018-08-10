#include <iostream>
using namespace std;

int main()
{
	int i, j, m;
	double max, t, ans = 1;
	char c;
	for (i = 0; i < 3; i++)
	{
		max = -1;
		for (j = 0; j < 3; j++)
		{
			cin >> t;
			if (t > max)
			{
				max = t;
				m = j;
			}
		}
		ans *= max;
		if (m == 0) c = 'W';
		else if (m == 1) c = 'T';
		else c = 'L';
		if (i > 0) cout << " ";
		cout << c;
	}
	ans = (ans * 0.65 - 1) * 2;
	printf(" %.2f", ans);
	return 0;
}