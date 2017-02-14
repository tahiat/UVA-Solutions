#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 101
int N;
int Path[size][size],Visited[size],Ans;
void initpath(){
	int i, j;
	for (i = 0; i <= N; i++){
		for (j = 0; j <= N; j++)
		{
			Path[i][j] = 0;
		}
	}
}
void initvisited(){
	for (int i = 1; i <= N; i++)
		Visited[i] = 0;
}
void fill(int x){
	int i, y;
	Visited[x] = 1;
	for (y = 1; y <= N; y++)if (Path[x][y] && Visited[y] == 0)
		fill(y);
}
int checkCritical(int x){
	int y;
	initvisited();
	Visited[x] = 1;
	for (y = 1; y <= N; y++)if (Path[x][y])
	{
		fill(y);
		break;
	}
	for (y = 1; y <= N; y++)if (Path[x][y] && Visited[y] == 0)
		return 1;
	return 0;
}
int main(){
	int p;
	//freopen("input.txt", "r", stdin);
	char a;
	int x,y;
	while (cin >> N){
		if (N == 0)
			break;
		initpath();
		while (cin >> x){
			if (x == 0)break;
			while (2 == scanf("%d%c", &y, &a)){
				Path[x][y] = Path[y][x] = 1;
				if (a == '\n')break;
				
			}
		}
		Ans = 0;
		for (int i = 1; i <= N; i++){
			Ans+= checkCritical(i);
		}
		printf("%d\n", Ans);
	}
}