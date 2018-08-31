#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct grade
{
	string id;
	int p = -1, m = -1, f = -1, total;
};
map<string, grade> stu;

void read(int num, int p);
bool cmp(grade a, grade b);

int main()
{
	int p, m, n, i;
	cin >> p >> m >> n;
	read(p, 1);
	read(m, 2);
	read(n, 3);
	vector<grade> v;
	for (auto it : stu)
	{
		string id = it.first;
		grade g = it.second;
		if (g.p < 200) continue;
		int total;
		if (g.m > g.f)
		{
			if (g.f == -1) total = (double)g.m * 0.4 + 0.5;
			else total = (double)g.m * 0.4 + (double)g.f * 0.6 + 0.5;
		}
		else
			total = g.f;
		if (total < 60) continue;
		g.total = total;
		g.id = id;
		v.push_back(g);
	}
	sort(v.begin(), v.end(), cmp);
	for (grade g : v)
		printf("%s %d %d %d %d\n", g.id.c_str(), g.p, g.m, g.f, g.total);
	return 0;
}

void read(int num, int p)
{
	string id;
	int grade;
	for (int i = 0; i < num; i++)
	{
		cin >> id >> grade;
		if (p == 1) stu[id].p = grade;
		else if (p == 2) stu[id].m = grade;
		else if (p == 3) stu[id].f = grade;
	}
}

bool cmp(grade a, grade b)
{
	if (a.total != b.total) return a.total > b.total;
	return a.id < b.id;
}
