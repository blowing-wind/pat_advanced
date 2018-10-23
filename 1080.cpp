#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int id, e, i, f;
	vector<int> v;
};

vector<int> quota;
vector<Node> stu;
vector<vector<int>> admission;

bool cmp(Node a, Node b)
{
	return (a.f != b.f) ? (a.f > b.f) : (a.e > b.e);
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	quota.resize(M);
	admission.resize(M);
	stu.resize(N);
	int i, j, t;
	for (i = 0; i < M; i++)
		cin >> quota[i];
	for (i = 0; i < N; i++)
	{
		stu[i].id = i;
		cin >> stu[i].e >> stu[i].i;
		stu[i].f = (stu[i].e + stu[i].i) / 2;
		for (j = 0; j < K; j++)
		{
			cin >> t;
			stu[i].v.push_back(t);
		}
	}
	sort(stu.begin(), stu.end(), cmp);
	int last = -1;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < K; j++)
		{
			t = stu[i].v[j];
			if (quota[t] > 0)
			{
				quota[t]--;
				admission[t].push_back(stu[i].id);
				last = t;
				break;
			}
			else if (t == last && stu[i].f == stu[i - 1].f && stu[i].e == stu[i - 1].e)
			{
				admission[t].push_back(stu[i].id);
				break;
			}
		}
	}
	for (i = 0; i < M; i++)
	{
		if (admission[i].size() != 0)
		{
			sort(admission[i].begin(), admission[i].end());
			cout << admission[i][0];
			for (j = 1; j < admission[i].size(); j++)
				cout << " " << admission[i][j];
		}
		cout << endl;
	}
	return 0;
}
