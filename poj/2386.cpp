#include <iostream>
#include <string>
#include <vector>

using namespace std;

int h,w;
vector<string> map;

void dfs(int y, int x){
	map[y][x] = '@';

	/* debug
	for(int iy=0; iy<h; iy++){
		for(int ix=0; ix<w; ix++){
			cout<<map[iy][ix];
		}
		cout<<endl;
	}
	cout<<endl;	
	*/

	for(int dy=-1;dy<=1;dy++)for(int dx=-1;dx<=1;dx++){
		int yy = y + dy, xx = x + dx;
		if( yy < 0 || xx < 0 || h <= yy || w <= xx ){ continue; }
		if( map[yy][xx] == 'W'){ dfs(yy,xx); }
	}
}

int main(){
	cin >> h >> w;
	map.assign(h,"");
	for(int i=0; i<h; i++){ cin >> map[i]; }

	int ans = 0;
	for(int y=0; y<h; y++)for(int x=0; x<w; x++){
		if( map[y][x] == 'W'){
			ans++;
			dfs(y,x);
		}
	}	

	cout << ans << endl;
	return 0;
}
