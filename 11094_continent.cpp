#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 21
int M, N, X, Y, Ans, Result;
char Ground[size][size];
void fill1(int x,int y){
	Ground[x][y] = 'w';
	if (Ground[(x - 1) % M ][y]== 'l')
		fill1(x - 1, y);
	if (Ground[(x + 1) % M][y] == 'l')
		fill1(x + 1, y);
	if (Ground[x][(y - 1) % N] == 'l')
		fill1(x, y - 1);
	if (Ground[x][(y + 1) % N ]== 'l')
		fill1(x, y + 1);
}
void fill2(int x,int y){
	Ans++;
	Ground[x][y] = 'w';
	if (Ground[(x - 1) % M][y] == 'l')
		fill2(x - 1, y);
	if (Ground[(x + 1) % M][y] == 'l')
		fill2(x + 1, y);
	if (Ground[x][(y - 1) % N] == 'l')
		fill2(x, y - 1);
	if (Ground[x][(y + 1) % N] == 'l')
		fill2(x, y + 1);
}
int main(){
	freopen("input.txt", "r", stdin);
	Result = 0;
	while (cin >> M >> N){
		for (int i = 0; i < M; i++){
			cin >> Ground[i];
		}
		cin >> X >> Y;
		fill1(X, Y);
		for (int i = 0; i < M; i++){
			for (int j = 0; j < N; j++){
				if (Ground[i][j] == 'l'){
					Ans = 0;
					fill2(i, j);
					if (Ans >= Result)
						Result = Ans;
				}
			}
		}
		cout << Result << endl;
	}
}