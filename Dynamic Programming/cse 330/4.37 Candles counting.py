#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
void get_num(int j,int shift,int *zero,int *one);
void init( int n );
void range_increment( int i, int j, int val, int *tree );
int query( int i, int *tree );
int dp[128][150000];
int H[50000],C[50000],N;
int mask[8]={0,0b1,0b11,0b111,0b1111,0b11111,0b111111,0b1111111};

int main(){
  int N,K,i,j,x,y,max=-1;
  for(i=0;i<128;i++)
    for(j=0;j<150000;j++)
      dp[i][j]=0;
  scanf("%d%d",&N,&K);
  for(i=0;i<N;i++){
    scanf("%d%d",H+i,C+i);
    if(max==-1 || H[i]>max)
      max=H[i];
  }
  init(max);
  for(i=0;i<N;i++){
    if(H[i]!=1)
      for(j=0;j<(1<<(K-1));j++){
        get_num(j,C[i]-1,&x,&y);
        range_increment(H[i],max,query(H[i]-1,&dp[y][0]),&dp[y][0]);
        if(!j)
          range_increment(H[i],max,1,&dp[y][0]);
        else
          range_increment(H[i],max,query(H[i]-1,&dp[x][0]),&dp[y][0]);
      }
    else
      range_increment(H[i],max,1,&dp[1<<(C[i]-1)][0]);
  }
  printf("%d",query(max,&dp[(1<<K)-1][0]));
  return 0;
}
void get_num(int j,int shift,int *zero,int *one){
  int x,y;
  x=((j<<1)&(~mask[shift+1]));
  y=(j&mask[shift]);
  *zero=(x|y);
  *one=((*zero)|(1<<shift));
  return;
}
void init( int n ){
  N = 1;
  while( N < n ) N *= 2;
}
void range_increment( int i, int j, int val, int *tree ){
  for( i += N, j += N; i <= j; i = ( i + 1 ) / 2, j = ( j - 1 ) / 2 )
  {
    if( i % 2 == 1 ) tree[i] = (tree[i] +val)%MOD;
    if( j % 2 == 0 ) tree[j] = (tree[j] +val)%MOD;
  }
}
int query( int i, int *tree ){
  int ans = 0,j;
  for( j = i + N; j; j /= 2 ) ans = (ans+tree[j])%MOD;
  return ans;
}
