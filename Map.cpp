//Created by Brandon Barnes

#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main(){
	map<int, int> testMap;
	map<int, int> testMapSequel;
	
	for(int i = 0; i<10; i++){
		testMap.insert(pair<int, int>(i, i));
		cout << "Map at " << i << " is " << testMap[i] << endl; 
		testMap.erase(i);
		testMap.insert(pair<int, int>(i, i+1));
		cout << "Now it is " << testMap[i] << endl;
	}
	cout << "clearing testMap" << endl;
	testMap.clear();
	cout << "Check if empty: " << testMap.empty() << endl;
	cout << "check current size is equal to 0: " << testMap.size() << endl;
	cout << "The max size for testMap is: " << testMap.max_size() << endl;
	cout << "Now refilling testMap" << endl;
	for(int i = 0; i<10; i++){
		testMap.insert(pair<int, int>(i, i+5));
		testMapSequel.insert(pair<int, int>(i, i+25));
		cout << "testMap at " << i << " is " << testMap[i] << endl;
		cout << "testMapSequel at " << i << " is " << testMapSequel[i] << endl;
	}
	swap(testMap, testMapSequel);
	
	cout << "Current states of maps" <<endl;
	for(int i = 1; i<10; i++){
		cout << "testMap at " << i << " is " << testMap[i] << endl;
		cout << "testMapSequel at " << i << " is " << testMapSequel[i] << endl;
	}
	

	return 0;
}
