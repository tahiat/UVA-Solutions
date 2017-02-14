#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 8
int sx, sy, ex, ey;
int absl(int x){
	if (x < 0)
		return x;
	else
		return -x;
}

int main(){
	//freopen("input.txt", "r", stdin);
	while (cin >> sx >> sy >> ex >> ey){
		if (sx == 0 && sy == 0 && ex == 0 && ey == 0)
			break;
		if (sx == ex && sy == ey)
		{
			printf("0\n"); continue;
		}
		else if (sx == ex || sy == ey || absl(sx - ex) == absl(sy - ey))
		{
			printf("1\n"); continue;
		}
		else
		{
			printf("2\n"); continue;
		}
	}
}