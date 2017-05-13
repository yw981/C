#define MAX 10
#include <stdio.h>
int a[MAX],book[MAX],n,m,mm,maxv,v[29][3];
// ´Óstep 0¿ªÊ¼ 
int exist(int v,int arr[],int from,int to){
	int i;
	for(i=from;i<to;i++){
		if(v==arr[i]) return 1;
	}
	return 0;
}

int val(){
	
}

void dfs(int step){
	int i,curv;
	//printf("step %d\n",step);
    if(step==n){
    	
//		for(i=n-m;i<n;i++){
//			printf("%d",a[i]+1);
//        }
//        printf("\n");
        
        curv = 0;
    	for(i=0;i<mm;i++){
    		
    		if(exist(v[i][0]-1,a,n-m,n-m/2)&&exist(v[i][1]-1,a,n-m,n-m/2)){
    			curv += v[i][2];
    		}
    		if(exist(v[i][0]-1,a,n-m/2,n)&&exist(v[i][1]-1,a,n-m/2,n)){
    			curv += v[i][2];
    		}
    	}
//    	printf("cur %d\n",curv);
    	if(curv>maxv) maxv = curv;
        
        return;
    }   
    for(i=0;i<n;i++){
		if(book[i]==0){
			a[step] = i;
			book[i] = 1;
            dfs(step+1);
            book[i] = 0;
		}        
    }
}
int main()
{
	int nn,k,i;
	scanf("%d%d%d",&nn,&k,&mm);
	for(i=0;i<mm;i++){
		scanf("%d%d%d",&v[i][0],&v[i][1],&v[i][2]);
	}
	maxv = 0;
	n=nn;
	m=k*2;
    dfs(n-m);
	printf("%d",maxv);
	return 0;
}
