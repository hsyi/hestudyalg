#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=1011;

int dp[MAXN][MAXN];
char s1[MAXN],s2[MAXN];
string st[MAXN][MAXN];
int n;
void lcd(){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<1+n;i++)
        for(int j=1;j<1+n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                st[i][j]=st[i-1][j-1]+s1[i-1];
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                st[i][j]=(dp[i][j]==dp[i-1][j]?st[i-1][j]:st[i][j-1]);
                if(dp[i-1][j]==dp[i][j-1] )st[i][j]=min(st[i-1][j],st[i][j-1]);
            }
            if(dp[i][j]==dp[i-1][j]){
                  st[i][j]=min(st[i][j],st[i-1][j]);
            }
            if(dp[i][j]==dp[i][j-1]){
                   st[i][j]=min(st[i][j],st[i][j-1]);
            }
        }
}
/*
bool outf[MAXN];
void out(int i,int j){
    if(!outf[dp[i][j]) {
        outf[dp[i][j]]=true;
        //printf("%c",dpc[i][j]);
         if(i==0 || j==0) return ;
         if(dpw[i][j]==1){
             out(i-1,j-1);
            printf("%c",dpc[i][j]);
        }
        else if(dpw[i][j]==2){
            out(i-1,j);
        }
         else out(i,j-1);
}
*/
int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    while(cin>>s1){
        //cout<<s1<<' ';
        n=strlen(s1);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                st[i][j]="";
        for(int i=0;i<n;i++)
            s2[i]=s1[n-i-1];
        s2[n]='\0';
        //cout<<n<<"s2:"<<s2<<' ';
        lcd();
        int n2=st[n][n].length();
        for(int i=0;i<n2/2;i++){
            cout<<st[n][n][i];
        }
        if(n2%2) cout<<st[n][n][n2/2];
        for(int i=n2/2-1;i>=0;i--){
            cout<<st[n][n][i];
        }
        cout<<endl;
    }
    /*while(~scanf("%s",s1)){
        n=strlen(s1);
        for(int i=0;i<n;i++)
            s2[i]=s1[n-i-1];
        lcd();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(dp[i][j]==dp[n][n]){
                    out(i,j);
                    goto NEXT;
                }
            }
        NEXT:printf("\n");
    }*/
    return 0;
}
