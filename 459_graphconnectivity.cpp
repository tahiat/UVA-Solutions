#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
char Pair[2],Maxnode;
#define size 100
int T, Parent[size], maxx;
int Used[size];
void initused(){
	char i;
	for (i = 'A'; i <= maxx; i++){
		Used[i] = 0;
	}
}
void initparent(){
   int i, j;
   for (i = 'A'; i <= maxx; i++){
		Parent[i] = i;
	}
}
int findparent(char node){
	if (Parent[node] == node)
		return node;
	else
	{
		Parent[node] = findparent(Parent[node]);
		return Parent[node];
	}
}
void makefriend(char a, char b){
	int u, v;
	u = findparent(a);
	v = findparent(b);
	if (u != v)
	{
		Parent[u] = v;
		for (char i = 'A'; i <= maxx; i++){
			if (Parent[i] == u)
				Parent[i] = v;
		}
	}
	//else
	//	return;
}
int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int t,k;
	int flag = 0;
	int Ans;
	char p;
	cin >> t;
	p = getchar();
	p = getchar();
	for (T = 1; T <= t; T++){
		Ans = 0;
		if (flag == 1)
			printf("\n");
		flag = 1;
		cin >> Maxnode;
		maxx = (int)Maxnode;
		p = getchar();
		initparent();
		initused();
		while (gets(Pair)){
			if (Pair[0] == '\0')break;
			makefriend(Pair[0], Pair[1]);
		}
		for (k = 'A'; k <= maxx; k++){
			if (Used[Parent[k]] == 0){
				Used[Parent[k]] = 1;
				Ans++;
			}
		}
		cout << Ans << endl;
	}
}