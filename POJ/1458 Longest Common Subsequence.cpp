/* 
Longest Common Subsequence
Common Subsequence
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 50871		Accepted: 20956
Description

A subsequence of a given sequence is the given sequence with some elements (possible none) left out. Given a sequence X = < x1, x2, ..., xm > another sequence Z = < z1, z2, ..., zk > is a subsequence of X if there exists a strictly increasing sequence < i1, i2, ..., ik > of indices of X such that for all j = 1,2,...,k, xij = zj. For example, Z = < a, b, f, c > is a subsequence of X = < a, b, c, f, b, c > with index sequence < 1, 2, 4, 6 >. Given two sequences X and Y the problem is to find the length of the maximum-length common subsequence of X and Y.
Input

The program input is from the std input. Each data set in the input contains two strings representing the given sequences. The sequences are separated by any number of white spaces. The input data are correct.
Output

For each set of data the program prints on the standard output the length of the maximum-length common subsequence from the beginning of a separate line.
Sample Input

abcfbc         abfcab
programming    contest 
abcd           mnp
Sample Output

4
2
0
Source

Southeastern Europe 2003

����������s1,s2,
��MaxLen(i,j)��ʾ:
s1�����i���ַ��γɵ��Ӵ�����s2��ߵ�j��
�ַ��γɵ��Ӵ�������������еĳ���(i,j��0��ʼ�㣩
MaxLen(i,j) ���Ǳ���ġ�״̬��
�ٶ� len1 = strlen(s1),len2 = strlen(s2��
��ô��Ŀ����Ҫ�� MaxLen(len1,len2)

��Ȼ��
MaxLen(n,0) = 0 ( n= 0��len1��
MaxLen(0,n) = 0 ( n=0��len2��
���ƹ�ʽ��
if ( s1[i-1] == s2[j-1] ) //s1��������ַ���s1[0]
	MaxLen(i,j) = MaxLen(i-1,j-1) + 1;
else
	MaxLen(i,j) = Max(MaxLen(i,j-1),MaxLen(i-1,j) );
ʱ�临�Ӷ�O(mn) m,n�������ִ�����

��̬�滮����

   1������str1������str2
 
  �����ȷֱ�Ϊm��n��
  ������1����ά����L[m.n]��
    ����ʼ��L��������Ϊ0
    ��m��n�ֱ��0��ʼ��m++��n++ѭ����
       - ���str1[m] == str2[n]����L[m,n] = L[m - 1, n -1] + 1��
       - ���str1[m] != str2[n]����L[m,n] = max{L[m,n - 1]��L[m - 1, n]}
    ������L[m,n]�е�����һ�������ģ���������־�������������еĳ���
    ��������L���ҳ�һ����Ĺ���������
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1000
using namespace std;
int main() {
	int la,lb,i,j,lcs[MAX][MAX];
	char a[MAX],b[MAX];
	while(cin >> a >> b){
		la = strlen(a);
		lb = strlen(b);
		// ����lcs[la][lb]
		// lcs�������±�+1 
		for(i=0;i<la;i++)
			for(j=0;j<lb;j++)
				lcs[i+1][j+1]=a[i]==b[j]?lcs[i][j]+1:max(lcs[i][j+1],lcs[i+1][j]);
		cout << lcs[la][lb] << endl;
	}

}
/*
	ѭ������д�� 
		for(i=0;i<la;i++){
			for(j=0;j<lb;j++){
				// lcs�������±�+1
				if(a[i]==b[j]){
					lcs[i+1][j+1] = lcs[i][j]+1;
				}
				else{
					lcs[i+1][j+1] = max(lcs[i][j+1],lcs[i+1][j]);
				}
			}
		}
		
*/

