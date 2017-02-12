#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 1001
int T,Tindex,Extention;
int Len;
int Source[size], Time[size], Duration[size], Target[size];
int solve(int index,int curex,int base){
	if (index > 0 && curex == base)
		return 9999;
	
	for (int i = 0; i < Len; i++){
		if (Source[i] == curex && Tindex >= Time[i] && Tindex <= (Time[i] + Duration[i]))
		{
			return solve(index+1,Target[i], base);
		}	
	}
	return curex;
}
void takeinput(){
	int a, b, c, d,i;
	for ( i = 0; i < size; i++)
	{
		cin >> a;
		if (a == 0)break;
		cin >> b >> c >> d;
		Source[i] = a;
		Time[i] = b;
		Duration[i] = c;
		Target[i] = d;
		
	}
	Len = i;
	while (cin >> Tindex){
		if (Tindex == 9000)break;
		cin >> Extention;
		printf("AT %04d CALL TO %04d RINGS %04d\n", Tindex, Extention, solve(0,Extention,Extention));
	}
	
}
int main(){
	freopen("input.txt", "r", stdin);
	int t;
	cin >> T;
	printf("CALL FORWARDING OUTPUT\n");
	for (t = 1; t <= T; t++)
	{
		printf("SYSTEM %d\n", t);
		takeinput();
	}
	cout << "END OF OUTPUT" << endl;
}