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
struct team {
	int len,id;
	bool operator < (const team &A) const {
		return len>A.len;
	}
};

int a[N];
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //ifstream s("input.txt");
  //ofstream c("intput.txt");
  tt=1;
  cin>>tt;
  while(tt--) {
		cin>>n>>m>>k;
		priority_queue<team> q;
		rep(i,1,n) cin>>a[i];
		rep(i,1,m) q.push({0,i});
		vector<int> ans(n+1),sum(m+1);
		for(int i=n;i>=1;i--) {
			team t=q.top();
			q.pop();
			t.len+=a[i];
			sum[t.id]+=a[i];
			ans[i]=t.id;
			q.push(t);
		}
		int maxx=0,minn=1e9;
		rep(i,1,m) {
			maxx=max(maxx,sum[i]);
			minn=min(minn,sum[i]);
		}
		if(maxx-minn>k) cout<<"NO\n";
		else {
			cout<<"YES\n";
			rep(i,1,n) cout<<ans[i]<<' ';
			cout<<'\n';
		}
  }
  return 0;
}
/*

*/
