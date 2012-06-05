#include <iostream>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)
 
using namespace std;
 
int main(){
  int ma,da,mb,db,nm,nd,ans=0;
  int md[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  cin>>ma>>da>>mb>>db;
 
  nm=ma; nd=da;
  while( nm!=mb || nd!=db ){
    //cout<<nm<<' '<<nd<<endl;
    ans++;
    if( ++nd > md[nm-1] ){
      nd=1;
      if( ++nm > 12){
        nm=1;
      }
    }
  }
  
  cout<<ans<<endl;	
  return 0;
}
