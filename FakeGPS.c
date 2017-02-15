#include <stdio.h>
int main(){
	int i,count=40000;
	double x=116.3792429120,y=39.8649483,fx=121.3210736,fy=31.1948953,gapx,gapy,gapmile;
	FILE * out = fopen("output.csv","w");
	fputs("LINECODE,LINENAME,MILE,POINTX,POINTY\n",out);
	gapmile = (double)1318.0 / count;
	gapx = (fx-x)/count;
	gapy = (fy-y)/count;
	for(i=0;i<=count;i++){
		fprintf(out,"3002,¾©»¦¸ßÌú,%.3lf,%.5lf,%.5lf\n",gapmile*i,x+gapx*i,y+gapy*i);
	}
	
	fclose(out);
	return 0;	
}
