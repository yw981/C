/*
2757:����������� Longest increasing subsequence
�鿴 �ύ ͳ�� ��ʾ ����
��ʱ������: 2000ms �ڴ�����: 65536kB
����
һ����������bi����b1 < b2 < ... < bS��ʱ�����ǳ���������������ġ����ڸ�����һ������(a1, a2, ..., aN)�����ǿ��Եõ�һЩ������������(ai1, ai2, ..., aiK)������1 <= i1 < i2 < ... < iK <= N�����磬��������(1, 7, 3, 5, 9, 4, 8)��������һЩ���������У���(1, 7), (3, 4, 8)�ȵȡ���Щ����������ĳ�����4������������(1, 3, 5, 8).

������񣬾��Ƕ��ڸ��������У��������������еĳ��ȡ�
����
����ĵ�һ�������еĳ���N (1 <= N <= 1000)���ڶ��и��������е�N����������Щ������ȡֵ��Χ����0��10000��
���
����������еĳ��ȡ�
��������
7
1 7 3 5 9 4 8
�������
4
��Դ
������ Northeastern Europe 2002, Far-Eastern Subregion �ı�������
*/

#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;
int main() {
	int n,i,j,prev=-1,data[MAX],lis[MAX];
	cin >> n;
	for(i=0;i<n;i++){
		cin >> data[i];
		// ����aNΪ�յ��������Ӵ�����
		// l(aN)=N֮ǰ��aNС�������Ǹ���1�����û�б�aNС��Ԫ����l(aN)=1 
		lis[i]=1;
		for(j=0;j<i;j++){
			if(data[j]<data[i]){
				// С��
				if(lis[j]+1>lis[i]) lis[i]=lis[j]+1;	
			}
		}
	}	
	cout << *max_element(lis,lis+n) << endl;
}
