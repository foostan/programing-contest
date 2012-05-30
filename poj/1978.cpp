#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)

using namespace std;


int main(){
  int n,r;

  while(cin>>n>>r && n!=0 && r!=0){
    vector<int> deck;
    rep(i,n){ deck.push_back(n-i); }

    rep(i,r){
      int p,c;
      cin>>p>>c;

      vector<int> dp,dc,dr;
      REP(j,1,n+1){
        if(j<p) dp.push_back(deck[j-1]);
        else if(j<(c+p)) dc.push_back(deck[j-1]);
        else dr.push_back(deck[j-1]);
      }

      /*
      cout<<"p[ ";
      rep(j,dp.size()) cout<<dp[j]<<' ';
      cout<<" ]";
      cout<<"c[ ";
      rep(j,dc.size()) cout<<dc[j]<<' ';
      cout<<" ]";
      cout<<"r[ ";
      rep(j,dr.size()) cout<<dr[j]<<' ';
      cout<<" ]"<<endl;
      */

      dc.insert(dc.end(),dp.begin(),dp.end());
      dc.insert(dc.end(),dr.begin(),dr.end());
      deck.swap(dc);
    }
    
    cout<<deck[0]<<endl;
  }

  return 0;
}
