#include <iostream>

using namespace std;


int main(){
	int y,ans=false;
	cin >> y;


	if( y % 4 == 0){
		ans = true;
		if( y % 100 == 0){
			ans = false;
			if( y % 400 == 0){
				ans = true;
			}
		}
	}

	cout << (ans?"YES":"NO") << endl;

	return 0;
}
