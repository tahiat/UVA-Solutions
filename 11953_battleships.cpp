#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 101
#define valid(nx,ny) nx>=0 && nx<N && ny>=0 && ny<N 
int N,T,Ans;
char Ground[size][size];

void readinput(){
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Ground[i];
}
int fx[] = { -1, 1, 0, 0 };
int fy[] = { 0, 0, -1, 1 };
void solve(int x, int y){
	int nx, ny;
	for (int i = 0; i < 4; i++){         // one way of solution
		nx = x + fx[i];
		ny = y + fy[i];
		if (valid(nx,ny) && Ground[nx][ny]!='.'){
			Ground[nx][ny] = '.';
			solve(nx, ny);
		}
	}
	

}
void solveinput(){
	int i, j;
	Ans = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (Ground[i][j] == 'x'){
				solve(i, j);
				Ans++;
			}
		}
	}
}
void printoutput(){
	printf("Case %d: %d\n", T, Ans);
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (T = 1; T <= t; T++){
		readinput();
		solveinput();
		printoutput();
	}
}