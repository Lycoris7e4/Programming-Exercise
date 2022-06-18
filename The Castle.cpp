/*
ID: afrank21
LANG: C++
TASK: castle
*/
#include <bits/stdc++.h>

struct rooms
{
	bool west, north, east, south;
	int color;
}r[55][55];
int scale = 0;

//有墙为true, 0代表没有染色
void addWall(int i, int j, int t)
{
	t % 2 == 1 ? r[i][j].west = true : r[i][j].west = false;
	t /= 2;
	t % 2 == 1 ? r[i][j].north = true : r[i][j].north = false;
	t /= 2;
	t % 2 == 1 ? r[i][j].east = true : r[i][j].east = false;
	t /= 2;
	t % 2 == 1 ? r[i][j].south = true : r[i][j].south = false;
	r[i][j].color == 0;
}

//横纵坐标， 填充颜色
void floodfill(int xi, int yi, int c)
{
	if (r[xi][yi].color != c)
	{
		r[xi][yi].color == c;
		++scale;
	}
	else return;

	if (r[xi][yi].west == false)
	{
		floodfill(xi - 1, yi, c);
	}
	if (r[xi][yi].north == false)
	{
		floodfill(xi, yi - 1, c);
	}
	if (r[xi][yi].east == false)
	{
		floodfill(xi + 1, yi, c);
	}
	if (r[xi][yi].south == false)
	{
		floodfill(xi, yi + 1, c);
	}
	return;
}

int main()
{
	//Input and Add walls
	int m, n, tmp;
	std::cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			std::cin >> tmp;
			addWall(i, j, tmp);
		}
	}
	
	//Floodfill
	int tcolor = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (r[i][j].color == 0)
			{
				int t = scale;
				scale = 0;
				floodfill(i, j, tcolor);
				++tcolor;
				scale = std::max(t, scale);
			}
		}
	}

	printf("%d\n%d\n", tcolor - 1, scale);
	return 0;
}