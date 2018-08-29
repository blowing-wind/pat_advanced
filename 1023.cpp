#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool judge(vector<char> a, vector<char> b);

int main()
{
	int i, p, q = 0;
	string a, b;
	cin >> a;
	vector<char> v1, v2;
	for (i = a.size() - 1; i >= 0; i--)
	{
		v1.push_back(a[i]);
		p = ((a[i] - '0') * 2  + q) % 10;
		v2.push_back(p + '0');
		b = to_string(p) + b;
		q = ((a[i] - '0') * 2 + q) / 10;
	}
	if (q > 0)
	{
		v2.push_back(p + '0');
		b = to_string(q) + b;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	bool ans = judge(v1, v2);
	printf("%s\n%s", ans ? "Yes" : "No", b.c_str());
	return 0;
}

bool judge(vector<char> a, vector<char> b)
{
	if (a.size() != b.size()) return false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}
