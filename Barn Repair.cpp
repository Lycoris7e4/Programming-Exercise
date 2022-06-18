/*
ID: afrank21
LANG: C++
TASK: barn1
*/
#include <bits/stdc++.h>
using namespace std;

int m, s, c, ans;
int code[300], decode[300];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
//  freopen("barn1.in", "r", stdin);
//  freopen("barn1.out", "w", stdout);
    //Input
    cin >> m >> s >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> code[i];
    }
    sort(code, code + c);
    for (int i = 1; i < c; i++)
    {
        decode[i - 1] = code[i] - code[i - 1] - 1;
    }
    sort(decode, decode + c - 1, cmp);

    ans = code[c - 1] - code[0] + 1;
    for (int i = 0; i < m - 1; i++)
    {
        ans -= decode[i];
    }

    //Output
    cout << ans << endl;
//  fclose(stdin);
//  fclose(stdout);
    return 0;
}