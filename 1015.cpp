#include <iostream>
#include <math.h>
#include <string>
using namespace std;

bool isPrime(int a);
string toDRadix(int a, int d);
int toDecimal(string a, int d);

int main()
{
	int N, D;
	string s;
	while (true)
	{
		cin >> N;
		if (N < 0) break;
		cin >> D;
		if (!isPrime(N))
		{
			cout << "No" << endl;
			continue;
		}
		s = toDRadix(N, D);
		N = toDecimal(s, D);
		if (isPrime(N))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

bool isPrime(int a)
{
	if (a <= 1)
		return false;
	int i, t = sqrt(a);
	for (i = 2; i <= t; i++)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}

string toDRadix(int a, int d)
{
	string s;
	int b, c;
	if (a == 0) return "0";
	while (a)
	{
		b = a / d;
		c = a % d;
		s = to_string(c) + s;
		a = b;
	}
	return s;
}

int toDecimal(string a, int d)
{
	int i, sum = 0;
	for (i = 0; i < a.size(); i++)
		sum += (a[i] - '0') * pow(d, i);
	return sum;
}