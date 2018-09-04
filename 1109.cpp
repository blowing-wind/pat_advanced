#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct person
{
	string name;
	int height;
};

bool cmp(person a, person b)
{
	return (a.height != b.height) ? (a.height > b.height) : (a.name < b.name);
}

int main()
{
	int N, K, i;
	cin >> N >> K;
	vector<person> v(N);
	for (i = 0; i < N; i++)
		cin >> v[i].name >> v[i].height;
	sort(v.begin(), v.end(), cmp);
	vector<int> num(K, N / K);
	num[0] += N % K;
	for (i = 0; i < K; i++)
	{
		vector<string> v2(num[i]);
		int begin, end;
		if (i == 0) begin = 0;
		else begin = num[0] + num[1] * (i - 1);
		v2[num[i] / 2] = v[begin].name;
		int cnt = 1;
		while (cnt < num[i])
		{
			if (cnt % 2 == 1)
				v2[num[i] / 2 - (cnt + 1) / 2] = v[begin + cnt].name;
			else
				v2[num[i] / 2 + (cnt + 1) / 2] = v[begin + cnt].name;
			cnt++;
		}
		cout << v2[0];
		for (int j = 1; j < num[i]; j++)
			cout << " " << v2[j];
		cout << endl;
	}
	return 0;
}
