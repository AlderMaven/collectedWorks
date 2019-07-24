//Created by Brandon Barnes

#include <iostream>
#include <vector>


using namespace std;


int flipsNecessary(vector<bool> arr1, vector<bool> arr2){
	
	if(arr1.size() != arr2.size()){
		return -1;  //No number of flips can turn arr1 into arr2
	}
	else{
		int accumulator = 0;
		
		for(int i = 0; i<arr1.size(); i++){
			if(arr1[i]!=arr2[i]){
				accumulator+=1;
			}
		}
		return accumulator;
	}
}

int main(){
	bool dummy98A[] = {1, 0, 0, 1};
	bool dummy98B[] = {1, 1, 1, 1};
	vector<bool> arr1(dummy98A, dummy98A + sizeof(dummy98A)/sizeof(bool));
	vector<bool> arr2(dummy98B, dummy98B + sizeof(dummy98B)/sizeof(bool));
	
	cout << flipsNecessary(arr1, arr2) << endl;
	
	
	
	return 0;
}