/*
a:特殊密码锁
总时间限制: 1000ms 内存限制: 1024kB
描述
有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），按钮有凹/凸两种状态，用手按按钮会改变其状态。

然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。

当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。

输入
两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态，其中0代表凹，1代表凸。
输出
至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
样例输入
011
000
样例输出
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
