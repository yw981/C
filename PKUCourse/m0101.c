/*
a:����������
��ʱ������: 1000ms �ڴ�����: 1024kB
����
��һ������Ķ���������������n�������İ�ť��ɣ�n<30������ť�а�/͹����״̬�����ְ���ť��ı���״̬��

Ȼ������ͷ�۵��ǣ����㰴һ����ťʱ���������ڵ�������ť״̬Ҳ�ᷴת����Ȼ������㰴��������������ұߵİ�ť���ð�ťֻ��Ӱ�쵽�������ڵ�һ����ť��

��ǰ������״̬��֪����Ҫ����������ǣ���������Ҫ�����ٴΰ�ť�����ܽ�������ת��Ϊ��������Ŀ��״̬��

����
���У�����������0��1��ɵĵȳ��ַ�������ʾ��ǰ/Ŀ��������״̬������0������1����͹��
���
������Ҫ���еİ���ť��������������޷�ʵ��ת�䣬�����impossible��
��������
011
000
�������
1
*/
#include<stdio.h>
#include<string.h>
int getBit(int num,int i){
	return (num >> i) & 1;	
}

void setBit(int & num,int i,int val){
	if(val)
		num |= (1 << i);
	else 
		num &= ~(1 << i);
}

void flipBit(int & num,int i){
	num ^= (1 << i);
}

int equal(int len,int a,int b){
	
}

void flipLock(int & stat,int len,int pos){
	flipBit(stat,pos);
	if(pos>0)
		flipBit(stat,pos-1);
	if(pos<len-1)
		flipBit(stat,pos+1);
}

int main(){
	char input[31]={0},output[31]={0};
	int i,len,lt,replace=0;
	gets(input);
	gets(output);
	len=strlen(input);
	for(i=0;i<(1>>len);i++){
		
	}
	lt=strlen(t);
	printf("Possible %d\n",sizeof(double));
	return 0;
}
