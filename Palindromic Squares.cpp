/*
ID: afrank21
LANG: C++
TASK: palsquare
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 300;

int B;
int t[1000];
char A[12] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L' };

//Base convertion and Judge
bool base(int n, int B)
{
    //Convertion
    int i = 0;
    while (n != 0)
    {
        t[i++] = n % B;
        n /= B;
    }

    //Judge
    int x = 0, y = i - 1;
    while (x < y)
    {
        if (t[x] != t[y])
        {
            return false;
        }
        x++, y--;
    }
    return true;
}

//Convertion and Output
void output(int n, int B)
{
    //Convertion
    int i = 0;
    while (n != 0)
    {
        t[i++] = n % B;
        n /= B;
    }

    //Output
    for (int j = i - 1; j >= 0; --j)
    {
        if (t[j] >= 0 && t[j] <= 9)
        {
            cout << t[j];
        }
        else if (t[j] > 9)
        {
            cout << A[t[j] - 10];
        }
    }
}

int main()
{
//  freopen("palsquare.in", "r", stdin);
//  freopen("palsquare.out", "w", stdout);
    //Input
    cin >> B;

    int k = 1;
    while (k <= N)
    {
        if (base(k * k, B))
        {
            output(k, B);
            cout << " ";
            output(k * k, B);
            cout << endl;
        }
        k++;
    }
 // fclose(stdin);
 // fclose(stdout);
    return 0;
}