#include <bits/stdc++.h>
using namespace std;
const int maxn = 65540;

int a[maxn], b[maxn], c[maxn];
int maxi = 0;

int main()
{
	fill(a, a + maxn, 0);
	fill(b, b + maxn, 0);
	fill(c, c + maxn, 0);

	int n, k;
	cin >> n >> k;
	int year;
	for (int i = 0; i < n; i++)
	{
		cin >> year;
		a[year / 12]++;
		maxi = max(maxi, year / 12);
	}
	int t = 1;
	b[0] = 0;
	for (int i = 1; i <= maxi; i++)
	{
		if (a[i] != 0)
		{
			b[t] = i;
			t++;
		}
	}
	for (int i = 0; i < t; i++)
	{
		c[i] = abs(b[i + 1] - b[i]) - 1;
	}
	sort(c, c + t - 1);
	int ans = (t - 1) * 12;
	for (int i = 0; i < t - k; i++)
	{
		ans += c[i] * 12;
	}
	cout << ans;
	return 0;
}