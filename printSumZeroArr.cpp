//Created by Brandon Barnes
//Compile with c++11
//Based on design from: https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/

#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

void print(vector<pair<int, int>> out) { 
    for (auto it = out.begin(); it != out.end(); it++) {
        cout << "Subarray found from Index " <<  it->first << " to " << it->second << endl; 
	}
} 


vector<pair <int, int> > printSumZeroArr(int array[], int size){
	
	unordered_map<int, vector<int> > hashMap;
	
	vector<pair<int, int> > returnVector;
	
	int sum = 0;
	
	for(int i=0; i<size; i++){
		sum += array[i];
		
		if(sum == 0){
			returnVector.push_back(make_pair(0,i));
		}
		
		if(hashMap.find(sum) != hashMap.end()){
			vector<int> vc = hashMap[sum];
			for(auto it = vc.begin(); it != vc.end(); it++){
				returnVector.push_back(make_pair(*it+1, i));
			}
		}
		hashMap[sum].push_back(i);
	}
	print(returnVector);
	return returnVector;
}



int main(){
	int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
   
    vector<pair<int, int> > out = printSumZeroArr(arr, n); 
	
	
	
	
	
	return 0;
}