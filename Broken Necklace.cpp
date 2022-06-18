/*
ID: afrank21
LANG: C++
TASK: beads
*/
#include <bits/stdc++.h>
using namespace std;

int N;
char beads[1000], tmp;
int l = 0, r = 0, w = 0, ans = 0;

int main()
{
//	freopen("beads.in", "r", stdin);
//	freopen("beads.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> beads[i];
		beads[N + i] = beads[i];
	}

	for (int i = 0; i < 2 * N; i++)
	{
		if (beads[i] == 'w')
		{
			r++, w++;
		}
		else if (beads[i] == tmp)
		{
			r++, w = 0;
		}
		else
		{
			ans = max(ans, l + r);
			l = r - w;
			r = w + 1;
			w = 0;
			tmp = beads[i];
		}
	}
	ans = max(ans, l + r);
	cout << min(ans, N) << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}