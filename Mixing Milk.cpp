/*
ID: afrank21
LANG: C++
TASK: milk
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
struct farmer
{
    int p, a;
}l[5000];

bool compare(farmer& a, farmer& b)
{
    if (a.p != b.p)
        return a.p < b.p;
    else
        return a.a < b.a;
}

int main()
{
//  freopen("milk.in", "r", stdin);
//  freopen("milk.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> l[i].p >> l[i].a;
    }
    sort(l, l + m, compare);
    int k = 0;
    while (true)
    {
        if (n > l[k].a)
        {
            ans += l[k].p * l[k].a;
            n -= l[k].a;
        }
        else
        {
            ans += l[k].p * n;
            break;
        }
        k++;
    }
    cout << ans << endl;
//  fclose(stdin);
//  fclose(stdout);
    return 0;
}