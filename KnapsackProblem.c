#include<stdio.h>

int weight[5] = {4,5,6,2,2},
	value[5]  = {6,4,5,3,6};

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
	/*
	int i,j;
	for(i=4;i>=0;i--){
		for(j=0;j<=10;j++){
			printf("%d ",pack(j,i));
		}
		printf("\n");
	}
	*/
	printf("%d \n",pack(10,4));
	return 0;
}