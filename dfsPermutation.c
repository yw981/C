//ȫ�������� 
#define MAX 10
#include <stdio.h>
int a[MAX],book[MAX],n,m,count;
// ��step 0��ʼ 
void dfs(int step){
	int i;
	//printf("step %d\n",step);
    if(step==n){
    	count++;
    	/*
		for(i=n-m;i<n;i++){
			printf("%d",a[i]);
        }
        printf("\n");
        */
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

// A(m,n) ȫ���У���int���� 
int main()
{
	printf("input A(m,n) n and m(MAX<=10):");
	scanf("%d%d",&n,&m);
	count = 0;
    dfs(n-m);
    printf("\ncount : %d",count);
	//system("pause");
	return 0;
}


