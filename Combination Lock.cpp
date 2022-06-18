/*
ID: afrank21
LANG: C++
TASK: combo
*/
#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d, e, f;
int ans = 0;

int main()
{
//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);
    //Input
    cin >> n;
    cin >> a >> b >> c >> d >> e >> f;

    //Enumeration
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (((abs(i - a) <= 2 || abs(i - a) >= n - 2) &&
                    (abs(j - b) <= 2 || abs(j - b) >= n - 2) &&
                    (abs(k - c) <= 2 || abs(k - c) >= n - 2)) ||
                    ((abs(i - d) <= 2 || abs(i - d) >= n - 2) &&
                        (abs(j - e) <= 2 || abs(j - e) >= n - 2) &&
                        (abs(k - f) <= 2 || abs(k - f) >= n - 2)))
                {
                    ++ans;
                }
            }
        }
    }

    //Output
    cout << ans << endl;
//  fclose(stdin);
//  fclose(stdout);
    return 0;
}