//Created by Brandon Barnes
//Compile with c++11

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;



void printUncommon(string s1, string s2){
	unordered_set<char> hashMap;
	vector<char> toRemove;
	
	
	for(int i = 0; i<s1.length(); i++){
		hashMap.insert(s1[i]);
	}
	for(int i = 0; i<s2.length(); i++){
		if(hashMap.find(s2[i]) == hashMap.end()){
			cout << s2[i] << ' ';
		}
		else{
			toRemove.push_back(s2[i]);
		}
	}
	for(int i=0; i<toRemove.size(); i++){
		hashMap.erase(toRemove[i]);
	}
	for(auto it = hashMap.begin(); it != hashMap.end(); it++){
		cout << *it << ' ';
	}
	
}


int main(){
	string s1 = "characters";
	string s2 = "alphabets";
	
	printUncommon(s1, s2);
	
	return 0;
}