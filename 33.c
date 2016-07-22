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
        if(NumRow!=3||NumCol!=3) return 0;  // ���
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
        f(x,r,c+1);   // ���
    else
        f(x, r+1, 0);
}

//����x���̵ĵ�r�е�c��
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
 
    if(x[r][c]==1)  // �Ѿ�����������
    {
        GoNext(x,r,c);
        return;
    }
     
    rr = GetRowStoneNum(x,r);
    cc = GetColStoneNum(x,c);
 
    if(cc>=3)  // ��������
        GoNext(x,r,c);  
    else if(rr>=3)  // ��������
        f(x, r+1, 0);   
    else
    {
		//�����Է���
        x[r][c] = 1;
        GoNext(x,r,c);
        x[r][c] = 0;
        
		//���񲻷���
        if(!(3-rr >= 6-c || 3-cc >= 6-r))  // ���л�������ȱ�ӣ��򱾸��ܿ��ţ��ٿ���һ��Ҳ������3���ˣ�
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