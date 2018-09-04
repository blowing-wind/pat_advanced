#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int N, i, j, cnt = 0;
	cin >> N;
	char a[50], b[50];
	double sum = 0.0;
	for (i = 0; i < N; i++)
	{
		double d;
		cin >> a;
		sscanf(a, "%lf", &d);
		sprintf(b, "%.2lf", d);
		bool flag = false;
		for (j = 0; j < strlen(a); j++)
		{
			if (a[j] != b[j]) flag = true;
		}
		if (flag || d < -1000 || d > 1000)
			printf("ERROR: %s is not a legal number\n", a);
		else
		{
			sum += d;
			cnt ++;
		}
	}
	if (cnt == 0) printf("The average of 0 numbers is Undefined");
	else if (cnt == 1) printf("The average of 1 number is %.2lf", sum);
	else printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
	return 0;
}
