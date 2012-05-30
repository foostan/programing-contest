#include <iostream>
#include <string>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)

using namespace std;


int mtoi(string mn){
  int in=0;
  rep(i,(int)mn.size()){
    int c=1;
    if('2'<=mn[i] && mn[i]<='9'){ c=mn[i]-'0'; i++; }
    if(mn[i]=='m'){ in+=c*1000; }
    else if(mn[i]=='c'){ in+=c*100; }
    else if(mn[i]=='x'){ in+=c*10; }
    else if(mn[i]=='i'){ in+=c; }
  }

  return in;
}

string itom(int in){
  string mn;
  int pn=1000;
  char c[]={'m','c','x','i'};
  rep(i,4){
    int q=in/pn;
    if(q>0){
      if(in/pn>1) mn+='0'+q;
      mn+=c[i];
    }
    in%=pn; pn/=10;
  }

  return mn;
}

int main(){
  int n;
  cin>>n;
  rep(i,n){
    string a,b;
    cin>>a>>b;
    cout<<itom(mtoi(a)+mtoi(b))<<endl;
  }
  return 0;
}
