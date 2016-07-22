#include <stdio.h>
int qingkuang = 0;
void f(char * x, int r, int c,int row,int col);
 
void show(char * x,int row,int col)
{
    int i,j;
	for(i=0; i<row; i++){
        for(j=0; j<col; j++) printf("%c", x[i*row+j]);
        printf("\n");
    }
	//for(i=0; i<row*col; i++){
	//	printf("%c",x[i]);
	//}
    printf("\n");
}
 
void gonext(char * x, int r, int c,int row,int col)
{
	if(r==row-1&&c==col-1)
    {
        show(x,row,col);
        return;
    }

    if(c<col-1)
        f(x,r,c+1,row,col);   
    else
        f(x, r+1, 0,row,col);

	
}

void f(char * x, int r, int c,int row,int col){
	//printf("%d %d\n",r,c);
	if(x[r*col+c]=='?'){
		x[r*col+c]='R';
		//printf("%d %d try R\n",r,c);
		gonext(x,r,c,row,col);
		x[r*row+c]='C';
		//printf("%d %d try C\n",r,c);
		gonext(x,r,c,row,col);
	}
	else{
		gonext(x,r,c,row,col);
	}

    
 
    
}
int main(int argc, char* argv[])
{
    char x[3][6] = {
        "?C?RC",
		"C?RRR",
		"????R"
	};
    
 
    f(x, 0, 0 ,3 ,5);
     
 
    return 0;
}