#include<iostream>
#include<map>
using namespace std;
const int maxn=2e5+11;
int a[maxn];
int n,k;
map<int,int> mp;
int main(){
    int kas;
    cin>>kas;
    while(kas--){
        cin>>n>>k;
        int l=0,r=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(mp[a[i]]!=0) r+=mp[a[i]];
            mp[a[i]]++;
        }
        while(l<r){
            int mid=(r+l)>>1;

    return 0;
}
