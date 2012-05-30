#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)

using namespace std;

int n;
vector<string> w;

string re(string a){
  string tmp;
  int len = a.size()-1;
  rep(i,len+1){
    tmp+=a[len-i];
  }

  return tmp;
}

int main(){
  cin>>n;
  w.assign(n,"");
  rep(i,n){
    cin>>w[i];
  }

  rep(i,n){
    REP(j,i,n){
      if(re(w[i])>re(w[j])){
        w[i].swap(w[j]);
      }
    }
  }

  rep(i,n){
    cout<<w[i]<<endl;
  }

  return 0;
}
