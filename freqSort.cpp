//Created by Brandon Barnes
//modified for compilation time from: https://www.geeksforgeeks.org/sort-elements-frequency-set-4-efficient-approach-using-hash/
//Compile with c++11

#include <iostream>
#include <unordered_map>
#include <algorithm>


using namespace std;


unordered_map<int, int> m2;


bool freqComparator(const pair<int, int> &a, const pair<int, int> &b){
	if(a.second == b.second){
		return m2[a.first] < m2[b.first];
	}
	return a.second > b.second;
}


void freqSort(int array[], int size){
	unordered_map<int, int> m;
	vector<pair<int, int> > v;
	
	for(int i=0; i<size; i++){
		m[array[i]]++;
		if(m2[array[i]]==0){
			m2[array[i]] = i+1;
		}
	}
	
	copy(m.begin(), m.end(), back_inserter(v));
	sort(v.begin(), v.end(), freqComparator);
	
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].second; j++){
			cout << v[i].first << ' ';
		}
	}
	
	
}

int main(){
	
	int a[] = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 }; 
    int n = sizeof(a) / sizeof(a[0]); 
	
	freqSort(a, n);
	cout << endl;
	
	return 0;
}