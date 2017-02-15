#include<stdio.h>
int main(){
	int j,n,i=0,k,book[10],already[10]={0},err=0,take=0,result=1,gap;
	char c,test[20]={"04??2?7"};
	for(i=0;i<10;i++){
		book[i]=-1;
	}
	i=0;
	while((c=getchar()) != '\n' ){
		if(c=='?'){
			
		}
		else{
			k=c-'0';
			if((book[i%10]==-1&&!already[k])||book[i%10]==k){
				book[i%10] = k;
				already[k] = 1;
			}
			else{
				err = 1;	
			}
		}
		i++;
	}
	for(j=0;j<10&&j<=i;j++){
		if(book[j]!=-1) take++;	
	}
	//while(i<n){
	//	scanf("%d",&data[i]);	
	//	i++;
	//}
	/*
	for(j=0;j<10;j++){
		printf("%d ",book[j]);
	}
	printf("\n");
	for(j=0;j<10;j++){
		printf("%d ",already[j]);
	}
	printf("\n%d \n",err);
	*/
	if(err) printf("0");
	else{
		if(i<10) gap = i-take;
		else gap = 10-take;
		//printf("kkk %d %d \n",take,gap);
		for(j=10-take;j>10-take-gap;j--) result *= j;
		printf("%d",result);
	}
	
	return 0;
}
