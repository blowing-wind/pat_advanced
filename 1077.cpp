#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, i, j;
	scanf("%d\n", &N);
	string *s = new string[N];
	for (i = 0; i < N; i++)
		getline(cin, s[i]);
	i = 1;
	string ans;
	while (true)
	{
		char c = s[0][s[0].size() - i];
		bool flag = true;
		for (j = 1; j < N; j++)
		{
			char c2 = s[j][s[j].size() - i];
			if (i > s[j].size() || c2 != c)
			{
				flag = false;
				break;
			}
		}
		if (flag) ans = c + ans;
		else break;
		i++;
	}
	if (ans == "") cout << "nai";
	else cout << ans;
	return 0;
}
