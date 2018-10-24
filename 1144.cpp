#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<bool> v(N + 1);
	int i, t;
	for (i = 0; i < N; i++)
	{
		cin >> t;
		if (t <= N && t > 0) v[t] = true;
	}
	for (i = 1; i <= N; i++)
	{
		if (v[i] == false) break;
	}
	cout << i;
	return 0;
}
