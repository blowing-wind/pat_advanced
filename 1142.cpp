#include <iostream>
using namespace std;

bool G[201][201];
int Nv, Ne;

int main()
{
	int i, v, w;
	cin >> Nv >> Ne;
	for (i = 0; i < Ne; i++)
	{
		cin >> v >> w;
		G[v][w] = G[w][v] = true;
	}
	int M, K, t, j;
	cin >> M;
	for (i = 0; i < M; i++)
	{
		cin >> K;
		bool mark[201] = {};
		for (j = 0; j < K; j++)
		{
			cin >> t;
			mark[t] = true;
		}
		bool clique, flag, maximal;
		clique = maximal = true;
		for (v = 1; v <= Nv; v++)
		{
			if (mark[v])
			{
				for (w = v + 1; w <= Nv; w++)
				{
					if (mark[w] && !G[v][w]) clique = false;
				}
			}
			if (!clique) break;
			if (maximal && !mark[v])
			{
				flag = true;
				for (w = 1; w <= Nv; w++)
				{
					if (mark[w] && !G[v][w])
					{
						flag = false;
						break;
					}
				}
				if (flag == true) //oh my god!
					maximal = false;
			}
		}
		if (!clique) cout << "Not a Clique" << endl;
		else if (!maximal) cout << "Not Maximal" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
