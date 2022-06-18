/*
ID: afrank21
LANG: C++
TASK: sprime
*/
#include <bits/stdc++.h>
using namespace std;

int n;

bool prime(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

void dfs(int a, int k)
{
    //Exit
    if (k == n)
    {
        cout << a << endl;
        return;
    }
    else
    {
        for (int i = 1; i < 10; i += 2)
        {
            if (prime(a * 10 + i))
            {
                dfs(a * 10 + i, k + 1);
            }
        }
    }
}

int main()
{
//    freopen("sprime.in", "r", stdin);
//    freopen("sprime.out", "w", stdout);
    //Input
    cin >> n;
    dfs(2, 1); dfs(3, 1); dfs(5, 1); dfs(7, 1);
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}