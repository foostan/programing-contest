#include <iostream>
#include <stdio.h>

using namespace std;

bool func(int y, int m, int d){
	if( y % m == 0 ){
		if( (y/m) % d == 0){
			return true;
		}
	}
	return false;
}

bool uru(int y){
	bool uru = false;

	if( y % 4 == 0){
		uru = true;
		if( y % 100 == 0){
			uru = false;
			if( y % 400 == 0){
				uru = true;
			}
		}
	}

	return uru;
}

int main(){
	int y,m,d;
	int md[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	scanf("%d/%d/%d",&y,&m,&d);

	while( !func(y,m,d) ){
		if( ++d > md[m-1] ){
			if(uru(y) && m==2 && d==29){ continue; }
			d=1;
			if( ++m > 12){
				m=1;
				y++;
			}
		}
	}

	printf("%04d/%02d/%02d\n",y,m,d);

	return 0;
}

