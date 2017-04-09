#include<vector>
#include<cstdio>
using namespace std;
const int MAXN=2e5+11;
int n,a,b,k;
int num[MAXN];
int main(){
    scanf("%d%d%d%d",&n,&a,&b,&k);
    getchar();
    for(int i=0;i<n;i++){
        char tmp=getchar();
        if(tmp=='1') num[i]=1;
    }
    vector<int> ans;
    int cnt=0;
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(num[i]==0) {
            cnt++;
            if(cnt==b) {
                ans.push_back(i+1);
                cnt=0;
                cnt1++;
            }
        }
        else cnt=0;
    }
    cnt1-=a-1;
    printf("%d\n",cnt1);
    for(int i=0;i<cnt1;i++){
        printf("%d ",ans[i]);
    }
        
    return 0;
}
    

