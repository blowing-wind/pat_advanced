#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

double P, r;
vector<vector<int>> G;
void func(int root, double &sum, int depth);

int main()
{
	int N;
	cin >> N >> P >> r;
	G.resize(N);
	r = 1.0 + r / 100;
	int K, i, j, t;
	for (i = 0; i < N; i++)
	{
		cin >> K;
		G[i].push_back(K);
		if (K > 0)
		{
			for (j = 0; j < K; j++)
			{
				cin >> t;
				G[i].push_back(t);
			}
		}
		else 
		{
			cin >> t;
			G[i].push_back(t);
		}
	}
	double sum = 0.0;
	func(0, sum, 0);
	printf("%.1lf", sum);
	return 0;
}

void func(int root, double &sum, int depth)
{
	if (G[root][0] == 0)
	{
		sum += P * pow(r, depth) * G[root][1];
		return;
	}
	for (int i = 1; i < G[root].size(); i++)
		func(G[root][i], sum, depth + 1);
}
