#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

void search(map<string, set<string>> &m, string t)
{
	if (m.find(t) == m.end())
		cout << "Not Found" << endl;
	else
	{
		for (string id : m[t])
			cout << id << endl;
	}
}

int main()
{
	int N, i, j;
	map<string, set<string>> title, author, key, publisher, year;
	string id, t;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
	{
		getline(cin, id);
		for (j = 0; j < 5; j++)
		{
			if (j != 2) getline(cin, t);
			if (j == 0) title[t].insert(id);
			else if (j == 1) author[t].insert(id);
			else if (j == 2)
			{
				while (cin >> t)
				{
					key[t].insert(id);
					char c = getchar();
					if (c == '\n') break;
				}
			}
			else if (j == 3) publisher[t].insert(id);
			else year[t].insert(id);
		}
	}
	int M, index;
	scanf("%d\n", &M);
	for (i = 0; i < M; i++)
	{
		getline(cin, t);
		cout << t << endl;
		index = t[0] - '0';
		t = t.substr(3);
		if (index == 1) search(title, t);
		else if (index == 2) search(author, t);
		else if (index == 3) search(key, t);
		else if (index == 4) search(publisher, t);
		else  search(year, t);
	}
	return 0;
}
