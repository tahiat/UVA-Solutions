#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define valid(nx,ny) nx>=0 && nx<R && ny>=0 && ny<C
#define size 101
int R, C, M, N, T,W,Even,Odd;
int Grid[size][size],Visited[size][size];
int fx[8];
int fy[8]; 
void initGrid(){
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			Grid[i][j] = 0;
			Visited[i][j] = 0;
		}
	}
}
void printoutput(){
	printf("Case %d: %d %d\n",T,Even,Odd);
}
void dfs(int x,int y){
	int i, j, nx, ny;
	if (Visited[x][y])return;
	Visited[x][y] = 1;
	for (i = 0; i < 8; i++){
		nx = x + fx[i];
		ny = y + fy[i];
		if (valid(nx, ny) && Grid[nx][ny] != -1 ){
			++Grid[x][y];
			dfs(nx, ny);
		}
	}
}
void solution(){
	Even = 0;
	Odd = 0;
	dfs(0, 0);
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (Grid[i][j] > 0){
				if (Grid[i][j] % 2 == 0)
					Even++;
				else
					Odd++;
			}
		}
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	int t,x,y;
	cin >> t;
	for (T = 1; T <= t; T++){
		cin >> R >> C >> M >> N;
		
		fx[0] = -N;
		fx[1] = N;
		fx[2] = -N;
		fx[3] = N;
		fx[4] = -M;
		fx[5] = -M;
		fx[6] = M;
		fx[7] = M;
		
		fy[0] = M;
		fy[1] = M;
		fy[2] = -M;
		fy[3] = -M;
		fy[4] = -N;
		fy[5] = N;
		fy[6] =-N;
		fy[7] = N;
		
		initGrid();
		cin >> W;
		for (int i = 1; i <= W; i++)
		{
			cin >> x >> y;
			Grid[x][y] = -1;
		}
		solution();
		printoutput();
	}
}