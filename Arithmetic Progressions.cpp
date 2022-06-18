/*
ID: afrank21
LANG: C++
TASK: ariprog
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
bool bkt[250 * 250 * 2 + 10];
int k = 0;

struct Arithmetic
{
    int x, y;
}ans[10010];

bool cmp(Arithmetic aa, Arithmetic bb)
{
    return aa.y < bb.y || (aa.y = bb.y && aa.x < bb.x);
}

int main()
{
//    freopen("ariprog.in", "r", stdin);
//    freopen("ariprog.out", "w", stdout);
    //Input
    cin >> n >> m;

    //Integrate
    for (int i = 0; i <= m; i++)
    {
        for (int j = i; j <= m; j++)
        {
            bkt[i * i + j * j] = true;
        }
    }

    //Enumeration
    int imax = m * m * 2;
    for (int i = 0; i <= imax; i++)
    {
        if (bkt[i])
        {
            for (int j = i + 1; j <= imax; j++)
            {
                if (bkt[j])
                {
                    int d = j - i;

                    //Cut the branches
                    int maxn = i + (n - 1) * d;
                    if (maxn > imax)
                    {
                        break;
                    }

                    bool j = true;
                    for (int t = i + d; t <= maxn; t += d)
                    {
                        if (!bkt[t])
                        {
                            j = false;
                            break;
                        }
                    }

                    if (j)
                    {
                        ans[k].x = i;
                        ans[k].y = d;
                        k++;
                    }
                }
            }
        }
    }

    //Output
    if (!k)
    {
        cout << "NONE" << endl;
    }
    else
    {
        sort(ans, ans + k, cmp);
        for (int i = 0; i < k; i++)
        {
            cout << ans[i].x << " " << ans[i].y << endl;
        }
    }
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}