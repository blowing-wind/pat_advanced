#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, i;
	cin >> N;
	vector<int> vec(N);
	for (i = 0; i < N; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());

	if (N % 2 == 0) cout << 0;
	else cout << 1;
	int sum1, sum2;
	sum1 = sum2 = 0;
	for (i = 0; i < N / 2; i++)
		sum1 += vec[i];
	for (i = N / 2; i < N; i++)
		sum2 += vec[i];
	cout << " " << sum2 - sum1;
	return 0;
}
