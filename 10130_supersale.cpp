#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 1001
int T;
int N;
int P[size];
int W[size];
int G;   //number of people
int GW[size];
int Ans;
int A[size];
int Maxbuy;
void readcase(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d %d", &P[i], &W[i]);
	scanf("%d", &G);
	for (i = 0; i < G; i++)
		scanf("%d", &GW[i]);
}
void print()
{
	int taka=0;
	for (int i = 0; i < N; i++)
	{
		if (1 == A[i])
			taka += P[i];
	}
	if (taka > Ans)
	{
		Ans = taka;
	}
	//printf("%d\n", Ans);
}
void solve(int i,int gw)
{
	//printf("solve(%d %d)\n", i, gw);
	if (i == N)
	{
		print();
		return;
	}
	A[i] = 0;
	solve(i + 1,gw);
	A[i] = 1;
	if (gw - W[i]>=0)
		solve(i + 1, gw - W[i]);
	else
		return;
}
void solvecase()
{
	int i;
	
	Maxbuy = 0;
	for (i = 0; i < G; i++)
	{
		Ans = 0;
		solve(0,GW[i]);
		Maxbuy += Ans;
	}
}
void printcase(){
	printf("%d\n",Maxbuy);
}
int main()
{
	int test;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d",&test);
	for (T = 1; T <= test; T++)
	{
		readcase();
		solvecase();
		printcase();
	}
}