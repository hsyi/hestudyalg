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
ll n;
char sit;

int main(){
#ifndef ONLINE_JUDGE
//    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
  //  freopen("/Users/heshengyi/Downloads/out.txt","w",stdout)
#endif
    ios::sync_with_stdio(false);
    cin>>n;
    ll round=(n-1)>>2;
    ll nhang=n%2;
    round*=(4+12);
    if(nhang==0) round+=6+1;
    cin>>sit;
    switch(sit){
        case 'f':round+=1;break;
        case 'e':round+=2;break;
        case 'd':round+=3;break;
        case 'a':round+=3+1;break;
        case 'b':round+=3+2;break;
        case 'c':round+=3+3;break;
        default:cout<<"bug"<<endl;
    }
    cout<<round;

    return 0;
}
