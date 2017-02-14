#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int T,N,M,L;
#define size 10000
int Path[size][size],Hitpoint,Ans,Used[size];
void initpath(){
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			Path[i][j] = 0;
	
}
void initused(){
	for (int i = 0; i <= N; i++){
		Used[i] = 0;
	}
}
void solve(int i){
	int j;
	Ans++;
	Used[i] = 1;
	for (j = 1; j <= N; j++){
		if (Path[i][j] && !Used[j])
		{
			Used[j] = 1;
			solve(j);
		}
	}
}
int main(){
//	freopen("input.txt", "r", stdin);
	int t,i,j,x,y;
	cin >> t;
	for (T = 1; T <= t; T++){
		initpath();
		initused();
		cin >> N >> M >> L;
		for (i = 1; i <= M; i++){
			cin >> x >> y;
			Path[x][y] = 1;
		}
		Ans = 0;
		while (L--){
			cin >> Hitpoint;
			if (Used[Hitpoint]==0)
			 solve(Hitpoint);
		}
		cout << Ans << endl;
	}
}