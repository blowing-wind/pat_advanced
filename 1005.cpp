#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int sum = 0;
	for (char c : s)
		sum += (c - '0');
	string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string s2 = to_string(sum);
	cout << arr[s2[0] - '0'];
	for (int i = 1; i < s2.size(); i++)
		cout << " " << arr[s2[i] - '0'];
	return 0;
}