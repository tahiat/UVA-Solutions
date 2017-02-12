#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 10000 
int NI, St, En, N;
int Path[size][size];
int Distance[size];
int Rasta[size];
int Nrasta[size];
int Front, Rear, Q[size];
int Parent[size],Visited[size];
void initqueue(){
	Front = Rear = 0;
}
//void push(int val){
//	int i, j,temp,flag=0;
//	for (i = Front; i < Rear; i++){
//		if (Q[i] == val)
//		{
//			for (j = i; j < Rear; j++){
//				Q[j] = Q[j + 1];
//			}
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 1){
//		for (i = Front; i < Rear; i++)
//		{
//			if (Distance[val]<Distance[Q[i]])
//			{
//				for (j = Rear - 1; j >= i; j--){
//					Q[j + 1] = Q[j];
//				}
//				//Q[i] = val;
//				break;
//			}
//		}
//		Q[i] = val;
//		return;
//	}
//	for (i = Front; i < Rear; i++)
//	{
//		if (Distance[val]<Distance[Q[i]])
//		{
//			for (j = Rear-1; j >=i; j--){
//				Q[j + 1] = Q[j];
//			}
//			//Q[i] = val;
//			break;
//		}
//	}
//	Q[i] = val;
//	Rear++;
//}
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
	return (Front == Rear);
}

void solution(){
	initqueue();
	initd();
	int x, y;
	Distance[St] = 0;
	push(St);
	Visited[St] = 1;
	Parent[St] = St;
	while (!isempty()){
		x = pop();
		for (int i = 1; i <= NI; i++){
			if (Path[x][i] != -1 ){
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
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
	int i, j, k, n, x, y;
	int T = 1;
	while (cin >> NI){
		if (NI == 0)
			break;
		initpath();
		for (i = 1; i <= NI; i++){
			cin >> n;
			for (j = 1; j <= n; j++){
				cin >> x >> y;
				if (Path[i][x] != -1){
					if (y < Path[i][x])
						Path[i][x] = y;
				}
				else
				Path[i][x] = y;
			}
		}
		/*for (i = 1; i <= NI; i++){
			for (j = 1; j <= NI; j++)
			{
				cout << Path[i][j] << " ";
			}
			cout << endl;
		}*/
		cin >> St >> En;
		N = 0;
		solution();
		printf("Case %d: Path =", T++);
		printpath(En);
		printf("; %d second delay\n", Distance[En]);
	}
}