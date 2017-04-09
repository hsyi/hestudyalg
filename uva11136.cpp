#include<iostream>
#include<set>
#include<cstring>
using namespace std;

int n;
multiset<int> ms;

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("out.txt","w",stdout);
    while(cin>>n && n){
        ms.clear();
        long long  ans=0;
        for(int i=0;i<n;i++){
            int k=0;
            cin>>k;
            for(int j=0;j<k;j++){
                int tmp=0;
                cin>>tmp;
                ms.insert(tmp);
            }
            //cout<<"bugreport\n";
            ans+=-(*(ms.begin()))+(*(--ms.end()));
            ms.erase(ms.begin());
            ms.erase(--ms.end());
        }
        cout<<ans<<endl;
    }
    return 0;
}
