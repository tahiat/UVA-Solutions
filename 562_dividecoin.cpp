#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 102
#define size1 50001
int N;
int T;
int arr[size];
int A[size];
int dp[size][size1];
int total;
void initdp(){
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size1; j++)
			dp[i][j] = -1;
}
void readcase(){
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		total += arr[i];
	}
}
void print()
{
	for (int i = 0; i < N; i++)cout << A[i];
	cout << endl;
}
int absl(int val){
	if (val < 0)
		return - val;
	else
		return val;
}
int solve(int i,int sum){
	int left, right;
	if (dp[i][sum] != -1)
		return dp[i][sum];
	if (i == N){
		//print();
		return  dp[i][sum]=absl(total - 2 * sum);
	}
	A[i] = 0;
	left=solve(i+1,sum);
	A[i] = 1;
	right=solve(i + 1,sum+arr[i]);
	if (left < right)
		return dp[i][sum] = left;
	else
		return dp[i][sum] = right;

}
void solvecase(){
	printf("%d\n",solve(0,0));
}
int main(){
	int testcase;
	freopen("input.txt", "r", stdin);
	cin >> testcase;
	for ( T= 1; T<= testcase; T++)
	{
		total = 0;
		initdp();
		readcase();
		solvecase();
	}

}