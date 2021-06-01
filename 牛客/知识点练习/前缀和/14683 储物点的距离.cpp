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
const ll N=200005;
const double esp=1e-6;
void debug(ll x)  { cout<<111<<" "<<x<<'\n'; }
ll n,m,k,tt;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }
ll a[N],b[N];
ll sum[N],pre[N];
ll get(int x,int l,int r,int p) {
	if(l>r) return 0;
	ll ans1=((1ll*x*(pre[r]-pre[l-1])%mod)+mod)%mod;
	ll ans2=(sum[r]-sum[l-1]+mod)%mod;
	ll ans=0;
	if(p==1) {
		ans=(ans1-ans2+mod)%mod;
	}
	else {
		ans=(ans2-ans1+mod)%mod;
	}
	
	return ans;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //ifstream s("input.txt");
  //ofstream c("intput.txt");
  tt=1;
  //cin>>tt;
  while(tt--) {
		cin>>n>>m;
		a[1]=1;
		rep(i,2,n) {
			ll x;
			cin>>x;
			a[i]=(a[i-1]+x)%mod;
		}
		rep(i,1,n) {
			cin>>b[i];
			pre[i]=(pre[i-1]+b[i])%mod;
			sum[i]=(sum[i-1]+a[i]*b[i]%mod)%mod;
		}
		rep(i,1,m) {
			int x,l,r;
			cin>>x>>l>>r;
			if(x>r) {
				cout<<get(a[x],l,r,1)<<'\n';
			}
			else if(x<l) {
				cout<<get(a[x],l,r,0)<<'\n';
			}
			else cout<<(get(a[x],l,x,1)+get(a[x],x,r,0)+mod)%mod<<'\n';
		}
		
  }
  return 0;
}
/*

*/
