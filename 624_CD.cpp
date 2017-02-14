#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 21
int N,M,Data[size],A[size],Prev,Res[size],one;

 void init(){
	int var = 0;
	for (int i = 0; i < M; i++)
	{
		Res[i] = 0;
		A[i] = 0;
	}
	
}
void solve(int level, int sum){
	
	if (level == M ){
		if (sum >= Prev){
				for (int i = 0; i < level; i++)
				{
					Res[i] = A[i];
				}
				Prev = sum;
				//one = none;
		}
			return;
	}
	A[level] = 0;
	solve(level + 1, sum);
	if (sum+Data[level]<=N)
	{
		A[level] = 1;
		solve(level + 1, sum+Data[level]);
	}
}
void printcase(){
	int sum = 0;
	for (int i = 0; i < M; i++){
		if (Res[i]){
			cout << Data[i] << " ";
			sum += Data[i];
		}
	}
	cout << "sum:" << sum << endl;
}
int  main()
{
	freopen("input.txt", "r", stdin);
	int i;
	while (cin >> N){
		cin >> M;
		for (i = 0; i < M; i++)
			cin >> Data[i];
		init();
		Prev = 0;
		solve(0,0);
		printcase();
	}
	return 0;
}