#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int Score;
int C,P;
int valid(int val)
{
	if (val <= 20 || (val <= 40 && 0 == val % 2) || (val <= 60 && 0 == val % 3) || 50 == val)
		return 1;
	else
		return 0; 
}
int counter;
int repeat3, repeat2, norepeat;
int countPermutation (int x)
{
	int i, j, k;
	counter = 0;
	repeat2 = 0;
	repeat3 = 0;
	norepeat = 0;
	for (i = 0; i <= 60; i++)
	{
		if (i > x)
			break;
		if (valid(i)){
			for (j = 0; j <= 60; j++)
			{
				if (j+i> x)
					break;
				if (valid(j)){
					for (k = 0; k <= 60; k++)
					{
						if (k+j+i> x)
							break;
						if (valid(k))
						{
							
				     		if (i + j + k == x)
							{
								counter += 1;
								
								if (i == j && j == k){
									repeat3+=1;
								}
								if ((i == j&&j != k) || (j == k&&k != i) || (i == k&& j!= k))
								{
									repeat2+=1;
								}
								if (i != j && j!= k && k!=i)
									norepeat+=1;
							}

						}
					}
				}

			}
		}
	}
	C = (norepeat / 6) + (repeat2 / 3) + repeat3;
	return counter;
}

int main()
{
	
	while (scanf("%d", &Score) == 1)
	{
		
		if (Score > 180){
			cout << "THE SCORE OF " << Score << " CANNOT BE MADE WITH THREE DARTS." << endl;
		}
		else
		{
			if (Score <= 0)
			{
				cout << "END OF OUTPUT" << endl;
				break;
			}

			else{
				P = countPermutation(Score);
				if (C>0){
					cout << "NUMBER OF COMBINATIONS THAT SCORES " << Score << " IS " << C << "." << endl;
					cout << "NUMBER OF PERMUTATIONS THAT SCORES " << Score << " IS " << P << "." << endl;
				}
				else{
					cout << "THE SCORE OF " << Score << " CANNOT BE MADE WITH THREE DARTS." << endl;
				}
			}
		}
		for (int i = 0; i<70; i++)
			cout << '*';
		cout << endl;
	}
	return 0;
}
