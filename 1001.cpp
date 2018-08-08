#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b, s;
	cin >> a >> b;
	char c;

	s = a + b;
	if (s < 0)
	{
		s = -s;
		c = '-';
	}
	else
	{
		c = '+';
	}

	vector<int> v;
	while (s > 999)
	{
		v.push_back(s % 1000);
		s /= 1000;
	}

	if (c == '-')
	{
		cout << c;
	}
	cout << s;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		printf(",%03d", v[i]);
	}
	return 0;
}