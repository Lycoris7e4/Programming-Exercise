/*
ID: afrank21
LANG: C++
TASK: numtri
*/
#include <bits/stdc++.h>
using namespace std;

int ans[1010], t[1010];
int r, n, imax = 0;

int main()
{
//    freopen("numtri.in", "r", stdin);
//    freopen("numtri.out", "w", stdout);
    cin >> n;
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            cin >> r;
            ans[j] = max(ans[j - 1], ans[j]) + r;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        ans[i] > imax ? imax = ans[i] : 0;
    }
    cout << imax << endl;
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}