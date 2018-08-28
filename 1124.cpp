#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int M, N, S;
	cin >> M >> N >> S;
	int i, cnt = 0;
	string id;
	set<string> checked;
	bool begin = false; //从S开始计数
	for (i = 1; i <= M; i++)
	{
		cin >> id;
		if (i == S || cnt == N)
		{
			if (checked.find(id) == checked.end())
			{
				cout << id << endl;
				cnt = 1;
				checked.insert(id);
				begin = true;
			}
		}
		else if (begin)
			cnt++;
	}
	if (S > M) cout << "Keep going..." << endl;
	return 0;
}
