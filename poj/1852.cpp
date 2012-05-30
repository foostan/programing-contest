#include<iostream>
#include<vector>

using namespace std; 


int main(){
  int c,l,n;
  cin>>c;
  while(c--){
    int mint=0, maxt=0;
    cin>>l>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin>>x[i];

    //if maxt, all ants look to inside
    //if mint, all ants look to outside
    for(int i=0; i<n; i++){
      mint = max(mint,min(x[i], l-x[i]));
      maxt = max(maxt,max(x[i], l-x[i]));
    }

    cout<<mint<<' '<<maxt<<endl;
  }
  return 0;
}

