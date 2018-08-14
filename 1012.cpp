#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct grade
{
	int s[3];
	double A;
};
int cnt[3][101];
int cnt2[3][101];

int avgRank(vector<double> avg, double d);

int main()
{
	int n, m;
	cin >> n >> m;
	map<int, grade> mapp;
	vector<double> avg;

	int id, i, j;
	grade g;
	for (i = 0; i < n; i++)
	{
		cin >> id;
		g.A = 0;
		for (j = 0; j < 3; j++)
		{
			cin >> g.s[j];
			g.A += (double)g.s[j];
			cnt[j][g.s[j]]++;
		}
		g.A /= 3;
		cout << g.A << endl;
		avg.push_back(g.A);
		mapp[id] = g;
	}

	cnt2[0][100] = cnt2[1][100] = cnt2[2][100] = 1;
	for (i = 99; i >= 0; i--)
	{
		for (j = 0; j < 3; j++)
			cnt2[j][i] = cnt2[j][i + 1] + cnt[j][i + 1];
	}

	sort(avg.begin(), avg.end());

	int min, s, t;
	char arr[4] = { 'C', 'M', 'E', 'A' };
	for (i = 0; i < m; i++)
	{
		min = 3000;
		cin >> id;
		if (mapp.find(id) == mapp.end())
		{
			cout << "N/A" << endl;
			continue;
		}
		for (j = 0; j < 3; j++)
		{
			t = cnt2[j][mapp[id].s[j]];
			if ( t < min)
			{
				min = t;
				s = j;
			}
		}
		t = avgRank(avg, mapp[id].A);
		if (t <= min)
		{
			min = t;
			s = 3;
		}
		cout << min << " " << arr[s] << endl;
	}
	return 0;
}

int avgRank(vector<double> avg, double d)
{
	int mid = -1, i = 0, j = avg.size() - 1;
	while (i <= j)
	{
		mid = (i + j) / 2;
		if (d > avg[mid])
			i = mid + 1;
		else if (d == avg[mid])
			break;
		else
			j = mid - 1;
	}
	return avg.size() - mid;
}