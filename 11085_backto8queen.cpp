#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 9
int Board[size];
int Used[size][size];
int T;
int Max;
int Min;
int A[9];
void initused()
{
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			Used[i][j] = 0;
	for (int i = 1; i <= 8; i++)A[i] = 0;
}
void readcase()
{
	int i, j;
	for (i = 2; i <= 8; i++)
	{
		cin>>Board[i];
	}
}
int absdif(int a, int b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}

int checkValidity(int r, int c)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if (r == i && Used[i][j] == -1)
				return 0;
			else if (c == j && Used[i][j] == -1)
				return 0;
			else if ((absdif(r, i) == absdif(c, j)) && Used[i][j] == -1)
				return 0;
		}
	}
	return 1;
}
void solve(int r)
{
	
	if (r == 9)
	{
		int d=0;
		for (int i = 1; i <r; i++)
		{
			if (A[i] != Board[i])
				d++;
		}
		//cout <<" " << d<<endl;
		if (d < Min)
			Min = d;
		return;
	}

	for (int k = 1; k <= 8; k++)if (0 == Used[k][r])
	{
		if (checkValidity(k, r))
		{
			Used[k][r] = -1;
			A[r] = k;
			solve(r + 1);
			Used[k][r] = 0;
		}
	}
}
void solvecase()
{
	int sum;
	initused();
	Min = 8;
	solve(1);
}
void printcase()
{
	printf("Case %d: %d\n",T++, Min);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	T = 1;
	while (cin>>Board[1])
	{
		readcase();
		solvecase();
		printcase();
	}
}