#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size1 100000
#define size2 100
int N;
int Path[size1][size2];
int Node[size1];
int S, D;
void initcase(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) Path[i][j] = 0;
}
int n;
int  Searchindex(int val)
{

	for (int i = 0; i < N; i++)if (Node[i] == val)
		return i;
	Node[n++] = val;
	return n-1;
}
void readcase()
{
	int x, y, noc;
	int index1, index2;
	cin >> N;	//no of comrade
	initcase();
	n = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		index1 = Searchindex(x);
		cin >> noc;
		for (int j = 0; j < noc; j++)
		{
			cin >> y;
			index2 = Searchindex(y);
			Path[index1][index2] = 1;
		}
	}
	cin >> S >> D;
}
void printcase(){
	cout << S << D<<endl;
	for (int i = 0; i < N; i++)cout << Node[i]<<" ";
}
int main()
{
	freopen("input.txt", "r", stdin);
	int t;
	while (cin >> t){
		readcase();
		printcase();
	}
}