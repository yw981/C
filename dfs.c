
#define MAX 10
#include <stdio.h>
int a[MAX],book[MAX],n;
void dfs(int step){
	int i;
	printf("step %d\n",step);
    if(step==n){
		for(i=0;i<n;i++){
			printf("%d",a[i]);
        }
        printf("\n");
        return;
    }
    
    for(i=0;i<n;i++){
		if(book[i]==0){
			a[step] = i;
			book[i] = 1;
            dfs(step+1);
            book[i] = 0;
		}
		return;
        
    }
}
int main()
{
	scanf("%d",&n);
    dfs(1);
	//system("pause");
	return 0;
}
