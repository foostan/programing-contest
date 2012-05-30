#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef pair<string,int> sn;

const int MLEN=100;

sn p_num(sn num){
  num.first.insert(num.second,".");
  unsigned int i;
  for(i=0; i<num.first.size() && num.first[i]=='0'; i++); num.first.erase(0,i);
  for(i=num.first.size()-1; i>=0 && num.first[i]=='0'; i--); num.first.erase(i+1,num.first.size()-i);
  if(num.first[num.first.size()-1]=='.') num.first.erase(num.first.find("."),1);

  return num;
}

sn mul(sn a, sn b){
  string ans; ans.assign(MLEN,'0');
  rep(i,MLEN){
    rep(j,MLEN){
      int idx=MLEN - ((MLEN-i)+(MLEN-j)-1);
      if(idx<0) continue;
      int tmp = (a.first[i]-'0')*(b.first[j]-'0')+ans[idx]-'0';
      ans[idx] = (tmp%10)+'0';
      int up=tmp/10; idx--;
      
      while(up>0){
        tmp = up + ans[idx]-'0';
        ans[idx] = (tmp%10)+'0';
        up = tmp/10;
        idx--;
      }
    }
  }

  return sn(ans,MLEN-((MLEN-a.second)+(MLEN-b.second)));
}

int main(){
  string tmp,s;
  int n;
  while(cin>>tmp>>n){
    s.assign(MLEN-tmp.size()+1,'0');
    s+=tmp;
    int p=s.find(".",0);
    s.erase(p,1);
    sn num=sn(s,p),ans=num;

    rep(i,n-1){
      ans=mul(ans,num);
    }

    cout<<p_num(ans).first<<endl;
  }
  return 0;
}
