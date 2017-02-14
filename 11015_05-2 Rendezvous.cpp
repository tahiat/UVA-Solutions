#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size1 25
#define size2 242
int Path[size1][size1],N,M,Cost[size1];
char Name[size1][size1];
void initPath(){
	int i, j;
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++)
		{
			Path[i][j] = 999999;
		}
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	int T=1,i,j,x,y,k,jog;
	char p;
	while (cin >> N >> M){
		if (N == 0)
			break;
		initPath();
		p = getchar();
		for (i = 1; i <= N; i++)
		{
			scanf("%s", Name[i]);
		}
		for (i = 1; i <= M; i++){
			cin >> x >> y >> k;
			Path[x][y] = Path[y][x] = k;
		}
		for (k = 1; k <= N; k++){
			for (i = 1; i <= N; i++){
				for (j = 1; j <= N; j++){
					if (Path[i][k] + Path[k][j] < Path[i][j])
						Path[i][j] = Path[i][k] + Path[k][j];
				}
			}
		}
		jog = 0;
		int soto = 999999,idx;
		for (i = 1; i <= N; i++){
			for (j = 1; j <= N; j++){
				if (i != j){
					jog += Path[i][j];
				}
			}
			Cost[i] = jog;
			jog = 0;
			if (Cost[i] < soto)
			{
				soto = Cost[i];
				idx = i;
			}
		}
		printf("Case #%d : ",T++);
		puts(Name[idx]);
	}
}