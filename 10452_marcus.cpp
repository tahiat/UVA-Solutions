#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 50
char grid[size][size];
int T, R, C,Ans[size],Used[size][size],ptr;
int fx[] = { -1, 1, 0, 0 };
int fy[] = { 0, 0, -1, 1 };
void initused(){
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++)
		{
			Used[i][j] = 0;
		}
		Ans[i] = 0;
	}
}
void solve(int x, int y){
	int nx, ny;
	if (grid[x][y] == '#')
		return;
	Used[x][y] = 1;
	
	if (x - 1 >= 0 && Used[x - 1][y] == 0 && (grid[x-1][y]=='#'||grid[x - 1][y] == 'I' || grid[x - 1][y] == 'E' || grid[x - 1][y] == 'H' || grid[x - 1][y] == 'O' || grid[x - 1][y] == 'V' || grid[x - 1][y] == 'A'))
	{
		Ans[ptr++] = 1;
		solve(x - 1, y);
	}
	else if (y - 1 >= 0 && Used[x][y - 1] == 0 && (grid[x][y-1]=='#'||grid[x][y - 1] == 'I' || grid[x][y - 1] == 'E' || grid[x][y - 1] == 'O' || grid[x][y - 1] == 'H' || grid[x][y - 1] == 'V' || grid[x][y - 1] == 'A')){
		Ans[ptr++] = 2;
		solve(x, y - 1);
	}
	else if (y + 1 < C && Used[x][y + 1] == 0 && (grid[x][y+1]=='#'||grid[x][y + 1] == 'I' || grid[x][y + 1] == 'E' || grid[x][y + 1] == 'O' || grid[x][y + 1] == 'H' || grid[x][y + 1] == 'V' || grid[x][y + 1] == 'A')){
		Ans[ptr++] = 3;
		solve(x, y + 1);
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	int t,i,j,k;
	cin >> t;
	for (T = 1; T <= t; T++){
		initused();
		cin >> R >> C;
		for (int i = 0; i < R; i++)
			scanf("%s", grid[i]);
		ptr = 0;
		for (j = 0; j < C; j++){
			if (grid[R - 1][j] == '@')
				solve(R - 1, j);
		}
		for (int i = 0; i < ptr; i++)
		{
			if (Ans[i] == 1 && i == 0)
			{
				cout << "forth";
				continue;
			}
			else if (Ans[i] == 1 && i != 0)
			{
				cout << " forth";
				continue;
			}
			if (Ans[i] == 2 && i == 0)
			{
				cout << "left";
				continue;
			}
			else if (Ans[i] == 2 && i != 0)
			{
				cout << " left";
				continue;
			}
			if (Ans[i] == 3 && i == 0)
			{
				cout << "right";
				continue;
			}
			else if (Ans[i] == 3 && i != 0)
			{
				cout << " right";
				continue;
			}
		}
		cout << endl;
	}
}