#include<iostream>
using namespace std;
const int maxn=1e5+11;
const int inf=0x3f3f3f3f;
int a[maxn];
int l,r;
int main(){
    int kas;
    cin>>kas;
    while(kas--){
        int n,s;
        cin>>n>>s;
        int ans=inf;
        int tmp=0;
        l=0;r=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            tmp+=a[i];
            while(l<=i && tmp>=s){
                if(tmp>=s) ans=min(ans,i-l+1);
                tmp-=a[l];
                l++;
            }
        }
        if(ans>=inf) ans=0; 
        cout<<ans<<endl;
    }
    return 0;
}


