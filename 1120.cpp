#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int N, i, t;
	cin >> N;
	string s;
	set<int> num;
	for (i = 0; i < N; i++)
	{
		cin >> t;
		s = to_string(t);
		t = 0;
		for (char c : s)
			t += (c - '0');
		num.insert(t);
	}
	cout << num.size() << endl;
	for (auto it = num.begin(); it != num.end(); it++)
	{
		if (it != num.begin()) cout << " ";
		cout << *it;
	}
	return 0;
}
