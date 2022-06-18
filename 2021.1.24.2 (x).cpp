#include<bits/stdc++.h>
using namespace std;

int n, q;
int fence[100005] = { 0 };
int tmp[100005] = { 0 };
char c;
int mini = 100;

void init()
{
	for (int i = 1; i <= n; i++)
	{
		fence[i] = tmp[i];
	}
}

long long f(int l, int r)
{

}

int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> c;
		tmp[i] = c - 64;
	}
	
	int a, b;
	for (int i = 0; i < q; i++) //第 i 组数据
	{
		init();
		cin >> a >> b;
		for (int j = a; j <= b; j++)
		{
			fence[j] = 0;
		}

		if (a == 1)
			if (b == n)
				cout << 0 << endl;
			else
				cout << f(b + 1, n) << endl;
		else
			if (b == n)
				cout << f(1, a - 1) << endl;
			else
				cout << f(1, a - 1) + f(b + 1, n) << endl;
	}
	return 0;
}