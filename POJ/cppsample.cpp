#include <iostream>
#include<fstream>
#define MAX 101
using namespace std;
int main() {
	int n,i,j,data[MAX];
	ifstream cin("C:\\PROJECT\\C\\POJ\\in.txt");
	//freopen("in.txt","r",stdin);  
    //freopen("out.txt","w",stdout); 
	cin >> n;
	cin >> i;
	for(i=0;i<n;i++){
		cin >> data[i];
	}
	cout << n+i << endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;  
}
