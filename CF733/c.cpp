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
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define REP(i, n) for (int i=0;i<n;++i)
#define clr(x,a) memset(x,a,sizeof(x))
#define RD(x) scanf("%d",&x)
typedef long long ll;
const int INF=0x3f3f3f3f;
int n,m;
const int MAXN=511;
const int MAXM=511;
int a[MAXN],b[MAXM];

vector<pair<int,char> > ans;

bool getans(int s,int e,int bas){
    int maxid=0;
    a[0]=0;
    for(int i=s;i<=e;i++){
        if(a[i]>a[maxid]) maxid=i;
    }
    while(e-s>=1){
        if(a[maxid]>a[maxid+1] && maxid+1<=e){
            ans.push_back(mp(maxid-s+1+bas,'R'));
            a[maxid]+=a[maxid+1];
            for(int i=maxid+1;i<=e;i++){
                a[i]=a[i+1];
            }
            e--;
        }
        else if(a[maxid]>a[maxid-1] && maxid-1>=s){
            a[maxid]+=a[maxid-1];
            ans.push_back(mp(maxid-s+1+bas,'L'));
            for(int i=maxid-1;i<=e;i++){
                a[i]=a[i+1];
            }
            e--;
            maxid--;
        }
        else {
            if(maxid<e) maxid++;
            else return false;
        }
    }
    return true;
}

        
int main(){
#ifndef ONLINE_JUDGE
    //freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
   // freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    RD(n);
    REP(i,n){
        RD(a[i+1]);
    }
    RD(m);
    REP(i,m) RD(b[i+1]);
    int pb=1;
    int sum=0;
    a[0]=a[1];
    int ps=1;
    REP(i,n){
        sum+=a[i+1];
        if(sum==b[pb]){
            if(!getans(ps,i+1,pb-1)) {
                goto pno;
             }
             if(pb==m && i==n-1){
                printf("YES\n");
                REP(i,(int)ans.size()){
                    printf("%d %c\n",ans[i].first,ans[i].second);
                }
                return 0;
             }
            ps=i+2;
            sum=0;
            pb++;
        }
    }

pno:printf("NO");

    return 0;
}
