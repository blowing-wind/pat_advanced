#include <iostream>
using namespace std;

int main()
{
	int k, i, t;
	int sum = 0, last = 0;
	cin >> k;
	for (i = 0; i < k; i++)
	{
		cin >> t;
		if (t > last)
			sum += (t - last) * 6;
		else
			sum += (last - t) * 4;
		last = t;
	}
	sum += k * 5;
	cout << sum;
	return 0;
}
