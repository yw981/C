#include<stdio.h>
#include<string.h>

int getType(char c){
	// 1数字 3e 4小数点 99结束 -1其它
	if(c>='0'&&c<='9') return 1;
	else if(c=='e') return 3;
	else if(c=='.') return 4;
	else if(c==' ') return 5;
	else if(c==0) return 99;
    return -1;
}

int fsm(int stat,int type){
	// 99成功 -1失败
	if(stat==0){
		if(type==5) return 0;
		if(type==1) return 1;
	}
	if(stat==1){
		if(type==1) return 1;
		if(type==4) return 2;
		if(type==3) return 4;
		if(type==5) return 6;
		if(type==99) return 99;
	}
	if(stat==2){
		if(type==1) return 3;
	}
	if(stat==3){
		if(type==1) return 3;
		if(type==3) return 4;
		if(type==5) return 6;
		if(type==99) return 99;
	}
	if(stat==4){
		if(type==1) return 5;
	}
	if(stat==5){
		if(type==1) return 5;
		if(type==5) return 6;
		if(type==99) return 99;
	}
	if(stat==6){
		if(type==5) return 6;
		if(type==99) return 99;
	}
	return -1;
}

int isNumber(char* s) {
	int l = strlen(s),i,stat=0,type;
	for(i=0;i<=l;i++){

		stat = fsm(stat,getType(s[i]));
		printf("stat %d\n",stat);
		if(stat==99) return 1;
		if(stat==-1) return 0;
	}
    return 0;
}

int main(){
	char s[10]={"1"};
	printf("%d",isNumber(s));
	return 0;
}