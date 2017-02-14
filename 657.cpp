#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 55
int W, H;
int T;
char Board[size][size];
int Score[1000];
int Dnum;
int ptr;
void dfs2(int i, int j)
{
	if (Board[i][j] != 'X')return;
	Board[i][j] = '*';
	if (i + 1 < H )
	{
		dfs2(i + 1, j);
	}
	if (i - 1 >= 0 )
	{
		dfs2(i - 1, j);
	}
	if (j + 1 < W )
	{
		dfs2(i, j + 1);
	}
	if (j - 1 >= 0)
	{
		dfs2(i, j - 1);
	}
}

void dfs1(int i, int j)
{
	if (Board[i][j] == '.')
		return;
	if (Board[i][j] == 'X')
	{
		Dnum++;
		dfs2(i, j);
	}
	Board[i][j] = '.';
	if (i + 1 < H)
		dfs1(i + 1, j);
	if (i - 1 >= 0 )
		dfs1(i - 1, j);
	if (j + 1 < W )
		dfs1(i, j + 1);
	if (j - 1 >= 0 )  
		dfs1(i, j - 1);
}
int main()
{
	T = 1;
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int i, j;
	int flag = 0;
	while (cin >> W >> H)
	{
		if (W == 0 && H == 0)
			break;
		//if (flag == 1)
			//printf("\n");
		flag = 1;
		ptr = 1;
		for (i = 0; i < H; i++)
			scanf("%s", Board[i]);

		for (i = 0; i < H; i++)
		{
			for (j = 0; j < W; j++)
			{
				if (Board[i][j] != '.')
				{
					Dnum = 0;
					dfs1(i, j);
					if (Dnum)
					Score[ptr++] = Dnum;
					//ptr++;
				}
			}
		}
		int temp = 0;
		for (i = 1; i < ptr - 1; i++)
		{
			for (j = 1; j < ptr - i; j++)
			{
				if (Score[j]>Score[j + 1])
				{
					temp = Score[j];
					Score[j + 1] = Score[j];
					Score[j] = temp;
				}
			}
		}
		printf("Throw %d\n", T++);
		printf("%d", Score[1]);
		for (i = 2; i < ptr; i++)
			printf(" %d", Score[i]);
		printf("\n\n");
	}
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//char grid[100][100];
//int visited[100][100];
//int Case, w, h;
//int ans[100];
//int index, countX;
//
//void initcase()
//{
//	for (int i = 0; i < h; i++)
//	{
//		for (int j = 0; j < w; j++)
//		{
//			visited[i][j] = 0;
//		}
//	}
//}
//
//
//void X_count(int i, int j)
//{
//	if (i < 0 || i >= h || j < 0 || j >= w || visited[i][j] == 1 || visited[i][j] == 2)
//		return;
//
//	if (grid[i][j] != 'X')
//		return;
//
//	visited[i][j] = 2;
//	X_count(i - 1, j);
//	X_count(i + 1, j);
//	X_count(i, j + 1);
//	X_count(i, j - 1);
//
//}
//
//
//void star_X_count(int i, int j)
//{
//	if (i < 0 || i >= h || j < 0 || j >= w || visited[i][j] == 1)
//		return;
//
//	if (grid[i][j] == '.')
//		return;
//
//	if (grid[i][j] == 'X' && visited[i][j] != 2)
//	{
//		countX++;
//		X_count(i, j);
//	}
//
//	visited[i][j] = 1;
//	star_X_count(i - 1, j);
//	star_X_count(i + 1, j);
//	star_X_count(i, j - 1);
//	star_X_count(i, j + 1);
//	//star_X_count(i - 1, j - 1);
//	//star_X_count(i - 1, j + 1);
//	//star_X_count(i + 1, j - 1);
//	//star_X_count(i + 1, j + 1);
//
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	for (Case = 1; Case; Case++){
//		cin >> w >> h;
//		if (w == 0 && h == 0)
//			break;
//
//		for (int i = 0; i < h; i++)
//		{
//			for (int j = 0; j < w; j++)
//			{
//				cin >> grid[i][j];
//			}
//		}
//
//		initcase();
//		index = -1;
//		int dicecount = 0;
//		for (int i = 0; i < h; i++)
//		{
//			for (int j = 0; j < w; j++)
//			{
//				if ((grid[i][j] == '*' || grid[i][j] == 'X') && visited[i][j] == 0){
//					index++;
//					countX = 0;
//					star_X_count(i, j);
//					ans[index] = countX;
//					dicecount++;
//				}
//			}
//		}
//
//		for (int i = 0; i < index; i++)
//		{
//			for (int j = i + 1; j <= index; j++)
//			{
//				int temp;
//				if (ans[i]>ans[j])
//				{
//					temp = ans[i];
//					ans[i] = ans[j];
//					ans[j] = temp;
//				}
//			}
//		}
//		cout << "Throw " << Case << endl;
//		//cout << "dicecount "<<dicecount << endl;
//		for (int i = 0; i <= index; i++){
//			if (i != 0)
//				cout << " ";
//			cout << ans[i];
//		}
//		cout << endl << endl;
//	}
//
//}