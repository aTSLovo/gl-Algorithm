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
int dp[55][55];
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //ifstream s("input.txt");
  //ofstream c("intput.txt");
  tt=1;
  //cin>>tt;
  while(tt--) {
		string s;
		cin>>s;
		n=s.size();
		s=" "+s;
		rep(i,1,n) dp[i][i]=1;
		for(int len=2;len<=n;len++) {
			for(int i=1;i+len-1<=n;i++) {
				int j=i+len-1;
				dp[i][j]=1e9;
				if(s[i]==s[j]) dp[i][j]=min(dp[i+1][j],dp[i][j-1]);
				else {
					for(int z=i;z<j;z++) {
						dp[i][j]=min(dp[i][j],dp[i][z]+dp[z+1][j]);
					}
				}
			}
		}
		cout<<dp[1][n]<<'\n';
  }
  return 0;
}
/*

*/
