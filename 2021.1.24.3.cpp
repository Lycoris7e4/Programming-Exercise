#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, ansa, ansb;
int a[maxn][maxn], sumA[maxn][2], sumB[maxn][2];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (j % 2) sumA[i][0] += a[i][j];
			else sumA[i][1] += a[i][j];
	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= n; i++)
			if (i % 2) sumB[j][0] += a[i][j];
			else sumB[j][1] += a[i][j];
	for (int i = 1; i <= n; i++){
		ansa += max(sumA[i][0], sumA[i][1]);
		ansb += max(sumB[i][0], sumB[i][1]);
	}
	printf("%d\n", max(ansa, ansb));
	return 0;
}