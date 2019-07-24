//Created by Brandon Barnes

#include <iostream>
#include <string>

using namespace std;


int binaryConverter(string binString){
	int accumulator = 0;
	int powerAccumulator = 1;
	
	for(int i = binString.length()-1; i>-1;i--){
		accumulator = accumulator +(((int)binString[i])-48)*powerAccumulator;
		powerAccumulator = powerAccumulator*2;
	}
	
	
	return accumulator;
}


int main(){
	string binString = "1010";
	cout << binaryConverter(binString) << endl;
}