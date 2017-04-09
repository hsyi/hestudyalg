#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1011;
vector<int> v;
struct Post{
    int x1,x2,y1,y2;
} post[MAXN];
int w,h,n;
int getid(int l){
    return lower_bound(v.begin(),v.end(),l)-v.begin()+1;
}
int main(){
    cin>>w>>h>>n;
    for(int i=0;i<n;i++){
        cin>>post[i].x1>>post[i].y1>>post[i].x2>>post[i].y2;
        v.push_back(post[i].x1);
        v.push_back(post[i].y1);
        v.push_back(post[i].x2);
        v.push_back(post[i].y2);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<n;i++){
        post[i].x1=getid(post[i].x1);
        post[i].y1=getid(post[i].y1);
        post[i].x2=getid(post[i].x2);
        post[i].y2=getid(post[i].y2);
    }
    int ans=0,pos=0;
    for(int i=0;i<n;i++){
        int tmp=1;
        bool cover[4]={0};
        for(int j=i+1;j<n;j++){
            if(!(post[i].x2<=post[j].x1 || post[i].x1>=post[j].x2|| post[i].y2<=post[j].y1 || post[i].y1>=post[j].y2)){
                tmp++;
            }
            if(post[i].x1<post[j].x2 && post[i].x1>post[j].x1 && post[i].y1>post[j].y1 && post[i].y1<post[j].y2)
                cover[0]=1;
            if(post[i].x1<post[j].x2 && post[i].x1>post[j].x1 && post[i].y2>post[j].y1 && post[i].y2<post[j].y2)
                cover[1]=1;
            if(post[i].x2<post[j].x2 && post[i].x2>post[j].x1 && post[i].y1>post[j].y1 && post[i].y1<post[j].y2)
                cover[2]=1;
            if(post[i].x2<post[j].x2 && post[i].x2>post[j].x1 && post[i].y2>post[j].y1 && post[i].y2<post[j].y2)
                cover[3]=1;
            
        }
        if(tmp>ans && !(cover[0] &&  cover[1] && cover[2] && cover[3])){
            ans=tmp;
            pos=i+1;
        }
    }
    cout<<ans<<" "<<pos<<endl;
    return 0;
}
