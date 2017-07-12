#include<stdio.h>
#include<string.h>
#define MAX 100001
int main()
{
    int n,i,j,k,m,a[MAX]={0};
    long long t,tt;
    // 循环节 
	int x[MAX];
	// 循环节 开始的数字 
	int sn[MAX];
	//int p[MAX];
	int book[MAX]={0};
    scanf("%d%lld", &n,&t);
    for(i=1;i<=n;i++){
    	scanf("%d", &a[i]);
    	//p[i] = i;
    }
    for(j=1;j<=n;j++){
    	// n个box,找循环节
    	memset(book,0,MAX);
    	k = j;
    	book[k] = 1;
    	//printf("b %d = 1\n",k);
    	m = 1;
    	while(1){
    		k = a[k];
    		//printf("%d",k);
    		m++;
    		if(book[k] > 0){
				// 找到
				sn[j] = k; 
				x[j] = m-book[k];
			//	printf("find %d is %d\n\n",k,m-book[k]);
				break; 
    		}
    		book[k] = m;
    		//printf("b %d = %d\n",k,m);
    		
    	}
    }
    
	for(i=1;i<=n;i++){
		tt = t;
		k=i;
		while(tt>0){
			if(k==sn[i]){
				tt = tt % x[i];	
			}
			k = a[k];
			tt--;	
		}
    	printf("%d\n",k);
    }


    return 0;
}
