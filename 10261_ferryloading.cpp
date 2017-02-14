#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
int Flen;
#define size 101
int Carlen[size];
int Len;
void readcase(){
	int temp;
	cin >> Flen;
	Len = 0;
	while (cin >> temp){
		if (temp == 0)break;
		Carlen[Len++] = temp;
       }
}
char p[100];
double Left, Right;
int Ans;
void solvecase()
{
	Left = Right = 0;
	Ans = 0;
	for (int i = 0; i < Len; i++)
	{
		if (Left <= Right)
		{
			
			if (Left + Carlen[i]/100 <= Flen)
			{
				p[i] = 'l';
				Left += Carlen[i] / 100;
				Ans++;
			}
		}
		else
		{
			if (Right + Carlen[i]/100 <= Flen)
			{
				p[i] = 'r';
				Right += Carlen[i] / 100;
				Ans++;
			}
		}

	}
}
int f = 1;
void printcase()
{
	
	if (f == 0)
		printf("\n");
	f = 0;
	printf("%d\n", Ans);
	for (int i = 0; i < Ans; i++)
	{
		if (p[i] == 'l')
			printf("port\n");
		else if (p[i] == 'r')
			printf("starboard\n");
	}
}
int main(){
	int t;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//int Flen;
	cin >> t;
	for (int T = 1; T <= t; T++)
	{
		readcase();
		solvecase();
		printcase();
	}
}