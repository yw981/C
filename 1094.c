/*
#1094 : Lost in the City
时间限制:10000ms
单点时限:1000ms
内存限制:256MB

描述
Little Hi gets lost in the city. He does not know where he is. He does not know which direction is north.
Fortunately, Little Hi has a map of the city. The map can be considered as a grid of N*M blocks. Each block is numbered by a pair of integers. The block at the north-west corner is (1, 1) and the one at the south-east corner is (N, M). Each block is represented by a character, describing the construction on that block: '.' for empty area, 'P' for parks, 'H' for houses, 'S' for streets, 'M' for malls, 'G' for government buildings, 'T' for trees and etc.
Given the blocks of 3*3 area that surrounding Little Hi(Little Hi is at the middle block of the 3*3 area), please find out the position of him. Note that Little Hi is disoriented, the upper side of the surrounding area may be actually north side, south side, east side or west side.

输入
Line 1: two integers, N and M(3 <= N, M <= 200).
Line 2~N+1: each line contains M characters, describing the city's map. The characters can only be 'A'-'Z' or '.'.
Line N+2~N+4: each line 3 characters, describing the area surrounding Little Hi.

输出
Line 1~K: each line contains 2 integers X and Y, indicating that block (X, Y) may be Little Hi's position. If there are multiple possible blocks, output them from north to south, west to east.

样例输入
8 8
...HSH..
...HSM..
...HST..
...HSPP.
PPGHSPPT
PPSSSSSS
..MMSHHH
..MMSH..
SSS
SHG
SH.
样例输出
5 4
*/

#include<stdio.h>

int m,n;

void match(char map[][201],char me[][4]){
	int i,j;
	for(i=0;i<=m-3;i++){
		for(j=0;j<=n-3;j++){
			//printf("%c%c%c\n%c%c%c\n%c%c%c\n\n",me[0][0],me[0][1],me[0][2],me[1][0],me[1][1],me[1][2],me[2][0],me[2][1],me[2][2]);
			//printf("%c%c%c\n%c%c%c\n%c%c%c\n\n",map[i][j],map[i][j+1],map[i][j+2],map[i+1][j],map[i+1][j+1],map[i+1][j+2],map[i+2][j],map[i+2][j+1],map[i+2][j+2]);
			//printf("%c%c%c\n%c%c%c\n%c%c%c\n\n",map[i+2][j+2],map[i+2][j+1],map[i+2][j],map[i+1][j+2],map[i+1][j+1],map[i+1][j],map[i][j+2],map[i][j+1],map[i][j]);
			//printf("---------------------\n");
			if((me[0][0]==map[i][j] && me[0][1]==map[i][j+1] && me[0][2]==map[i][j+2] &&
				me[1][0]==map[i+1][j] && me[1][1]==map[i+1][j+1]&&me[1][2]==map[i+1][j+2]&&
				me[2][0]==map[i+2][j]&&me[2][1]==map[i+2][j+1]&&me[2][2]==map[i+2][j+2]) ||

				(me[0][0]==map[i][j+2]&&me[0][1]==map[i+1][j+2]&&me[0][2]==map[i+2][j+2]&&
				me[1][0]==map[i][j+1]&&me[1][1]==map[i+1][j+1]&&me[1][2]==map[i+2][j+1]&&
				me[2][0]==map[i][j]&&me[2][1]==map[i+1][j]&&me[2][2]==map[i+2][j]) ||

				(me[0][0]==map[i+2][j+2]&&me[0][1]==map[i+2][j+1]&&me[0][2]==map[i+2][j]&&
				me[1][0]==map[i+1][j+2]&&me[1][1]==map[i+1][j+1]&&me[1][2]==map[i+1][j]&&
				me[2][0]==map[i][j+2]&&me[2][1]==map[i][j+1]&&me[2][2]==map[i][j]) ||

				(me[0][0]==map[i+2][j]&&me[0][1]==map[i+1][j]&&me[0][2]==map[i][j]&&
				me[1][0]==map[i+2][j+1]&&me[1][1]==map[i+1][j+1]&&me[1][2]==map[i][j+1]&&
				me[2][0]==map[i+2][j+2]&&me[2][1]==map[i+1][j+2]&&me[2][2]==map[i][j+2]) 			
				
				){
					printf("%d %d\n",i+2,j+2);
			}			
		}
	}
	
}

int main(){
	int i,j;
	char map[201][201]={0},me[4][4]={0};
	//FILE * fp;
	//fp = fopen("data.txt","r");
	//fscanf(fp,"%d%d\n",&n,&m);
	scanf("%d%d\n",&n,&m);
	for(i=0;i<n;i++){
		//fscanf(fp,"%s",map[i]);
		scanf("%s",map[i]);
	}
	for(i=0;i<3;i++){
		//fscanf(fp,"%s",me[i]);
		scanf("%s",me[i]);
	}

	match(map,me);

	/*
	for(i=0;i<3;i++){
		printf("%s\n",me[i]);
	}
	*/
	return 0;
}