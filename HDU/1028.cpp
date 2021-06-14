//author:aTSL
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#define rep(i,a,n)  for(int i=a;i<=n;i++)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define pb push_back
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll N=100005;
const double esp=1e-6;
void debug(ll x)  { cout<<111<<" "<<x<<'\n'; }
ll n,m,k,tt;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }
ll qpow(ll a,ll b) {
  ll res=1;
  while(b) {
    if(b&1) res=res*a%mod;
    a=a*a%mod;
    b>>=1;
  }
  return res;
}
ll dp[125][125];
int a[1005];
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //ifstream s("input.txt");
  //ofstream c("intput.txt");
  tt=1;
  //cin>>tt;
  //将推到0的需要+1
  for(int i=0;i<=120;i++) dp[0][i]=1;
  for(int i=1;i<=120;i++) {
    for(int j=1;j<=120;j++) {
      if(j>i) dp[i][j]=dp[i][i];
      else if(j==i) dp[i][j]=1+dp[i][j-1];
      else dp[i][j]=dp[i-j][j]+dp[i][j-1];
    }
  }
  while(cin>>n) {
    cout<<dp[n][n]<<'\n';
  }
  return 0;
}
/*

*/
