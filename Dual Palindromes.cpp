/*
ID: afrank21
LANG: C++
TASK: dualpal
*/
#include <bits/stdc++.h>
using namespace std;

int n, s;
int ans[20];//Record the answer
int c = 0;//count
int t[1000];

bool jdg(int num)
{
    int B = 2;//Base
    c = 0;

    //Judge (Base part)
    while (B <= 10)
    {
        //Convert
        int i = 0;
        int k = num;
        while (k != 0)
        {
            t[i++] = k % B;
            k /= B;
        }

        //Judge
        int x = 0, y = i - 1, j = 0;
        while (x < y)
        {
            if (t[x] != t[y])
            {
                j = 1;
                break;
            }
            x++, y--;
        }
        if (!j)
        {
            ++c;
        }
        ++B;
        memset(t, 0, sizeof(t));
    }

    //Judge (Final part)
    if (c >= 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
//  freopen("dualpal.in", "r", stdin);
//  freopen("dualpal.out", "w", stdout);
    //Input
    cin >> n >> s;

    //Judge
    int t = 0;
    ++s;
    while (t < n)
    {
        if (jdg(s))
        {
            ans[t++] = s;
        }
        ++s;
    }

    //Output
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
//  fclose(stdin);
//  fclose(stdout);
    return 0;
}