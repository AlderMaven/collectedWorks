//Created by Brandon Barnes

#include <iostream>


using namespace std;

bool isPowTwoHelper(int testInt){
	if(testInt == 1){
		return true;
	}
	if(testInt%2==1){
		return false;
	}
	
	return isPowTwoHelper(testInt/2);
	
	
}



bool isPowTwo(int testInt){
	if(testInt == 1){
		return true;
	}
	if(testInt%2 != 0){
		return false;
	}
	if(testInt < 1){
		return 0;
	}
	return isPowTwoHelper(testInt/2);
}


int main(){
	
	for(int i = 1; i<10; i++){
		
		cout << "i is: " << i << ' ' << "isPowTwo is: " << isPowTwo(i) << endl;
	}
	
	return 0;
}