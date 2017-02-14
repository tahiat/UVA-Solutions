#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define size 100
double Totaldistance, Capacity, Mileage, OriginCost,Half,cango;
int No_station,T;
double Distance[size], Price[size],Min;
void init(){
	for (int i = 0; i <= No_station; i++)
	{
		Distance[i] = 0;
		Price[i] = 0;
	}
}
void solve(int at_station,double cost, double remaining_gasolin){
	if (cost > Min)
		return;
	double temp;
	if (at_station == No_station ){
		 temp = (Totaldistance - Distance[at_station]) / Mileage;
		if (remaining_gasolin < temp){
			cost = cost + (Capacity-remaining_gasolin)*Price[at_station] + 200.0;
		}
		if (cost < Min)
			Min = cost;
		return;
	}
	temp = (Distance[at_station + 1] - Distance[at_station]) / Mileage;
	if (temp > remaining_gasolin){
		cost = cost + (Capacity - remaining_gasolin)*Price[at_station] + 200.0;
		solve(at_station + 1, cost, Capacity - temp);
	}
	else if (remaining_gasolin > Half && temp <= remaining_gasolin){
		solve(at_station + 1, cost, remaining_gasolin - temp);
	}
	else {
		solve(at_station + 1, cost, remaining_gasolin - temp);
		cost = cost + (Capacity - remaining_gasolin)*Price[at_station] + 200.0;
		solve(at_station+1, cost, Capacity - temp);
	}
}
void solvecase(){
	Min = 999999;
	Half = Capacity / 2.0;
	double temp = Capacity - (Distance[1]/Mileage);
	solve(1,OriginCost*100.0,temp);// at origin, o distance initial cost in cent,ramining full
	double Ans = Min / 100.0;
	printf("Data Set #%d\n", T++);
	printf("minimum cost = $%.2lf\n", Ans);
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int i, j;
	T = 1;
	while (cin >> Totaldistance){
		if (Totaldistance < 0)
			break;
		//cin >> Capacity >> Mileage >> OriginCost >> No_station;
		scanf("%lf %lf %lf %d", &Capacity, &Mileage, &OriginCost, &No_station);
		//init();
		for (i = 1; i <= No_station; i++){
			//cin >> Distance[i] >> Price[i];
			scanf("%lf %lf",&Distance[i], &Price[i]);
		}
	  solvecase();
	}
}