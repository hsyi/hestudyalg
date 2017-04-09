#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5000+11;
const int inf=0x3f3f3f3f;
char cows[maxn];
bool magic[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cows[i];
    }
    pair<int,int> ans;
    ans.first=inf;
    for(int k=1;k<=n;k++){
        int tmp=0;
        int pre=0;
        memset(magic,0,sizeof(magic));
        for(int i=0;i<=n-k;i++){
            if((pre%2 && cows[i]=='F')||(pre%2==0 && cows[i]=='B')) {
                tmp++;
                //cout<<"==="<<endl;
                magic[i]=true;
                pre++;
            }
            if((i+1-k)>=0) {if(magic[i+1-k]) pre--;}
        }
        bool flag=true;;
        for(int i=n-k+1;i<n;i++){
            if((pre%2 && cows[i]=='F')||(pre%2==0 && cows[i]=='B')) {
                flag=false;
                break;
            }
            if((i+1-k)>=0) {if(magic[i+1-k]) pre--;}
        }
        if(flag){
            if(tmp<ans.first){
                ans=make_pair(tmp,k);
                //cout<<"MODEDEBUG   "<<tmp<<" "<<k<<endl;
            }
        }
    }
    cout<<ans.second<<" "<<ans.first<<endl;
            

    return 0;
}
