/*
ID: afrank21
LANG: C++
TASK: milk2
*/
#include <bits/stdc++.h>
using namespace std;

int N, ans1 = 0, ans2 = 0; //ans1: 至少一只、 ans2: 无
int l, r;
struct farmer_time
{
	int bg, ed; //开始 & 结束时间
}t[5005];

bool cmp(farmer_time a, farmer_time b)
{
	return a.bg < b.ed;
}

int main()
{
//	freopen("milk2.in", "r", stdin);
//	freopen("milk2.out", "w", stdout);
	cin >> N;
	for (register int i = 0; i < N; i++)
	{
		cin >> t[i].bg >> t[i].ed;
	}
	sort(t, t + N, cmp);
	l = t[0].bg, r = t[0].ed;
	for (register int i = 1; i < N; i++)
	{
		if (t[i].bg <= r)
		{
			r = max(r, t[i].ed);
		}
		else
		{
			ans1 = max(ans1, r - l);
			ans2 = max(ans2, t[i].bg - r);
			l = t[i].bg, r = t[i].ed;
		}
	}
	ans1 = max(ans1, r - l);
	printf("%d %d\n", ans1, ans2);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}