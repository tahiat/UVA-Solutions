#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int S, T;
int primefactor[100];

int main()
{
	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	int i, j;
	int test = 1;
	int flag;
	while (cin >> S >> T)
	{
		int dif = T - S;
		int ptr = 1;
		if (S == 0 && T == 0)
			break;
		for (i = 2; i <= S/2; i++)
		{
			if (S%i == 0){
				flag = 0;
				for (j = 2; j < i; j++)
				{

					if (i%j == 0){
						flag = 1; continue;
					}

				}
				if (flag == 0)
					primefactor[ptr++] = i;
				flag = 0;
			}
		}
		int f = 0;
		if (dif == 0){
			printf("Case %d: 0\n", test++); continue;
		}
		for (int k = ptr - 1; k >= 1; k--)
		{
			if (dif%primefactor[k] == 0)
			{
				f = 1;
				printf("Case %d: %d\n", test++, dif / primefactor[k]);
				break;
			}
		}
	    if (f == 0)
		printf("Case %d: -1\n", test++);


	}
}