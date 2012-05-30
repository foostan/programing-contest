#include <iostream>
#include <vector>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)

using namespace std;

int main(){
  int n;
  while(cin>>n && n!=0){
    int w,h,s,t,ans=0;
    cin>>w>>h;
    vector<string> map(h);
    rep(i,h)rep(j,w) map[i]+='.';
    rep(i,n){
      int x,y;
      cin>>x>>y;
      map[y-1][x-1]='*';
    }

    cin>>s>>t;

    rep(i,h-(t-1)) rep(j,w-(s-1)){
      int cnt=0;
      rep(k,t) rep(l,s){ if(map[i+k][j+l]=='*') cnt++; }
      ans=max(ans,cnt);
    }

    cout<<ans<<endl;
  }
  return 0;
}
