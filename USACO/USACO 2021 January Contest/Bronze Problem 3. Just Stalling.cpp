/*
ID: atsl
PROG: Just Stalling
LANG: C++17
*/
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
#include <fstream>
#define rep(i,a,n)  for(int i=a;i<=n;i++)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define pb push_back
typedef long long ll;
using namespace std;
void debug(ll x)  { cout<<111<<" "<<x<<endl; }
const int mod=1e9+7;
const int N=100005;
ll n,m,k,tt;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //ifstream s("Cowntagion.in");
  //ofstream c("Cowntagion.out");
  //freopen("photo.in", "r", stdin);
  //freopen("photo.out", "w", stdout);
  tt=1;
//  cin>>tt;
  while(tt--) {
    cin>>n;
    vector<int> a(n+1),b(n+1);
    rep(i,1,n) cin>>a[i];
    sort(a.begin()+1,a.begin()+1+n);
    rep(i,1,n) cin>>b[i],b[i]=upper_bound(a.begin()+1,a.begin()+1+n,b[i])-a.begin()-1;
    sort(b.begin()+1,b.begin()+1+n);
    ll ans=1,cnt=0;
    rep(i,1,n) ans*=(b[i]-cnt),cnt++;
    if(ans<=0) ans=0;
    cout<<ans;
  }
  return 0;
}
/*

*/
