#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define size 101
int Time[size], Duration[size], Source[size], Target[size];
int Case,D;
int Len;
int result;
int T;
int solve(int index,int curex,int baseex){
	if (index>0 && curex == baseex){ 
		return 9999;
	}
	for (int i = 0; i < Len; i++)if (Source[i] ==curex && T >= Time[i] && T <= (Time[i] + Duration[i])){
		
		return solve(index + 1, Target[i], baseex);
		//printf("aftersolve %d ,%d,%d\n", index, Target[i], baseex);
	}
	/printf("returning value %d\n", curex);
	return curex;

}

void takeinput(){
	int i;
	for (i = 0; i < size; i++)
	{
		cin >> Source[i];
		if (Source[i] == 0){
			Len = i;
			break;
		}
		cin >> Time[i] >> Duration[i] >> Target[i];
	}
	Len = i;
	while (cin >> T){
		if (T == 9000)
			break;
		cin >> D;
		result = D;
		
		printf("AT %04d CALL TO %04d RINGS %04d\n", T, D, solve(0, D, D));
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	int t;
	cin >> Case;
	cout << "CALL FORWARDING OUTPUT" << endl;
	for (t = 1; t <= Case; t++)
	{		
		cout << "SYSTEM " << t << endl;
		takeinput();
	}
	cout << "END OF OUTPUT";
}