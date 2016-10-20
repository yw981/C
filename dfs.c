#define MAX 10
#include <stdio.h>
int a[MAX],book[MAX],n;
// 从step 0开始 
void dfs(int step){
	int i;
	//printf("step %d\n",step);
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
    }
}
int main()
{
	scanf("%d",&n);
    dfs(0);
	//system("pause");
	return 0;
}

/*
#define MAX 10
#include <stdio.h>
char dict[3] = {"+*"},result[MAX]={0};
int book[2]={0},n;
// 从step 0开始 
void dfs(int step){
	int i;
	printf("step %d\n",step);
    if(step==n){
        printf("%s\n",result);
        return;
    }
    //有问题 
    for(i=0;i<2;i++){
		if(book[i]==0){
			result[step] = dict[i];
			book[i] = 1;
            dfs(step+1);
            book[i] = 0;
		}        
    }
}
int main()
{
	scanf("%d",&n);
    dfs(0);
	//system("pause");
	return 0;
}
*/
