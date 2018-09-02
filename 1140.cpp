#include <iostream>
#include <string>
using namespace std;

string func(string s);

int main()
{
	int D, N;
	cin >> D >> N;
	string s = to_string(D);
	for (int i = 1; i < N; i++)
		s = func(s);
	cout << s;
	return 0;
}

string func(string s)
{
	int cnt = 1;
	string ans;
	s += "#";
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1]) cnt++;
		else
		{
			ans += s[i - 1];
			ans += to_string(cnt);
			cnt = 1;
		}
	}
	return ans;
}
