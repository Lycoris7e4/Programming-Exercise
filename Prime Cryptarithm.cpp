/*
ID: afrank21
LANG: C++
TASK: crypt1
*/
#include <bits/stdc++.h>
using namespace std;

int N, mini = 10;
int digit[20] = { 0 };
int ans = 0;

//������λ�ж�
bool jdg(int x)
{
	for (int i = 0; i < N; i++)
	{
		if (x == digit[i])
		{
			return true;
		}
	}
	return false;
}

//���ж�
bool JDG(int x)
{
	while (x > 0)
	{
		if (!jdg(x % 10)) return false;
		x /= 10;
	}
	return true;
}

int main()
{
//	freopen("crypt1.in", "r", stdin);
//	freopen("crypt1.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> digit[i];
		if (digit[i] < mini) mini = digit[i];
	}

	for (int a1 = 0; a1 < N; a1++) //��������λ������
	{
		for (int a2 = 0; a2 < N; a2++) //������ʮλ������
		{
			for (int a3 = 0; a3 < N; a3++) //��������λ������
			{
				for (int a4 = 0; a4 < N; a4++) //����ʮλ������
				{
					for (int a5 = 0; a5 < N; a5++) //������λ������
					{
						int a = digit[a1] * 100 + digit[a2] * 10 + digit[a3]; //������
						int b = digit[a4] * 10 + digit[a5]; //����
						if (a * b < 10000 && JDG(a * b) &&
							a * digit[a4] < 1000 && JDG(a * digit[a4]) &&
							a * digit[a5] < 1000 && JDG(a * digit[a5]))
						{
							++ans;
						}
					}
				}
			}
		}
	}

	cout << ans << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}