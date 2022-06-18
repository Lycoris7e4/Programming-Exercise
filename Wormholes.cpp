/*
ID: afrank21
LANG: C++
TASK: wormhole
*/
#include <bits/stdc++.h>
using namespace std;

int n, ans, t[20];
struct position
{
    int x, y;
}p[20];

bool cmp(position a, position b)
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

bool jdg(int k, int condition, int begin, int s)    //condition = 0 transfer; condition = 1 walk
{
    if (s != 1 && k == begin && condition == 1)
    {
        return true;
    }

    if (condition == 0)
    {
        if (p[k].y == p[k + 1].y)
        {
            return jdg(k + 1, 1, begin, s + 1);
        }
        else
        {
            return false;
        }
    }
    if (condition == 1)
    {
        return jdg(t[k], 0, begin, s + 1);
    }
}

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (jdg(i, 1, i, 1))
        {
            return true;
        }
    }
    return false;
}

void dfs(int x)
{
    //Output
    if (x == n + 1)
    {
        if (check())
        {
            ++ans;
        }
        return;
    }

    //Enumeration
    if (!t[x])
    {
        for (int i = x + 1; i <= n; i++)
        {
            if (!t[i])
            {
                t[i] = x; t[x] = i;
                dfs(x + 1);
                t[i] = t[x] = 0;
            }
        }
    }
    else
    {
        dfs(x + 1);
    }
    return;
}

int main()
{
    //Input
//  freopen("wormhole.in", "r", stdin);
//  freopen("wormhole.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }

    memset(t, 0, sizeof(t));
    sort(p + 1, p + n + 1, cmp);
    dfs(1);

    //Output
    cout << ans << endl;
//  fclose(stdin);
//  fclose(stdout);
    return 0;
}