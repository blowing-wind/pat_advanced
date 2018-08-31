#include <iostream>
#include <string>
using namespace std;

bool palindromic(string s);
string add(string s);

int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	bool isPalindromic = false;
	while (!(isPalindromic = palindromic(s)) && cnt < 10)
	{
		s = add(s);
		cnt++;
	}
	if (isPalindromic)
		printf("%s is a palindromic number.", s.c_str());
	else
		printf("Not found in 10 iterations.");
	return 0;
}

bool palindromic(string s)
{
	int t = s.size();
	for (int i = 0; i < t / 2; i++)
	{
		if (s[i] != s[t - i - 1]) return false;
	}
	return true;
}

string add(string s)
{
	string sum, s2;
	int i, p, q = 0;
	for (i = 0; i < s.size(); i++)
	{
		s2 = s[i] + s2;
		p = ((s[i] - '0') + (s[s.size() - i - 1] - '0') + q) % 10;
		sum = to_string(p) + sum;
		q = ((s[i] - '0') + (s[s.size() - i - 1] - '0') + q) / 10;
	}
	if (q > 0) sum = to_string(q) + sum;
	printf("%s + %s = %s\n", s.c_str(), s2.c_str(), sum.c_str());
	return sum;
}
