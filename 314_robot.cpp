#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 110
int N, M, Board[size][size],B1,B2,E1,E2,VAT,dik,Ans1,Ans2;
char Map[size][size],Dir[6];
int Front, Rear;
#define valid(nx,ny) nx>=1 && nx<=M-1 && ny>=1 && ny<=N-1  
#define validpath(nx,ny) Board[nx][ny]!=1 && Board[nx][ny-1]!=1 && Board[nx-1][ny-1]!=1 && Board[nx-1][ny]!=1
int Cost[size][size][4];
typedef struct b{
	int x, y, cost,dir;
}Qnode;
Qnode Q[1000000];
void initq(){
	Front = Rear = 0;
}
int isempty(){
	return Front == Rear;
}
void push(Qnode val){
	Q[Rear++] = val;
}
Qnode pop(){
	return Q[Front++];
}
void init(){
	int i, j;
	for (i = 0; i <=M+1; i++){
		for (j = 0; j <= N+1; j++){
			Board[i][j] = 0;
			for (int k = 1; k <= 4; k++){
				Cost[i][j][k] = 9999;
			}
		}
	}
}
int northx[] = { -1, -2, -3 };
int northy[] = { 0, 0, 0 };
int southx[] = { 1, 2, 3 };
int southy[] = { 0, 0, 0 };
int eastx[] = { 0, 0, 0 };
int easty[] = { 1, 2, 3 };
int westx[] = { 0, 0, 0 };
int westy[] = { -1, -2, -3 };
void solvecase(){
	Qnode temp1, temp2,temp3;
	int xx, yy,d,nx,ny,a,b,c,c1;
	initq();
	temp1.x = B1; 
	temp1.y = B2; 
	temp1.dir = dik; 
	temp1.cost = 0;
	Cost[B1][B2][dik] = 0;
	push(temp1);
	while (!isempty()){
		temp2 = pop();
		d = temp2.dir;
		xx = temp2.x;
		yy = temp2.y;
		c = temp2.cost;
		if (xx == E1 && yy == E2){
			Ans1 = temp2.cost;
			if (Ans1 < Ans2)
				Ans2 = Ans1;
			/*break;*/
		}
		// go north 1----------->
		//if (Board[xx - 2][yy - 1] != 1 && Board[xx - 2][yy] != 1 && xx-2 >= 0){
			for (int i = 0; i < 3; i++){
				nx = xx + northx[i];
				ny = yy + northy[i];
				if (valid(nx, ny) && validpath(nx, ny)){
					a = nx; b = ny;
					temp3.x = a;
					temp3.y = b;
					temp3.dir = 1;

					if (d == 1){
						c1 = temp3.cost = temp2.cost + 1;
					}
					else if (d == 2){
						c1 = temp3.cost = temp2.cost + 1 + 2;
					}
					else if (d == 3 || d == 4){
						c1 = temp3.cost = temp2.cost + 1 + 1;
					}
					if (Cost[a][b][1] != 9999/*Visited[a][b] == 1*/){
						if (Cost[a][b][1] > c1){
							Cost[a][b][1] = c1;
							push(temp3);
						}
					}
					else
					{
						push(temp3);
						
						Cost[a][b][1] = c1;
					}
				}
				else
					break;
			}
		//}
		// go south 2----------->
		//if (Board[xx + 2][yy - 1] != 1 && Board[xx + 2][yy] != 1 && xx + 2 >= 0 /*&& Visited[xx+1][yy]==0*/){
			for (int i = 0; i < 3; i++){
				nx = xx + southx[i];
				ny = yy + southy[i];
				if (valid(nx, ny) && validpath(nx, ny)){
					a = nx; b = ny; 
					temp3.x = a; 
					temp3.y = b;
					temp3.dir = 2;
					if (d == 2){
						c1=temp3.cost = temp2.cost + 1;
					}
					else if (d == 1){
						c1 = temp3.cost = temp2.cost + 1 + 2;
					}
					else if (d == 3 || d == 4){
						c1 = temp3.cost = temp2.cost + 1 + 1;
					}
					if (Cost[a][b][2]!=9999/*Visited[a][b] == 1*/){
						if (Cost[a][b][2] > c1){
							Cost[a][b][2] = c1;
							push(temp3);
						}
					}
					else
					{
						push(temp3);
						Cost[a][b][2] = c1;
					}
				}
				else break;
			}
		//}
		// go East 3----------->
		//if (Board[xx - 1][yy + 2] != 1 && Board[xx - 1][yy + 2] != 1 && yy + 2 < N/* && Visited[xx][yy+1]==0*/){
			for (int i = 0; i < 3; i++){
				nx = xx + eastx[i];
				ny = yy + easty[i];
				if (valid(nx, ny) && validpath(nx, ny)){
					a = nx; b = ny; 
					temp3.x = a; 
					temp3.y = b;
					temp3.dir = 3;
					if (d == 3){
						c1 = temp3.cost = temp2.cost + 1;
					}
					else if (d == 4)
						c1=temp3.cost = temp2.cost + 1 + 2;
					else if (d == 1 || d == 2)
						c1=temp3.cost = temp2.cost + 1 + 1;
					if (Cost[a][b][3]!=9999/*Visited[a][b] == 1*/){
						if (Cost[a][b][3] > c1){
							Cost[a][b][3] = c1;
							push(temp3);
						}
					}
					else
					{
						push(temp3);
						Cost[a][b][3] = c1;
					}
				}
				else 
					break;
			}
	//	}
		// go west 4----------->
		//if (Board[xx - 1][yy - 2] != 1 && Board[xx - 1][yy - 2] != 1 && yy - 2 >= 0/* && Visited[xx][yy-1]==0*/){
			for (int i = 0; i < 3; i++){
				nx = xx + westx[i];
				ny = yy + westy[i];
				if (valid(nx, ny) && validpath(nx, ny)){
					a = nx; b = ny;
					temp3.x = a; 
					temp3.y = b;
					temp3.dir = 4;
					if (d == 4)
						c1=temp3.cost = temp2.cost + 1;
					else if (d == 3)
						c1=temp3.cost = temp2.cost + 1 + 2;
					else if (d == 1 || d == 2)
						c1=temp3.cost = temp2.cost + 1 + 1;
					if (Cost[a][b][4]!=9999/*Visited[a][b] == 1*/){
						if (Cost[a][b][4] > c1){
							Cost[a][b][4] = c1;
							push(temp3);
						}
					}
					else
					{
						push(temp3);
						Cost[a][b][4] = c1;
					}
				}
				else
					break;
			}
		//}
	}
}
void showinput(){
	int i, j;
	for (i = 0; i < M; i++){
		for (j = 0; j < N; j++)
			cout << Board[i][j] << " ";
		cout << endl;
	}
	cout << B1 << " " << B2 << "  " << E1 << " " << E2 << endl;
	cout << "initial direction = " << dik << endl;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i,j;
	while (cin >> M >> N){
		if (N == 0 && M == 0)break;
		init();
		for (i = 0; i < M; i++){
			for (j = 0; j < N; j++){
				cin >> Board[i][j];
			}
		}
		cin >> B1 >> B2 >> E1 >> E2;
		scanf("%s", Dir);
		if (Dir[0] == 's')dik = 2;
		else if (Dir[0] == 'n')dik = 1;
		else if (Dir[0] == 'e')dik = 3;
		else if (Dir[0] == 'w')dik = 4;
		//showinput();
		Ans2 = 10000;
		solvecase();
		if (Ans2 == 10000)
			printf("-1\n", Ans2);
		else
			printf("%d\n", Ans2);
		/*cout << Cost[E1][E2][1] << " " << Cost[E1][E2][2] << " " << Cost[E1][E2][3] << " " << Cost[E1][E2][4] << endl;*/
	}
}