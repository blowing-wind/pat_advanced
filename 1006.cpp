#include <iostream>
#include <string>

using namespace std;

struct T
{
	int h;
	int m;
	int s;
};

bool cmp(T a, T b);

int main()
{
	int m, i;
	cin >> m;
	string id, earlyId, lateId;
	T begin, end, early, late;

	late.h = late.m = late.s = 0;
	early.h = 23;
	early.m = early.s = 59;

	for (i = 0; i < m; i++)
	{
		cin >> id;
		scanf_s("%d:%d:%d %d:%d:%d", &begin.h, &begin.m, &begin.s, &end.h, &end.m, &end.s);
		if (cmp(begin, early))
		{
			early = begin;
			earlyId = id;
		}
		if (cmp(late, end))
		{
			late = end;
			lateId = id;
		}
	}
	cout << earlyId << " " << lateId;
	return 0;
}

bool cmp(T a, T b)
{
	if (a.h != b.h) return a.h < b.h;
	if (a.m != b.m) return a.m < b.m;
	return a.s < b.s;
}