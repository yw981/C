//ȥ��ȫ���еĵݹ�ʵ��  
#include <stdio.h>  
#include <string.h>  
void swap(char *a, char *b)  
{  
    char t = *a;  
    *a = *b;  
    *b = t;  
}  
//��pszStr�����У�[nBegin,nEnd)���Ƿ����������±�ΪnEnd���������  
int is_swap(char *str, int begin, int end)  
{
	int i;  
    for (i = begin; i < end; i++)  
        if (str[i] == str[end])  
            return 0;  
    return 1;  
}  
//k��ʾ��ǰѡȡ���ڼ�����,m��ʾ���ж���������0��ʼ��ʾȫ���� 
void step(char *str, int k, int m)  
{
	int i;
	if (k == m)  
    {
		//static int s_i = 1;
		//printf("  ��%3d������\t%s\n", s_i++, str);
		printf(" %s\n",str);
	}  
    else  
    {  
        for (i = k; i <= m; i++) //��i�����ֱ�������������ֽ������ܵõ��µ�����  
        {  
            if (is_swap(str, k, i)) //�ӵ�ǰλ�õ�i֮ǰ���ظ��������� 
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
    printf("         ȥ��ȫ���еĵݹ�ʵ��\n");
    printf("%s��ȫ��������:\n", str);  
    permutation(str);  
    return 0;  
}  
