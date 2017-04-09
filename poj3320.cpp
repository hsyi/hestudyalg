#include<set>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxp=1e6+11;
int a[maxp];
map<int,int> mp;
int main(){
    int p;
    scanf("%d",&p);
    int ans=inf;
    int sum=0,tmp=0;
    for(int i=0;i<p;i++){
        //cin>>a[i];
        scanf("%d",&a[i]);
        if(mp.find(a[i])==mp.end()) {sum++;mp[a[i]]=0;}
    }
    int s=0,e=0;
    tmp=1;
    mp[a[0]]=1;
    for(;;){
        while(e<p-1 && tmp<sum){
            if(mp[a[++e]]==0) tmp++;
            mp[a[e]]++;
        }
        if(tmp<sum) break;
        ans=min(e-s+1,ans);
        if(--mp[a[s++]]==0) tmp--;
    }
    //cout<<ans<<endl;
    printf("%d\n",ans);
    return 0;
}




