#include <bits/stdc++.h>
using namespace std;

string word;

int main() {
	cin >> word;
	int k = 0;
	string result = "";
	while (k < word.length() - 1)
	{
		if (word[k] == 'A' && word[k + 1] != 'A')
		{
			result += word[k + 1];
			result += "A";
			k += 2;
		}
		else
		{
			result += word[k];
			k++;
		}
	}
	if (k < word.length()) result += word[k];
	cout << result << endl;
	return 0;
}