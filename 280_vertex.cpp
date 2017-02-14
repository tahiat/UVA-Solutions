#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 101
int N, Path[size][size],Ans[size][size],visited[size],Node,C;
void initpath(){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			Ans[i][j] = 0;
			Path[i][j] = -1;
			//visited[i][j] = 0;
		}
	}
}
void initvisited(){
	for (int i = 1; i <= N; i++)
		visited[i] = 0;
}
void solve(int i, int count){
	int j, k;
	if (count >= C)
		C = count;
	for (j = 1; j <= N; j++)if (Path[i][j]==1 && !visited[j]){
		visited[j] = 1;
		Ans[Node][j] = 1;
		solve(j, count+1);
		//visited[i][j] = 0;
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	int i, j,start,dest,nq;
	while (cin >> N){
		initpath();
		if (N == 0)break;
		while (cin >> start){
			if (start == 0)break;
			while (cin >> dest)
			{
				if (dest == 0)break;
				Path[start][dest] = 1;
			}
		}
		cin >> nq;
		while (nq--){
			C = 0;
			cin >> Node;
			solve(Node, 0);
			printf("%d", N-C);
			for (int l = 1; l <= N; l++){
				if (!Ans[Node][l])
					printf(" %d", l);
			}
			cout << endl;
			initvisited();
		}
	}
}