#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Node
{
	string name;
	int d, h, m, time;
	bool on_off;
};

int toll[25];
bool cmp(Node a, Node b);
double billFromZero(Node a);

int main()
{
	int i, N, month;
	string s;
	Node node[1000];
	for (i = 0; i < 24; i++)
	{
		cin >> toll[i];
		toll[24] += toll[i];
	}
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> node[i].name;
		scanf_s("%d:%d:%d:%d", &month, &node[i].d, &node[i].h, &node[i].m);
		node[i].time = ((node[i].d * 24) + node[i].h) * 60 + node[i].m;
		cin >> s;
		node[i].on_off = (s == "on-line") ? true : false;
	}
	sort(node, node + N, cmp);
	map<string, vector<Node>> mapp;
	for (i = 1; i < N; i++)
	{
		if (node[i].name == node[i - 1].name && !node[i].on_off && node[i - 1].on_off)
		{
			mapp[node[i].name].push_back(node[i - 1]);
			mapp[node[i].name].push_back(node[i]);
		}
	}
	for (auto it : mapp)
	{
		vector<Node> v = it.second;
		cout << it.first;
		printf(" %02d\n", month);
		double t, sum = 0.0;
		for (i = 1; i < v.size(); i += 2)
		{
			printf("%02d:%02d:%02d %02d:%02d:%02d %d ", v[i - 1].d, v[i - 1].h, v[i - 1].m, v[i].d, v[i].h, v[i].m, v[i].time - v[i - 1].time);
			t = billFromZero(v[i]) - billFromZero(v[i - 1]);
			printf("$%.2f\n", t);
			sum += t;
		}
		printf("Total amount: $%.2f\n", sum);
	}
	return 0;
}

bool cmp(Node a, Node b)
{
	return (a.name != b.name) ? (a.name < b.name) : (a.time < b.time);
}

double billFromZero(Node a)
{
	double sum = a.d * toll[24] * 60 + a.m * toll[a.h];
	for (int i = 0; i < a.h; i++)
		sum += toll[i] * 60;
	return sum / 100;
}