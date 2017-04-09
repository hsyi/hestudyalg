#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXV=62;
const int MAXN=51;
int f[MAXV][3];
int n;
int v[MAXN];
int w[MAXN];
int main(){
    int kas;
    scanf("%d",&kas);
    while(kas--){
        double tv;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf%d",&tv,&w[i]);
            v[i]=(int)(2*tv);
         //   printf("==%d %d\n",v[i],w[i]);
        }
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++){
            for(int j=MAXV-1;j>=0;j--){
                for(int k=2;k>=0;k--){
                    if(k!=0){
                        if((j-v[i]>0)&&f[j-v[i]][k-1]){
                            f[j][k]=max(f[j][k],f[j-v[i]][k-1]+w[i]);
         //                   if(j==10) printf("======k:%d %d %d",k,w[i],f[j][k]);
                        }
                    }
                    else{
                        if(v[i]==j)
                            f[j][k]=max(f[j][k],w[i]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=10;i<=60;i+=10){
            for(int j=0;j<3;j++){
                ans=max(ans,f[i][j]);
           //     printf("f[%d][%d] %d\n",i,j,f[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
            

