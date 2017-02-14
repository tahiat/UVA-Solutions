#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 102
int N,M,Path[size][size],St,En;
void initpath(){
	int i, j;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (i == j)
			Path[i][j] = 0;
			else 
			Path[i][j] = 9999;
		}
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	int T,t,i,j,x,y,k;
	cin >> t;
	for (T = 1; T <= t; T++){
		cin >> N>>M;
		initpath();
		for (i = 1; i <= M; i++){
			cin >> x >> y;
			Path[x][y] = Path[y][x] = 1;
		}
		cin >> St >> En;
		for (k = 0; k < N; k++)
		{
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
				{
					if (Path[i][k] + Path[k][j] < Path[i][j])
						Path[i][j] = Path[i][k] + Path[k][j];
				}
			}
		}
		int Jog = 0,Max=0;
		for (i = 0; i < N; i++){
			Jog =  Path[St][i] + Path[i][En];	
			if (Jog > Max)
				Max = Jog;
		}
		printf("Case %d: %d\n", T, Max);
		
	}
}