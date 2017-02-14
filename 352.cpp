#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 25
int N, M;
int C=0;
char Grid[size][size];
void readcase(){
	int i;
	for (i = 0; i < M; i++)
		scanf("%s", Grid[i]);
}
void fill(int i, int j){
	Grid[i][j] = '0';
	if (i - 1 >= 0 && j - 1 >= 0 && '1' == Grid[i - 1][j - 1])
		fill(i - 1, j - 1);
	if (i - 1 >= 0 && '1' == Grid[i - 1][j])
		fill(i - 1, j);
	if (i - 1 >= 0 && j + 1< N && '1' == Grid[i - 1][j + 1])
		fill(i - 1, j + 1);
	if (j - 1 >= 0 && '1' == Grid[i][j - 1])
		fill(i, j - 1);
	if (j + 1<N && '1' == Grid[i][j + 1])
		fill(i, j + 1);
	if (i + 1<M && j - 1 >= 0 && '1' == Grid[i + 1][j - 1])
		fill(i + 1, j - 1);
	if (i + 1<M && '1' == Grid[i + 1][j])
		fill(i + 1, j);
	if (i + 1<M && j + 1<N && '1' == Grid[i + 1][j + 1])
		fill(i + 1, j + 1);
}
int Ans;
void solvecase(){
	int i, j;
	Ans = 0;
	for (i = 0; i < M; i++){
		for (j = 0; j < N; j++)
			if (Grid[i][j] == '1')
			{
				Ans++;
				fill(i, j);
			}

	}

}
void printcase(){
	C++;
	printf("Image number %d contains %d war eagles.\n",C, Ans);
}
int main(){
	int t;
	freopen("input.txt", "r", stdin);
	while (cin >> M){
		N=M;
		readcase();
		solvecase();
		printcase();
	}
	return 0;
}