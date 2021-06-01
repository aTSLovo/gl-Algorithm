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
int a[55];
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //ifstream s("input.txt");
  //ofstream c("intput.txt");
  tt=1;
  //cin>>tt;
  while(tt--) {
		cin>>n;
		rep(i,1,n) cin>>a[i];
        int x;
        cin>>x;
		sort(a+1,a+1+n);
		int ans=a[n]-a[1];
		
		for(int i=1;i<n;i++) {
			int l=min(a[1]+x,a[i+1]-x);
			int r=max(a[n]-x,a[i]+x);
			ans=min(ans,r-l);
		}
		cout<<ans<<'\n';
  }
  return 0;
}
/*

*/
