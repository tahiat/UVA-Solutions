#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 10
int Grid[size][size];
int used[size];
int N,T,Ans1,Ans2,A[size];
int col[size];
int Min,F_Min;
void initcol(){
	for (int i = 0; i < N; i++)
		col[i] = 0;
}
void initused(){
	for (int i = 0; i < N; i++)
		used[i] = 0;
}
void print(){
	int val=9999,c;

	for (int k = 0; k < N; k++){
		val = 9999;
		for (int l = 0; l < N; l++)if(col[l]==0){
			
			if (Grid[A[k]][l] < val){
				val = Grid[A[k]][l];
				c = l;
			}
		}
		col[c] = 1;
		Min += Grid[A[k]][c];
		val = 9999;
	}
	if (Min < F_Min)
		F_Min = Min;
	initcol();
	Min = 0;
}
void solve(int i){
	if (i == N){
		print();
		return;
	}
	for (int j = 0; j < N; j++)if (used[j] == 0){
		used[j] = 1;
		A[i] = j;
		solve(i + 1);
		used[j] = 0;
	}
}
void solvecase(){
	F_Min = 99999;
	Min = 0;
	initused();
	initcol();
	solve(0);
}
int main(){
	int t;
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	cin >> t; 
	int i, j, k;
	for (T = 1; T <= t; T++){
		cin >> N;
		for (i = 0; i < N; i++){
			for (j = 0; j < N; j++){
				cin >> Grid[i][j];
			}
		}
		solvecase();
		printf("%d\n", F_Min);
	}
}