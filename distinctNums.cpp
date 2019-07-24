//Created by Brandon Barnes
//Compile with c++11

#include <iostream>
#include <unordered_set>
#include <vector>


using namespace std;


void distinctNums(int array[], int size, int windowSize){
	unordered_set<int> hashMap;
	vector<int> toRemove;
	
	if(windowSize<1){
		return;
	}
	if(windowSize==1){
		for(int i = 0; i<size;i++){
			cout << array[i] << ' ' << endl;
		}
		return;
		
	}
	
	for(int i = 0; i<size; i++){
		if((i+windowSize)<size){
			for(int j=i; j<(i+windowSize);j++){
				if(j==i){
					hashMap.insert(array[j]);
				}
				else{
					if(hashMap.find(array[j])!=hashMap.end()){
						toRemove.push_back(array[j]);
					}
					else{
						hashMap.insert(array[j]);
					}
				}
				
			}
			while(!(toRemove.empty())){
				hashMap.erase(toRemove.back());
				toRemove.pop_back();
			}
			for(auto it=hashMap.begin(); it!=hashMap.end();it++){
				cout << *it << ' ';
			}
			cout << endl;
			hashMap.clear();
		}
	}
}



int main(){
	int array[] = {1, 2, 1, 3, 4, 2, 3};
	int arraySize = sizeof(array)/sizeof(array[0]);
	
	distinctNums(array, arraySize, 4);
	
	
	
	return 0;
}