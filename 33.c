#include <stdio.h>
int N = 0;
void f(int x[][6], int r, int c);
int CheckStoneNum(int x[][6])
{
	int i,k;
    for(k=0; k<6; k++)
    {
        int NumRow = 0;
        int NumCol = 0;
        for(i=0; i<6; i++)
        {
            if(x[k][i]) NumRow++;
            if(x[i][k]) NumCol++;
        }
        if(NumRow!=3||NumCol!=3) return 0;  // 填空
    }
    return 1;
}
 
int GetRowStoneNum(int x[][6], int r)
{
    int sum = 0,i;
    for(i=0; i<6; i++)   if(x[r][i]) sum++;
    return sum;
}
 
int GetColStoneNum(int x[][6], int c)
{
    int sum = 0,i;
    for(i=0; i<6; i++)   if(x[i][c]) sum++;
    return sum;
}
 
void show(int x[][6])
{
    int i,j;
	for(i=0; i<6; i++){
        for(j=0; j<6; j++) printf("%2d", x[i][j]);
        printf("\n");
    }
    printf("\n");
}
 
void GoNext(int x[][6],  int r,  int c)
{
    if(c<6)
        f(x,r,c+1);   // 填空
    else
        f(x, r+1, 0);
}

//处理x棋盘的第r行第c列
void f(int x[][6], int r, int c)
{
	int rr,cc;
    if(r==6)
    {
        if(CheckStoneNum(x))
        {
            N++;
            //show(x);
        }
        return;
    }
 
    if(x[r][c]==1)  // 已经放有了棋子
    {
        GoNext(x,r,c);
        return;
    }
     
    rr = GetRowStoneNum(x,r);
    cc = GetColStoneNum(x,c);
 
    if(cc>=3)  // 本列已满
        GoNext(x,r,c);  
    else if(rr>=3)  // 本行已满
        f(x, r+1, 0);   
    else
    {
		//本格尝试放子
        x[r][c] = 1;
        GoNext(x,r,c);
        x[r][c] = 0;
        
		//本格不放子
        if(!(3-rr >= 6-c || 3-cc >= 6-r))  // 本行或本列严重缺子，则本格不能空着，再空着一共也够不了3个了！
            GoNext(x,r,c);  
    }
}
int main(int argc, char* argv[])
{
    int x[6][6] = {
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };
 
    f(x, 0, 0);
     
    printf("%d\n", N);
 
    return 0;
}