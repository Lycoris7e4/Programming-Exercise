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
	int moo; //第 i 头奶牛一次循环后的位置
}pos[100005];
vector<int> cow[100005]; //第 i 头奶牛一轮循环能到达的位置

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

	for (int i = 1; i <= n; i++) //处理第 i 头奶牛
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