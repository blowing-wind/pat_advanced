#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int left[20], right[20];
	int N, i, root;
	string l, r;
	cin >> N;
	bool notRoot[20] = {};
	for (i = 0; i < N; i++)
	{
		cin >> l >> r;
		if (l == "-") left[i] = -1;
		else
		{
			left[i] = stoi(l);
			notRoot[left[i]] = true;
		}
		if (r == "-") right[i] = -1;
		else
		{
			right[i] = stoi(r);
			notRoot[right[i]] = true;
		}
	}
	for (i = 0; i < N; i++)
	{
		if (!notRoot[i])
		{
			root = i;
			break;
		}
	}
	queue<int> q;
	q.push(root);
	bool hasEmpty = false, complete = true;
	int last;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		last = v;
		if (left[v] != -1)
		{
			q.push(left[v]);
			if (hasEmpty)
			{
				complete = false;
				break;
			}
		}
		else hasEmpty = true;
		if (right[v] != -1)
		{
			q.push(right[v]);
			if (hasEmpty)
			{
				complete = false;
				break;
			}
		}
		else hasEmpty = true;
	}
	if (!complete) printf("NO %d", root);
	else printf("YES %d", last);
	return 0;
}
