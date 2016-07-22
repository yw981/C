#include<stdio.h>
#include<string.h>
int main(){
	char s[11]={0},t[11]={0},cs[11]={0},ct[11]={0},fr,to;
	int i,ls,lt,replace=0;
	gets(s);
	gets(t);
	ls=strlen(s);
	lt=strlen(t);
	if(ls!=lt){
		printf("Impossible\n");
		return 0;
	}
	else{
		for(i=0;i<ls;i++){
			if(replace==0){
				if(s[i]!=t[i]){
					fr=s[i];
					to=t[i];
					//printf("%c %c\n",fr,to);
					replace =1;
				}
			}
			else{
				if(s[i]==fr) s[i]=to;
				if(t[i]==fr) t[i]=to;
				if(s[i]!=t[i]){
					printf("Impossible\n");
					return 0;
				}
			}
		}
	}
	printf("Possible\n");
	return 0;
}