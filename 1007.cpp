#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int k, i;
	cin >> k;

	vector<int> v(k);
	bool allNegative = true;
	int begin, sum;
	int maxBegin, maxEnd, maxSum = -1;
	begin = sum = 0;

	for (i = 0; i < k; i++)
	{
		cin >> v[i];
		sum += v[i];
		if (sum > maxSum)
		{
			maxSum = sum;
			maxBegin = begin;
			maxEnd = i;
		}
			 
		if (sum < 0)
		{
			sum = 0;
			begin = i + 1;
		}
			
		if (v[i] >= 0)
			allNegative = false;
	}
	if (allNegative)
		printf("%d %d %d", 0, v[0], v[k - 1]);
	else
		printf("%d %d %d", maxSum, v[maxBegin], v[maxEnd]);
	return 0;
}
