#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#define size 25
using namespace std;
int T;
char input[4*size];
int A[size];
void readcase()
{
	gets(input);
}
int N;
void formatting()
{
	N = 0;
	A[0] = 0;
	for (int i = 0; input[i]; i++)
	{
		if (input[i] >= '0'&&input[i] <= '9')
		{
			A[N] = A[N] * 10 + input[i] - '0';
		}
		else if (input[i] == ' ')
		{
			N++;
			A[N] = 0;
		}
	}
	N++;
}
int Ans;
int solve(int i, int sum1, int sum2)
{
	if (i == N)
	{
		if (sum1 == sum2){
			return 1;
		}
		else 
			return  0;
	}
	if(solve(i + 1, sum1 + A[i], sum2))
		return 1;
	if(solve(i + 1, sum1, sum2 + A[i]))
		return 1;
	return 0;
}
void solvecase()
{

   Ans=	solve(0, 0, 0);
	if (Ans == 1)
		printf("YES\n");
	else
		printf("NO\n");
}
int main()
{
	int t; 
	char c[2];
	freopen("input.txt", "r", stdin);
	cin >> t;
	gets(c);
	for (T = 1; T <= t; T++)
	{
		readcase();
		formatting();
		solvecase();
	}

}