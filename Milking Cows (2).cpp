/*
ID: afrank21
LANG: C++
TASK: milk2
*/
#include <bits/stdc++.h>
using namespace std;

int n, l[5000], r[5000], maxi = 0, mini = 0, bg = 1000000, ed = 0;
int a[1000000] = { 0 };

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        if (bg >= l[i])
        {
            bg = l[i];
        }
        if (ed <= r[i])
        {
            ed = r[i] - 1;
        }
        for (int j = l[i]; j < r[i]; j++)
        {
            a[j]++;
        }
    }
    int tp = 0;
    int m = bg;
    while (true)
    {
        while (a[m] != 0)
        {
            tp++;
            m++;
            if (m > ed) break;
        }
        if (tp > maxi) maxi = tp;
        if (m > ed) break;
        tp = 0;
        while (a[m] == 0)
        {
            tp++;
            m++;
            if (m > ed) break;
        }
        if (tp > mini) mini = tp;
        if (m > ed) break;
        tp = 0;
    }
    cout << maxi << " " << mini << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}