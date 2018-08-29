#include <iostream>
#include <string>
using namespace std;

bool judge(string s);
string add(string s);

int main()
{
	string N;
	int K, cnt = 0;
	cin >> N >> K;
	while (!judge(N) && cnt < K)
	{
		N = add(N);
		cnt++;
	}
	cout << N << endl << cnt;
	return 0;
}

bool judge(string s)
{
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i - 1]) return false;
	}
	return true;
}

string add(string s)
{
	string sum;
	int p, q, i;
	q = 0;
	for (i = 0; i < s.size(); i++)
	{
		p = ((s[i] - '0') + (s[s.size() - i - 1] - '0') + q) % 10;
		sum = to_string(p) + sum;
		q = ((s[i] - '0') + (s[s.size() - i - 1] - '0') + q) / 10;
	}
	if (q > 0) sum = to_string(q) + sum;
	return sum;
}
