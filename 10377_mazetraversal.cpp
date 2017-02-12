#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#define size 61
#define size1 1000
using namespace std;
int H, W, X, Y,T,RowD;
char Grid[size][size],Direction[size1][size1];
void solve(){
	char dir = 'N';
	int i, j;
	int flag = 0;
	for (i = 0; i < RowD; i++){
		for (j = 0; Direction[i][j] != '\0'; j++){
			if (Direction[i][j] == 'R'){
				if (dir == 'N'){
					dir = 'E';
				}
				else if (dir == 'E')
					dir = 'S';
				else if (dir == 'S')
					dir = 'W';
				else if (dir == 'W')
					dir = 'N';
			}
			else if (Direction[i][j] == 'L'){
				if (dir == 'N')
					dir = 'W';
				else if (dir == 'W')
					dir = 'S';
				else if (dir == 'S')
					dir = 'E';
				else if (dir == 'E')
					dir = 'N';
			}
			else if (Direction[i][j] == 'F'){
				if (dir == 'N'){
					if (X - 1 >= 0 && Grid[X - 1][Y] != '*')
					{
						X = X - 1;
					}
				}
				else if (dir == 'S'){
					if (X + 1 < H && Grid[X + 1][Y] != '*')
					{
						X = X + 1;
						
					}
				}
				else if (dir == 'W'){
					if (Y - 1 >= 0 && Grid[X][Y - 1] != '*')
					{
						Y = Y - 1;
						
					}
				}
				else if (dir == 'E')
				{
					if (Y + 1 < W && Grid[X][Y + 1] != '*')
					{
						Y += 1;
						
					}
				}
			}
			else if (Direction[i][j] == 'Q')
			{
				cout << X+1 << " " << Y+1 << " " << dir << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 1)break;
	}
}
int main(){
	///*freopen("input.txt", "r", stdin);
	//freo*/pen("output.txt", "w", stdout);
	int t,i,j;
	char p;
	cin >> t;
	int n = 0;
	for (T = 1; T <= t; T++){
		cin >> H >> W;
		p = getchar();
		for (i = 0; i < H; i++)
			gets(Grid[i]);
		//for (i = 0; i < H; i++)
			//puts(Grid[i]);
		cin >> X >> Y;
		X = X - 1;
		Y = Y - 1;
		p = getchar();
		i = 0;
		if (n == 1)cout << endl;
		while (gets(Direction[i])){
			if (Direction[i][0] == '\0')
				break;
			i++;
		}
		RowD = i;
		solve();
		n = 1;
	}

}