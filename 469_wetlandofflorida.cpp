#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 150
char area[size][size];
char cor[2][2];
int T;
int L, NQ, R, C, Ans;
int fx[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int fy[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

void fillarea(int row, int col){
	int nx, ny;
	area[row][col] = 'L';
	for (int i = 0; i < 8; i++)
	{
		nx = row + fx[i];
		ny = col + fy[i];
		if (nx >= 0 && nx < L && ny >= 0 && ny < L && area[nx][ny] == 'W'){
			Ans++;
			//area[nx][ny] = 'L';
			fillarea(nx, ny);
		}
	}
}
int main(){
	int i,j;
	freopen("input.txt", "r", stdin);
	cin >> T;
	char p;
	p = getchar();
	int a, b;
	int flag = 0;
	for (int t = 1; t <= T; t++)
	{
		p = getchar();
		i = 0;
		while (gets(area[i])){
			if (area[i][0] != 'W' && area[i][0] != 'L'){
				R = area[i][0] - '0';
				C = area[i][2] - '0';
				break;
			}
			i++;
		}
		L = i - 1 ;
		if (flag == 1)printf("\n");
		Ans = 1;
		fillarea(R - 1, C - 1);
		cout << Ans << endl;
		j = 0;
		while (gets(cor[j])){
			if (cor[j][0] == '\0')
				break;
			Ans = 1;
			R = cor[j][0] - '0';
			C = cor[j][2] - '0';
			fillarea(R - 1, C - 1);
			cout << Ans << endl;
		}
		flag = 1;
	}
}
