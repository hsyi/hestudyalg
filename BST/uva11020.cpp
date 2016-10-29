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
struct Point{
    int x,y;
    bool  operator < (const Point b) const {
        return x<b.x || (x==b.x && y<b.y);
    }
};
multiset<Point> ms;
int main(){
#ifndef ONLINE_JUDGE
   freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
//    freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int T;
    bool fuck=false;
    scanf("%d",&T);
    REP(kas,T){
        int n;
        scanf("%d",&n);
        ms.clear();
        if(fuck) putchar(10);
        fuck=true;
        printf("Case #%d:\n",kas+1);
        REP(i,n){
            Point np;
            scanf("%d%d",&np.x,&np.y);
            multiset<Point>::iterator it;
            it=ms.lower_bound(np);//大于等于
            if(it!=ms.begin() && np.y  > (--it)->y) goto PT;
            ms.insert(np);

            it=ms.upper_bound(np);//大于

            while(it!=ms.end() && it->y >= np.y) {
                it=ms.erase(it);
            }
PT:          printf("%lu\n",ms.size());
        }
    }
    
    return 0;
}
