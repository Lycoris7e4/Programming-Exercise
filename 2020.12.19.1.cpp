#include<bits/stdc++.h>
using namespace std;

int num[10];

int main()
{
	for (int i = 0; i < 7; i++)
	{
		cin >> num[i];
	}
	sort(num, num + 7);
	if (num[2] != num[0] + num[1])
	{
		cout << num[0] << " " << num[1] << " " << num[2];
	}
	else
	{
		cout << num[0] << " " << num[1] << " " << num[3];
	}
	return 0;
}