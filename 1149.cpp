#include <bits/stdc++.h>
using namespace std;

int stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, cnt = 0;

int num(int x){
	int ans = 0;
	if (x == 0) return 6;
	while(x > 0)
	{
		ans += stick[x % 10];
		x /= 10;
	}
	return ans;
}

int main(){
	cin >> n;
	n -= 4;
	for (int i = 0; i < 1000; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			if (num(i) + num(j) + num(i + j) == n)
			{
				++cnt;
			}
		}
	}
	cout << cnt;
	return 0;
}
