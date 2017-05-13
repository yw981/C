#include<stdio.h>
int main(){
	char map[11][11] = {0};
	int i,j,k,h,w,a,b;
	scanf("%d%d%d%d",&h,&w,&a,&b);
	for(i=0;i<h;i++){
		scanf("%s",map[i]);	
	}
	
	for(i=0;i<a;i++){
		for(j=0;j<h;j++){
			for(k=0;k<b;k++){
				printf("%s",map[j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
