/*
ID: afrank21
LANG: C++
TASK: gift1
*/
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int NP; 
string t;
struct personal_data
{
	string name;
	int money;
	int number;
}p[15];

int jdg(string s){ //ÅÐ¶ÏÃû×ÖÐòºÅ 
	for (int i = 0; i < NP; i++)
	{
		if (s == p[i].name)
		{
			return i;
		}
	}
}

int main(){
//	freopen("gift1.in", "r", stdin);
//	freopen("gift1.out", "w", stdout);
	cin >> NP;
	for (int i = 0; i < NP; i++)
	{
		cin >> p[i].name;
	}
	for (int i = 0; i < NP; i++)
	{
		cin >> t;
		int a, b, n = jdg(t);
		cin >> a >> b;
		if (b == 0) continue;
		int tmp = (a / b);
		p[n].money -= tmp * b;
		for (int j = 0; j < b; j++)
		{
			cin >> t;
			n = jdg(t);
			p[n].money += tmp;
		}
	}
	for (int i = 0; i < NP; i++)
	{
		cout << p[i].name << " " << p[i].money << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
