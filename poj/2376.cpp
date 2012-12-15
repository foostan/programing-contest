#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef pair<int,int> se;


int main(){
  int N,T;
  vector<se> t;

  cin>>N>>T;
  rep(i,N){ int s,e; cin>>s>>e; t.push_back(se(s,e)); }	
  sort(t.begin(),t.end());

  int ti=0,ci=0,ans=0;
  while( ci<N && ti<T ){
    int mx=0;
    for(;ci<N && t[ci].first<=ti+1; ci++) mx=max(mx,t[ci].second);
    if(mx==0) break;
    ti=mx; ans++;
  }

  cout<<(ti==T?ans:-1)<<endl;
  
  return 0;
}
