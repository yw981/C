/*
003:ȫ����
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
����һ���ɲ�ͬ��Сд��ĸ��ɵ��ַ������������ַ���������ȫ���С� ���Ǽ������Сд��ĸ��'a' < 'b' < ... < 'y' < 'z'�����Ҹ������ַ����е���ĸ�Ѿ����մ�С�����˳�����С�

����
����ֻ��һ�У���һ���ɲ�ͬ��Сд��ĸ��ɵ��ַ�������֪�ַ����ĳ�����1��6֮�䡣
���
�������ַ������������з�ʽ��ÿ��һ�����С�Ҫ����ĸ��Ƚ�С��������ǰ�档��ĸ�����¶��壺

��֪S = s1s2...sk , T = t1t2...tk����S < T �ȼ��ڣ�����p (1 <= p <= k)��ʹ��
s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp������
��������
abc
�������
abc
acb
bac
bca
cab
cba
*/
#include<stdio.h>
#include<string.h>

void swap(char c[],int a,int b){
	char t = c[a];
	c[a] = c[b];
	c[b] = t;
}

void perm(char c[],int s,int e){
	int i;
	if(s == e){
		printf("%s\n",c);
	}
	else{
		for(i=e;i>=s;i--){
			swap(c,i,e);
			perm(c,s,e-1);
			swap(c,i,e);
		}
	}
}

int main(){
	char input[7]={0};
	int len;
	gets(input);
	len=strlen(input);
	perm(input,0,len-1);
	return 0;
}
