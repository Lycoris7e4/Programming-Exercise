#include <bits/stdc++.h>
using namespace std;

int n, flower[105];
int ans = 0;

bool jdg(int a, int b) //��ƽ�������棬���򷵻ؼ�
{
	double sum = 0;
	for (int i = a; i <= b; i++)
	{
		sum += flower[i];
	}
	double avg = sum / (b - a + 1);
	//cout << avg << endl;
	for (int i = a; i <= b; i++)
	{
		if (flower[i] == avg)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> flower[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (jdg(i, j))
			{
				++ans;
				//cout << i << " " << j << endl;
			}
		}
	}
	cout << ans + n;
	return 0;
}