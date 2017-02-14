#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 101
int N, M;
char Grid[size][size];
void readcase(){
	int i;
	for (i = 0; i < M; i++)
		scanf("%s", Grid[i]);
}
void fill(int i, int j){
	Grid[i][j] = '*';
	if (i-1>=0 && j-1>=0 && '@' == Grid[i-1][j-1])
	fill(i - 1, j - 1);
	if (i-1>=0 && '@' == Grid[i - 1][j])
	fill(i - 1, j);
	if (i-1>=0 && j+1< N && '@' == Grid[i - 1][j+1])
	fill(i - 1, j + 1);
	if (j-1>=0 && '@' == Grid[i][j - 1])
	fill(i, j - 1);
	if (j+1<N && '@' == Grid[i][j + 1])
	fill(i, j + 1);
	if (i+1<M && j-1>=0 && '@' == Grid[i + 1][j -1])
	fill(i + 1, j - 1);
	if (i+1<M && '@' == Grid[i + 1][j ])
	fill(i + 1, j);
	if (i+1<M && j+1<N && '@' == Grid[i + 1][j + 1])
	fill(i + 1, j + 1);
}
int Ans;
void solvecase(){
	int i, j;
	Ans = 0;
	for (i = 0; i < M; i++){
		for (j = 0; j < N; j++)
			if (Grid[i][j] == '@')
			{
				Ans++;
				fill(i, j);
			}

	}
	
}
void printcase(){
	cout << Ans << endl;
}
int main(){
	int t;
	freopen("input.txt", "r", stdin);
	while (cin >> M >> N){
		if (M == 0)break;
		readcase();
		solvecase();
		printcase();
	}
	return 0;
}