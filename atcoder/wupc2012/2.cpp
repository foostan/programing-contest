
#include <iostream>
#include <string>
#include <vector>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)
 
using namespace std;
 
int main(){
  int n;
  string ans;
  vector<string> strs;
  cin>>n;
  rep(i,n){ string tmp; cin>>tmp; strs.push_back(tmp); }
 
  ans=strs[0];
  ans.insert(ans.end(),strs[1].begin(),strs[1].end());
  rep(i,n){
    REP(j,i+1,n){
      string tmp1=strs[i], tmp2=strs[j];
      tmp1.insert(tmp1.end(),strs[j].begin(),strs[j].end());
      tmp2.insert(tmp2.end(),strs[i].begin(),strs[i].end());
      ans=min(min(ans,tmp1),tmp2);
     // cout<<tmp1<<' '<<tmp2<<endl;
    }
  }
 
 
  cout<<ans<<endl;
  return 0;
}
