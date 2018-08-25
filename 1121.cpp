#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int N, M;
	cin >> N;
	vector<int> couple(100000, -1);
	bool party[100000] = {};
	int i, a, b;
	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		couple[a] = b;
		couple[b] = a;
	}
	cin >> M;
	vector<int> v(M);
	for (i = 0; i < M; i++)
	{
		cin >> v[i];
		party[v[i]] = true;
	}
	set<int> s;
	for (int a : v)
	{
		if (couple[a] >= 0 && party[couple[a]]) continue;
		s.insert(a);
	}
	cout << s.size() << endl;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		if (it != s.begin()) cout << " ";
		printf("%05d", *it);
	}
	return 0;
}
