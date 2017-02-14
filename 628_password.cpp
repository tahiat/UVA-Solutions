#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int Nw,Nr;
char Word[101][257],Rule[257];
int Used[300],Len;
void solvecase(int i,char res[],int pos){
	int j, k, l,m, flag=0;
	if (i == Len){
		for (int n = 0;n<pos; n++)
		{
			cout << res[n];
		}
		printf("\n");
		return;
	}
	switch (Rule[i])
	{
	case '#':
		for (j = 0; j < Nw; j++){
			for (k = 0; Word[j][k] != '\0'; k++)
				res[pos++] = Word[j][k];
			solvecase(i + 1, res, pos);
			pos -= k;
		}
		break;
	case '0':
		for ( l = 0; l < 10; l++)
		{
			res[pos++] = l + '0';
			solvecase(i + 1, res,pos);
			pos -= 1;
		}
		break; 
	}



	//for (j =0; Rule[j] != '\0'; j++)if (Used[j] == 0){  // to parse thr rule 
	//	Used[j] = 1;
	//	for (int c = Len - 1; c >= 1; c--){
	//		for (int d = c-1; d >= 0; d--){
	//			if (Used[c] == 1 && Used[d] == 0)
	//			{
	//				flag = 1; break;
	//			}
	//		}
	//	}
	//	if (flag == 1)break;
	//		if (Rule[j] == '0'){
	//			for (k = 0; k < 10; k++){
	//				//printf("%d", k);
	//				P[pos++] = k+'0';
	//				solvecase(i+1,pos);
	//				pos -= 1;// return;
	//			}
	//		}
	//		else if (Rule[j] == '#'){
	//			for (l = 0; Word[l][0]; l++){
	//				for ( m = 0; Word[l][m] != '\0'; m++)
	//				{
	//					P[pos++] = Word[l][m];
	//					//printf("%c", Word[l][m]);
	//				}
	//				solvecase(i+1,pos);
	//				pos -= m;//return;
	//			}
	//		}
	//	Used[j] = 0;
	//}
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int i;
	char c[5000];
	while (cin >> Nw){
		for (i = 0; i < Nw; i++){
			scanf("%s", Word[i]);
		}
		cin >> Nr;
		for (i = 0; i < Nr; i++){
			
			scanf("%s", Rule);
			Len = 0;
			while (Rule[Len] != '\0')Len++;
			printf("--\n");
			solvecase(0,c,0);
		}
	}
}