#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1011;
char cakes[maxn];
int k;
int len;
bool flip[maxn];
void gao(){
    memset(flip,0,sizeof(flip));
    int cur=0;
    int ans=0;
    for(int i=1;i<=len-k+1;i++){
        if(i-k>0) {
            if(flip[i-k]) cur--;  
        }
        if((cakes[i-1]=='-' && ((cur&1)==0)) || (cakes[i-1]=='+' && (cur&1) ) ) {
            flip[i]=true;
            cur++;  
            ans++;
        }
       // printf("i:%d flip:%d\n",i,flip[i]);
    }
    for(int i=len-k+2;i<=len;i++){
         if(i-k>0) {
            if(flip[i-k]) cur--;  
            //printf("%d\n",cur);
        }
         if((cakes[i-1]=='-' && ((cur&1) ==0)) || (cakes[i-1]=='+' && (cur&1) ) ) {
            //printf("debug\n");
            //printf("%c \n",cakes[i-1]);
           goto FAIL;  
        }
       // printf("i:%d flip:%d\n",i,flip[i]);
    }
    printf("%d\n",ans);
    return;
    FAIL:
    printf("IMPOSSIBLE\n");

}
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        scanf("%s%d",cakes,&k);
        len=strlen(cakes);
        printf("Case #%d: ",cas++);
        gao();
    }
}