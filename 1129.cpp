#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt[50001], K;
bool inRecommendation[50001];
vector<int> recommendation;

void getRecommendation();
void compare(int t);
bool cmp(int a, int b);

int main()
{
	int N, i, t;
	cin >> N >> K;
	
	for (i = 0; i < N; i++)
	{
		cin >> t;
		if (i > 0)
		{
			cout << t << ":";
			getRecommendation();
		}
		cnt[t]++;
		if (recommendation.size() < K && !inRecommendation[t])
		{
			recommendation.push_back(t);
			inRecommendation[t] = true;
		}
		else if (recommendation.size() == K && !inRecommendation[t])
			compare(t);
		sort(recommendation.begin(), recommendation.end(), cmp);
	}
	return 0;
}

void getRecommendation()
{
	for (int i : recommendation)
		cout << " " << i;
	cout << endl;
}

bool cmp(int a, int b)
{
	if (cnt[a] != cnt[b]) return cnt[a] > cnt[b];
	else return a < b;
}

void compare(int t)
{
	int min = recommendation[recommendation.size() - 1];
	if (cmp(t, min))
	{
		inRecommendation[min] = false;
		recommendation[recommendation.size() - 1] = t;
		inRecommendation[t] = true;
	}
}
