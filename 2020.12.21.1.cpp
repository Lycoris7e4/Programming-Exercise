#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int n, cnt = 0;
struct Edge
{
	int to, next;
}edge[maxn * 2];
int head[maxn];
int ans = 0;
bool vis[maxn];

void addEdge(int u, int v)
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = true;
		int tot = 1;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (vis[v]) continue;
			tot++;
			q.push(v);
		}
		int t = 1;
		while (t < tot)
		{
			t *= 2;
			++ans;
		}
		ans += tot - 1;
	}
}

int main()
{
	cin >> n;
	int u, v;
	fill(vis, vis + n + 1, false);
	fill(head, head + n + 1, -1);
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}
	bfs(1);
	cout << ans;
	return 0;
}