#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 201 
char Grid[size][size];
int Used[size][size];
#define valid(nx,ny) nx>=0 && nx<N && ny>=0 && ny<N
int N,flag,T;
int fx[] = { -1, -1, 0, 0, 1, 1 };
int fy[] = { -1, 0, -1, 1, 0, 1 };
void initused(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Used[i][j] = 0;
}
void solve(int r, int c){
	//cout << c<<" ";
	int nx, ny,i;
	if (c == N - 1){
		flag = 1;
		//cout << endl;
		return;
	}
	if (flag == 1)
		return;
	Used[r][c] = 1;
	for (i = 0; i < 6; i++){
		nx = r + fx[i];
		ny = c + fy[i];
		if (valid(nx, ny)  && Used[nx][ny] == 0 && Grid[nx][ny]=='w'){
			solve(nx, ny);
		}
	}
}
void makesolution(){
	int i, j;
	flag = 0;
	initused();
	for (i = 0; i < N; i++){	// seracher in first colomn to find  white bolock
		if (Grid[i][0] == 'w'){
			solve(i, 0);
			//initused();
			if (flag == 1)
				break;
		}
	}
}
void printoutput(){
	if (flag == 0)
		cout << T++ << " " << "B" << endl;
	else
		cout << T++ << " " << "W" << endl;
}
int main(){
	freopen("input.txt", "r", stdin);
	int i, j;
	T = 1;
	while (cin >> N){
		if (N == 0)break;
		for (i = 0; i < N; i++)
			scanf("%s", Grid[i]);
		makesolution();
		printoutput();
	}
}