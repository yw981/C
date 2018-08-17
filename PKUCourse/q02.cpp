/*
b:拨钟问题
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有9个时钟，排成一个3*3的矩阵。

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
(图 1)
现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。



移动    影响的时钟
 
 1         ABDE
 2         ABC
 3         BCEF
 4         ADG
 5         BDEFH
 6         CFI
 7         DEGH
 8         GHI
 9         EFHI    
输入
9个整数，表示各时钟指针的起始位置，相邻两个整数之间用单个空格隔开。其中，0=12点、1=3点、2=6点、3=9点。
输出
输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号从小到大输出结果。相邻两个整数之间用单个空格隔开。
样例输入
3 3 0 
2 2 2 
2 1 2 
样例输出
4 5 8 9 
来源
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
