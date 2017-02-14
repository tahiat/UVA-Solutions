#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 9
int Board[size][size];
int Used[size][size];
int T;
int Max;
void initused()
{
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			Used[i][j] = 0;
}
void readcase()
{
	int i, j;
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			cin >> Board[i][j];
		}
	}
}
int absdif(int a, int b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}

int checkValidity(int r,int c)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <=8; j++)
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
void solve(int r, int sum)
{
	if (r== 9)
	{
		if (sum > Max)
			Max = sum;
		return;
	}

	for (int k = 1; k <= 8; k++)if (0==Used[r][k])
	{
		if (checkValidity(r, k))
		{
			Used[r][k] = -1;
			solve(r + 1, sum + Board[r][k]);
			Used[r][k] = 0;
		}
	}	
}
void solvecase()
{
	int sum;
	initused();
	Max = 0;
    sum = 0;
    solve(1,sum);
}
void printcase()
{
	printf("%5d\n", Max);
}
int main()
{
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for (T = 1; T <= t; T++)
	{
		readcase();
		solvecase();
		printcase();
	}
}