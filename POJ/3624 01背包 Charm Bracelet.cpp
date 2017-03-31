/*
Charm Bracelet
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 37486		Accepted: 16341
Description

Bessie has gone to the mall's jewelry store and spies a charm bracelet. Of course, she'd like to fill it with the best charms possible from the N (1 ¡Ü N ¡Ü 3,402) available charms. Each charm i in the supplied list has a weight Wi (1 ¡Ü Wi ¡Ü 400), a 'desirability' factor Di (1 ¡Ü Di ¡Ü 100), and can be used at most once. Bessie can only support a charm bracelet whose weight is no more than M (1 ¡Ü M ¡Ü 12,880).

Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.

Input

* Line 1: Two space-separated integers: N and M
* Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di

Output

* Line 1: A single integer that is the greatest sum of charm desirabilities that can be achieved given the weight constraints

Sample Input

4 6
1 4
2 6
3 12
2 7
Sample Output

23
Source

USACO 2007 December Silver
*/
#include <iostream>
#define MAX 3402
using namespace std;

int weight[MAX],desirability[MAX];

int pack(int capacity,int itemNum){
	int packThis,notPackThis;
	if(capacity<=0) return 0;
	if(itemNum==0){
		if(capacity<weight[itemNum]) return 0;
		else return desirability[itemNum];
	}
	else{
		if(capacity>weight[itemNum]){
			packThis = desirability[itemNum]+pack(capacity-weight[itemNum],itemNum-1);
			notPackThis = pack(capacity,itemNum-1);
			return packThis>notPackThis?packThis:notPackThis;
		}
		else{
			return pack(capacity,itemNum-1);
		}
	}
}

int main(){
	int n,i,j,m;
	cin >> n >> m;
	for(i=0;i<n;i++){
		cin >> weight[i] >> desirability[i];
	}
	cout << pack(m,n) << endl;
	return 0;
}
