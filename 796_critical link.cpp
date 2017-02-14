#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 101
int Link[size][size];
int N,visited[size];
int Res[size][size],Ans;
void initvisited(){
	for (int i = 0; i < N; i++)
		visited[i] = 0;
}
void fill(int x){
	int y;
	visited[x] = 1;
	for (y = 0; y < N; y++)if (Link[x][y] && visited[y] == 0)
		fill(y);
}
void initlink(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Link[i][j] = 0;
}
//int check(int i, int j){
//	for (int k = 0; k < Ans; k++){
//		if ((Res[k][0] == i && Res[k][1] == j) || (Res[k][0] == j && Res[k][1] == i))
//			return 0;
//	}
//	return 1;
//}
void solvecase(){
	int x, y;
	Ans = 0;
	for (x = 0; x < N; x++){
		for (y = x+1; y < N; y++)if( Link[x][y]){
			initvisited();
			Link[x][y] = Link[y][x] = 0;
			fill(x);
			if (visited[y] == 0 ){
				Res[Ans][0] = x;
				Res[Ans][1] = y;
				Ans++;
			}
			Link[x][y] = Link[y][x] = 1;
		}
	}
	printf("%d critical links\n", Ans);
	if (Ans>0){
		for (int i = 0; i < Ans; i++)
			printf("%d - %d\n", Res[i][0], Res[i][1]);
	}
}
int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int x,m,y,bracket;
	while (1==scanf("%d",&N)){
		initlink();
		for (int i = 0; i < N; i++){
			scanf("%d (%d)", &x, &m);
			for (int j = 0; j < m; j++){
				cin >> y;
				Link[x][y] = Link[y][x] = 1;
			}
		}
		solvecase();
		printf("\n");
	}
}