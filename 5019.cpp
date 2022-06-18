#include <bits/stdc++.h>
using namespace std;

int n, d[100005];
long long cnt = 0;

int main(){
	cin >> n;
	memset(d, 0, sizeof d);
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
	}
	
	for (int i = 2; i <= n; i++)
	{
		if (d[i] > d[i - 1]) cnt += d[i] - d[i - 1];
	}
	
	cout << cnt + d[1];
	return 0;
}
