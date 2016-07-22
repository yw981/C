/*
#1038 : 01����
ʱ������:20000ms
����ʱ��:1000ms
�ڴ�����:256MB

����
��˵��һ�ܵĹ����СHi��СHo�Ѿ���˼�����õ���ãã��Ľ�ȯ�������ڣ����ڵ���СHo��ȡ������ʱ���ˣ�
СHo����������M�Ž�ȯ������Ʒ����N����Ʒ���ֱ���Ϊ1��N�����е�i����Ʒ��Ҫneed(i)�Ž�ȯ���жһ���ͬʱҲֻ�ܶһ�һ�Σ�Ϊ��ʹ������õ��Ľ�ȯ���װ��˷ѣ�СHo��ÿ����Ʒ�����˷֣����е�i����Ʒ������ֵΪvalue(i),��ʾ���������Ʒ��ϲ��ֵ����������֪����ƾ�������ϵ���Щ��ȯ�����Ի�����Щ��Ʒ��ʹ����Щ��Ʒ��ϲ��ֵ֮���ܹ����
��ʾһ������������⡢����״̬�Ƕ�̬�滮��ؼ���һ��
��ʾ����˵���˼���ʱ�����ģ���������������μ��ٿռ�����

����
ÿ�����Ե㣨�����ļ������ҽ���һ��������ݡ�
ÿ��������ݵĵ�һ��Ϊ����������N��M,��ʾ��Ʒ�ĸ������Լ�СHo���еĽ�ȯ����
��������n������ÿһ������һ����Ʒ�����е�i��Ϊ��������need(i)��value(i)��������ǰ��������
�������ݱ�֤
����100%�����ݣ�N��ֵ������500��M��ֵ������10^5
����100%�����ݣ�need(i)������2*10^5, value(i)������10^3

���
����ÿ��������ݣ����һ������Ans����ʾСHo���Ի�õ���ϲ��ֵ��

��������
5 1000
144 990
487 436
210 673
567 58
1056 897
�������
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