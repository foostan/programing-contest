#include <iostream>
#include <vector>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)

using namespace std;

int main(){
  int n,q;
  while(cin>>n>>q && n!=0){
    int m;
    vector<int> cdates;
    cdates.assign(100,0);

    rep(i,n){
      cin>>m;
      rep(j,m){
        int d;
        cin>>d;
        cdates[d]++;
      }
    }
    
    int xday=0,xm=0;
    rep(i,100){
      if(cdates[i]>=q && cdates[i]>xm){ xday=i; xm=cdates[i]; }
    }
    cout<<xday<<endl;
  }

  return 0;
}
