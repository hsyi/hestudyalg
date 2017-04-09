#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int k2,k3,k5,k6;
long long sum;
long long cnt256,cnt32;
int main(){
    cin>>k2>>k3>>k5>>k6;
    int min56=min(k2,min(k5,k6));
    cnt256=min56;
    sum+=cnt256*256;
    cnt32=min(k2-min56,k3);
    sum+=cnt32*32;
    cout<<sum;
    return 0;
}
