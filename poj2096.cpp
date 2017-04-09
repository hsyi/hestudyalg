#include<iostream>
#include<iomanip>
using namespace std;
const int maxn=1e3+11;
const int maxs=1e3+11;
double dp[maxn][maxs];
int n,s;
int main(){
    while(cin>>n>>s){
        dp[n][s]=0;
        for(int i=n;i>=0;i--){
            for(int j=s;j>=0;j--){
                if(i==n && j==s) continue;
                dp[i][j]=((n-i)*j*dp[i+1][j]+i*(s-j)*dp[i][j+1]+(s-j)*(n-i)*dp[i+1][j+1]+n*s)/(s*n-i*j);
            }
        }
        cout<<fixed<<setprecision(4)<<dp[0][0]<<endl;
    }
    return 0;
}
