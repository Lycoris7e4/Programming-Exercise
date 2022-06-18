/*
ID: afrank21
LANG: C++
TASK: skidesign
*/
#include <bits/stdc++.h>
using namespace std;

int n, h[2000];
int ans = 9999999999;

int main()
{
//  freopen("skidesign.in", "r", stdin);
//  freopen("skidesign.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    sort(h, h + n);
    for (int i = h[0]; i <= h[n - 1]; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (h[j] - i > 17)
            {
                sum += (h[j] - i - 17) * (h[j] - i - 17);
            }
            else if (h[j] < i)
            {
                sum += (i - h[j]) * (i - h[j]);
            }
        }
        ans = min(sum, ans);
    }

    //Output
    cout << ans << endl;
//  fclose(stdin);
//  fclose(stdout);
    return 0;
}