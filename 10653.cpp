#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 1000
int R, C;
int grid[size][size];
int Ans;
void initcase(){
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			grid[i][j] = 0;
}

int Sx, Sy, Ex, Ey;

void readcase(){
	int nr,r,c,nb;
	cin >> nr;
	for (int i = 0; i < nr; i++)
	{
		cin >> r >> nb;
		for (int j = 0; j < nb; j++)
		{
			cin >> c;
			grid[r][c] = -1;
		}
		
	}
	cin >> Sx >> Sy;
	cin >> Ex >> Ey;
}

typedef struct Queuestruct{
	int x, y,val;
}QNode;

QNode Q[size*size-1];

int front, rear;

void initqueue(){
	front = rear = 0;
}
void push(QNode n)
{
	Q[rear++] = n;
}
QNode pop(){
	return Q[front++];
}
int isempty(){
	return(front == rear);
}
int fx[] = { -1, +1,+0,+0 };
int fy[] = { +0,+0, -1, +1 };
void solve()
{
	QNode a, b;
	int nx, ny;
	while (0 == isempty())
	{
		a = pop();
		//cout << a.x<<" "<<a.y<<endl;
		if (a.x == Ex && a.y == Ey)
			break;
		Ans++;
		for (int j = 0; j < 4; j++)
		{
			nx = a.x + fx[j];
			ny = a.y + fy[j];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] != -1 && (grid[nx][ny]==0) )
			{
				b.x = nx;
				b.y = ny;
				grid[nx][ny] = a.val + 1;
				b.val = grid[nx][ny];
				push(b);
			}
		}
	}
}
void solvecase()
{
	QNode temp;
	temp.x = Sx;
	temp.y = Sy;
	temp.val = 0;
	initqueue();
	grid[Sx][Sy] = 10;
	push(temp);
	Ans = 0;
	solve();
}
void printcase()
{
/*	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			//cout << "  "<<grid[i][j]<<"  ";
			printf(" %2d ", grid[i][j]);
		cout << endl;
	}*/
	
	printf("%d\n", grid[Ex][Ey]);

}
int main()
{
	//cout << "heloo";
	freopen("input.txt", "r", stdin);
	while (2 == scanf("%d %d", &R, &C))
	{
		if (R == 0 && C == 0)
			break;
		initcase();
		readcase();
		solvecase();
		printcase();
	}
}