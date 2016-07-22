/*
#1039 : �ַ�����
ʱ������:1000ms
����ʱ��:1000ms
�ڴ�����:256MB
����
СHi�������һ���ַ�������Ϸ������һ��ֻ������д��ĸ"ABC"���ַ���s���������������½��еģ�

1)���s�������ȳ���1������ͬ��ĸ��ɵ��Ӵ�����ô��Щ�Ӵ��ᱻͬʱ���������µ��Ӵ�ƴ���µ��ַ���������"ABCCBCCCAA"��"CC","CCC"��"AA"�ᱻͬʱ����������"AB"��"B"ƴ���µ��ַ���"ABB"��
2)���������ᷴ��һ��һ�ֽ��У�ֱ���µ��ַ������������ڵ���ͬ�ַ�Ϊֹ�����硱ABCCBCCCAA������һ�������õ�"ABB"���پ���һ�������õ�"A"

��Ϸ�е�ÿһ��СHi�������һ���ַ���s����������ʼǰСHi�л�����s������λ��(��һ���ַ�֮ǰ�����һ���ַ�֮���Լ����������ַ�֮��)��������һ���ַ�('A','B'����'C')���õ��ַ���t��t����һϵ��������СHi�ĵ÷������������ַ���������
�����СHi����Ҫ��β����ַ������ܻ����ߵ÷֡�

����
�����һ����һ������T(1<=T<=100)������������ݵ�������
֮��T��ÿ��һ����'A''B''C'��ɵ��ַ���s�����Ȳ�����100��

���
����ÿһ��������ַ��������СHi����ܵõ��ķ�����

��ʾ
��һ�����ݣ���"ABCBCCCAA"�ĵ�2���ַ������'C'�õ�"ABCCBCCCAA"��������õ�"A"���ܹ�����9���ַ�(���������'C')��
�ڶ������ݣ�"AAA"����'A'�õ�"AAAA"��������õ�""���ܹ�����4���ַ���
���������ݣ������ǲ����ַ���õ�"AABC","ABBC"����"ABCC"���������2���ַ���

��������
3
ABCBCCCAA
AAA
ABC

�������
9
4
2
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * insertChar(char * s,int pos,char c){
	int l = strlen(s),i;
	char * re = (char *) malloc((l+2)*sizeof(char));
	for(i=0;i<l+2;i++){
		if(i<pos) re[i] = s[i];
		else if(i==pos) re[i] = c;
		else re[i] = s[i-1];
	}
	return re;
}

void delChar(char * s,int start,int end){
	int l = strlen(s),i,gap=end-start+1;
	for(i=start;i<l-gap+1;i++){
		s[i] = s[i+gap];
	}
}

int disappear(char * s){
	int flag,outflag,len,i,start,end,count = 0;
	char c;
	do{
		
		flag = 0,outflag=0;
		len = strlen(s);
		if(len<2) break;
		for(i=len-2;i>=0;i--){
			if(flag==0){
				if(s[i]==s[i+1]){
					flag = 1;
					c = s[i];
					start = i;
					end = i+1;
				}
			}
			else{
				if(s[i]==c){
					start = i;
				}
				else{
					count += (end-start+1);
					//printf("%D %d\n",start,end);
					delChar(s,start,end);
					flag = 0;
					outflag=1;
				}
			}
		}
		if(flag){
			count += (end-start+1);
			delChar(s,start,end);
			flag = 0;
		}
		//printf("%s %d\n",s,count);
	}while(outflag);
	return count;
}

int solve(char * s){
	char * tmp,max=0;
	int tv,i;
	for(i=0;i<strlen(s)+1;i++){
		tmp = insertChar(s,i,'A');
		tv = disappear(tmp);
		if(tv>max) max = tv;
		//printf("%s %d\n",tmp,disappear(tmp));
		tmp = insertChar(s,i,'B');
		tv = disappear(tmp);
		if(tv>max) max = tv;
		//printf("%s %d\n",tmp,disappear(tmp));
		tmp = insertChar(s,i,'C');
		tv = disappear(tmp);
		if(tv>max) max = tv;
		//printf("%s %d\n",tmp,disappear(tmp));
	}
	return max;
}

int main(){
	int t;
	//char str[102] = {"AAAA"};
	//printf("%d\n",disappear(str));

	
	char str[102] = {0};
	scanf("%d",&t);
	while(t-->0){
		scanf("%s",str);
		printf("%d\n",solve(str));
	}
	
	return 0;
}