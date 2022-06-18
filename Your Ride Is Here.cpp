/*
ID: afrank21
LANG: C++
TASK: ride
*/
#include <cstdio>
#include <iostream>
using namespace std;

char comet[10], group[10];
int pdtc = 1, pdtg = 1;

int chr(char c){
	return c - 64;
} 
 
int main(){
//	freopen("ride.in", "r", stdin);
//	freopen("ride.out", "w", stdout);
	cin >> comet >> group;
	for (int i = 0; i < strlen(comet); i++)
	{
		pdtc *= chr (comet[i]);
	}
	for (int j = 0; j < strlen(group); j++)
	{
		pdtg *= chr (group[j]);
	}
	if (pdtc % 47 == pdtg % 47) cout << "GO" << endl;
	else cout << "STAY" << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
