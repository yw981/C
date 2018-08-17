/*
b:��������
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��9��ʱ�ӣ��ų�һ��3*3�ľ���

|-------|    |-------|    |-------|
|       |    |       |    |   |   |
|---O   |    |---O   |    |   O   |
|       |    |       |    |       |
|-------|    |-------|    |-------|
    A            B            C    

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O   |    |   O   |
|   |   |    |   |   |    |   |   |
|-------|    |-------|    |-------|
    D            E            F    

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O---|    |   O   |
|   |   |    |       |    |   |   |
|-------|    |-------|    |-------|
    G            H            I    
(ͼ 1)
������Ҫ�����ٵ��ƶ�����9��ʱ�ӵ�ָ�붼����12���λ�á���������9�ֲ�ͬ���ƶ������±���ʾ��ÿ���ƶ��Ὣ���ɸ�ʱ�ӵ�ָ����˳ʱ�뷽�򲦶�90�ȡ�



�ƶ�    Ӱ���ʱ��
 
 1         ABDE
 2         ABC
 3         BCEF
 4         ADG
 5         BDEFH
 6         CFI
 7         DEGH
 8         GHI
 9         EFHI    
����
9����������ʾ��ʱ��ָ�����ʼλ�ã�������������֮���õ����ո���������У�0=12�㡢1=3�㡢2=6�㡢3=9�㡣
���
���һ����̵��ƶ����У�ʹ��9��ʱ�ӵ�ָ�붼ָ��12�㡣�����ƶ�����Ŵ�С������������������������֮���õ����ո������
��������
3 3 0 
2 2 2 
2 1 2 
�������
4 5 8 9 
��Դ
1166
*/
#include<stdio.h>
#include<string.h>

int getGroup(long long num,int which){
	return (num >> (which*2)) & 3;	
}
/*
 1        ABDE
 2         ABC
 3         BCEF
 4         ADG
 5         BDEFH
 6         CFI
 7         DEGH
 8         GHI
 9         EFHI 
 */ 
void changeClock(int clock[],int group,int num){
	int len[9] = {4,3,4,3,5,3,4,3,4},i;
	int data[9][5] = {
		{0,1,3,4},
		{0,1,2},
		{1,2,4,5},
		{0,3,6},
		{1,3,4,5,7},
		{2,5,8},
		{3,4,6,7},
		{6,7,8},
		{4,5,7,8}	
	};
	for(i=0;i<len[group];i++){
		clock[data[group][i]] = (clock[data[group][i]] + num )%4;	
	}
	// printf("change ok\n");
}

void convert(int start[],int test){
	int t,next,i,result = 0;
	for(i=0;i<9;i++){
		t = getGroup(test,i);
		printf("%d",t);
		changeClock(start,i,t);
	}
	printf(" ok\n");
}

int check(int clock[]){
	int i;
	for(i=0;i<9;i++){
		if(clock[i]!=0) return 0;
	}
	return 1;
}

int main(){
	int input[9]={0},copy[9],j,origin = 0,goal = 0,count=0,len,result;
	long long i;
	for(i=0;i<9;i++){
		scanf("%d",&input[i]);
	}
	for(i=0;i<(1<<18);i++){
		for(j=0;j<9;j++){
			copy[j] = input[i];
		}
		convert(copy,i);
		if(i % 10000 == 0) printf("cc %X\n",i);
		if(check(copy)){
			printf("%X\n",i);
			return 0;
		}
	 	if(i % 10000 == 0) printf("dd %X\n",i);
	}
	printf("impossible\n",origin,goal);
	return 0;
}
