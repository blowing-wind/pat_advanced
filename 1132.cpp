#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	int N, i;
	cin >> N;
	string s;
	int z, a, b;
	for (i = 0; i < N; i++)
	{
		cin >> z;
		s = to_string(z);
		a = stoi(s.substr(0, s.size() / 2));
		b = stoi(s.substr(s.size() / 2));
		if (a == 0 || b == 0 || z % (a * b) != 0)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}
