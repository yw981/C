/*
//ȫ�������� 
#define MAX 10
#include <stdio.h>
int a[MAX],book[MAX],n;
// ��step 0��ʼ 
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
*/


#define MAX 10
#include <stdio.h>
char dict[4] = {"1234567"},result[MAX]={0};
int n;
// ��step 0��ʼ 
void dfs(int step){
	int i;
	//printf("step %d\n",step);
    //n��λ�� 
    if(step==n){
        printf("%s\n",result);
        return;
    }
    //ÿ��λ�ü���ѡ�� 
    for(i=0;i<2;i++){
		result[step] = dict[i];
		dfs(step+1);		       
    }    
}
int main()
{
	scanf("%d",&n);
    dfs(0);
	//system("pause");
	return 0;
}

