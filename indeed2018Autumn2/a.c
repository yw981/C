#include<stdio.h>
int main(){
	long long n;
	int c=0,s;
	scanf("%lld",&n);
	if(n==1) {
		printf("0");
		return 0;	
	}
	
	while(n > 1){
		s = n % 2;
		c += s;
		c++;
		n /= 2;
	}
	printf("%d",c);
	return 0;
}
