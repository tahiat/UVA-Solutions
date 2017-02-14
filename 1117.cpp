#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int coin[22];
long long int Ans;
int main(){

	int N,temp[22],t,p;
	for (int i = 1; i <= 21; i++)
		coin[i] = i*i*i;
	while (cin >> N)
	{
		Ans = 1;
		for (int i = 2; i <= 21; i++)
		{
			//Ans+=1;
			temp[i] = N / coin[i];
			if (temp[i] < 1)break;
			t=N - coin[i];
			for (int j = i - 1; j > 1; j--){
				p = t / coin[j];
				Ans += p;
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																`````			}
			Ans += temp[i];
		}
		printf("%lld\n",Ans);
	}
}