// this problem has been solved, solutin is in home pc

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 20 
int NI,St,En,N;
int Path[size][size];
int Distance[size];
int Rasta[size];
int Nrasta[size];
int Front, Rear,Q[size];
int Parent[size],Used[size];
void initqueue(){
	Front = Rear = 0;
	for (int i = 0; i < NI; i++){
		Used[i] = 0;
	}
}
void push(int val){
	Q[Rear++] = val;
}
int pop(){
	return Q[Front++];
}
void initd(){
	for (int i = 1; i <= NI; i++)
	{
		Distance[i] = 999999;
	}

}
void initpath(){
	for (int i = 1; i <= NI; i++)
		for (int j = 1; j <= NI; j++)
			Path[i][j] = -1;
}
int isempty(){
	int i , x = 0;
	for (i = Front; i < Rear; i++)
		if (Used[i] == 0)
			return 1;
	return 0;
}

void solution(){
	initqueue();
	initd();
	int x, y;
	Distance[St] = 0;
	push(St);
	Parent[St] = St;
	while (!isempty()){
		x = pop();
		for (int i = 1; i <= NI; i++){
			if (Path[x][i] != -1){
				if (Distance[x] + Path[x][i] < Distance[i])
				{
					Distance[i] = Distance[x] + Path[x][i];
					Parent[i] = x;
					push(i);
				}
			}
		}
	}
}
void printpath(int x){
	if (Parent[x] == x){
		printf(" %d", x);
		return;
	}
	printpath(Parent[x]);
	printf(" %d", x);
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, k,n,x,y;
	int T = 1;
	while (cin >> NI){
		if (NI == 0)
			break;
		initpath();
		for (i = 1; i <= NI; i++){
			cin >> n;
			for (j = 1; j <= n; j++){
				cin >> x >> y;
				Path[i][x] = y;
			}
		}
		cin >> St >> En;
		N = 0;
		solution();
		printf("Case %d: Path =", T++);
		printpath(En);
	    printf("; %d second delay\n", Distance[En]);
	}
}