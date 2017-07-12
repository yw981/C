/*
2815:�Ǳ�����
�鿴 �ύ ͳ�� ��ʾ ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����

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
           (ͼ 1)

   #  = Wall   
   |  = No wall
   -  = No wall

ͼ1��һ���Ǳ��ĵ���ͼ�������дһ�����򣬼���Ǳ�һ���ж��ٷ��䣬���ķ����ж�󡣳Ǳ����ָ��m?n(m��50��n��50)�����飬ÿ�����������0~4��ǽ��
����
����ӱ�׼�����豸�������ݡ���һ���������������ֱ����ϱ��򡢶�����ķ��������ڽ��������������ÿ��������һ������(0��p��50)��������һ�����ֱ�ʾ������Χ��ǽ��1��ʾ��ǽ��2��ʾ��ǽ��4��ʾ��ǽ��8��ʾ��ǽ��ÿ�������ô�������Χǽ������֮�ͱ�ʾ���Ǳ�����ǽ���������Σ�����(1,1)����ǽͬʱҲ�Ƿ���(2,1)�ı�ǽ����������ݱ�֤�Ǳ��������������䡣
���
�Ǳ��ķ��������Ǳ�����󷿼��������ķ������������ʾ�ڱ�׼����豸�ϡ�
��������
4 
7 
11 6 11 6 3 10 6 
7 9 6 13 5 15 5 
1 10 12 7 13 7 5 
13 11 10 8 10 12 13 
�������
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
			//cout << (map[i][j] & 4); ��λ��Ľ����4����1�� 
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
	if(room[i][j] || i<0 || j<0 || i>=m || j>=n) return; //Ϳ��ɫ��
	//δͿ����Ϳ��ɫ
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
