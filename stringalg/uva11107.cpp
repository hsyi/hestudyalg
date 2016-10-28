#pragma comment(linker"/STACK:1024000000,1024000000")
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
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define REP(i, n) for (int i=0;i<n;++i)
#define clr(x,a) memset(x,a,sizeof(x))
typedef long long ll;
const int INF=0x3f3f3f3f;

const int MAXN=1010*111;
int  s[MAXN];//char表示范围-128~127
int t[MAXN],t2[MAXN],sa[MAXN],h[MAXN],*ranks;
int c[MAXN];//c对应所有后缀数组的rank种类数，所以也要开大点！！
int n;
void build_sa(int m){
    //assert (n==365);
    int *x=t,*y=t2;
    REP(i,m) c[i]=0;
    REP(i,n) c[x[i]=s[i]]++;
    for(int i=1;i<m;i++) c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1){
        int p=0;
        for(int i=n-k;i<n;i++) y[p++]=i;
        REP(i,n) if(sa[i]>=k) y[p++]=sa[i]-k;

        REP(i,m) c[i]=0;
        REP(i,n) c[x[y[i]]]++;
        for(int i=1;i<m;i++) c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]] = y[i];
        
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(int i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
        if(p>n-1) break;
        m=p;
    }
    ranks=x;
    //assert(n==365);
}

void calcuh(){
    int k=0;
    for(int i=0;i<n;i++){
        if(k) k--;
        if(ranks[i]==0) {h[ranks[i]]=0;k=0;continue;}
        int j=sa[ranks[i]-1];
        while(j+k<n && k+i<n && s[j+k]==s[i+k]) k++;
        h[ranks[i]]=k;
    }
}
bool flags[1111];
int idx[MAXN];
int nn;
bool ifgood (int L,int R){
        memset(flags,0,sizeof(flags));
        if(R-L<=nn/2) return false;
        int cnt=0;
        for(int i=L;i<R;i++){
            int x=idx[sa[i]];
            if(!flags[x]) { flags[x]=1;cnt++;}
        }
        return cnt>nn/2;
}

void print_sub(int l,int r){
    for(int i=l;i<r;i++){
        printf("%c",s[i]+'a'-1);
    }
    printf("\n");
}

bool isok(int l,bool print){
    int L=0;
    for(int R=1;R<=n;R++){
        if(R==n || h[R]<l){
            if(ifgood(L,R)) {
                if(print) print_sub(sa[L],sa[L]+l);
                else return true;
            }
            L=R;
        }
    }
    return false;
}

    char ss[1111];
int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
   // freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int kas=0;
    while(~scanf("%d",&nn)&&nn){
        if(kas++) putchar(10); 
        if(nn<200) printf("bugshuju");
        n=0;
        int maxl=0;
        REP(i,nn){
            scanf("%s",ss);
            maxl=max(maxl,(int)strlen(ss));
            REP(j,(int)strlen(ss)){
                s[n]=ss[j]-'a'+1;
                idx[n++]=i+1;
            }
            s[n++]=30+i;
            
            idx[n-1]=i+1;
        }
        s[n]='\0';
        if(nn==1){
            puts(ss);
            continue;
        }
        //puts(s);
        //printf("n: %d\n",n);
      //  printf("%d\n",n);
        build_sa(300);
        calcuh();
        //printf("%d\n",n);
       // printf("tofindbug2\n");
       // for(int i=0;i<n;i++) {
        //    printf("%d ",h[i]);
       // }
       // printf("\n");
       // printf("tofindbug\n");
        //for(int i=0;i<n;i++) {
        //    printf("%d ",ranks[i]);
        //}
        //printf("\n");
        int l=1,r=maxl;
        while(l<=r){
            int m=l+((r-l)>>1);
            if(isok(m,0)) l=m+1;
            else {
 //              assert (m>6) ;
                r=m-1;
            }
        }
        if(r) isok(r,1);
        else printf("?\n");
       // if(isok(2,0)) printf("buggggg\n");
       // else printf("buginisok");
       // printf("%d\n",r);
    }

        

    return 0;
}
