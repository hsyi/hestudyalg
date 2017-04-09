#include<iostream>
#include<algorithm>
#define lowbit(x) x&-x
using namespace std;
const int MAXK=5e4+11;
int B[MAXK],s[MAXK],a[MAXK];
int k;
void add(int p,int x){
    for(int i=p;i<=k;i+=lowbit(i)){
        B[i]+=x;
    }
}
int sum(int p){
    int ret=0;
    for(int i=p;i;i-=lowbit(i)) ret+=B[i];
    return ret;
}
int main(){
    int kas=0;
    cin>>kas;
    while(kas--){
        cin>>k;
        for(int i=1;i<=k;i++) add(i,1);
        for(int i=0;i<k;i++){
            int s;
            cin>>s;
            s++;
            if(i) cout<<" ";
            int l=1,r=k;
            while(l<r){
                int mid=(l+r)>>1;
                if(sum(mid)>=s) r=mid;
                else l=mid+1;
            }
            add(r,-1);
            cout<<r;
        }
        cout<<endl;
    }
    return 0;
}


