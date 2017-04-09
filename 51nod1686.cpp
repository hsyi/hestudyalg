#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5+11;
int n;
ll k;
int a[maxn];
int b[maxn];
vector<int> vec;
int getid(int x){
    return lower_bound(vec.begin(),vec.end(),x)-vec.begin()+1;
}
bool check(int x){
    int l=0;
    ll cnt=0;
    bool flag=false;
    //map<int,int> mp;
    memset(b,0,sizeof(b));
    for(int r=1;r<=n;r++){
        //mp[a[r]]++;
        b[a[r]]++;
        if(b[a[r]]>=x){
            flag=true;
            if(b[a[r]]>x){
                b[a[l]]--;
                l++;
            }
            while(a[l]!=a[r]) b[a[l]]--,l++;
        }
        if(flag) cnt+=(ll)(l);
    }
    if(cnt>=k) return true;
    else return false;
}
int main(){
    cin>>n>>k;
    cerr<<k<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vec.push_back(a[i]);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i=1;i<=n;i++){
        a[i]=getid(a[i]);
        //cout<<a[i]<<endl;
    }
    int l=1,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        cerr<<mid<<":";
        if(check(mid)) {
            l=mid+1;
                   }
        else {
            r=mid-1;
                   }
    }
    cout<<r<<endl;
    return 0;
}
