#include<cstring>
#include<cstdio>
using namespace std;
int n;
int main(){
    int kas;
    scanf("%d",&kas);
    while(kas--){
        scanf("%d",&n);
        char c;
        c=getchar();
        while(c>'z' || c<'a') c=getchar();
        int counts[3]={1,0};
        char p=c;
        int cur=0;
        bool flag=false;
        for(int i=1;i<n;i++){
            c=getchar();
            if(flag) continue;
            if(c==p){
                counts[cur]++;
            }
            else if(c==p+1){
                if(cur<2){
                    cur=(cur+1)%3;
                    counts[cur]=1;
                }
                else{
                    counts[0]=counts[1];
                    counts[1]=counts[2];
                    counts[2]=1;
                }
            }
            else {
                counts[0]=1;
                counts[1]=counts[2]=0;
                cur=0;
            }
            if(counts[0]>=counts[1] && counts[2]>=counts[1] && counts[1]){
                puts("YES");
                flag=true;
            }
            p=c;
        }
        if(!flag) puts("NO");
    }
    return 0;
}

