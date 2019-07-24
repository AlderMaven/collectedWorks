//Created by Brandon Barnes

#include <iostream> //cout dependency
#include <string> //string dependency
#include <sstream> //oss dependency

using namespace std;

string reverseOrder(string original){
	ostringstream oss;
	string returnString;
	
	for(int i = original.size()-1; i>0; i--){
		if(original[i]=='.'){
			for(int j = i+1; j<original.size() && original[j] != '.'; j++){
				oss << original[j];
				
			}
			oss << original[i];
		}
		cout << original.size() <<endl;
	}
	int iterator=0;
	while(original[iterator]!='.' && iterator<original.size()){
		oss<<original[iterator];
		iterator++;
	
	}
	returnString = oss.str();
	return returnString;
}

int main(){
	string testString = "i.like.this.program.very.much";
	
	cout << reverseOrder(testString) << endl;
return 0;
}