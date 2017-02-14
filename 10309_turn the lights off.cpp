#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 12
char Grid[size][size], TestName[20];
int Ans;
int main(){
	freopen("input.txt", "r", stdin);
	int i, j;
	while (scanf("%s", TestName)){
		if (TestName[0] == 'e'){
			break;
		}
		else if (TestName[5] == 'f')
			Ans = 0;
		else if (TestName[5] == 'n')
			Ans = 44;
		for (i = 0; i < 10; i++)
			scanf("%s", Grid[i]);

	}
}