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

输入两个串s1,s2,
设MaxLen(i,j)表示:
s1的左边i个字符形成的子串，与s2左边的j个
字符形成的子串的最长公共子序列的长度(i,j从0开始算）
MaxLen(i,j) 就是本题的“状态”
假定 len1 = strlen(s1),len2 = strlen(s2）
那么题目就是要求 MaxLen(len1,len2)

显然：
MaxLen(n,0) = 0 ( n= 0…len1）
MaxLen(0,n) = 0 ( n=0…len2）
递推公式：
if ( s1[i-1] == s2[j-1] ) //s1的最左边字符是s1[0]
	MaxLen(i,j) = MaxLen(i-1,j-1) + 1;
else
	MaxLen(i,j) = Max(MaxLen(i,j-1),MaxLen(i-1,j) );
时间复杂度O(mn) m,n是两个字串长度

动态规划方法

   1、序列str1和序列str2
 
  ·长度分别为m和n；
  ·创建1个二维数组L[m.n]；
    ·初始化L数组内容为0
    ·m和n分别从0开始，m++，n++循环：
       - 如果str1[m] == str2[n]，则L[m,n] = L[m - 1, n -1] + 1；
       - 如果str1[m] != str2[n]，则L[m,n] = max{L[m,n - 1]，L[m - 1, n]}
    ·最后从L[m,n]中的数字一定是最大的，且这个数字就是最长公共子序列的长度
    ·从数组L中找出一个最长的公共子序列
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
		// 所求lcs[la][lb]
		// lcs数组里下标+1 
		for(i=0;i<la;i++)
			for(j=0;j<lb;j++)
				lcs[i+1][j+1]=a[i]==b[j]?lcs[i][j]+1:max(lcs[i][j+1],lcs[i+1][j]);
		cout << lcs[la][lb] << endl;
	}

}
/*
	循环完整写法 
		for(i=0;i<la;i++){
			for(j=0;j<lb;j++){
				// lcs数组里下标+1
				if(a[i]==b[j]){
					lcs[i+1][j+1] = lcs[i][j]+1;
				}
				else{
					lcs[i+1][j+1] = max(lcs[i][j+1],lcs[i+1][j]);
				}
			}
		}
		
*/

