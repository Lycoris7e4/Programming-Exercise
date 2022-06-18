#include <bits/stdc++.h>
using namespace std;

int n, m;
bool b[1000] = {0};

int main(){
	cin >> n >> m;
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (++t > n) t -= n;
			b[t] ? --j : 0;
		}
		cout << t << " ";
		b[t] = 1;
	}
	return 0;
} 
