//Created by Brandon Barnes

#include <iostream>
#include <string>

using namespace std;

string longestCommonPrefix(string args[], int size){
	string returnString;
	int temp = 0;
	
	if(size==0){
		return "";
	}
	if(size==1){
		return args[0];
	}
	else{
		returnString = args[0];
	}
	for(int i = 1; i<size;i++){
		if(returnString.size()>args[i].size()){
			temp = args[i].size();
			for(int j = 0; j<temp;j++){
				if(args[i].at(j)!=returnString.at(j)){
					temp = j;
					break;
				}
			}
			if(temp == 0){
				return "";
			}
			else{
				returnString = args[i].substr(0,temp);
			}
		}
		else{
			temp = returnString.size();
			for(int j = 0; j<temp;j++){
				if(args[i].at(j)!=returnString.at(j)){
					temp = j;
					break;
				}
			}
			if(temp == 0){
				return "";
			}
			else{
				returnString = returnString.substr(0,temp);
			}
		}
	}
	
	
	return returnString;
}

int main(){
	
	string args[] = {"apple", "ape", "april"};
	
	cout << longestCommonPrefix(args, 3)<<endl;
	
	
	cout << "exiting" <<endl;
	
	
	return 0;
}