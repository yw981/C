//去重全排列的递归实现  
#include <stdio.h>  
#include <string.h>  
void swap(char *a, char *b)  
{  
    char t = *a;  
    *a = *b;  
    *b = t;  
}  
//在pszStr数组中，[nBegin,nEnd)中是否有数字与下标为nEnd的数字相等  
int is_swap(char *str, int begin, int end)  
{
	int i;  
    for (i = begin; i < end; i++)  
        if (str[i] == str[end])  
            return 0;  
    return 1;  
}  
//k表示当前选取到第几个数,m表示共有多少数。从0开始表示全排列 
void step(char *str, int k, int m)  
{
	int i;
	if (k == m)  
    {
		//static int s_i = 1;
		//printf("  第%3d个排列\t%s\n", s_i++, str);
		printf(" %s\n",str);
	}  
    else  
    {  
        for (i = k; i <= m; i++) //第i个数分别与它后面的数字交换就能得到新的排列  
        {  
            if (is_swap(str, k, i)) //从当前位置到i之前有重复，就跳过 
            {  
                swap(str + k, str + i);  
                step(str, k + 1, m);  
                swap(str + k, str + i);  
            }  
        }  
    }  
}  
void permutation(char *str)  
{  
    step(str, 0, strlen(str) - 1);  
}  
int main()  
{
	char str[5] = {"aabb"};   
    printf("         去重全排列的递归实现\n");
    printf("%s的全排列如下:\n", str);  
    permutation(str);  
    return 0;  
}  
