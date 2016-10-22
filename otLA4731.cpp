#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<cstdlib>  
#include<iostream>  
#include<algorithm>  
#include<vector>  
#include<map>  
#include<queue>  
#include<stack> 
#include<string>
#include<map> 
using namespace std;  
#define LL long long  
const int maxn=105;
const int INF=1000000000;

int d[maxn][maxn];
int u[maxn],sum[maxn];//sum[i]是从u[i]到u[n]的和 

int cmp(int a,int b){
	return a>b;
}
int main(){
freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    freopen("/Users/heshengyi/Downloads/otout.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,w;
		scanf("%d%d",&n,&w);
		for(int i=1;i<=n;i++) scanf("%d",&u[i]);
		sort(u+1,u+n+1,cmp);
		//printf("%d\n",u[0]);
		
		sum[1]=u[1];
		for(int i=2;i<=n;i++) sum[i]=u[i]+sum[i-1]; 
		
		for(int i=1;i<=w;i++){
			for(int j=i;j<=i+n-w;j++){
				if(i==1){
					d[i][j]=j*sum[j];
					continue;
				}
				d[i][j]=INF;
				for(int k=i-1;k<j;k++)
					d[i][j]=min(d[i][j],d[i-1][k]+j*(sum[j]-sum[k]));
			}
		}
		//printf("%d\n",d[w][n]);
		double ans=(double)d[w][n]/sum[n];
		printf("%.4lf\n",ans);
	}
	return 0;
}
   
  
