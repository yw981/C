/*
2815:城堡问题
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述

     1   2   3   4   5   6   7  
   #############################
 1 #   |   #   |   #   |   |   #
   #####---#####---#---#####---#
 2 #   #   |   #   #   #   #   #
   #---#####---#####---#####---#
 3 #   |   |   #   #   #   #   #
   #---#########---#####---#---#
 4 #   #   |   |   |   |   #   #
   #############################
           (图 1)

   #  = Wall   
   |  = No wall
   -  = No wall

图1是一个城堡的地形图。请你编写一个程序，计算城堡一共有多少房间，最大的房间有多大。城堡被分割成m?n(m≤50，n≤50)个方块，每个方块可以有0~4面墙。
输入
程序从标准输入设备读入数据。第一行是两个整数，分别是南北向、东西向的方块数。在接下来的输入行里，每个方块用一个数字(0≤p≤50)描述。用一个数字表示方块周围的墙，1表示西墙，2表示北墙，4表示东墙，8表示南墙。每个方块用代表其周围墙的数字之和表示。城堡的内墙被计算两次，方块(1,1)的南墙同时也是方块(2,1)的北墙。输入的数据保证城堡至少有两个房间。
输出
城堡的房间数、城堡中最大房间所包括的方块数。结果显示在标准输出设备上。
样例输入
4 
7 
11 6 11 6 3 10 6 
7 9 6 13 5 15 5 
1 10 12 7 13 7 5 
13 11 10 8 10 12 13 
样例输出
5
9
       0010 2
       ___
0001 |      | 0100 4
       ---
       1000 8
*/
#include <iostream>
#include <cstring>
#include <fstream>
#define MAX 50
using namespace std;
int m,n,map[MAX][MAX],room[MAX][MAX];
int maxRoomArea = 0, roomNum = 0,roomArea;

void drawMap(){
	int i,j;
	for(i=0;i<m;i++){
		if(i==0){	
			for(j=0;j<n;j++){
				if(j==0) cout << "#";
				cout << "####";
			}
			cout << "\n";	
		}
		for(j=0;j<n;j++){
			if(j==0) cout << "#";
			cout << " " << room[i][j] << " ";
			//cout << (map[i][j] & 4); 按位与的结果是4不是1！ 
			if(map[i][j] & 4){
				cout << "#";
			}
			else{
				cout << "|";	
			}
		}
		cout << "\n";
		for(j=0;j<n;j++){
			if(j==0) cout << "#";
			if(map[i][j] & 8){
				cout << "###";
			}
			else{
				cout << "---";	
			}
			cout << "#";
		}
		cout << "\n";
	}	
}

void dfs(int i,int j){
	if(room[i][j] || i<0 || j<0 || i>=m || j>=n) return; //涂过色了
	//未涂过，涂上色
	room[i][j] = roomNum; 
	roomArea++;
	if( (map[i][j] & 1) == 0 ) dfs(i,j-1);
	if( (map[i][j] & 2) == 0 ) dfs(i-1,j);
	if( (map[i][j] & 4) == 0 ) dfs(i,j+1);
	if( (map[i][j] & 8) == 0 ) dfs(i+1,j);
	
}

int main() {
	int i,j;
	ifstream cin("C:\\PROJECT\\C\\POJ\\in.txt");
	//freopen("in.txt","r",stdin);  
    //freopen("out.txt","w",stdout); 
	cin >> m >> n;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	memset(room,0,sizeof(room));
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(room[i][j]==0){
				roomNum++;
				roomArea=0;
				dfs(i,j);
				if(roomArea>maxRoomArea) maxRoomArea = roomArea;
			}
		}
	}
	cout << roomNum << endl;
	cout << maxRoomArea << endl;
	drawMap();
	return 0;  
}
