//Created by Brandon Barnes with help from https://ide.geeksforgeeks.org/6oUzCiq4iX

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool stringComparator(string first, string second){
	return(stoi(first+second)>stoi(second+first));
}

string constructLargest(int array[], int size){
	ostringstream stringBuilder;
	string returnString;
	vector<string> intStrings;
	
	
	for(int i = 0; i<size;i++){
		if(array[i]<0){
			return NULL;
		}
		intStrings.push_back(to_string(array[i]));
	}
	sort(intStrings.begin(), intStrings.end(), stringComparator);
	for(int i = 0; i<size;i++){
		stringBuilder<<intStrings[i];
	}
	returnString = stringBuilder.str();
	return returnString;
}

string constructLargest(vector<int> array, int size){
	ostringstream stringBuilder;
	string returnString;
	vector<string> intStrings;
	
	
	for(int i = 0; i<size;i++){
		if(array[i]<0){
			return NULL;
		}
		intStrings.push_back(to_string(array[i]));
	}
	sort(intStrings.begin(), intStrings.end(), stringComparator);
	for(int i = 0; i<size;i++){
		stringBuilder<<intStrings[i];
	}
	returnString = stringBuilder.str();
	return returnString;
}

int main(){
	vector<int> array = {0, 1, 5, 11, 9};
	cout << constructLargest(array, 5);
	return 0;
}