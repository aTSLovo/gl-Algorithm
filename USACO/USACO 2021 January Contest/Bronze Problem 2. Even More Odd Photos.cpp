/*
ID: atsl
PROG: Even More Odd Photos
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
  //ifstream s("photo.in");
  //ofstream c("photo.out");
  //freopen("photo.in", "r", stdin);
  //freopen("photo.out", "w", stdout);
  tt=1;
//  cin>>tt;
  while(tt--) {
    cin>>n;
    int odd=0,even=0;
    rep(i,1,n) {
      int x;
      cin>>x;
      if(x&1) odd++;
      else even++;
    }
    int flag=0,ans=0;
    while(1) {
      if(flag&1) {
        if(odd>0) odd--,ans++;
        else break;
      }
      else {
        if(even>0) even--,ans++;
        else if(odd>1) odd-=2,ans++;
        else if(odd==1) {
          ans--;
          break;
        }
      }
      flag^=1;
    }
    cout<<ans;
  }
  return 0;
}
/*

*/
