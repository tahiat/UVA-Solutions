#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 101
int Path[size][size],T,N,K,Max;
int Ncolor[size],Node[size];
void initcolor(){
	for (int i = 1; i <= N; i++)
		Ncolor[i] = -1;  /// not yet colored
}
void initpath(){
	int i, j;
	for (i = 1; i <= N;i++)
	for (j = 1; j <= N; j++)
		Path[i][j] = 0;
}
void countnode(){
	int i,j,Count=0;
	for (i = 1; i <= N; i++){
		if (Ncolor[i] == 1)
			Count += 1;
	}
	if (Count >=Max)
	{
		Max = Count;
		for (i = 1, j = 1; i <= N; i++){
			if (Ncolor[i] == 1){
				Node[j] = i;
				j++;
			}
		}
	}
}
void solve(int i){
	int j, flag = 0;
	if (i> N){
		countnode();
		return;
	}
	for (j = 1; j <= N; j++){
			if (Path[i][j] && Ncolor[j] == 1)
			{
				flag = 1; break;
			}
		}
	if (flag == 1)
	{
		Ncolor[i] = 0;
		solve(i + 1);
	}
	else
	{
		Ncolor[i] = 1;
		solve(i + 1);
		Ncolor[i] = 0;
		solve(i + 1);
	}	
	//solve(i + 1);
}
void solvecase(){
	Max = 0;
	initcolor();
	for (int i = 1; i <= N; i++){
		solve(i);
	    initcolor();
   }
}
void printoutput(){
	cout << Max << endl;
	cout << Node[1];
	for (int i = 2; i <= Max; i++)
		cout <<" "<<Node[i] ;
	cout << endl;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t,i,x,y;
	int f = 1;
	cin >> t;
	for (T = 1; T <= t; T++){
		cin >> N >> K;
		initpath();
		for (i = 0; i < K; i++){
			cin >> x >> y;
			Path[x][y] = Path[y][x] = 1;
		}
		solvecase();
		printoutput();
	}
}