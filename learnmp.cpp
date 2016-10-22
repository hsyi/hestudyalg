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
const int INF=0x3f3f3f3f;
int failure[100];
void fail(string& p){
    for(int i=1,j=failure[0]=-1;i<p.size();++i){
      // while(j>=0 && p[j+1]!=p[i])
        //    j=failure[j];
        if(p[j+1] == p[i]) j++;
        else j=-1;
            failure[i]=j;
    }
}
int main(){
#ifndef ONLINE_JUDGE
   // freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
   // freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    string a=string("abzabzc");
    fail(a);
    for(int i=0;i<6;i++){
        printf("%d ",failure[i]);
    }
    getchar();
    return 0;
}
