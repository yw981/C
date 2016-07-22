#include<stdio.h>
int main(){
	double nexta,nextb,result;
	int a,b,k,i=0;
	scanf("%d%d%d",&a,&b,&k);
	nexta = a;
	nextb = b+0.5;
	while(i<k){
		if(nexta < nextb){
			result = 1;
			nexta += a;
		}
		else{
			result = 2;
			nextb += b;
		}
		i++;
	}
	if(result==1) printf("Takahashi\n");
	if(result==2) printf("Aoki\n");
	return 0;
}


