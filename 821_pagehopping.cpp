// somethings wrong when running in this ide but its a accepted code :)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 101
int Path[size][size];
int Node[size];
int Maximum;
void initp(){
	int i, j;
	for ( i = 1; i <=size; i++)
	{
		for ( j = 1; j <= size; j++){
			Path[i][j] = 9999;
		}
	}
	
}
void initn(){
	int i;
	for (i = 0; i <= size; i++)
		Node[i] = 0;
}
int searchindex(int node){
	for (int i = 1; i <= Maximum; i++){
		if (Node[i] == node)
			return i;
	}
	Node[++Maximum] = node;
	return Maximum;
}
int main(){
	freopen("input.txt", "r", stdin);
	int C = 1;
	int x, y, k, i, j,a,b;
	float Ans;
		while (cin >> x >> y){
		if (x == 0 && y == 0)
			break;
		Maximum = 0;
		initp();
		initn();
		a = searchindex(x);
		b = searchindex(y);
		Path[a][b] = 1;
		while (cin >> x >> y){
			if (x == 0 && y == 0)
				break;
			a = searchindex(x);
			b = searchindex(y);
			Path[a][b] = 1;
		}
		for (k = 1; k <= Maximum; k++){
			for (i = 1; i <= Maximum; i++){
				for (j = 1; j <= Maximum; j++){
					if (Path[i][k] + Path[k][j] < Path[i][j])
						Path[i][j] = Path[i][k] + Path[k][j];
				}
			}
		}
		int Sum = 0,no=0;
		for (i = 1; i <= Maximum; i++){
			for (j = 1; j <= Maximum; j++){
				if (i != j){
					Sum += Path[i][j];
					no++;
				}
			}
		}
		Ans = (float)Sum / no;
		printf("Case %d: average length between pages = %.3f clicks\n", C++, Ans);
	}
}