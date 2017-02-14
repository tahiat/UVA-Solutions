#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 51
#define valid(nx,ny) nx>=0 && nx<H && ny>=0 && ny<W
char Grid[size][size];
int Used[size][size];
int Sx, Sy;
int H, W;
int Ans;
int fx[] = { 0, 0, -1, 1 };
int fy[] = { 1, -1, 0, 0 };
void solve(int sx, int sy){
	int gold;
//printf("at (%d,%d)gold %d\n",sx,sy,Ans);
	int nx, ny;
	if (Grid[sx][sy] == 'G')
	{
		Ans += 1;
		Grid[sx][sy] = '.';
	}
	if (Grid[sx][sy + 1] == 'T' || Grid[sx + 1][sy] == 'T' || Grid[sx - 1][sy] == 'T' || Grid[sx][sy - 1] == 'T'){
		//Ans = gold;
		//printf("-----------\n");
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		nx = sx + fx[i];
		ny = sy + fy[i];
		if (valid(nx, ny) && Grid[nx][ny] != '#' && Used[nx][ny] == 0)
		{
			Used[nx][ny] = 1;
			solve(nx, ny);
			//Used[nx][ny] = 0;
		}
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	int i, j;
	while (cin >> W >> H){
		for (i = 0; i < H; i++){
			for (j = 0; j < W; j++){
				cin >> Grid[i][j];
				Used[i][j] = 0;
				if (Grid[i][j] == 'P')
				{
					Sx = i;
					Sy = j;
				}
			}	
		}
		Ans = 0;
		solve(Sx, Sy);
		cout << Ans << endl;
	}
}