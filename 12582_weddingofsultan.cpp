#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int T,Len;
#define size 200
char Data[size];
int main(){
	//freopen("input.txt", "r", stdin);
	int t, i;
	cin >> t;
	for (T = 1; T <= t; T++){
		scanf("%s", Data);
		int Ans[size],stack[size];
		for (int i = 0; i < size; i++){
			Ans[i] = 0;
			stack[i] = 0;
		}
		int stcindx = -1;
		for (int i = 0; Data[i]; i++){
			if (stcindx < 0 || stack[stcindx] != Data[i]){
				stack[++stcindx] = Data[i];
				Ans[Data[i]]++;
			}
			else{
				stcindx --;
				if (stcindx >= 0)
				{
					Ans[stack[stcindx]]++;
				}
			}
		}
		Ans[Data[0]]--;
		printf("Case %d\n", T);
		for (int k = 'A'; k <= 'Z'; k++){
			if (Ans[k])
				printf("%c = %d\n", k, Ans[k]);
		}

	}
}