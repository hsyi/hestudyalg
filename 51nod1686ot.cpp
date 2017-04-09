#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<bitset>
#include<vector>
#include<utility>
#include<numeric>
#include<cstring>
#include<iterator>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
#define fi first
#define se second
#define MP make_pair
#define ll long long
#define PR pair<ll,ll>
#define LS (root<<1)
#define RS ((root<<1)|1)
#define LSON LS,l,mid
#define RSON RS,(mid+1),r
#define MID mid=((l+r)/2)
#define mm(a,b) memset(a,b,sizeof(a))
#define rep(a,b,c) for(int a=b;a<c;a++)
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define Pi acos(-1.0)
#define MAXN 100005
#define MAXE 3000050
#define Inf 9999999
#define debug puts("**************");
template<class T> T f_max(T a, T b){ return a > b ? a : b; }
template<class T> T f_min(T a, T b){ return a < b ? a : b; }
template<class T> T f_abs(T a){ return a > 0 ? a : -a; }
template<class T> T gcd(T a, T b){ return b ? gcd(b, a%b) : a; }
template<class T> T lcm(T a, T b){ return a / gcd(a, b)*b; }
const int mod=1000007;
int n;
ll k;
int a[MAXN], b[MAXN];
int cnt[MAXN];
ll fxck(int x){
    mm(cnt,0);
    ll ret=0;
    int last=0;
    bool flag=false;
    for(int i=1;i<=n;i++){
        cnt[a[i]]++;
        if(cnt[a[i]]>=x){
            flag=true;
            if(cnt[a[i]]>x)
                cnt[a[last]]--, last++;
            while(a[last]!=a[i])
                cnt[a[last]]--, last++;
        }
        if(flag)
        ret+=(ll)last;
    }
//    printf("fxck(%d)=%lld\n",x,ret);
    return ret;
}
int main(){
    int T, cas=1;

    while(~scanf("%d%lld",&n,&k)){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+1+n);
        int m=unique(b+1,b+1+n)-(b+1);
        for(int i=1;i<=n;i++)
            a[i]=lower_bound(b+1,b+1+m,a[i])-b;
//        k=(ll)n*(n-1)/2-(k-1);
//        printf("%lld\n",k);
        int l=1, r=n, ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            cerr<<mid<<":";
            if(fxck(mid)>=k){
                l=mid+1;
                ans=mid;
                cerr<<"true"<<endl;
            }
            else{
                r=mid-1;
                cerr<<"false"<<endl;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
