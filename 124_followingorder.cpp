#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 21
char node[size],Node[size],node2[size];
int Path[size][size];
int flag;
int M, N, Used[size], Per[size];
void initpath(){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++)
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
		cout << Node[Per[i]];
	cout << endl;
}
void solve(int i){
	//if (1 == flag)return;
	int j;
	if (i> N){
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
int searchindex(char i){
	for (int k = 1; k <= N; k++){
		if (Node[k] == i)
			return k;
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	flag = 0;
	int i, j;
	char x, y;
	while (gets(node)){
		  gets(node2);
			initpath();
			int k = 1;
			for (int i = 0; node[i] != '\0'; i = i + 2){
				Node[k++] = node[i];
			}
			x = 1;
			N = 0;
			while (Node[x++] != '\0')N++;
			while (x = getchar()){
				if (x == ' ')continue;
				if (x == '\n')
					break;
				cin >> y;
				i = searchindex(x);
				j = searchindex(y);
				Path[i][j] = 1;
			}
			initused();
			flag = 0;
			if (flag == 1)
				printf("\n");
			solve(1);
			flag = 1;
		}
		gets(node);
	}
	