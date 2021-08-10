/*
ID: atsl
PROG: Rectangular Pasture
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
struct team {
  int x,y;
}arr[2505];
bool cmpx(team a,team b) {
  return a.x<b.x;
}
bool cmpy(team a,team b) {
  return a.y<b.y;
}
int g[2505][2505];
int get(int x1,int y1,int x2,int y2) {
  return g[x2][y2]-g[x1-1][y2]-g[x2][y1-1]+g[x1-1][y1-1];
}
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
    rep(i,1,n) cin>>arr[i].x>>arr[i].y;
    sort(arr+1,arr+1+n,cmpx);
    rep(i,1,n) arr[i].x=i;
    sort(arr+1,arr+1+n,cmpy);
    rep(i,1,n) arr[i].y=i;

    rep(i,1,n) g[arr[i].x][i]=1;
    rep(i,1,n) rep(j,1,n) g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
    /*
    rep(i,1,n) {
      rep(j,1,n) cout<<g[i][j]<<' ';
      cout<<endl;
    }
    */
    ll ans=0;

    for(int i=1;i<=n;i++) {
      for(int j=i;j<=n;j++) {
        int x1=min(arr[i].x,arr[j].x);
        int x2=max(arr[i].x,arr[j].x);
        ans+=1ll*get(1,i,x1,j)*get(x2,i,n,j);
        //if(i==1&&j==3) cout<<x1<<' '<<x2<<' '<<get(1,i,x1,j)<<' '<<get(x2,i,n,j)<<endl;
      }
    }

    cout<<ans+1;

  }
  return 0;
}
/*
二维前缀和维护矩形格点数量
*/
