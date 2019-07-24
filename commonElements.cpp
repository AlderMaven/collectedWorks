//Created by Brandon Barnes
//Compile with c++11

#include <iostream>
#include <unordered_map>


using namespace std;

void commonElements(int array1[], int array2[], int array3[], int size1, int size2, int size3){
	unordered_map<int, int> hashMap;
	bool elementPrinted = false;
	
	for(int i = 0; i<size1; i++){
		if(hashMap[array1[i]] == 0){
			hashMap[array1[i]]++;
		}
	}
	
	for(int i = 0; i<size2; i++){
		if(hashMap[array2[i]] == 1){
			hashMap[array2[i]]++;
		}
	}
	
	for(int i = 0; i<size3; i++){
		if(hashMap[array3[i]] == 2){
			hashMap[array1[i]]++;
		}
	}
	
	for(auto i = hashMap.begin(); i!=hashMap.end(); i++){
		if(i->second==3){
			cout<<i->first << ' ';
			elementPrinted = true;
		}
	}
	cout << endl;
	if(elementPrinted){
		return;
	}
	else{
		cout << "No common elements" << endl;
	}
}

int main(){
	int arrayOne[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arrayTwo[] = {1, 3, 5, 7, 9};
	int arrayThree[] = {1, 2, 3, 5, 7};
	
	int size1 = sizeof(arrayOne) / sizeof(arrayOne[0]);
	int size2 = sizeof(arrayTwo) / sizeof(arrayTwo[0]);
	int size3 = sizeof(arrayThree) / sizeof(arrayThree[0]);
	
	commonElements(arrayOne, arrayTwo, arrayThree, size1, size2, size3);
	
}