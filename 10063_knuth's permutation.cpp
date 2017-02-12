#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 11
int len;
char input[size];
void solve(int index, char output[]){
	int i, j; char temp[size];
	if (index == len){
		for (int k = 0; k < len; k++)
			cout << output[k];
		cout << endl;
		
		return;
	}
	for (i = 0; i <= index; i++){
		for (j = 0; j < i; j++)
			temp[j] = output[j];
		temp[i] = input[index];
		for ( ; j < index; j++)
			temp[j + 1] = output[j];
		solve(index + 1, temp);
	}
	
}
int main(){
	int flag = 0;
	while (gets(input)){
		len = 0;
		char output[size];
		while (input[len])len++;
		if (flag == 1)cout << endl;
		solve(0, output);
		flag = 1;
	}
}