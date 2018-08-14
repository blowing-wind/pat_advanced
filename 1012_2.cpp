#include <iostream>
#include <map>
using namespace std;

struct grade
{
	int s[4];
};

int cnt[4][101];
int cnt2[4][101];

int main()
{
	int n, m;
	cin >> n >> m;
	map<int, grade> mapp;
	
	int id, i, j;
	grade g;
	for (i = 0; i < n; i++)
	{
		cin >> id;
		g.s[0] = 0;
		for (j = 1; j < 4; j++)
		{
			cin >> g.s[j];
			g.s[0] += g.s[j];
			cnt[j][g.s[j]]++;
		}
		g.s[0] = g.s[0] / 3.0 + 0.5;
		cnt[0][g.s[0]]++;
		mapp[id] = g;
	}

	for (i = 0; i < 4; i++)
	{
		cnt2[i][100] = 1;
		for (j = 99; j >= 0; j--)
			cnt2[i][j] = cnt2[i][j + 1] + cnt[i][j + 1];
	}
	int min, s, t;
	char arr[4] = { 'A', 'C', 'M', 'E' };
	for (i = 0; i < m; i++)
	{
		min = 3000;
		cin >> id;
		if (mapp.find(id) == mapp.end())
		{
			cout << "N/A" << endl;
			continue;
		}
		for (j = 0; j < 4; j++)
		{
			t = cnt2[j][mapp[id].s[j]];
			if ( t < min)
			{
				min = t;
				s = j;
			}
		}
		cout << min << " " << arr[s] << endl;
	}
	return 0;
}