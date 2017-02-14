#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 101
int Path[size][size];
int flag;
int M, N,Used[size],Per[size];
void initpath(){
	for (int i = 1; i <=N ; i++){
		for (int j = 1; j <= N;j++)
		{ 
			Path[i][j] = 0;
		}
	}
}
void initused(){
	for (int i = 1; i <= N; i++)
		Used[i] = 0;
}
int checkusedchild(int i){
	int j;
	for (j = 1; j <= N; j++)if (1 == Path[i][j] && 1 == Used[j])
		return 1;
	return 0;
}
void read(){
	int i, j;
	while (M--){
		cin >> i >> j;
		Path[i][j] = 1;
	}

}
void printperm(){
	int i;
	for (i = 1; i <= N; i++)
		cout << Per[i]<<" ";
	cout << endl;
}
void solve(int i){
	if (1 == flag)return;
	int j;
	if (i> N){
		flag = 1;
		printperm();
		return;
	}
	for (j = 1; j <= N; j++)if (Used[j] == 0){
		if (1 == checkusedchild(j))
			return;
		Used[j] = 1;
		Per[i] = j;
		solve(i + 1);
		Used[j] = 0;
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	int i, j;
	while (cin >> N >> M){
		if (N == 0 && M == 0)
			break;
		initpath();
		read();
		initused();
		flag = 0;
		solve(1);
	}

}