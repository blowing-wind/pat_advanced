#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct student
{
	string id;
	int score, location, localRank;
};

bool cmp(student a, student b)
{
	if (a.score != b.score) return a.score > b.score;
	return a.id < b.id;
}

int main()
{
	int N, K, i, j;
	cin >> N;
	vector<student> rank;
	for (i = 1; i <= N; i++)
	{
		cin >> K;
		vector<student> v(K);
		for (j = 0; j < K; j++)
		{
			cin >> v[j].id >> v[j].score;
			v[j].location = i;
		}
		sort(v.begin(), v.end(), cmp);
		v[0].localRank = 1;
		rank.push_back(v[0]);
		for (j = 1; j < K; j++)
		{
			if (v[j].score == v[j - 1].score) v[j].localRank = v[j - 1].localRank;
			else v[j].localRank = j + 1;
			rank.push_back(v[j]);
		}
	}
	sort(rank.begin(), rank.end(), cmp);
	cout << rank.size() << endl;
	int final_rank = 1;
	printf("%s %d %d %d\n", rank[0].id.c_str(), final_rank, rank[0].location, rank[0].localRank);
	for (i = 1; i < rank.size(); i++)
	{
		if (rank[i].score != rank[i - 1].score) final_rank = i + 1;
		printf("%s %d %d %d\n", rank[i].id.c_str(), final_rank, rank[i].location, rank[i].localRank);
	}
	return 0;
}
