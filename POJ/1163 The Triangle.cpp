/*
The Triangle
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 47545		Accepted: 28777
Description

7
3   8
8   1   0
2   7   4   4
4   5   2   6   5

(Figure 1)
Figure 1 shows a number triangle. Write a program that calculates the highest sum of numbers passed on a route that starts at the top and ends somewhere on the base. Each step can go either diagonally down to the left or diagonally down to the right. 
Input

Your program is to read from standard input. The first line contains one integer N: the number of rows in the triangle. The following N lines describe the data of the triangle. The number of rows in the triangle is > 1 but <= 100. The numbers in the triangle, all integers, are between 0 and 99.
Output

Your program is to write to standard output. The highest sum is written as an integer.
Sample Input

5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
Sample Output

30
Source

IOI 1994
*/

#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
int main() {
	// C++自动初始化 ？ 
	int data[MAX][MAX],maxSum[MAX][MAX];
	int n,i,j;
	cin >> n;
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			cin >> data[i][j];
	for(j=0;j<n;j++)
		maxSum[n-1][j]=data[n-1][j];
	for(i=n-2;i>=0;i--)
		for(j=0;j<=i;j++)
			maxSum[i][j]=data[i][j]+max(maxSum[i+1][j],maxSum[i+1][j+1]);
	cout << maxSum[0][0] << endl;
}
