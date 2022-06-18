/*
ID: afrank21
LANG: C++
TASK: milk3
*/
#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int j[21][21][21], ans[21];

void f(int x, int y, int z)
{
    //Exit
    if (j[x][y][z])
        return;
    else
        j[x][y][z] = true;

    //Judge
    if (x == 0)
        ans[z] = true;

    //6 ways
    x + y > b ? f(x + y - b, b, z) : f(0, x + y, z); //a -> b
    x + y > a ? f(a, x + y - a, z) : f(x + y, 0, z); //b -> a
    x + z > c ? f(x + z - c, y, c) : f(0, y, x + z); //a -> c
    x + z > a ? f(a, y, x + z - a) : f(x + z, y, 0); //c -> a
    y + z > b ? f(x, b, y + z - b) : f(x, y + z, 0); //c -> b
    y + z > c ? f(x, y + z - c, c) : f(x, 0, y + z); //b -> c
}

int main()
{
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    //Input
    cin >> a >> b >> c;

    memset(j, false, sizeof(j));
    f(0, 0, c);

    bool flag = true;
    //Ouput
    for (int i = 0; i <= 20; i++)
    {
        if (ans[i] && flag)
        {
            cout << i;
            flag = false;
        }
        else if (ans[i])
        {
            cout << " " << i;
        }
    }
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}