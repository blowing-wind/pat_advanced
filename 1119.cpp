#include <iostream>
#include <vector>
using namespace std;

int N, pre[30], post[30];
vector<int> in;

bool judge(int b1, int e1, int b2, int e2);

int main()
{
	int i;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> pre[i];
	for (i = 0; i < N; i++)
		cin >> post[i];
	if (judge(0, N - 1, 0, N - 1))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << in[0];
	for (i = 1; i < in.size(); i++)
		cout << " " << in[i];
	cout << endl;
	return 0;
}

bool judge(int b1, int e1, int b2, int e2)
{
	if (b1 == e1)
	{
		in.push_back(pre[b1]);
		return true;
	}
	int p;
	for (p = b2; p < e2 && post[p] != pre[b1 + 1]; p++);
	bool j1 = judge(b1 + 1, b1 + 1 + p - b2, b2, p);
	in.push_back(pre[b1]);
	if (p == e2 - 1) return false;
	bool j2 = judge(b1 + 2 + p - b2, e1, p + 1, e2 - 1);
	return j1 && j2;
}
