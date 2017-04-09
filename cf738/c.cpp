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
typedef long long ll;
const int INF=0x3f3f3f3f;
int n,k,s,t;
const int MAXN=2e5+11;
const int MAXK=2e5+11;
const int MAXS=2e9+11;
const int MAXT=2e9+11;
struct Car{int c,v;} car[MAXN];
bool cmp(Car &a,Car &b) {return a.c<b.c;}
bool cmp2(Car &a,Car &b) {return a.v<b.v;}
int g[MAXK];
int at,nt;
bool check(int v){
    int  maxl=v;
    double  minl=v/2.0;
    int p=0;
    double  mint=0;;
    for(int i=0;i<k;i++){
        int tmpl=g[i]-p;
        if(tmpl>maxl) return false;
        if(minl-(double)tmpl>1e-4) mint+=(double)tmpl;
        else {
            mint+=3.0*(double)tmpl-(double)v;
        }
        if(mint-(double)t>1e-4) return false;
        p=g[i];
    }
    return true;
}
int main(){
#ifndef ONLINE_JUDGE
//    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
  //  freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>s>>t;
    if(s>t) {
        cout<<"-1";
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>car[i].c;
        cin>>car[i].v;
    }
    for(int i=0;i<k;i++) cin>>g[i];
    g[k++]=s;
    sort(car,car+n,cmp2);
    sort(g,g+k);
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(car[mid].v)) r=mid-1;
        else l=mid+1;
    }
    //cout<<l<<" == "<<r<<endl;
    if(l==n) {
        cout<<"-1";
        return 0;
    }
    int v=car[l].v;
    sort(car,car+n,cmp);
    for(int i=0;i<n;i++){
        if(car[i].v>=v) {
            cout<<car[i].c;
            return 0;
        }
    }

    RES:cout<<"-1";
    return 0;
}
