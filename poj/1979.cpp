#include <iostream>

using namespace std;

int w,h,sx,sy,cnt;
char field[20][20];

/*
void p_field(){
	for(int y=0; y<h; y++){
		for(int x=0; x<w; x++){
			cout << field[y][x];
		}
		cout << endl;
	}
	cout << endl;
}
*/

void step(int x, int y){
	if(field[y][x] != '.') return;

	field[y][x] = '+'; // change current tile color
	cnt++; // count black tile
	//p_field();

	if(y!=0) step(x,y-1);
	if(x!=w-1) step(x+1,y);
	if(y!=h-1) step(x,y+1);
	if(x!=0) step(x-1,y);
}

int main(){
	while(cin>>w>>h && w!=0 && h!=0){
		sx,sy,cnt=0;
		if( w==0 && h==0) break;
		for(int y=0; y<h; y++){
			for(int x=0; x<w; x++){
				cin >> field[y][x];
			}
		}
	
		// find start posint
		for(int y=0; y<h; y++){
			for(int x=0; x<w; x++){
				if(field[y][x] == '@'){ sx=x; sy=y; field[y][x]='.'; }
			}
		}
	
		//cout<<sx<<' '<<sy<<endl;
		//p_field();
		
		step(sx,sy);
	
		cout << cnt << endl;	
	}

	return 0;
}
