/*
#1038 : 01背包
时间限制:20000ms
单点时限:1000ms
内存限制:256MB

描述
且说上一周的故事里，小Hi和小Ho费劲心思终于拿到了茫茫多的奖券！而现在，终于到了小Ho领取奖励的时刻了！
小Ho现在手上有M张奖券，而奖品区有N件奖品，分别标号为1到N，其中第i件奖品需要need(i)张奖券进行兑换，同时也只能兑换一次，为了使得辛苦得到的奖券不白白浪费，小Ho给每件奖品都评了分，其中第i件奖品的评分值为value(i),表示他对这件奖品的喜好值。现在他想知道，凭借他手上的这些奖券，可以换到哪些奖品，使得这些奖品的喜好值之和能够最大。
提示一：合理抽象问题、定义状态是动态规划最关键的一步
提示二：说过了减少时间消耗，我们再来看看如何减少空间消耗

输入
每个测试点（输入文件）有且仅有一组测试数据。
每组测试数据的第一行为两个正整数N和M,表示奖品的个数，以及小Ho手中的奖券数。
接下来的n行描述每一行描述一个奖品，其中第i行为两个整数need(i)和value(i)，意义如前文所述。
测试数据保证
对于100%的数据，N的值不超过500，M的值不超过10^5
对于100%的数据，need(i)不超过2*10^5, value(i)不超过10^3

输出
对于每组测试数据，输出一个整数Ans，表示小Ho可以获得的总喜好值。

样例输入
5 1000
144 990
487 436
210 673
567 58
1056 897
样例输出
2099
 */
#include<stdio.h>

int weight[100] = {0},
	value[100]  = {0};

int pack(int capacity,int itemNum){
	int packThis,notPackThis;
	if(capacity<=0) return 0;
	if(itemNum==0){
		if(capacity<weight[itemNum]) return 0;
		else return value[itemNum];
	}
	else{
		if(capacity>weight[itemNum]){
			packThis = value[itemNum]+pack(capacity-weight[itemNum],itemNum-1);
			notPackThis = pack(capacity,itemNum-1);
			return packThis>notPackThis?packThis:notPackThis;
		}
		else{
			return pack(capacity,itemNum-1);
		}
	}
}

int main(){
	int i,n,cp;
	scanf("%d%d",&n,&cp);
	for(i=0;i<n;i++){
		scanf("%d%d",&weight[i],&value[i]);
	}
	printf("%d",pack(cp,n));
	return 0;
}