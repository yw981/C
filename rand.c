#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int gene(){
	int book[2]={0},count=0;
	while(book[0]==0||book[1]==0){
		count++;
		if((rand()+1)%3==0){
			book[0]=1;
			//printf("0 ");
		}
		else{
			book[1]=1;
			//printf("1 ");
		}
	}
	//printf(" count:%d",count);
	//printf("\n");
	return count;
}

int main(){
	int i,sum=0,total=10000000;
	
	srand(time(0));
	for(i=0;i<total;i++){
		sum += gene();
		
	}
	printf(" ave = %lf",(double)sum/total);
	return 0;
}






/*
有n个事件，发生的概率分别为p1 .. pn，求做多少次实验（期望）这n个事件都发生过
  */

