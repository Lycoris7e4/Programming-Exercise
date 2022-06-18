#include<bits/stdc++.h>
using namespace std;

int n;
struct cows
{
	char d;
	int x, y;
}cow[55];
const string inf = "Infinity";

int jdg(int i) // ith Cow
{
	int ans = 1000000000;
	for (int j = 0; j < n; j++)
	{
		if (i == j || cow[i].d == cow[j].d) continue;
		if (cow[i].d == 'E') // East
		{
			if (cow[j].x < cow[i].x || cow[j].y > cow[i].y) continue;
			if (cow[j].x - cow[i].x > cow[i].y - cow[j].y && jdg(j) > cow[i].y - cow[j].y)
			{
				ans = min(cow[j].x - cow[i].x, ans);
			}
		}
		else if (cow[i].d == 'N') // North
		{
			if (cow[j].x > cow[i].x || cow[j].y < cow[i].y) continue;
			if (cow[j].y - cow[i].y > cow[i].x - cow[j].x && jdg(j) > cow[i].x - cow[j].x)
			{
				ans = min(cow[j].y - cow[i].y, ans);
			}
		}
	}
	return ans;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cow[i].d >> cow[i].x >> cow[i].y;
	}
	for (int i = 0; i < n; i++) // ith Cow
	{
		if (jdg(i) == 1000000000) cout << inf << endl;
		else cout << jdg(i) << endl;
	}
	return 0;
}
