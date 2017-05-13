#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 105
int c, n, m;
double dp[MAX*10][MAX];
int main()
{
 freopen("input.txt","r",stdin);
 while(scanf("%d",&c) != EOF)
 {
  if(c == 0) break;
  scanf("%d %d",&n,&m);
  if(m > c || m > n || (m+n)%2 != 0)
  {
   printf("0.000\n");
   continue;
  }
  memset(dp,0,sizeof(dp));
  if(n > 1000) n = 1000+n%2;
  dp[0][0] = 1;
  for(int i = 1; i <= n; ++i)
  {
   for(int j = 0; j <= c; ++j)
   {
    if( (i+j)%2 != 0 ) continue;
    dp[i][j] = dp[i-1][j-1]*(c-j+1.0)/c + dp[i-1][j+1]*(j+1.0)/c;
   }
  }
  printf("%.3lf\n",dp[n][m]);
 }
 return 0;
}
