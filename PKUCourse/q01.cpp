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

思路分析

首先思考枚举法，每个按钮有2种状态，但是最多可能有30个灯，因此状态有2^30之多，穷举一定会超时。

重点1 
一个灯如果按了第二下，就会抵消上一次按下所产生的影响。因此，一个灯只有按或者不按两种情况，不存在一个灯要开关多次的情况。

例如八个灯 00000000 
按1后 11000000 
按3后 10110000 
按1后 01110000 
这和八个灯 00000000 
只按一次3后 01110000 
是完全相同的情况

重点2 
我们只需要考虑是否按下第一个灯。因为如果第一个灯的状态被确定了，
那么是否按下第二个灯也就决定了（如果第一个灯与期望不同，则按下，如果期望相同，则不按下）
同理，第三个灯是否按下也唯一确定。
所以，本题只要分两种情况：灯1被按下和没有被按下 
之后使用for循环判断别的灯是否需要按下即可 
当循环结束，若现在的灯况与答案相同，则输出两种方案中按键次数最少的，若不同，则impossible！
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
			// i=0时判定
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
