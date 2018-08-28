#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, i;
	cin >> N;
	vector<double> v(N);
	for (i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	for (i = 1; i < N; i++)
		v[i] = (v[i] + v[i - 1]) / 2.0;
	int ans = v[N - 1];
	cout << ans;
	return 0;
}
