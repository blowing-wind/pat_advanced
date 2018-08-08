#include <iostream>
#include <vector>
using namespace std;

struct pol
{
	int exp;
	double coe;
};

void read(vector<pol> &v);
vector<pol> add(vector<pol> a, vector<pol> b);

int main()
{
	vector<pol> a, b, c;
	read(a);
	read(b); 
	c = add(a, b);
	cout << c.size();
	for (pol p : c)
		printf(" %d %.1f", p.exp, p.coe);
	return 0;
}

void read(vector<pol> &v)
{
	int k;
	pol p;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> p.exp >> p.coe;
		v.push_back(p);
	}
}

vector<pol> add(vector<pol> a, vector<pol> b)
{
	vector<pol> c;
	pol p;
	int i = 0, j = 0;
	while (i < a.size() && j < b.size())
	{
		if (a[i].exp < b[j].exp)
		{
			c.push_back(b[j]);
			j++;
		}
		else if (a[i].exp > b[j].exp)
		{
			c.push_back(a[i]);
			i++;
		}
		else
		{
			p.exp = a[i].exp;
			p.coe = a[i].coe + b[j].coe;
			i++;
			j++;
			if (p.coe == 0) continue;
			c.push_back(p);
		}
	}
	while (i < a.size())
	{
		c.push_back(a[i]);
		i++;
	}
	while (j < b.size())
	{
		c.push_back(b[j]);
		j++;
	}
	return c;
}