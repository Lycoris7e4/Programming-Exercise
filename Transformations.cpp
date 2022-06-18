/*
ID: afrank21
LANG: C++
TASK: transform
*/
#include <bits/stdc++.h>
using namespace std;

int N;
bool jdg = true;
char before[15][15], after[15][15], t[15][15];

void rotate() //旋转90度
{
	int tmp;
	for (int i = 0; i < (N + 1) / 2; i++) //第 i 层
	{
		for (int j = 0; j < N - 1 - 2 * i; j++) // 第 j 个
		{
			tmp = t[i][i + j];
			t[i][i + j] = t[N - 1 - i - j][i];
			t[N - 1 - i - j][i] = t[N - 1 - i][N - 1 - i - j];
			t[N - 1 - i][N - 1 - i - j] = t[i + j][N - 1 - i];
			t[i + j][N - 1 - i] = tmp;
		}
	}
}

void reflect() //水平翻转
{
	int tmp;
	for (int i = 0; i < N; i++) //第 i 列
	{
		for (int j = 0; j < N / 2; j++) //第 j 行
		{
			tmp = t[i][j];
			t[i][j] = t[i][N - 1 - j];
			t[i][N - 1 - j] = tmp;
		}
	}
}

bool Judge() //判断是否相同
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (t[i][j] != after[i][j])
				return false;
		}
	}
	return true;
}

void out() //输出
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << t[i][j];
		}
		cout << endl;
	}
}

int main()
{
//	freopen("transform.in", "r", stdin);
//	freopen("transform.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> before[i][j];
			t[i][j] = before[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> after[i][j];
			if (jdg && after[i][j] != before[i][j]) jdg = false;
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		rotate();
		if (Judge())
		{
			cout << i << endl;
			return 0;
		}
	}
	rotate();
	reflect();
	if (Judge())
	{
		cout << 4 << endl;
		return 0;
	}
	for (int i = 1; i <= 3; i++)
	{
		rotate();
		if (Judge())
		{
			cout << 5 << endl;
			return 0;
		}
	}
	if (jdg)
	{
		cout << 6 << endl;
	}
	cout << 7 << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}