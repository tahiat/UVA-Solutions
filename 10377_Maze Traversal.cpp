#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 62
#define size1 1000
char Grid[size][size];
int H,W,T,X,Y;
char Direction[size1][size1],dir;
int Line,lx,ly;
void solve(){ 
	dir = 'N';
	int i, j, k;
	int flag = 0;
	for (i = 0; i < Line; i++){
		for (j = 0; Direction[i][j] != '\n'; j++)
		{
			if (Direction[i][j] == 'R'){
				if (dir == 'N')
					dir = 'E';
			else if (dir == 'E')
					dir = 'S';
			else if (dir == 'S')
					dir = 'W';
			else if (dir == 'W')
					dir = 'N';
				
			}
			else if (Direction[i][j] == 'L')
			{
	
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
					if (X -1>=0){
						X = X - 1;
						Y = Y;
					}
				}
				else if (dir == 'W'){
					if (Y - 1 >= 0){
						X = X;
						Y = Y - 1;
					}
				}
				else if (dir == 'E')
				{
					if (Y + 1 < W){
						X = X;
						Y = Y + 1;
					}
				}
				else if (dir == 'S'){
					if (X + 1 < H){
						X = X + 1;
						Y = Y;
					}
				}
			}
			else if (Direction[i][j] == 'Q'){
				lx = X;
				ly = Y;
				flag = 1;
				break;
			}

		}
		if (flag == 1)
			break;
	}
	cout << lx+1 << " " << ly+1 << " " << dir << endl;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t,i;
	int n = 0;
	char p;
	cin >> t;
	p=getchar();
	while (t)
	{
		cin >> H >> W;
		p = getchar();
		for ( i = 0; i < H; i++)
		{
			gets(Grid[i]);
		}
		//for (i = 0; i < H; i++)
			//printf("%s\n", Grid[i]);
		cin >> X >> Y;
		X = X - 1; Y = Y - 1;
		i = 0;
		p = getchar();
		while (gets(Direction[i]))
		{
			if (Direction[i][0] == '\0')
			{
				break;
			}
			i++;
		}
		Line = i;
		if (n == 1)
			cout << endl;

		solve();
		
		t--;
		n = 1;
	}

}