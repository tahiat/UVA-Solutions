#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 31
int NC;
int Node[size];
int Path[size][size];
int N;
void printcase();
void initPath(){
	for (int i = 0; i < size; i++)for (int j = 0; j < size; j++)Path[i][j] = 0;
}
void initcase(){
	initPath();
	N = 0;
}
int searchIndex(int value){
	int i;
	for (i = 0; i < N; i++)if (Node[i] == value)
		return i;
	Node[N] = value;
	N++;
	return N - 1;
}
void readcase(){
	int i;
	int x, y;
	int index1,index2;
	for (i = 0; i < NC; i++)
	{
		cin >> x >> y;
		index1 = searchIndex(x);
		index2 = searchIndex(y);
		Path[index1][index2] = Path[index2][index1] = 1;

	}
}
int Start, Ttl;
typedef struct queueStruct{
	int index;
	int ttl;
}QNode;
QNode Q[size];
int front, rear;

void initqueue(){
	front = rear = 0;
}

void push(QNode n){
	Q[rear] = n;
	rear++;
}
QNode pop(){
	return Q[front++];
}
int isempty(){
	return (front == rear);
}
int used[size];
void initused(){
	for (int i = 0; i < size; i++)
		used[i] = 0;
}
int Count;
void solve(){
	QNode x,y;
	int i, j;
	while (0 == isempty()){
		x = pop();
		if (x.ttl > Ttl)
			break;
		Count++;
		i = x.index;
		for (j = 0; j < N; j++)if (!used[j] && Path[i][j]){
			used[j] = 1;
			y.index = j;
			y.ttl = x.ttl + 1;
			push(y);
		}
	}
}
void solvecase(){
	QNode temp;
	while (2 == scanf("%d %d", &Start, &Ttl)){
		if (0 == Start && 0 == Ttl)
			break;
		temp.index = searchIndex(Start);
		temp.ttl = 0;
		initqueue();
		push(temp);
		initused();
		used[temp.index] = 1;
		Count = 0;
		solve();
		printcase();
	}
}
int Case;
void printcase(){
	cout << "Case " << Case << ":" << " " << N - Count << " nodes not reachable from node " << Start << " with TTL = " << Ttl <<"."<< endl;
	Case++;
}
int main()
{
	Case = 1;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (cin >> NC){
		if(0 == NC)
			break;
		initcase();
		readcase();
		solvecase();
		//printcase();
	}
	return 0;
}