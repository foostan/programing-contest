#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)

using namespace std;

int n;
double ans=0;
string c;

int main(){
  cin>>n>>c;
  rep(i,n){
    switch(c[i]){
      case 'A': ans+=4; break;
      case 'B': ans+=3; break;
      case 'C': ans+=2; break;
      case 'D': ans+=1; break;
      case 'F': ans+=0; break;
    }
  }


  cout<< setprecision(20)
    << (ans/n)
    << endl;
  /*
   * これでよかった模様 有効桁数間違い
  printf("%.10lf\n,"ans/n);
  */

  return 0;
}
