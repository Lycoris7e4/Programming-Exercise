#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int n, grid[1005][1005];
int ans[maxn];

int main()
{
	//gridȫ����ʼ��Ϊ0
	for (int i = 0; i < 1005; i++)
	{
		for (int j = 0; j < 1005; j++)
		{
			grid[i][j] = 0;
		}
	}

	cin >> n;
	for (int i = 1; i <= n; i++) //�� i ������
	{
		int a, b;
		cin >> a >> b;
		grid[a][b]++;
		if (a - 1 >= 0) grid[a - 1][b]++;
		grid[a + 1][b]++;
		if (b - 1 >= 0) grid[a][b - 1]++;
		grid[a][b + 1]++;


		if (i < 4) continue;

	}

	return 0;
}