/*
003:全排列
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。 我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列。

输入
输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
输出
输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：

已知S = s1s2...sk , T = t1t2...tk，则S < T 等价于，存在p (1 <= p <= k)，使得
s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立。
样例输入
abc
样例输出
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
