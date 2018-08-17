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

˼·����

����˼��ö�ٷ���ÿ����ť��2��״̬��������������30���ƣ����״̬��2^30֮�࣬���һ���ᳬʱ��

�ص�1 
һ����������˵ڶ��£��ͻ������һ�ΰ�����������Ӱ�졣��ˣ�һ����ֻ�а����߲������������������һ����Ҫ���ض�ε������

����˸��� 00000000 
��1�� 11000000 
��3�� 10110000 
��1�� 01110000 
��Ͱ˸��� 00000000 
ֻ��һ��3�� 01110000 
����ȫ��ͬ�����

�ص�2 
����ֻ��Ҫ�����Ƿ��µ�һ���ơ���Ϊ�����һ���Ƶ�״̬��ȷ���ˣ�
��ô�Ƿ��µڶ�����Ҳ�;����ˣ������һ������������ͬ�����£����������ͬ���򲻰��£�
ͬ�����������Ƿ���ҲΨһȷ����
���ԣ�����ֻҪ�������������1�����º�û�б����� 
֮��ʹ��forѭ���жϱ�ĵ��Ƿ���Ҫ���¼��� 
��ѭ�������������ڵĵƿ������ͬ����������ַ����а����������ٵģ�����ͬ����impossible��
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
	int mask = (1 << len) - 1;
	//printf("eq %d %d\n",a & mask,b & mask);
	return (a & mask) == (b & mask);
}

void flipLock(int & stat,int len,int pos){
	flipBit(stat,pos);
	if(pos>0)
		flipBit(stat,pos-1);
	if(pos<len-1)
		flipBit(stat,pos+1);
}

int tryConvert(int test,int len,int origin,int goal){
	int t,next,i,result = 0;
	setBit(result,len-1,test);
	if(test)
		flipLock(origin,len,len-1);
	for(i=len-1;i>=0;i--){
		if(i>0){
			next = getBit(origin,i)^getBit(goal,i);
			setBit(result,i-1,next);
			if(next)
				flipLock(origin,len,i-1);		
		}
		else{
			// i=0ʱ�ж�
			//printf("result %X %X\n",origin,result);
			if(getBit(origin,i)==getBit(goal,i)){
				return result;
			}
		}	
	}
	return -1;
}

int main(){
	char input[31]={0},output[31]={0};
	int origin = 0,goal = 0,i,count=0,len,result;
	gets(input);
	gets(output);
	len=strlen(input);
	for(i=len-1;i>=0;i--){
		setBit(origin,len-1-i,input[i]-'0');
		setBit(goal,len-1-i,output[i]-'0');
	}
	for(i=0;i<2;i++){
		result = tryConvert(i,len,origin,goal);
		if(result>=0){
			for(i=0;i<len;i++)
				if(getBit(result,i))
					count++;	
			printf("%d\n",count);
			return 0;
		}
	}
	printf("impossible\n",origin,goal);
	return 0;
}
