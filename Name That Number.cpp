/*
ID: afrank21
LANG: C++
TASK: namenum
*/
#include <bits/stdc++.h>
using namespace std;

string n;
vector<string> Dict;
const string trans = "2223334445556667 77888999";

int main()
{
//	freopen("namenum.in", "r", stdin);
//	freopen("namenum.out", "w", stdout);
	ifstream in("dict.txt");
	cin >> n;
	int len = n.length();
	string tmp;
	while (in >> tmp)
	{
		Dict.push_back(tmp);
	}

	bool jdg = false;
	for (int i = 0; i < Dict.size(); i++)
	{
		if (Dict[i].length() != len) continue;
		bool t = true;
		for (int j = 0; j < len; j++)
		{
			if (trans[Dict[i][j] - 'A'] != n[j])
			{
				t = false;
				break;
			}
		}
		if (t)
		{
			cout << Dict[i] << endl;
			jdg = true;
		}
	}
	if (!jdg)
	{
		cout << "NONE" << endl;
	}
	in.close();
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}