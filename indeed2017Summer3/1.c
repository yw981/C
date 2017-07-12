#include<stdio.h>
 
int main()
{
    int gap,n,i,j,k,m,a[100]={0},b[100]={0};
    scanf("%d%d", &n,&m);
    for(i=0;i<n;i++){
    	scanf("%d", &a[i]);
    }
    for(i=0;i<m;i++){
    	scanf("%d", &b[i]);
    }
	for(i=0;i<n;i++){
		gap = 0;
		k = 0;
    	for(j=1;j<=a[i];j++){
    		gap++;
    		while(k<m && gap==b[k]){
    			k++;
	    			gap++;
    		}
 //   		if(k<m) {
   // 			if(gap==b[k]){
	 //   			
    //			}
    //		}
    		
    	}
    	printf("%d\n",gap);
    }
    return 0;
}
