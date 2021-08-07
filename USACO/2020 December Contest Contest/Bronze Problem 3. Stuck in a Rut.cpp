/*
ID: atsl
PROG: Stuck in a Rut
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
char s[105];
ll x[105],y[105],endd[105],dui[105];
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //ifstream s("Stuck in a Rut.in");
  //ofstream c("Stuck in a Rut.out");
  //freopen("photo.in", "r", stdin);
  //freopen("photo.out", "w", stdout);
  tt=1;
//  cin>>tt;
  while(tt--) {
    cin>>n;
    rep(i,1,n) cin>>s[i]>>x[i]>>y[i],endd[i]=1e18;
    int cnt=0;
    while(cnt++<n) {
      rep(i,1,n) {
        if(s[i]=='E') {
          rep(j,1,n) {
            if(s[j]=='E'||i==j||x[j]<x[i]||y[j]>y[i]) continue;
            if(min(y[i],endd[j])-y[j]<x[j]-x[i]&&endd[j]>y[i]) {
              if(x[j]<endd[i]) endd[i]=x[j],dui[i]=j;
            }
            if(j==dui[i]) {
              if(endd[j]<=y[i]) endd[i]=1e18,dui[i]=0;
            }
          }
        }
        else {
          rep(j,1,n) {
            if(s[j]=='N'||i==j||x[j]>x[i]||y[j]<y[i]) continue;
            if(min(x[i],endd[j])-x[j]<y[j]-y[i]&&endd[j]>x[i]) {
              if(y[j]<endd[i]) endd[i]=y[j],dui[i]=j;
            }
            if(j==dui[i]) {
              if(endd[j]<=x[i]) endd[i]=1e18,dui[i]=0;
            }
          }
        }
      }
    }
    rep(i,1,n) {
      if(endd[i]==1e18) cout<<"Infinity\n";
      else {
        if(s[i]=='E') cout<<endd[i]-x[i]<<'\n';
        else cout<<endd[i]-y[i]<<'\n';
      }
    }

  }
  return 0;
}
/*

*/
