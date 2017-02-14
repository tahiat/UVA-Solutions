#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 101
int T,N,K,Grid[size][size];
int Node[size];
void initgrid(){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			Grid[i][j] = 0;
		}
	}
}
int main(){
	int t,i,j,x,y;
	cin >> t;
	for (T = 1; T <= t; T++){
		cin >> N >> K;
		initgrid();
		for (i = 0; i < K; i++)
		{
			cin >> x >> y;
			Grid[x][y] = Grid[y][x]=1;
		}

	}
}