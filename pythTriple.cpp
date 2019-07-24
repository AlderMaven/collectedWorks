//Created by Brandon Barnes



#include <iostream>
#include <algorithm>

using namespace std;

bool pythTriple(int array[], int size){
	bool returnBool = false;
	vector<int> workingVector;
	
	for(int i = 0; i<size; i++){
		workingVector.push_back(array[i]*array[i]);
	}
	
	sort(workingVector.begin(), workingVector.end());
	
	for(int a = 0; a<size-1; a++){
		for(int b = a+1; b<size; b++){
			for(int c = size-1; c>b;c--){
				if(workingVector[c] == workingVector[b]+workingVector[a]){
					cout << workingVector[c] <<endl;
					cout << workingVector[b] <<endl;
					cout << workingVector[a] <<endl;
					return true;
				}
				else if(workingVector[c] < workingVector[b]+workingVector[a]){
					break;
				}
				
			}
		}
		
	}
	
	
	return returnBool;
}


int main(){
	int array[] = {3, 5, 4, 7, 26, 98, 123, 452, 234, 111, 145, 197, 193, 134, 144, 187, 163, 147, 19, 20, 21, 22, 23, 24};
	cout << pythTriple(array, 24);
	
	
	return 0;
}