#include<stdio.h>
#define MAX 100
int main(){
	long long s,a[MAX],bian,max=0,c=0;
	int t,i,count=0;
	scanf("%d%lld",&t,&s);
	for(i=0;i<t;i++){
		scanf("%lld",&a[i]);
	}
	for(i=0;i<t;i++){
		c += a[i];
		count++;
		if(c>max) max = c;
		if(c>=s){
			printf("%d",count);
			return 0;
		}
	}
	bian = c;
	if(bian <=0){
		printf("-1");
		return 0;
	}
	count *= ((s - max) / bian);
	c = s - max;
	while(1){
		for(i=0;i<t;i++){
			c += a[i];
			count++;
			if(c>=s){
				printf("%d",count);
				return 0;
			}
		}	
	}
	return 0;
}

