/*
ID: afrank21
LANG: C++
TASK: friday
*/
#include <bits/stdc++.h>
using namespace std;

int N;
int t[10];
int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool leap(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0 && year % 400 != 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

int main()
{
//	freopen("friday.in", "r", stdin);
//	freopen("friday.out", "w", stdout);
	memset(t, 0, sizeof(t));
	cin >> N;
	int tmp = 6;
	for (int i = 0; i < N; i++) //年份1900 + i
	{
		for (int j = 0; j < 12; j++) //月份j + 1
		{
			if (j == 1)
			{
				if (leap(1900 + i))
					day[1] = 29;
				else
					day[1] = 28;
			}
			tmp = (tmp += day[j] % 7) % 7;
			t[tmp]++;
		}
	}
	t[tmp]--;
	cout << t[6] + 1 << " " << t[0];
	for (int i = 1; i <= 5; i++)
	{
		cout << " " << t[i];
	}
	cout << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}