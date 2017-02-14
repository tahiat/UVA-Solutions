#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 17
int N, H,T,Ht;
int arr[size],A[size];
int last;
void print(){
	/*for (int i = 0; i < Ht; i++)
		printf("%d ", A[i]);
	printf("\n");*/
	int i, j,flag;

	for (i = 0; i < N; i++){
		for (j = 0; j < Ht; j++){
			if (i == A[j])
			{
				flag = 1; break;
			}
			else flag = 0;
		}
		if (flag==1)
			printf("0");
		else
			printf("1");
		flag = 0;
	}
	printf("\n");
}
void solve(int i){
	int j;
  if (i == Ht){
		print();
		return;
	}
	for (j = last + 1; j < N; j++){
		last = j;
		A[i] = j;
		solve(i+1);
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	int t,f;
	cin >> t;
	f = 0;
	for (T = 1; T <= t; T++){
		cin >> N >> H;
		if (f == 1)printf("\n");
		Ht = N - H;
		last = -1;
		solve(0);
		f = 1;
	}
}