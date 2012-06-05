#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)
 
using namespace std;
 
typedef pair<int, int> p;
const int INF=1000000;
const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
 
p S,C,G;
int n,m,ans=0;
vector<string> map;
vector< vector<int> > dis;
 
int bfs(p S, p G){
  rep(i,n) dis[i].assign(m,INF);
 
  queue<p> que;
  que.push(S);
  dis[S.first][S.second] = 0;
  while(que.size()){
  
    //debug
    /*
    rep(i,n){
     rep(j,m){
       if(dis[i][j]==INF) cout<<"  "<<map[i][j];
       else printf("%3d",dis[i][j]);
     }
     cout<<endl;
    }
    cout<<endl;
    */
 
    p cp=que.front(); que.pop();
 
    // found point
    if(cp==G){
      return dis[cp.first][cp.second];
    }
   
    rep(i,4){
      int ny=cp.first+dy[i], nx=cp.second+dx[i];
      if(0<=ny && ny<n && 0<=nx && nx<m && map[ny][nx]!='#' && dis[ny][nx] == INF){
        que.push(p(ny,nx));
        dis[ny][nx]=dis[cp.first][cp.second]+1;
      }
    }
  }
 
  return INF;
}
 
 
int main(){
  cin>>n>>m;
  map.assign(n,"");
  rep(i,n){
    cin>>map[i];
    rep(j,m){
      if(map[i][j]=='S') S=p(i,j);
      else if(map[i][j]=='C') C=p(i,j);
      else if(map[i][j]=='G') G=p(i,j);
    }
  }
  dis.resize(n*m);
 
  //bfs
  ans += bfs(S,C);
  ans += bfs(C,G);
 
  cout<<((ans<INF)?ans:-1)<<endl;	
  return 0;
}
