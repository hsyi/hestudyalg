// BEGIN CUT HERE

// END CUT HERE
#line 5 "BinaryCode.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
const int MAXN=55;
int p[MAXN];
int Q[MAXN];
int n;
class BinaryCode
{
        public:
        string gao(bool assume0){
            if(assume0) p[0]=0;
            else p[0]=1;
            int msum=p[0];
            stringstream ans;
            ans<<p[0];
            for(int i=1;i<=n;i++){
                p[i]=Q[i-1]-msum;
                if(p[i]<0 || p[i]>1) return "NONE";
                if(i-2>=0) msum-=p[i-2];
                msum+=p[i];
                if(i==n) {
                    if(p[i]) return "NONE";
                }
                else ans<<p[i];
            }
            return ans.str();
        }
        vector <string> decode(string message)
        {
            vector<string> ans;
            n=message.length();
            memset(Q,0,sizeof(Q));
            for(int i=0;i<n;i++){
                Q[i]=message[i]-'0';
            }
            ans.push_back(gao(1));
            ans.push_back(gao(0));
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "123210122"; string Arr1[] = { "011100011",  "NONE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, decode(Arg0)); }
	void test_case_1() { string Arg0 = "11"; string Arr1[] = { "01",  "10" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, decode(Arg0)); }
	void test_case_2() { string Arg0 = "22111"; string Arr1[] = { "NONE",  "11001" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, decode(Arg0)); }
	void test_case_3() { string Arg0 = "123210120"; string Arr1[] = { "NONE",  "NONE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, decode(Arg0)); }
	void test_case_4() { string Arg0 = "3"; string Arr1[] = { "NONE",  "NONE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, decode(Arg0)); }
	void test_case_5() { string Arg0 = "12221112222221112221111111112221111"; string Arr1[] = { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, decode(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        BinaryCode ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
