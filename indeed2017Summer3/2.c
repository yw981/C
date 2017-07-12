#include<stdio.h>

int weight[20] = {0},
	value[20]  = {0};

int pack(int capacity,int itemNum){
	int packThis,notPackThis;
	if(capacity<=0) return 0;
	if(itemNum==0){
		if(capacity<weight[itemNum]) return 0;
		else return value[itemNum];
	}
	else{
		if(capacity>weight[itemNum]){
			packThis = value[itemNum]+pack(capacity-weight[itemNum],itemNum-1);
			notPackThis = pack(capacity,itemNum-1);
			return packThis>notPackThis?packThis:notPackThis;
		}
		else{
			return pack(capacity,itemNum-1);
		}
	}
}

int main(){
	int i,n,t;
	scanf("%d%d", &n,&t);
	for(i=0;i<3*t;i++){
		scanf("%d", &weight[i]);
	}
	for(i=0;i<3*t;i++){
		value[i] = 1;
	}
	printf("%d \n",pack(n,3*t));
	return 0;
}
