#include<stdio.h>
int main(){
	int n,m,i;
	scanf("%d%d",&n,&m);
	while(i<n){
		if(i<2){
			scanf("%d",&data[i]);
		}
		else{
			scanf("%d",&data[2]);
			if(data[0]<data[1]&&data[1]>data[2]){
				
				result++;
				//printf("re = %d",result);
			}
			data[0]=data[1];
			data[1]=data[2];
		}
		//printf("%d %d %d\n",data[0],data[1],data[2]);	
		i++;
	}
	if(n<3) result = 0;
	printf("%d",result);
	return 0;
}
