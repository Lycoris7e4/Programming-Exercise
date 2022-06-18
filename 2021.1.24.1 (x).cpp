#include<bits/stdc++.h>
using namespace std;

int n, cnt = 0;
struct Edge
{
	int to, next;
}edge[100005];
int head[100005];
struct position
{
	int a, b;
	int moo; //�� i ͷ��ţһ��ѭ�����λ��
}pos[100005];
vector<int> cow[100005]; //�� i ͷ��ţһ��ѭ���ܵ����λ��

void add_edge(int u, int v)
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int main()
{
	int k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> pos[i].a >> pos[i].b;
	}

	for (int i = 0; i <= n; i++) head[i] = -1;

	for (int i = 1; i <= n; i++) //����� i ͷ��ţ
	{
		pos[i].moo = i;
		cow[i].push_back(i);
		for (int j = 0; j < k; j++)
		{
			if (pos[j].a == pos[i].moo)
			{
				cow[i].push_back(pos[j].b);
				pos[i].moo = pos[j].b;
			}
			else if (pos[j].b == pos[i].moo)
			{
				cow[i].push_back(pos[j].a);
				pos[i].moo = pos[j].a;
			}
		}
	}
	
	for (int i = 1; i < n; i++)
	{
		add_edge(i, pos[i].moo);
	}
	return 0;
}