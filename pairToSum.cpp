//Created by Brandon Barnes
//pairToSum based on design from https://www.geeksforgeeks.org/given-two-unsorted-arrays-find-pairs-whose-sum-x/



#include <iostream>
#include <unordered_set>

using namespace std;

void pairToSumSpace(int array1[], int array2[], int size1, int size2, int desiredSum){
	bool nonePrinted = true;
	
	for(int i=0; i<size1; i++){
		for(int j=0; j<size2; j++){
			if(desiredSum==(array1[i]+array2[j])){
				cout << array1[i] << ' ' << array2[j] << endl;
				nonePrinted = false;
			}
		}
	}
	
	if(nonePrinted){
		cout << "No pairs form desired sum" << endl;
	}
}


void pairToSum(int array1[], int array2[], int size1, int size2, int desiredSum){
	bool nonePrinted = true;
	
	unordered_set<int> hash;
	for (int i=0; i<size1; i++){
		hash.insert(array1[i]);
	}
	
	for(int i=0; i<size2;i++){
		if(hash.find(desiredSum-array2[i])!=hash.end()){
			cout << desiredSum-array2[i] << ' ' << array2[i] << endl;
			nonePrinted=false;
		}
	}
	
	if(nonePrinted){
		cout << "No pairs form desired sum" << endl;
	}
}


int main(){
	int array1[] = {1, 0, -4, 7, 6, 4}; 
    int array2[] = {0 ,2, 4, -3, 2, 1}; 
    int desiredSum = 8; 
    int size1 = sizeof(array1)/sizeof(array1[0]); 
    int size2 = sizeof(array2)/sizeof(array2[0]); 
    pairToSumSpace(array1, array2, size1, size2, desiredSum); 
	
	
	
	
	return 0;
}