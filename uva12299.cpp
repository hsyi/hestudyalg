#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN=1e5+11;
int a[MAXN];
int Min[MAXN<<2];
int n,q;
void build(int l,int r,int rt){
    if(l==r) {Min[rt]=a[l];return;}
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)  cin>>a[i];
    build(1,n,1);
    char Query[40];
    getline(cin,Query);


