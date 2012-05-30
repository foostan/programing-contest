#include<iostream>
#include<string>
#include<algorithm>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)

using namespace std;

int main(){
  int n,cnt[4],minS,maxS;
  string c;
  cin>>n>>c;

  rep(i,n){
    cnt[(int)(c[i]-'0')-1]++;
  }

  minS=maxS=cnt[0];
  REP(i,1,4){
    minS=minS<cnt[i]?minS:cnt[i];
    maxS=maxS>cnt[i]?maxS:cnt[i];
  }

  cout<<maxS<<' '<<minS<<endl;
  return 0;
}
